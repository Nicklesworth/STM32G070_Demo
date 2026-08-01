cmake_minimum_required(VERSION 3.16)
project(DemoProject.elf VERSION 1.0 LANGUAGES ASM C CXX)

# ------------------------------------------------------------------------------
# C Standards
# ------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------------------------
# Executable Definition
# ------------------------------------------------------------------------------
add_executable(DemoProject.elf
    src/startup.s
    src/main.c
    src/syscalls.c
    src/sysmem.c
    src/system.c
    src/stm32g0xx_hal_msp.c
    lib/mcu/debug_console/debug_console.c
    lib/mcu/timers/systime.c
    lib/mcu/timers/timer_helpers.c
    lib/sdk/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal.c
    lib/sdk/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_cortex.c
    lib/sdk/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_gpio.c
    lib/sdk/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_rcc.c
    lib/sdk/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_tim.c
    lib/sdk/Drivers/STM32G0xx_HAL_Driver/Src/stm32g0xx_hal_uart.c
)

# ------------------------------------------------------------------------------
# Includes
# ------------------------------------------------------------------------------
target_include_directories(DemoProject.elf PRIVATE
    inc
    lib/common/general
    lib/common/structures
    lib/mcu/general
    lib/mcu/debug_console
    lib/mcu/timers
    lib/sdk/Drivers/CMSIS/Device/ST/STM32G0xx/Include
    lib/sdk/Drivers/CMSIS/Include
    lib/sdk/Drivers/STM32G0xx_HAL_Driver/Inc
)

# ------------------------------------------------------------------------------
# MCU DEFINITION
# ------------------------------------------------------------------------------
set(CPU             -mcpu=cortex-m0plus  )
set(INSTRUCTION_SET -mthumb          )
set(FPU_TYPE        -mfloat-abi=soft )

set(MCU_FLAGS
	${CPU}
	${INSTRUCTION_SET}
	${FPU_TYPE}
)

# -----------------------------------------------------------------------------
# Compiler Definitions
# -----------------------------------------------------------------------------
target_compile_definitions(DemoProject.elf PRIVATE
	NDEBUG
    STM32G070xx
)

# ------------------------------------------------------------------------------
# Compilation Options
# ------------------------------------------------------------------------------
target_compile_options(DemoProject.elf PRIVATE
    -g
	${MCU_FLAGS}
    -O0                     # Default unless overrideen by project.cmake file
    -fdata-sections         # Allow --gc-sections to remove unused data
    -ffunction-sections     # Allow --gc-sections to remove unused function
 	-fno-builtin 			# No assumptions on built in functions
	-fno-exceptions
	-fno-unwind-tables
	-fno-asynchronous-unwind-tables
    -Wall                   # Get all the warnings
	-Wno-unused-variable	# Ignore unused variables
    ${IMB_COMPILER_OPTIONS}
)

# -----------------------------------------------------------------------------
# Linker Options
# --------------------------'---------------------------------------------------
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/linker_script.ld)
target_link_options(DemoProject.elf PRIVATE
    ${MCU_FLAGS}
    --specs=nano.specs
    --specs=nosys.specs
    -Wl,--start-group
    -lstdc++
    -lc
    -lm
    -Wl,--end-group
	-Wl,--no-warn-rwx-segments
    -Wl,--gc-sections
    -Wl,-Map=${BUILD_TARGET}.map        
    -Wl,--print-memory-usage
	-T ${LINKER_SCRIPT}
)
