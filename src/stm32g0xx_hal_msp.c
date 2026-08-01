/*
 * This file is licensed under the terms described in the LICENSE
 * file located in the root directory of this source tree.
 */

#include "debug_console.h"

#define DEBUG_CONSOLE_TX_PORT	GPIOA				// Needs to be a GPIO_TypeDef
#define DEBUG_CONSOLE_TX_PIN	GPIO_PIN_0			// Needs to be GPIO_PIN_x (which is a mask)
#define DEBUG_CONSOLE_TX_AF		GPIO_AF0_USART1		// Needs to be GPIOEx_Alternate_function_selection

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	if(huart == &hDebugUART)
	{
		GPIO_InitTypeDef gpio_init;
		gpio_init.Pin               = DEBUG_CONSOLE_TX_PIN;
		gpio_init.Mode              = GPIO_MODE_AF_PP;
		gpio_init.Pull              = GPIO_NOPULL;
		gpio_init.Speed             = GPIO_SPEED_FREQ_VERY_HIGH;
		gpio_init.Alternate	        = DEBUG_CONSOLE_TX_AF;
		HAL_GPIO_Init(DEBUG_CONSOLE_TX_PORT, &gpio_init);
	}
}	