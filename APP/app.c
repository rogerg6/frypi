#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "app.h"


osThreadId_t LCDTaskHandle;
const osThreadAttr_t LCDTask_attributes = {
  .name = "LCDTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};


void app_tasks_init(void) {
    LCDTaskHandle = osThreadNew(LCD_task_init, NULL, &LCDTask_attributes);
}