/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Pwm_PBcfg.h For Nxp S32K14x FTM
Author: Steven
******************************************************************************/
#ifndef PWM_PBCFG_H
#define PWM_PBCFG_H

#include "Std_Types.h"

#define PWM_FTM0        (0x40038000UL)
#define PWM_FTM1        (0x40039000UL)
#define PWM_FTM2        (0x4003A000UL)
#define PWM_FTM3        (0x40026000UL)
#define PWM_FTM4        (0x4006E000UL)
#define PWM_FTM5        (0x4006F000UL)
#define PWM_FTM6        (0x40070000UL)
#define PWM_FTM7        (0x40071000UL)

typedef struct
{
    uint32 FtmHw;
    uint8  FtmCh;  /* ValidValue:0-7 */
    uint8  FTMSC;  /* ValidBits:0x1F CLKS&PS */
    uint8  CHELS;  /* Edge selection 0:High-true(normal) 1:Low-true(reversal) */
    uint16 FTMMOD;
    uint16 FTMCHV;
} Pwm_ChCfgType;

typedef struct
{
    const Pwm_ChCfgType* ChCfg;
    uint8 ChNum;
} Pwm_ConfigType;

#endif

