#pragma once

#include <stdint.h>

#include "HAL_Base.hpp"

namespace HAL
{
    enum class EXTI_Sense : uint8_t
    {
        LowLevel = 0b00,
        LogicalChange = 0b01,
        FallingEdge = 0b10,
        RisingEdge = 0b11
    };

    enum class EXTI : uint8_t
    {
        Int0 = _BV8 (0),
        Int1 = _BV8 (1)
    };

    /// Sets the sense for the given EXTI.
    [[ maybe_unused ]] void EXTI_SetSense (EXTI exti, EXTI_Sense sense) noexcept;

    /// Enables the given EXTI.
    [[ maybe_unused ]] void EXTI_Enable (EXTI exti) noexcept;
}