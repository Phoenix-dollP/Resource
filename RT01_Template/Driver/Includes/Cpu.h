/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Cpu.h For Cortex M4
Author: Steven
******************************************************************************/
#ifndef CPU_H
#define CPU_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

#define CPU_MAJOR_VERSION       (0x00)
#define CPU_MINOR_VERSION       (0x01)
#define CPU_PATCH_VERSION       (0x00)

#define Cpu_EnableInterrupt()   __enable_irq()
#define Cpu_DisableInterrupt()  __disable_irq()

extern void Cpu_ResumeInterrupt(void);
extern void Cpu_SuspendInterrupt(void);

extern void Cpu_Delay1US(void);
extern void Cpu_DelayUS(uint16 USTime);
extern void Cpu_DelayMS(uint16 MSTime);

#ifdef __cplusplus
}
#endif
#endif

