/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Mcu_PBcfg.h  For Nxp S32K14x Series
Author: Steven
******************************************************************************/
#ifndef MCU_PBCFG_H
#define MCU_PBCFG_H

#include "Mcu_Types.h"

typedef struct
{
    Mcu_PeriNameType PeriName;
    uint32 ClockCfg;  /* PCC register value */
    uint32 PowerCfg;  /* Reserved */
} Mcu_PeriCfgType;

typedef struct
{
    const Mcu_PeriCfgType* PeriCfg;
    uint16 PeriNum;
    Mcu_ClockIdType ClockId;
} Mcu_ConfigType;

#endif

