#include <stdint.h>
#include <stdio.h>
#include "S32k144.h"
#include "FreeRTOS.h"
#include "task.h"

#define   PTE9  9

/******************************************************************************
函数名称: void CanIn_ClrFrameData(CanIn_ID RxPduId, Byte_t Byte, Bits_t Bit)
函数说明: 钩子函数
最后修改: Wander
******************************************************************************/
void vApplicationStackOverflowHook  (TaskHandle_t xTask, char *pcTaskname)
{

}

void vApplicationIdleHook (void)
{

}

void vApplicationTickHook  (void)
{

}

void vApplicationMallocFailedHook  (void)
{

}

void delay(uint32_t Cnt)
{
    while(Cnt > 0)
    {
        Cnt--;
    }
}

void WDOG_disable(void)
{
    WDOG->CNT = 0xD928C520;
    WDOG->TOVAL = 0x0000FFFF;
    WDOG->CS = 0x00002100;
}

void AppTask1(void)
{
    while(1)
    {
        PTE->PCOR |= 1 << PTE9;
        printf("hello\r\n");
        
        vTaskDelay(100);
    }
}

void AppTask2(void)
{
    while(1)
    {
        PTE->PSOR |= 1 << PTE9;
        printf("hello\r\n");
        
        vTaskDelay(100);
    }
}


TaskHandle_t     AppTask1_Handle; 
TaskHandle_t     AppTask2_Handle;                      

BaseType_t xReturn;

/******************************************************************************
函数名称: void CanIn_ClrFrameData(CanIn_ID RxPduId, Byte_t Byte, Bits_t Bit)
函数说明: App Entry Function
最后修改: Wander
******************************************************************************/
int main(int argc, char *argv)
{
    WDOG_disable();
    
    PCC->PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK;
    
    PTE->PDDR |= 1 << PTE9;
    PORTE->PCR[9]  =  0x00000100;
    
    xReturn = xTaskCreate((TaskFunction_t )AppTask1,  
                        (const char*    )"AppTask1",
                        (uint16_t       )512,  
                        (void*          )NULL,
                        (UBaseType_t    )1, 
                        (TaskHandle_t*  )&AppTask1_Handle); 
                
    if (xReturn < 0)
    {
        printf("任务创建失败,Err:%d\r\n", xReturn);
    }
    
    xReturn = xTaskCreate((TaskFunction_t )AppTask2,  
                        (const char*    )"AppTask2",
                        (uint16_t       )512,  
                        (void*          )NULL,
                        (UBaseType_t    )5, 
                        (TaskHandle_t*  )&AppTask2_Handle); 
                
    if (xReturn < 0)
    {
        printf("任务创建失败,Err:%d\r\n", xReturn);
    }
     
    vTaskStartScheduler();
    
}            
