/*
 * This file is licensed under the terms described in the LICENSE
 * file located in the root directory of this source tree.
 */

#include "main.h"
#include "local_types.h"
#include "stm32g0xx_hal.h"

static void Clock_Init(void); 

int main(void)
 {
	HAL_Init();
	Clock_Init();
	while(1);
 }

static void Clock_Init(void)
{
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};

    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_PWR_CLK_ENABLE();

    RCC_OscInitStruct.OscillatorType  = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState        = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState    = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource   = RCC_PLLSOURCE_HSE;   // 8MHz Crystal/Oscillator
    RCC_OscInitStruct.PLL.PLLM        = RCC_PLLM_DIV1;       // 8MHz VCO Input
    RCC_OscInitStruct.PLL.PLLN        = 40;                  // 8MHz HSI * 40 / 5 = 64MHz (VCO must be beetween 64MHz and 344MHz)
    RCC_OscInitStruct.PLL.PLLP        = RCC_PLLP_DIV5;       // Adjust if using special I2S or ADC setup
    RCC_OscInitStruct.PLL.PLLR        = RCC_PLLR_DIV5;       // 8MHz HSI * 40 / 5 = 64MHz
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitStruct.ClockType       = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1);
    RCC_ClkInitStruct.SYSCLKSource    = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider   = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider  = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

    RCC_OscInitStruct.OscillatorType  = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState        = RCC_HSI_OFF;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    SystemCoreClockUpdate();
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