#include <avr/interrupt.h>

#include "HAL_EXTI.hpp"

namespace HAL
{
    /// Sets the sense for the given EXTI.
    [[ maybe_unused ]] void EXTI_SetSense (EXTI exti, EXTI_Sense sense) noexcept
    {
        const uint8_t OFFSET = (exti == EXTI::Int0) ? 0 : 2;
        
        EICRA &= ~(0b11 << OFFSET);
        EICRA |= (static_cast <uint8_t> (sense) << OFFSET);
    }

    /// Enables the given EXTI.
    [[ maybe_unused ]] void EXTI_Enable (EXTI exti) noexcept
    {
        EIMSK |= static_cast <uint8_t> (exti);
    }
}