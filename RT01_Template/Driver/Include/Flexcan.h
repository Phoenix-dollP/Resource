/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#ifndef FLEXCAN_H
#define FLEXCAN_H

extern void FLEXCAN0_init(void);
extern void FLEXCAN0_transmit_msg(void);
extern void FLEXCAN0_receive_msg(void);
extern void FLEXCAN0_Task(void);

#endif
