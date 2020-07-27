/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Nvic_PBcfg.h  Nxp S32K14x NVIC driver
Author: Steven
******************************************************************************/
#ifndef NVIC_PBCFG_H
#define NVIC_PBCFG_H

#include "Std_Types.h"

typedef struct
{
    uint16 IrqId;
    boolean Enabled;
    uint8 Priority;  /* Valid:0x10-0xF0(Bit[3:0] fixed to 0) */
} Nvic_IrqCfgType;

typedef struct
{
	  uint32 VTOR;  /* Vector table offset register value */
    const Nvic_IrqCfgType* IrqCfg;
    uint16 IrqNum;
} Nvic_ConfigType;

#endif

