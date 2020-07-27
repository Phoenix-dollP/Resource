/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Can_PBcfg.hNxp S32K14x FlexCAN Driver(Rx FIFO mode)
Author: Steven
******************************************************************************/
#ifndef CAN_PBCFG_H
#define CAN_PBCFG_H

#include "Can_Types.h"

#define CAN0    (0x40024000)
#define CAN1    (0x40025000)
#define CAN2    (0x4002B000)

/* ID Filter config type, must 8n(8,16,...) members */
typedef struct
{
    uint32 IDMR;
    uint32 IDAR;
} Can_IfCfgType;

/* Can controller config type */
typedef struct
{
    uint32 CanHw;
    uint32 CTRL1;   /* ValidBits:FFFF20C7 */
    uint32 RXFGMASK;
    uint16 Reserved;  /* For words(4bytes) alignment */
    uint8 TmNum;  /* Tx message box number(HTH number) */
    uint8 IfNum;  /* Must be 8n(8,16,24...104) */
    const Can_IfCfgType* IfCfg;
} Can_ChCfgType;

/* Note: don't set CallCbk to NULL */
typedef struct 
{
    void(*RxCallback)(uint8 Hrh, uint32 Id, uint8 Dlc, const uint8* Data);
    void(*TxCallback)(uint16 TxPduId);
    void(*ModeCsCbk)(uint8 CanCh, Can_CsModeType Mode);
    void(*BusoffCbk)(uint8 Ch);
    const Can_ChCfgType* ChCfg;
    uint8 ChNum;
} Can_ConfigType;

#endif
  
