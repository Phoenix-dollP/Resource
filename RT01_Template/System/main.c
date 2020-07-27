#include <stdint.h>
#include <stdio.h>
#include "S32k144.h"
#include "FreeRTOS.h"
#include "task.h"

#define   PTE9  9

/********************************* 任务句柄 ************************************/
/* 
 * 任务句柄是一个指针，用于指向一个任务，当任务创建好之后，它就具有了一个任务句柄
 * 以后我们要想操作这个任务都需要通过这个任务句柄，如果是自身的任务操作自己，那么
 * 这个句柄可以为NULL。
 */
TaskHandle_t AppTaskCreate_Handle = NULL;/* 创建任务句柄 */
TaskHandle_t Task1_Handle = NULL;/* LED任务句柄 */
TaskHandle_t Task2_Handle = NULL;/* KEY任务句柄 */

/******************************** 内核对象句柄 *********************************/
/*
 * 信号量，消息队列，事件标志组，软件定时器这些都属于内核的对象，要想使用这些内核
 * 对象，必须先创建，创建成功之后会返回一个相应的句柄。实际上就是一个指针，后续我
 * 们就可以通过这个句柄操作这些内核对象。
 *
 * 内核对象说白了就是一种全局的数据结构，通过这些数据结构我们可以实现任务间的通信，
 * 任务间的事件同步等各种功能。至于这些功能的实现我们是通过调用这些内核对象的函数
 * 来完成的
 * 
 */


/******************************* 全局变量声明 **********************************/
/*
 * 当我们在写应用程序的时候，可能需要用到一些全局变量。
 */


/*
*************************************************************************
*                             函数声明
*************************************************************************
*/
static void AppTaskCreate(void);    /* 用于创建任务 */

void Bsp_Init(void);
void WDOG_disable(void);

void App_Task1(void* parameter);    /* App_Task1任务实现 */
void App_Task2(void* parameter);    /* App_Task2任务实现 */ 

/*******************************************************************************
  * @brief  钩子函数
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
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

/*******************************************************************************
  * @brief  主函数
  * @param  无
  * @retval 无
  * @note   第一步：开发板硬件初始化 
            第二步：创建APP应用任务
            第三步：启动FreeRTOS，开始多任务调度
  *****************************************************************************/
int main(int argc, char *argv[])
{
    BaseType_t xReturn;

    WDOG_disable();
    Bsp_Init();

    xReturn = xTaskCreate((TaskFunction_t )AppTaskCreate,  
                            (const char*    )"AppTaskCreate",
                            (uint16_t       )512,  
                            (void*          )NULL,
                            (UBaseType_t    )1, 
                            (TaskHandle_t*  )&AppTaskCreate_Handle); 
        
    if (xReturn < 0)
    {
        printf("任务创建失败,Err:%d\r\n", xReturn);
    }

    vTaskStartScheduler();
    
}          

/*******************************************************************************
  * @brief  为了方便管理，所有的任务创建函数都放在这个函数里面
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
void Bsp_Init(void)
{
    WDOG_disable();

    PCC->PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK;
    
    PTE->PDDR |= 1 << PTE9;
    PORTE->PCR[9]  =  0x00000100;
}

/*******************************************************************************
  * @brief  关闭看门狗
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
void WDOG_disable(void)
{
    WDOG->CNT = 0xD928C520;
    WDOG->TOVAL = 0x0000FFFF;
    WDOG->CS = 0x00002100;
}

/*******************************************************************************
  * @brief  任务1
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
void App_Task1(void* parameter)
{     
    while(1)
    {
        PTE->PCOR |= 1 << PTE9;
        printf("hello\r\n");
        
        vTaskDelay(100);

    }
}

/*******************************************************************************
  * @brief  任务2
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
void App_Task2(void* parameter)
{
    while(1)
    {
        PTE->PSOR |= 1 << PTE9;
        printf("hello\r\n");

        vTaskDelay(100);
    }
}

/*******************************************************************************
  * @brief  为了方便管理，所有的任务创建函数都放在这个函数里面
  * @param  无
  * @retval 无
  * @note
  *****************************************************************************/
static void AppTaskCreate(void)
{
    BaseType_t xReturn;

    xReturn = xTaskCreate((TaskFunction_t )App_Task1,  
                        (const char*    )"App_Task1",
                        (uint16_t       )512,  
                        (void*          )NULL,
                        (UBaseType_t    )1, 
                        (TaskHandle_t*  )&Task1_Handle); 
                
    if (xReturn < 0)
    {
        printf("任务创建失败,Err:%d\r\n", xReturn);
    }
    
    xReturn = xTaskCreate((TaskFunction_t )App_Task2,  
                        (const char*    )"App_Task2",
                        (uint16_t       )512,  
                        (void*          )NULL,
                        (UBaseType_t    )5, 
                        (TaskHandle_t*  )&Task2_Handle); 
                
    if (xReturn < 0)
    {
        printf("任务创建失败,Err:%d\r\n", xReturn);
    }

    vTaskDelete(AppTaskCreate_Handle);
}
