
#include "FreeRTOS.h"
#include "task.h"

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

int main()
{
    return 0;
}
