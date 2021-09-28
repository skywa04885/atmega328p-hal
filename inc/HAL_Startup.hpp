#pragma once

#include "stdint.h"

/// The entry which gets called when the chip is ready for user code.
extern "C" void __attribute__ (( noreturn )) __HAL_Entry (void) noexcept;
