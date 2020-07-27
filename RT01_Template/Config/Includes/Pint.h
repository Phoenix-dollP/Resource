/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Pint.h Port Interrupt driver
Author: Steven
******************************************************************************/
#ifndef PINT_H
#define PINT_H

#include "Std_Types.h"
#include "Pint_Define.h"

extern void Pint_Init(void);
extern void Pint_Enable(uint8 Ch);
extern void Pint_Disable(uint8 Ch);

#endif
