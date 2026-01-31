#include "cmsis_os.h"
#include "lcd.h"
#include "lcd_init.h"
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "tim.h"




void LCD_task_init(void *argument)
{
    // 开启lcd的亮度pwm
    HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);

    LCD_Init();
   LCD_Fill(0,0, LCD_W, LCD_H, BLACK);
   HAL_Delay(10);
   LCD_Set_Light(50);
   LCD_ShowString(72,LCD_H/2,(uint8_t*)"Welcome!", WHITE, BLACK, 24, 0);//12*6,16*8,24*12,32*16
   uint8_t lcd_buf_str[17];
   sprintf((char*)lcd_buf_str, "OV-Watch V%d.%d.%d", 0, 0, 1);
   LCD_ShowString(34, LCD_H/2+48, (uint8_t*)lcd_buf_str, WHITE, BLACK, 24, 0);
   HAL_Delay(1000);
   //LCD_Fill(0, LCD_H/2-24, LCD_W, LCD_H/2+49, BLACK);

  for(;;)
  {
    osDelay(1);
  }
}
