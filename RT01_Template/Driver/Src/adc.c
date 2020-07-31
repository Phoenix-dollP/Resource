/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#include "S32K144.h"    /* include peripheral declarations S32K144 */

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void ADC_init(void)
{
    PCC->PCCn[PCC_ADC0_INDEX] &= ~PCC_PCCn_CGC_MASK;
    PCC->PCCn[PCC_ADC0_INDEX] |= PCC_PCCn_PCS(1);
    PCC->PCCn[PCC_ADC0_INDEX] |= PCC_PCCn_CGC_MASK;

    ADC0->SC1[0] = 0x00001F;

    ADC0->CFG1 = 0x00000004;

    ADC0->CFG2 = 0x0000000c;
    ADC0->SC2 = 0x00000000;

    ADC0->SC3 = 0x00000000;
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
void coverAdcChan(uint16_t adcChan)
{
    ADC0->SC1[0] &= ~ADC_SC1_ADCH_MASK;
    ADC0->SC1[0] = ADC_SC1_ADCH(adcChan);
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
uint8_t adc_complete(void)
{
    return ((ADC0->SC1[0] & ADC_SC1_COCO_MASK) >> ADC_SC1_COCO_SHIFT);
}

/**
  * @brief  DMA_init
  * @param  
  * @param  
  * @retval 
  */
uint32_t read_adc_chx(void)
{
    uint16_t adc_result = 0;
    adc_result = ADC0->R[0];
    return (uint32_t)((5000*adc_result) / 0xffff);
}
