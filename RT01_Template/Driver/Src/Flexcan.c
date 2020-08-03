/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#include "S32K144.h"    /* include peripheral declarations S32K144 */
#include "FlexCAN.h"

uint32_t  RxCODE;              /*< Received message buffer code 			*/
/**
  * @brief  FLEXCAN0_init
  * @param  
  * @retval 
  */
uint32_t  RxID;                /*< Received message ID 					*/
uint32_t  RxLENGTH;            /*< Recieved message number of data bytes 	*/
uint32_t  RxDATA[2];           /*< Received message data (2 words) 		*/
uint32_t  RxTIMESTAMP;         /*< Received message time 					*/

void CAN0_NVIC_init_IRQs (void)
{
	S32_NVIC->ICPR[1] = 1 << (81 % 32);  /* IRQ81-CHA0 0-15: clr any pending IRQ*/
	S32_NVIC->ISER[(uint32_t)(CAN0_ORed_0_15_MB_IRQn) >> 5U] = (uint32_t)(1UL << ((uint32_t)(CAN0_ORed_0_15_MB_IRQn) & (uint32_t)0x1FU));
	S32_NVIC->IP[81] = 0xb;              /* IRQ81-CAN0 0-15: priority 10 of 0-15*/
}

void FLEXCAN0_init(void)
{
#define MSG_BUF_SIZE  4		/* Msg Buffer Size. (CAN 2.0AB: 2 hdr +  2 data= 4 words) */
  uint32_t   i=0;
  CAN0_NVIC_init_IRQs();

  PCC->PCCn[PCC_FlexCAN0_INDEX] |= PCC_PCCn_CGC_MASK; /* CGC=1: enable clock to FlexCAN0 */

  CAN0->MCR |= CAN_MCR_MDIS_MASK;         /* MDIS=1: Disable module before selecting clock 	*/
  CAN0->CTRL1 &= ~CAN_CTRL1_CLKSRC_MASK;  /* CLKSRC=0: Clock Source = SOSCDIV2				*/
  CAN0->MCR &= ~CAN_MCR_MDIS_MASK;        /* MDIS=0; Enable module config. (Sets FRZ, HALT)	*/

  while (!((CAN0->MCR & CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT))  {}
	/*!
	 * Good practice:
	 * ===================================================
	 * wait for FRZACK=1 on freeze mode entry/exit
	 */
  CAN0->CTRL1 = 0
      #if defined(S32K11x_SERIES)
      |CAN_CTRL1_PRESDIV(4)   /* PRESDIV=4: Sclock=PEclock/(PRESDIV+1) = 40MHz/5 = 8MHz    */
      #endif
      |CAN_CTRL1_PSEG2(3)	    /* Configure for 500 KHz bit time 								*/
		  |CAN_CTRL1_PSEG1(3) 		/* Time quanta freq = 16 time quanta x 500 KHz bit time= 8MHz 	*/
		  |CAN_CTRL1_PROPSEG(6)		/* PRESDIV+1 = Fclksrc/Ftq = 8 MHz/8 MHz = 1 					*/
		  |CAN_CTRL1_RJW(3)			/*    so PRESDIV = 0 											*/
		  |CAN_CTRL1_SMP(1); 		/* PSEG2 = Phase_Seg2 - 1 = 4 - 1 = 3 							*/
								            /* PSEG1 = PSEG2 = 3 											*/
									/* PROPSEG= Prop_Seg - 1 = 7 - 1 = 6 							*/
									/* RJW: since Phase_Seg2 >=4, RJW+1=4 so RJW=3. 				*/
									/* SMP = 1: use 3 bits per CAN sample 							*/
									/* CLKSRC=0 (unchanged): Fcanclk= Fosc= 8 MHz 					*/

  for(i=0; i<128; i++ )
  {   					/* CAN0: clear 32 msg bufs x 4 words/msg buf = 128 words */
    CAN0->RAMn[i] = 0;  /* Clear msg buf word */
  }
  for(i=0; i<16; i++ )
  {          						/* In FRZ mode, init CAN0 16 msg buf filters */
    CAN0->RXIMR[i] = 0xFFFFFFFF;  	/* Check all ID bits for incoming messages */
  }
  CAN0->RXMGMASK = 0x1FFFFFFF;  				/* Global acceptance mask: check all ID bits 	*/
  CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] = 0x04000000; /* Msg Buf 4, word 0: Enable for reception 	*/
                                                /* EDL,BRS,ESI=0: CANFD not used 				*/
                                                /* CODE=4: MB set to RX inactive 				*/
                                                /* IDE=0: Standard ID 							*/
                                                /* SRR, RTR, TIME STAMP = 0: not applicable 	*/
#ifdef NODE_A                                   /* Node A receives msg with std ID 0x511 		*/
  CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] = 0x14440000; /* Msg Buf 4, word 1: Standard ID = 0x111 		*/
#else                                           /* Node B to receive msg with std ID 0x555 	*/
  CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] = 0x15540000; /* Msg Buf 4, word 1: Standard ID = 0x555 		*/
  //CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] = 0x1FFFFFFF; /* Msg Buf 4, word 1: Standard ID = 0x555 		*/
#endif
                                /* PRIO = 0: CANFD not used */
  CAN0->MCR = 0x0000001F;       /* Negate FlexCAN 1 halt state for 32 MBs */

  CAN0->IMASK1 |= (1<<4); /* Open FIFO receives interrupt */

  while ((CAN0->MCR && CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT)  {}
  /* Good practice: wait for FRZACK to clear (not in freeze mode) */

  while ((CAN0->MCR && CAN_MCR_NOTRDY_MASK) >> CAN_MCR_NOTRDY_SHIFT)  {}
  /* Good practice: wait for NOTRDY to clear (module ready) */
}

void FLEXCAN0_transmit_msg(void)
{
	/*! Assumption:
	 * =================================
	 * Message buffer CODE is INACTIVE
	 */
	CAN0->IFLAG1 = 0x00000001;	/* Clear CAN 0 MB 0 flag without clearing others*/

  CAN0->RAMn[ 0*MSG_BUF_SIZE + 2] = 0xA5112233;	/* MB0 word 2: data word 0 */
  CAN0->RAMn[ 0*MSG_BUF_SIZE + 3] = 0x44556677; /* MB0 word 3: data word 1 */
#ifdef NODE_A
  CAN0->RAMn[ 0*MSG_BUF_SIZE + 1] = 0x15540000; /* MB0 word 1: Tx msg with STD ID 0x555 */
#else
  CAN0->RAMn[ 0*MSG_BUF_SIZE + 1] = 0x14440000; /* MB0 word 1: Tx msg with STD ID 0x511 */
#endif
  CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] = 0x0C400000 | 8 << CAN_WMBn_CS_DLC_SHIFT;
  	  	  	  	  	  	  	  	  	  	  	  	/* MB0 word 0: 								*/
                                                /* EDL,BRS,ESI=0: CANFD not used 				*/
                                                /* CODE=0xC: Activate msg buf to transmit 		*/
                                                /* IDE=0: Standard ID 							*/
                                                /* SRR=1 Tx frame (not req'd for std ID) 		*/
                                                /* RTR = 0: data, not remote tx request frame	*/
                                                /* DLC = 8 bytes 								*/
}

void FLEXCAN0_receive_msg(void)
{
/*! Receive msg from ID 0x556 using msg buffer 4
 * =============================================
 */
  uint8_t j;
  uint32_t dummy;

  RxCODE   = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;	/* Read CODE field */
  RxID     = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT;	/* Read ID 			*/
  RxLENGTH = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;	/* Read Message Length */

  for (j=0; j<2; j++)
  {  /* Read two words of data (8 bytes) */
    RxDATA[j] = CAN0->RAMn[ 4*MSG_BUF_SIZE + 2 + j];
  }
  RxTIMESTAMP = (CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] & 0x000FFFF);
  dummy = CAN0->TIMER;             /* Read TIMER to unlock message buffers */
  CAN0->IFLAG1 = 0x00000010;       /* Clear CAN 0 MB 4 flag without clearing others*/
}

void FLEXCAN0_Task(void)
{
//    if ((CAN0->IFLAG1 >> 4) & 1) {  /* If CAN 0 MB 4 flag is set (received msg), read MB4 */
//        FLEXCAN0_receive_msg ();      /* Read message */
//        //rx_msg_count++;               /* Increment receive msg counter */

//        //if (rx_msg_count == 1000) {   /* If 1000 messages have been received, */
//        //PTD->PTOR |= 1<<16;         /*   toggle output port D16 (Green LED) */
//        //rx_msg_count = 0;           /*   and reset message counter */
//    }
    if (CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] == 0x15540000)
    {
        CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] = 0x14000000;    /* Msg Buf 4, word 1: Standard ID = 0x500 		*/
    }
    else
    {
        CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] = 0x15540000;    /* Msg Buf 4, word 1: Standard ID = 0x555 		*/
    }

    FLEXCAN0_transmit_msg ();     /* Transmit message using MB0 */
}

void CAN0_ORed_0_15_MB_IRQHandler(void)
{
	unsigned char j;

	if ((CAN0->IFLAG1 >> 4) & 1)
	{

		RxCODE   = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] & 0x07000000) >> 24;  /* Read CODE field */
		RxID     = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 1] & CAN_WMBn_ID_ID_MASK)  >> CAN_WMBn_ID_ID_SHIFT ;
		RxLENGTH = (CAN0->RAMn[ 4*MSG_BUF_SIZE + 0] & CAN_WMBn_CS_DLC_MASK) >> CAN_WMBn_CS_DLC_SHIFT;
		for (j=0; j<2; j++) {  /* Read two words of data (8 bytes) */
		  RxDATA[j] = CAN0->RAMn[ 4*MSG_BUF_SIZE + 2 + j];
		}
		RxTIMESTAMP = (CAN0->RAMn[ 0*MSG_BUF_SIZE + 0] & 0x000FFFF);

		if((RxID==0x15540000)||(RxID==0x14880000))
		{
			FLEXCAN0_transmit_msg();
		}

		CAN0->IFLAG1 = 0x00000010;       /* Clear CAN 0 MB 4 flag without clearing others*/
	}
}



