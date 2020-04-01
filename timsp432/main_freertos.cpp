/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <ti/drivers/Board.h>

#include "app/app.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vApplicationMallocFailedHook();
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName);
extern void ti_ndk_config_Global_startupFxn();

#ifdef __cplusplus
}
#endif


int main(void)
{
    Board_init();

    App::initialize();

    ti_ndk_config_Global_startupFxn();

    /* Start the FreeRTOS scheduler */
    vTaskStartScheduler();

    return (0);
}


void vApplicationMallocFailedHook()
{
    /* Handle Memory Allocation Errors */
    while(1)
    {
    }
}


void vApplicationStackOverflowHook(TaskHandle_t pxTask, char *pcTaskName)
{
    //Handle FreeRTOS Stack Overflow
    while(1)
    {
    }
}
