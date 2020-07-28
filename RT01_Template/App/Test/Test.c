/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Test.c 
Author: Wander
******************************************************************************/
#include "Port.h"
#include "Test.h"
#include "stdio.h"
#include "FreeRTOS.h"
#include "task.h"

/*******************************************************************************
  * @brief  Test_task
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
 void Test_Init(void)
 {
     Port_Init();
 }

/*******************************************************************************
* @brief  Port_Test 模块
* @param  
* @retval 无
* @note
*****************************************************************************/
void Port_Test(void)
{
    (void)Port_FlipPin(PORT_DEBUG_LED);
    
}

/*******************************************************************************
  * @brief  Test_task
  * @param  
  * @retval 
  * @note
  *****************************************************************************/
void Test_task(void *parameter)
{
    while(1)
    {
        Port_Test();
        printf("hello world\r\n");
        
        vTaskDelay(100);
    }
}
