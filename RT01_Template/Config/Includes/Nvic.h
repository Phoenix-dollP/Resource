/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Nvic.h  Nxp S32K14x NVIC driver
Author: Steven
******************************************************************************/
#ifndef NVIC_H
#define NVIC_H

#include "Std_Types.h"
#include "Nvic_Define.h"

extern void Nvic_Init(void);
extern void Nvic_SetPending(uint16 IrqId, boolean Pending);
extern void Nvic_SetEnabled(uint16 IrqId, boolean Enabled, uint8 Priority);

#endif

