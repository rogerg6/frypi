#ifndef __KEY_H__
#define __KEY_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

//KEY1
#define KEY1_PORT	GPIOA
#define KEY1_PIN	GPIO_PIN_0
#define KEY1 HAL_GPIO_ReadPin(KEY1_PORT,KEY1_PIN)

void Key_GPIO_Init(void);
void Key_Interrupt_Callback(void);
int KeyScan(void);




#ifdef __cplusplus
}
#endif
#endif

