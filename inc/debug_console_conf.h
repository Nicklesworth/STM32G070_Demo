/*
 * This file is licensed under the terms described in the LICENSE
 * file located in the root directory of this source tree.
 */

#ifndef DEBUG_CONSOLE_CONF_H_
#define DEBUG_CONSOLE_CONF_H_

#define DEBUG_CONSOLE_UART		USART1				// Needs to be a USART_TypeDef
#define DEBUG_CONSOLE_TX_PORT	GPIOA				// Needs to be a GPIO_TypeDef
#define DEBUG_CONSOLE_TX_PIN	GPIO_PIN_0			// Needs to be GPIO_PIN_x (which is a mask)
#define DEBUG_CONSOLE_TX_AF		GPIO_AF0_USART1		// Needs to be GPIOEx_Alternate_function_selection

#endif // DEBUG_CONSOLE_CONF_H_
