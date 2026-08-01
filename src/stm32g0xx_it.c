// -----------------------------------------------------------------------------
// This file is licensed under the terms described in the LICENSE
// file located in the root directory of this source tree.
// -----------------------------------------------------------------------------
#include "stm32g0xx_hal.h"
#include "systime.h"

void TIM6_IRQHandler(void)
{
	SysTime_IRQ();
}
