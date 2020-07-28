/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Can_PBcfg.cNxp S32K14x FlexCAN Driver(Rx FIFO mode)
Author: Steven
******************************************************************************/
#include "Can_PBcfg.h"
#include "CanIf_Cbk.h"
//#include "jlrx_can.h"

static const Can_IfCfgType CanIfCfg[] =
{
    /* IDMR        IDAR */
    {0x80000000UL, 0x00000000UL},  /* IF0:接收所有帧 */
    {0x00000000UL, 0x00000000UL},  /* IF1:暂未使用 */
    {0x00000000UL, 0x00000000UL},  /* IF2:暂未使用 */
    {0x00000000UL, 0x00000000UL},  /* IF3:暂未使用 */
    {0x00000000UL, 0x00000000UL},  /* IF4:暂未使用 */
    {0x00000000UL, 0x00000000UL},  /* IF5:暂未使用 */
    {0x00000000UL, 0x00000000UL},  /* IF6:暂未使用 */
    {0x00000000UL, 0x00000000UL},  /* IF7:暂未使用 */
};

/* BUS:40MHz PROPSEG:6 PSEG1:4 PSEG2:4 SamplePoint:81.25% */
static const Can_ChCfgType CanChCfg[] = 
{
    /* Hw. CTRL1         RXFGMASK      R. Tm. If. IfCfg */
    {CAN0, 0x09DB3006UL, 0x00000000UL, 0, 8,  8,  CanIfCfg}, /* 500kbps */
};

static const Can_ConfigType CanConfig = 
{
    CanIf_RxCallback, /* RxCallback */
    CanIf_TxCallback, /* TxCallback */
    CanIf_ModeCsCallback, /* ModeCsCbk */
    BusOffCallback,/* BusoffCbk */
    CanChCfg,  /* ChCfg */
    sizeof(CanChCfg)/sizeof(CanChCfg[0]),  /* ChNum */
};

const Can_ConfigType* const CanCfgPtr = &CanConfig;

