/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Nvic_PBcfg.c  Nxp S32K14x NVIC driver
Author: Steven
******************************************************************************/
#include "Nvic_PBcfg.h"
#include "Nvic_Define.h"

static const Nvic_IrqCfgType NvicIrqCfg[] = 
{
    /* IrqId                Enabled Priority */
    {NVIC_IRQ_CAN0_ORED,    TRUE,   0xF0},
    {NVIC_IRQ_CAN0_MB00_15, TRUE,   0xF0},
    {NVIC_IRQ_ADC0,         TRUE,   0xF0},
    {NVIC_IRQ_LPUART1,      TRUE,   0xF0},
    {NVIC_IRQ_LPUART2,      TRUE,   0xF0},
    {NVIC_IRQ_LPSPI1,       TRUE,   0xF0},
    {NVIC_IRQ_LPSPI2,       TRUE,   0xF0},
    {NVIC_IRQ_PORTE,        TRUE,   0xF0},
    {NVIC_IRQ_PORTC,        TRUE,   0xF0},
};

static const Nvic_ConfigType NvicConfig = 
{
	0x00008000,
    NvicIrqCfg,
    sizeof(NvicIrqCfg)/sizeof(NvicIrqCfg[0]),
};

const Nvic_ConfigType* const NvicCfgPtr = &NvicConfig;

