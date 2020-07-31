/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#ifndef ADC_H
#define ADC_H

extern void ADC_init(void);
extern void coverAdcChan(uint16_t adcChan);
extern void adc_complete(void);
extern uint32_t read_adc_chx(void);

#endif

