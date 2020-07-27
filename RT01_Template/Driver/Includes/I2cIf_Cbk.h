/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : I2cIf_Cbk.h I2c Master driver interface
Author: Steven
******************************************************************************/
#ifndef I2CIF_CBK_H
#define I2CIF_CBK_H

#include "Std_Types.h"

#define I2CIF_E_OK         0x00  /* ͨѶOK */
#define I2CIF_E_BUSY       0x01  /* ����æ���� */
#define I2CIF_E_NO_ACK     0x02  /* �ӻ���Ӧ�� */
#define I2CIF_E_ARB_LOST   0x03  /* �ٲô��� */
#define I2CIF_E_BUS_ERROR  0x04  /* ���ߴ��� */
#define I2CIF_E_INT_ERROR  0x05  /* �ڲ����� */

extern void I2cIf_EndCallback(uint8 UChId, uint8 Error);

#endif

