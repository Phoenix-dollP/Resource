/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Mcu_PBcfg.c  For Nxp S32K14x Series
Author: Steven
******************************************************************************/
#include "Mcu_PBcfg.h"

static const Mcu_PeriCfgType McuPeriCfg[] = 
{
    /* Peripheral       ClockCfg      PowerCfg */
    {MCU_PERI_PORTA,    0xC0000000UL, 0x00000000UL},
    {MCU_PERI_PORTB,    0xC0000000UL, 0x00000000UL},
    {MCU_PERI_PORTC,    0xC0000000UL, 0x00000000UL},
    {MCU_PERI_PORTD,    0xC0000000UL, 0x00000000UL},
    {MCU_PERI_PORTE,    0xC0000000UL, 0x00000000UL},
    {MCU_PERI_FLEXCAN0, 0xC0000000UL, 0x00000000UL}, /* BUS_CLK:40MHz */
    {MCU_PERI_FTM1,     0xC6000000UL, 0x00000000UL}, /* SPLLDIV1_CLK:80MHz */
    {MCU_PERI_ADC0,     0xC6000000UL, 0x00000000UL}, /* SPLLDIV2_CLK:80MHz */
    {MCU_PERI_LPI2C0,   0xC6000000UL, 0x00000000UL}, /* SPLLDIV2_CLK:80MHz */
    {MCU_PERI_LPUART1,  0xC6000000UL, 0x00000000UL}, /* SPLLDIV2_CLK:80MHz */
    {MCU_PERI_LPUART2,  0xC6000000UL, 0x00000000UL}, /* SPLLDIV2_CLK:80MHz */
    {MCU_PERI_LPSPI1,   0xC6000000UL, 0x00000000UL}, /* SPLLDIV2_CLK:80MHz */
    {MCU_PERI_LPSPI2,   0xC6000000UL, 0x00000000UL}, /* SPLLDIV2_CLK:80MHz */
};

static const Mcu_ConfigType McuConfig = 
{
    McuPeriCfg,
    sizeof(McuPeriCfg)/sizeof(McuPeriCfg[0]),
    MCU_CLOCK_FULL,
};

const Mcu_ConfigType* const McuCfgPtr = &McuConfig;

