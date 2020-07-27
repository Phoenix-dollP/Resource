/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Can.h  Nxp S32K14x FlexCAN Driver(Rx FIFO mode)
Author: Steven
******************************************************************************/
#ifndef CAN_H
#define CAN_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Can_Types.h"
#include "Can_Define.h"

#define CAN_MAJOR_VERSION       (0x00)
#define CAN_MINOR_VERSION       (0x01)
#define CAN_PATCH_VERSION       (0x00)

#define CAN_MAX_CAN_NUM     	2
#define CAN_MAX_HTH_NUM     	32
#define CAN_MAX_HRH_NUM     	32

extern void Can_Init(void);
extern void Can_Start(void);
extern void Can_Stop(void);
extern void Can_PollFunction(void);
extern Std_ReturnType Can_Write(uint8 Hth, const Can_PduType* PduInfo);
extern Std_ReturnType Can_SetMode(uint8 Ch, Can_CsModeType CsMode);
extern uint8 Can_GetCanChNum(void);
extern uint8 Can_GetHthCanCh(uint8 Hth);
extern uint8 Can_GetHrhCanCh(uint8 Hrh);

#ifdef __cplusplus
}
#endif
#endif
