/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Mcu_Types.h  For Nxp S32K14x Series
Author: Steven
******************************************************************************/
#ifndef MCU_TYPES_H
#define MCU_TYPES_H

#include "Std_Types.h"

typedef enum
{
    MCU_LPM_MODE0,  /* VLPS */
    MCU_LPM_MODE1,  /* Stop1 */
    MCU_LPM_MODE2,  /* Stop2 */
    MCU_LPM_MODE3,  /* Reserved */
    MCU_LPM_MODE4,  /* Reserved */
} Mcu_LpModeType;

typedef enum
{
    MCU_RESET_SW,   /* software reset */
    MCU_RESET_WDG,  /* watchdog reset */
} Mcu_ResetType;

typedef enum
{
    MCU_CLOCK_FULL,  /* RUN OSC:8M   CORE:80M  BUS:40M */
    MCU_CLOCK_LPM0,  /* RUN SIRC:8M  CORE:4M   BUS:4M  */
    MCU_CLOCK_LPM1,  /* RUN FIRC:48M CORE:48M  BUS:48M */
} Mcu_ClockIdType;

/* Peripheral definition */
typedef enum
{
    MCU_PERI_FTFC = 0x080/4,
    MCU_PERI_DMAMUX = 0x084/4,
    MCU_PERI_FLEXCAN0 = 0x090/4,
    MCU_PERI_FLEXCAN1 = 0x094/4,
    MCU_PERI_FTM3 = 0x098/4,
    MCU_PERI_ADC1 = 0x09C/4,
    MCU_PERI_FLEXCAN2 = 0x0AC/4,
    MCU_PERI_LPSPI0 = 0x0B0/4,
    MCU_PERI_LPSPI1 = 0x0B4/4,
    MCU_PERI_LPSPI2 = 0x0B8/4,
    MCU_PERI_PDB1 = 0x0C4/4,
    MCU_PERI_CRC = 0x0C8/4,
    MCU_PERI_PDB0 = 0x0D8/4,
    MCU_PERI_LPIT = 0x0DC/4,
    MCU_PERI_FTM0 = 0x0E0/4,
    MCU_PERI_FTM1 = 0x0E4/4,
    MCU_PERI_FTM2 = 0x0E8/4,
    MCU_PERI_ADC0 = 0x0EC/4,
    MCU_PERI_RTC = 0x0F4/4,
    MCU_PERI_LPTMR0 = 0x100/4,
    MCU_PERI_PORTA = 0x124/4,
    MCU_PERI_PORTB = 0x128/4,
    MCU_PERI_PORTC = 0x12C/4,
    MCU_PERI_PORTD = 0x130/4,
    MCU_PERI_PORTE = 0x134/4,
    MCU_PERI_SAI0 = 0x150/4,
    MCU_PERI_SAI1 = 0x154/4,
    MCU_PERI_FLEXIO = 0x168/4,
    MCU_PERI_EPWM = 0x184/4,
    MCU_PERI_LPI2C0 = 0x198/4,
    MCU_PERI_LPI2C1 = 0x19C/4,
    MCU_PERI_LPUART0 = 0x1A8/4,
    MCU_PERI_LPUART1 = 0x1AC/4,
    MCU_PERI_LPUART2 = 0x1B0/4,
    MCU_PERI_FTM4 = 0x1B8/4,
    MCU_PERI_FTM5 = 0x1BC/4,
    MCU_PERI_FTM6 = 0x1C0/4,
    MCU_PERI_FTM7 = 0x1C4/4,
    MCU_PERI_CMP0 = 0x1CC/4,
    MCU_PERI_QSPI = 0x1D8/4,
    MCU_PERI_ENET = 0x1E4/4,
} Mcu_PeriNameType;

#endif

