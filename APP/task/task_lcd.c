#include "cmsis_os.h"
#include "lcd.h"
#include "lcd_init.h"
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "tim.h"

#include "lvgl/src/core/lv_obj.h"
#include "port/lv_port_disp.h"
#include "port/lv_port_indev.h"

static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

void lv_example_btn_1(void)
{
    lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);
}

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

   // lvgl
   lv_init();
   printf("lv init ok\r\n");
   lv_port_disp_init();
   printf("lv port disp init ok\r\n");
   //lv_port_indev_init();
    //ui_init();

  lv_example_btn_1();

  for(;;)
  {
    lv_task_handler();
    osDelay(5);
  }
}
