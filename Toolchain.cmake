# ============================================================
#  ARM GCC (arm-none-eabi) bare-metal toolchain file
# ============================================================

# Tell CMake this is a cross-compile for a non-host system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# ------------------------------------------------------------
# Toolchain prefix
# ------------------------------------------------------------
# Allow override from command line or environment
set(ARM_NONE_EABI_PREFIX arm-none-eabi CACHE STRING "ARM GCC toolchain prefix")

# ------------------------------------------------------------
# Compilers
# ------------------------------------------------------------
set(CMAKE_C_COMPILER   ${ARM_NONE_EABI_PREFIX}-gcc)
set(CMAKE_CXX_COMPILER ${ARM_NONE_EABI_PREFIX}-g++)
set(CMAKE_ASM_COMPILER ${ARM_NONE_EABI_PREFIX}-gcc)
set(CMAKE_AR           ${ARM_NONE_EABI_PREFIX}-ar)
set(CMAKE_OBJCOPY      ${ARM_NONE_EABI_PREFIX}-objcopy)
set(CMAKE_OBJDUMP      ${ARM_NONE_EABI_PREFIX}-objdump)
set(CMAKE_SIZE         ${ARM_NONE_EABI_PREFIX}-size)

# ------------------------------------------------------------
# Prevent CMake from trying to link executables during compiler checks
# (critical for bare-metal targets)
# ------------------------------------------------------------
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# ------------------------------------------------------------
# Where to search for libraries and headers
# ------------------------------------------------------------
# If your toolchain is installed in a known root, set it here.
# Example:
# set(ARM_GCC_ROOT /opt/gcc-arm-none-eabi)

# set(CMAKE_FIND_ROOT_PATH ${ARM_GCC_ROOT})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)