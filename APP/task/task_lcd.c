#include "cmsis_os.h"
#include "lcd.h"
#include "lcd_init.h"
#include "stm32f4xx_hal.h"
#include "stdio.h"

#include "lvgl/src/core/lv_obj.h"
#include "port/lv_port_disp.h"
#include "port/lv_port_indev.h"

#include "ui.h"

void LCD_task_init(void *argument)
{
   // lvgl
   lv_init();
   lv_port_disp_init();
   lv_port_indev_init();
   ui_init();

  for(;;)
  {
    lv_task_handler();
    osDelay(5);
  }
}
