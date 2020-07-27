/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Can_Isr.h Nxp S32K14x FlexCAN Driver(Rx FIFO mode)
Author: Steven
******************************************************************************/
#ifndef CAN_ISR_H
#define CAN_ISR_H

#include "Std_Types.h"

extern void Can_StatusIsr(uint8 Ch);
extern void Can_MsgboxIsr(uint8 Ch);
//extern void Can_ErrorsIsr(uint8 Ch);

#endif

