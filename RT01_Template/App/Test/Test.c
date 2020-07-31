/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Test.c 
Author: Wander
******************************************************************************/
#include <stdio.h>
#include "Port.h"
#include "Test.h"
#include "FreeRTOS.h"
#include "task.h"
#include "Mcu.h"
#include "lpit.h"
#include "Dma.h"
#include "adc.h"
#include "Lpuart.h"
#include "Dbgif.h"


/*******************************************************************************
* @brief  Port_Test 模块
* @param  
* @retval 无
* @note
*****************************************************************************/
void Test_Init(void)
{
    Clock_init();
    Port_Init ();
    LPIT0_init();
    //DMA_TCD_Transmit();
    //ADC_init();
    Lpuart2_init();
    Lpuart2_transmit_string(">>");
    Lpuart2_transmit_string("hello world\r\n");
    Dbgif_printf("Test init success\r\n") ;
    
}

     uint32_t result;
/*******************************************************************************
  * @brief  Test_task
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
 void ADC_Test(void)
 {


     //coverAdcChan(15);
     //while(adc_complete() == 0){}
     //result = read_adc_chx();
//    Lpuart2_transmit_string(">>");
//    Lpuart2_transmit_string("hello world\r\n");

 }

/*******************************************************************************
  * @brief  Test_task
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
 void Lpit_Test(void)
 {
     static uint32 test;
     test++;

 }


/*******************************************************************************
  * @brief  Test_task
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
 void Lpuart_Test(void)
 {
//     Lpuart2_transmit_char('>');
//     Lpuart2_receive_and_echo_char();
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
        //Port_Test();
        ADC_Test();
        //printf("hello world\r\n");
        LPIT0_Test();
        Lpuart_Test();
        
        vTaskDelay(100);
    }
}
