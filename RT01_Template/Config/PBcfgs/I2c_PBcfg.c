/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : I2c_PBcfg.c I2c Master driver For Nxp S32K14x Series LPI2C
Author: Steven 
******************************************************************************/
#include "I2c_PBcfg.h"
#include "I2cIf_Cbk.h"
#include "I2cIf_Define.h"

static const I2c_ChCfgType I2cChCfg[] = 
{
    /* CH0: 光感传感器 */
    {
    I2C0,  /* I2cId */
    I2CIF_CH_SENSOR_, /* UChId */
    0,     /* Reserved */
    0x00000004UL, /* MCFGR1v BitMask:03000607 */
    0x00000000UL, /* MCFGR2v BitMask:0F0F0FFF */
    0x00000100UL, /* MCFGR3v BitMask:000FFF00 */
    0x0F08141AUL, /* MCCR0v  BitMask:3F3F3F3F */
    I2cIf_EndCallback, /* EndCallback */
    }
};

static const I2c_ConfigType I2cConfig = 
{
    I2cChCfg,
    sizeof(I2cChCfg)/sizeof(I2cChCfg[0]),
};

const I2c_ConfigType* const I2cCfgPtr = &I2cConfig;

