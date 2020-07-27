/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port_PBcfg.h For Nxp S32K14x Series
Author: Steven
******************************************************************************/
#ifndef PORT_PBCFG_H
#define PORT_PBCFG_H

#include "Std_Types.h"
#include "Port_Define.h"

typedef struct 
{
    uint8 PortId;
    uint32 DDR;
    uint32 DOR;
    uint32 IDR;
} Port_GpioCfgType;

/* Pin PCR configuration */
typedef struct
{
    uint8 PortId;
    uint8 PinNum;
    uint32 PCRv;
} Port_PpcrCfgType;

typedef struct 
{
    const Port_GpioCfgType* GpioCfg;
    const Port_PpcrCfgType* PpcrCfg;
    uint8 GpioNum;
    uint8 PpcrNum;
} Port_ConfigType;

#endif

