/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Pwm_PBcfg.c For Nxp S32K14x FTM
Author: Steven
******************************************************************************/
#include "Pwm_PBcfg.h"

/* SPLL_DIV2:80MHz PS:/1 */
static const Pwm_ChCfgType PwmChCfg[] = 
{
    /* FtmHw   Ch FTMSC ELS MOD    CHV */
    {PWM_FTM1, 0, 0x08, 0,  4196, 0},  /* 20kHz=80MHz/4000 */
};

static const Pwm_ConfigType PwmConfig = 
{
    PwmChCfg,
    sizeof(PwmChCfg)/sizeof(PwmChCfg[0]),
};

const Pwm_ConfigType* const PwmCfgPtr = &PwmConfig;

