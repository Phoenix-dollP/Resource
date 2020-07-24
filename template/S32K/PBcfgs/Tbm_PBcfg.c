/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Tbm_PBcfg.c Timebase Moudle Driver(Nxp S32K14x Series SYSTICK Timer)
Author: Steven
******************************************************************************/
#include "Tbm_PBcfg.h"
#include "Sbs_Cbk.h"

static const Tbm_TimeCfgType TbmTimeCfg[] = 
{
    /* TickCallback   CSRv */
    {Sbs_TbmCallback, 79999UL},  /* 80MHz/8000 1ms周期 */
};

static const Tbm_ConfigType TbmConfig = 
{
    TbmTimeCfg,
    sizeof(TbmTimeCfg)/sizeof(Tbm_TimeCfgType),
};

const Tbm_ConfigType* const TbmCfgPtr = &TbmConfig;

