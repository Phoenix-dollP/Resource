/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : I2c_PBcfg.h I2c Master driver For Nxp S32K14x Series LPI2C
Author: Steven 
******************************************************************************/
#ifndef I2C_PBCFG_H
#define I2C_PBCFG_H

#include "I2c_Types.h"

#define I2C0                (0)
#define I2C1                (1)

typedef struct
{
    uint8 I2cId;
    uint8 UChId;
    uint16 Reserved;
    uint32 MCFGR1v;  /* BitMask:03000607 */
    uint32 MCFGR2v;  /* BitMask:0F0F0FFF */
    uint32 MCFGR3v;  /* BitMask:000FFF00 */
    uint32 MCCR0v;   /* BitMask:3F3F3F3F */
    void(*EndCallback)(uint8 UChId, uint8 Error);
} I2c_ChCfgType;

typedef struct
{
    const I2c_ChCfgType* ChCfg;
    uint8 ChNum;
} I2c_ConfigType;

#endif

