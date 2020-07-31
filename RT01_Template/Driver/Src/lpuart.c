/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#include "S32K144.h"    /* include peripheral declarations S32K144 */
#include "lpuart.h"

#define BAUD_115200
/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void UART2_NVIC_init_IRQs(void)
{
    S32_NVIC->ICPR[1] = 1 << (35 % 32);  /* IRQ48-UART2: clr any pending IRQ*/
    S32_NVIC->ISER[(uint32_t)(LPUART2_RxTx_IRQn) >> 5U] = (uint32_t)(1UL << ((uint32_t)(LPUART2_RxTx_IRQn) & (uint32_t)0x1FU));
    S32_NVIC->IP[35] = 0x7;              /* IRQ48-UART2: priority 7 of 0-15*/
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void Lpuart2_init(void)
{
    UART2_NVIC_init_IRQs();
    PCC->PCCn[PCC_LPUART2_INDEX] &= ~PCC_PCCn_CGC_MASK;  /* Ensure clk disabled for config */
    //PCC->PCCn[PCC_LPUART2_INDEX] |= PCC_PCCn_PCS(1);     /* Clock Src= 1 (SOSCDIV2_CLK) */
    PCC->PCCn[PCC_LPUART2_INDEX] |= PCC_PCCn_PCS(0b110);     /* Clock Src= 1 (SPLLDIV2_CLK) 40MHz*/
    PCC->PCCn[PCC_LPUART2_INDEX] |= PCC_PCCn_CGC_MASK;   /* Ensure clk disabled for config */
 #ifdef BAUD_115200
    LPUART2->BAUD = 0x0F000016;     /* Initialize for 115200 baud, 1 stop: */
                                    /* SBR=21 (0x15): baud divisor = 40M/115200/16 = ~15 */
                                    /* OSR=15: Over sampling ratio = 15+1=16 */
                                    /* SBNS=0: One stop bit */
                                    /* BOTHEDGE=0: receiver samples only on rising edge */
                                    /* M10=0: Rx and Tx use 7 to 9 bit data characters */
                                    /* RESYNCDIS=0: Resync during rec'd data word supported */
                                    /* LBKDIE, RXEDGIE=0: interrupts disable */
                                    /* TDMAE, RDMAE, TDMAE=0: DMA requests disabled */
                                    /* MAEN1, MAEN2, MATCFG=0: Match disabled */
#else
    LPUART2->BAUD = 0x0f000034;     /* Initialize for 9600 baud, 1 stop: */
                                    /* SBR=52 (0x34): baud divisor = 8M/9600/16 = ~52 */
                                    /* OSR=15: Over sampling ratio = 15+1=16 */
                                    /* SBNS=0: One stop bit */
                                    /* BOTHEDGE=0: receiver samples only on rising edge */
                                    /* M10=0: Rx and Tx use 7 to 9 bit data characters */
                                    /* RESYNCDIS=0: Resync during rec'd data word supported */
                                    /* LBKDIE, RXEDGIE=0: interrupts disable */
                                    /* TDMAE, RDMAE, TDMAE=0: DMA requests disabled */
                                    /* MAEN1, MAEN2, MATCFG=0: Match disabled */
#endif

//    LPUART2->CTRL = 0x000C0000;
    LPUART2->CTRL = 0x002C0000;     /* Enable transmitter & receiver, no parity, 8 bit char: */
                                    /* RE=1: Receiver enabled */
                                    /* TE=1: Transmitter enabled */
                                    /* PE,PT=0: No hw parity generation or checking */
                                    /* M7,M,R8T9,R9T8=0: 8-bit data characters*/
                                    /* DOZEEN=0: LPUART enabled in Doze mode */
                                    /* ORIE,NEIE,FEIE,PEIE,TIE,TCIE,RIE,ILIE,MA1IE,MA2IE=0: no IRQ*/
                                    /* TxDIR=0: TxD pin is input if in single-wire mode */
                                    /* TXINV=0: TRansmit data not inverted */
                                    /* RWU,WAKE=0: normal operation; rcvr not in statndby */
                                    /* IDLCFG=0: one idle character */
                                    /* ILT=0: Idle char bit count starts after start bit */
                                    /* SBK=0: Normal transmitter operation - no break char */
                                    /* LOOPS,RSRC=0: no loop back */
}


/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void Lpuart2_transmit_char(char send)
{
    while((LPUART2->STAT & LPUART_STAT_TDRE_MASK) >> LPUART_STAT_TDRE_SHIFT == 0);
    LPUART2->DATA = send;
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void Lpuart2_transmit_string(char data_string[])
{
    uint32_t i = 0;
    while(data_string[i] != '\0')
    {
        Lpuart2_transmit_char(data_string[i]);
        i++;
    }
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void Lpuart2_transmit_n_size(char data_string[], uint16_t size)
{
    uint32_t i = 0;
    while(data_string[i] != '\0')
    {
        Lpuart2_transmit_char(data_string[i]);
        i++;
    }
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
char Lpuart2_receive_char(void)
{
    char receive;

    while (((LPUART2->STAT) & LPUART_STAT_RDRF_MASK) >> LPUART_STAT_RDRF_SHIFT == 0) 
        LPUART2->STAT = LPUART_STAT_OR(0);

    receive = LPUART2->DATA;
    return receive;
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval bian
  */
void Lpuart2_receive_and_echo_char(void)
{
    char send = Lpuart2_receive_char();
    Lpuart2_transmit_char(send);
    Lpuart2_transmit_string("hello world");
    Lpuart2_transmit_char('\n');
}

void LPUART2_RxTx_IRQHandler(void)
{
    char rev;
    if (LPUART2->STAT & 0x00200000)
    {
        rev = LPUART2->DATA;

        /* 如果发射区不为空 */
        if((LPUART2->STAT & LPUART_STAT_TDRE_MASK)>>LPUART_STAT_TDRE_SHIFT!=0) 
        {
            LPUART2->DATA = rev;
        }
    }
}
