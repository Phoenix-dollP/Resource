/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Tbm_PBcfg.h Timebase Moudle Driver(Nxp S32K14x Series SYSTICK Timer)
Author: Steven
******************************************************************************/
#ifndef TBM_PBCFG_H
#define TBM_PBCFG_H

#include "Std_Types.h"

typedef struct
{
    void(*TickCallback)(void);
    uint32 CSRv;
} Tbm_TimeCfgType;

typedef struct
{
    const Tbm_TimeCfgType* TimeCfg;
    uint8 TimeNum;
} Tbm_ConfigType;

#endif

