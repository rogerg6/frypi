#include "cmsis_os.h"
#include "lcd.h"
#include "lcd_init.h"
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "tim.h"

#include "lvgl/src/core/lv_obj.h"
#include "port/lv_port_disp.h"
#include "port/lv_port_indev.h"

#include "ui.h"

void LCD_task_init(void *argument)
{
    // 开启lcd的亮度pwm
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);

    LCD_Init();
   LCD_Fill(0,0, LCD_W, LCD_H, BLACK);
   osDelay(10);
   LCD_Set_Light(50);
   LCD_ShowString(72,LCD_H/2,(uint8_t*)"Welcome!", WHITE, BLACK, 24, 0);//12*6,16*8,24*12,32*16
   uint8_t lcd_buf_str[17];
   sprintf((char*)lcd_buf_str, "OV-Watch V%d.%d.%d", 0, 0, 2);
   LCD_ShowString(34, LCD_H/2+48, (uint8_t*)lcd_buf_str, WHITE, BLACK, 24, 0);
   osDelay(1000);
   //LCD_Fill(0, LCD_H/2-24, LCD_W, LCD_H/2+49, BLACK);

   // lvgl
   lv_init();
   printf("lv init ok\r\n");
   lv_port_disp_init();
   printf("lv port disp init ok\r\n");
   lv_port_indev_init();
   printf("lv port indev init ok\r\n");
   // ??? 调度卡死
   ui_init();
   printf("lv ui init ok\r\n");

  for(;;)
  {
    lv_task_handler();
    osDelay(5);
  }
}
