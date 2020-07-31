/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#include "S32K144.h"    /* include peripheral declarations S32K144 */
#include <stdint.h>

uint8_t TCD0_Source[] = {"hello world"};
uint8_t volatile TCD0_Dest = 0;

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void DMA_init(void)
{

}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void DMA_TCD_init(void)
{
    DMA->TCD[0].SADDR = DMA_TCD_SADDR_SADDR((uint32_t) &TCD0_Source);
    DMA->TCD[0].SOFF = DMA_TCD_SOFF_SOFF(1);
    DMA->TCD[0].ATTR =  DMA_TCD_ATTR_SMOD(0)
                      | DMA_TCD_ATTR_SSIZE(0)
                      | DMA_TCD_ATTR_DMOD(0)
                      | DMA_TCD_ATTR_DSIZE(0);
                      
    DMA->TCD[0].NBYTES.MLNO = DMA_TCD_NBYTES_MLNO_NBYTES(1);
    DMA->TCD[0].SLAST = DMA_TCD_SLAST_SLAST(-11);

    DMA->TCD[0].DADDR = DMA_TCD_DADDR_DADDR((uint32_t) &TCD0_Dest);
    DMA->TCD[0].DOFF = DMA_TCD_DOFF_DOFF(0);
    DMA->TCD[0].CITER.ELINKNO = DMA_TCD_CITER_ELINKNO_CITER(11);
    DMA->TCD[0].DLASTSGA = DMA_TCD_DLASTSGA_DLASTSGA(0);
    DMA->TCD[0].CSR =   DMA_TCD_CSR_START(0)
                      | DMA_TCD_CSR_INTMAJOR(0)
                      | DMA_TCD_CSR_INTHALF(0)
                      | DMA_TCD_CSR_DREQ(1)
                      | DMA_TCD_CSR_ESG(0)
                      | DMA_TCD_CSR_MAJORELINK(0)
                      | DMA_TCD_CSR_ACTIVE(0)
                      | DMA_TCD_CSR_DONE(0)
                      | DMA_TCD_CSR_MAJORLINKCH(0)
                      | DMA_TCD_CSR_BWC(0);

    DMA->TCD[0].BITER.ELINKNO =   DMA_TCD_BITER_ELINKNO_BITER(11)
                                | DMA_TCD_BITER_ELINKNO_ELINK(0);
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void DMA_TCD_Transmit(void)
{
    DMA_init();
    DMA_TCD_init();

    DMA->SSRT = 0;

    while(((DMA->TCD[0].CSR >> DMA_TCD_CSR_START_SHIFT) & 1) |
          ((DMA->TCD[0].CSR >> DMA_TCD_CSR_ACTIVE_SHIFT) & 1)){}
    
    while(!((DMA->TCD[0].CSR >> DMA_TCD_CSR_START_SHIFT) & 1))
    {
        DMA->SSRT = 0;
        while(((DMA->TCD[0].CSR >> DMA_TCD_CSR_START_SHIFT) & 1) |
              ((DMA->TCD[0].CSR >> DMA_TCD_CSR_ACTIVE_SHIFT) & 1)){}
    }

    DMA->TCD[0].CSR &= ~(DMA_TCD_CSR_DONE_MASK);
}


