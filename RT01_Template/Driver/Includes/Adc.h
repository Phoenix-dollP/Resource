/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Adc.h ADC driver For Nxp S32K14x
Author: Steven
******************************************************************************/
#ifndef ADC_H
#define ADC_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Adc_Define.h"

#define ADC_MAJOR_VERSION       (0x00)
#define ADC_MINOR_VERSION       (0x01)
#define ADC_PATCH_VERSION       (0x00)

#define ADC_MAX_GROUP_NUM       (8)

typedef enum
{
    ADC_IDLE,
    ADC_BUSY,
    ADC_COMPLETED,
} Adc_StatusType;

extern void Adc_Init(void);
extern void Adc_DeInit(void);

extern void Adc_StopGroup(uint8 GroupId);
extern void Adc_StartGroup(uint8 GroupId, uint16* Buffer);
extern Adc_StatusType Adc_GetStatus(uint8 GroupId);

#ifdef __cplusplus
}
#endif
#endif

