/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#include "S32K144.h"    /* include peripheral declarations S32K144 */
#include "Test.h"
#include <stdint.h>

/**
  * @brief  SOSC_Init_8MHz
  * @param  
  * @param  
  * @retval 
  */
void NVIC_init_IRQs(void)
{
    S32_NVIC->ICPR[1] = 1 << (48 % 32);/* IRQ48-LPIT0 ch0: clr any pending IRQ*/
    S32_NVIC->ISER[1] = 1 << (48 % 32);/* IRQ48-LPIT0 ch0: enable IRQ */
    S32_NVIC->IP[48] = 0X0A;/* IRQ48-LPIT0 ch0: priority 10 of 0-15*/
}

/**
  * @brief  LPIT0_init
  * @param  
  * @param  
  * @retval 
  */
void LPIT0_init(void)
{
    NVIC_init_IRQs();
    
    PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6);/* Clock Src = 6 (SPLL2_DIV2_CLK)*/
    PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK;/* Enable clk to LPIT0 regs */
    LPIT0->MCR = 0x00000001;/* DBG_EN-0: Timer chans stop in Debug mode */
                            /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
                            /* SW_RST=0: SW reset does not reset timer chans, regs */
                            /* M_CEN=1: enable module clk (allow writing other LPIT0 regs) */

    LPIT0->MIER = 0x00000001;  /* TIE0=1: Timer Interrupt Enabled fot Chan 0 */
    LPIT0->TMR[0].TVAL = 40000000;  /* Chan 0 Timeout period: 80M clocks */
    LPIT0->TMR[0].TCTRL = 0X00000001;   /* T_EN=1: Timer channel is enabled */
                                        /* CHAIN=0: channel chaining is disabled */
                                        /* MODE=0: 32 periodic counter mode */
                                        /* TSOT=0: Timer decrements immediately based on restart */
                                        /* TSOI=0: Timer does not stop after timeout */
                                        /* TROT=0 Timer will not reload on trigger */
                                        /* TRG_SRC=0: External trigger source */
                                        /* TRG_SEL=0: Timer chan 0 trigger source is selected*/
}

/**
 * @brief  LPIT0_Timer 
 * @param  
 * @param  
 * @retval 
 */
void LPIT0_Test(void)
{
    //while(0 == (LPIT0->MSR & LPIT_MSR_TIF0_MASK)){}/* Wait for LPIT0 CH0 Flag */
    //Lpit_Test();

    //LPIT0->MSR |= LPIT_MSR_TIF0_MASK;* Clear LPIT0 timer flag 0 */

}

/**
 * @brief  LPIT0_Timer_interupt 
 * @param  
 * @param  
 * @retval 
 */
void LPIT0_Ch0_IRQHandler(void)
{
    LPIT0->MSR |= LPIT_MSR_TIF0_MASK;/* Clear LPIT0 timer flag 0 */
    Lpit_Test();
    //Port_Test();
}
