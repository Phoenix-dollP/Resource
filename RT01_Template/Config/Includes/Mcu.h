/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Mcu.h  For Nxp S32K14x Series
Author: Steven
******************************************************************************/
#ifndef MCU_H
#define MCU_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Mcu_Types.h"

#define MCU_MAJOR_VERSION       (0x00)
#define MCU_MINOR_VERSION       (0x01)
#define MCU_PATCH_VERSION       (0x00)

#define McuWatchdog     (*(volatile uint32*)0x40052004UL)
#define Mcu_FeedWdg()   (void)(McuWatchdog=0xB480A602UL)

extern void Mcu_Init(void);
extern void Mcu_EnterLpMode(Mcu_LpModeType LpMode);
extern void Mcu_SetCoreClock(Mcu_ClockIdType ClockId);
extern void Mcu_PerformReset(Mcu_ResetType ResetType);
extern void Mcu_SetPeriClock(Mcu_PeriNameType PeriName, uint32 Param);

#ifdef __cplusplus
}
#endif
#endif

