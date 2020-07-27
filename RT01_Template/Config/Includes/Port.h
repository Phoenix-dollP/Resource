/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#ifndef PORT_H
#define PORT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Port_Define.h"

#define PORT_MAJOR_VERSION      (0x00)
#define PORT_MINOR_VERSION      (0x01)
#define PORT_PATCH_VERSION      (0x00)

extern void Port_Init(void);

extern uint32 Port_Read(uint8 PortId);
extern void Port_Write(uint8 PortId, uint32 Levels);

extern Std_StatusType Port_ReadPin(uint8 PinId);
extern void Port_WritePin(uint8 PinId, Std_StatusType Level);
extern Std_StatusType Port_FlipPin(uint8 PinId);

extern void Port_SetPinIO(uint8 PinId, Std_StatusType Status);
extern Std_StatusType Port_GetPinIO(uint8 PinId);

extern void Port_SetPinFun(uint8 PinId, uint8 Fun);

#ifdef __cplusplus
}
#endif
#endif

