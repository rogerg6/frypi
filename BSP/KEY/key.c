#include "key.h"
#include "delay.h"
#include "cmsis_os2.h"

void Key_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = KEY1_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY1_PORT, &GPIO_InitStruct);

  /* EXTI interrupt init*/
	// HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  // HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

int KeyScan(void)
{
	int key_pressed = 0;
	if(!KEY1)
	{
		//ensure the key is down
		osDelay(3);
		if(!KEY1) key_pressed = 1;
	}
	return key_pressed;
}

