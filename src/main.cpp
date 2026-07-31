/*
 * This file is licensed under the terms described in the LICENSE
 * file located in the root directory of this source tree.
 */

#include "main.h"
#include "local_types.h"
#include "stm32g0xx_hal.h"

 int main(void)
 {
	HAL_Init();
	while(1);
 }

 void Error_Handler(void)
 {
	 while (1)
	 {
	 }
 }

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
	while (1)
	{
	}
}
#endif /* USE_FULL_ASSERT */