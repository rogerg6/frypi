#include "FreeRTOS.h"
#include "cmsis_os2.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "app.h"
#include "lvgl/src/lv_api_map.h"

#include <stdio.h>

osThreadId_t LCDTaskHandle;
const osThreadAttr_t LCDTask_attributes = {
  .name = "LCDTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

osThreadId_t lvgl_TaskHandle;
const osThreadAttr_t LVGL_hanlder_Task_attributes = {
  .name = "LCDTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

void LVGL_hanlder_task_init(void *params) {
    while (1) {
        lv_task_handler();
        osDelay(5);
        // printf("++++++\n");
    }
}


void app_tasks_init(void) {
    LCDTaskHandle = osThreadNew(LCD_task_init, NULL, &LCDTask_attributes);
    // lvgl_TaskHandle = osThreadNew(LVGL_hanlder_task_init, NULL, &LVGL_hanlder_Task_attributes);
}