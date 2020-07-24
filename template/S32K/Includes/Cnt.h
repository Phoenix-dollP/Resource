/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Cnt.h Conunter Service
Author: Steven
******************************************************************************/
#ifndef CNT_H
#define CNT_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

#define CNT_MAJOR_VERSION       (0x00)
#define CNT_MINOR_VERSION       (0x01)
#define CNT_PATCH_VERSION       (0x00)

#define CNT_ID_SYSTICK          0  /* ϵͳʱ��(��ʱ�жϼ���) */
#define CNT_ID_TIMSYNC          1  /* ͬ��ʱ��(����ѭ������) */
#define CNT_ID_UNDEF_0          2  /* �û����� */
#define CNT_ID_UNDEF_2          3  /* �û����� */

extern void Cnt_IncCounter(uint8 CntId);
extern void Cnt_GetCounter(uint8 CntId, uint16* CntValue);
extern uint16 Cnt_GetElapsed(uint8 CntId, uint16* PreValue);

#ifdef __cplusplus
}
#endif
#endif

