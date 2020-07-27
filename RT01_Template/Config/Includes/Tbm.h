/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Tbm.h Timebase Moudle Driver(Nxp S32K14x Series SYSTICK Timer)
Author: Steven
******************************************************************************/
#ifndef TBM_H
#define TBM_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

#define TBM_MAJOR_VERSION       (0x00)
#define TBM_MINOR_VERSION       (0x01)
#define TBM_PATCH_VERSION       (0x00)

extern void Tbm_Init(void);
extern void Tbm_PollFunction(void);

extern void Tbm_Stop(void);
extern void Tbm_Start(uint8 TimeId);

#ifdef __cplusplus
}
#endif
#endif


