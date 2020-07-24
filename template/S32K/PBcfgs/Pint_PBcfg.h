/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Pint_PBcfg.h Port interrupt driver
Author: Steven
******************************************************************************/
#ifndef PINT_PBCFG_H
#define PINT_PBCFG_H

#include "Std_Types.h"

/* Trigger mode type */
typedef enum
{
    PINT_TMODE_LOW = 0, /* Low level trigger */  
    PINT_TMODE_RISING,  /* Rising edge trigger */
    PINT_TMODE_FALLING, /* Falling edge trigger */
    PINT_TMODE_EDGES,   /* Both edges trigger */
    PINT_TMODE_HIGH,    /* High level trigger */
} Pint_TmodeType;

typedef struct
{
    uint8 PinId; /* PinId PORTA:0-31 PORTB:32-63 ... */
    boolean Single;  /* Single trigger */
    Pint_TmodeType Tmode;
    uint8 UChId;  /* Upper layer channel */
    void(*EventCallback)(uint8 UChId);
} Pint_ChCfgType;

typedef struct
{
    const Pint_ChCfgType* ChCfg;
    uint8 ChNum;
} Pint_ConfigType;

#endif

