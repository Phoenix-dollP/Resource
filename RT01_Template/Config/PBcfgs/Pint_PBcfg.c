/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Pint_PBcfg.c Port interrupt driver
Author: Steven
******************************************************************************/
#include "Pint_PBcfg.h"
//#include "Sbs_Cbk.h"

#define PA(n)   (32*0+n)
#define PB(n)   (32*1+n)
#define PC(n)   (32*2+n)
#define PD(n)   (32*3+n)
#define PE(n)   (32*4+n)
#define PF(n)   (32*5+n)
#define PG(n)   (32*6+n)
#define PH(n)   (32*7+n)

static const Pint_ChCfgType PintChCfg[] = 
{
    /* ACC */
    {
        PE(8),  /* PinId */
        FALSE,  /* Single */
        PINT_TMODE_FALLING, /* Tmode */
        SBS_WKU_ACC, /* UChId */
        Sbs_WkuCallback, /* EventCallback */
    },

//    /* CAN */
//    {
//        PC(2),  /* PinId */
//        FALSE,  /* Single */
//        PINT_TMODE_FALLING, /* Tmode */
//        SBS_WKU_CAN, /* UChId */
//        Sbs_WkuCallback, /* EventCallback */
//    },
};

static const Pint_ConfigType PintConfig = 
{
    PintChCfg,
    sizeof(PintChCfg)/sizeof(PintChCfg[0]),
};

const Pint_ConfigType* const PintCfgPtr = &PintConfig;

