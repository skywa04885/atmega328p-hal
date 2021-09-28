#include "HAL_GPIO.hpp"

namespace HAL
{
    /// Resets the given pin.
    [[ maybe_unused ]] void GPIO_Reset (GPIO_Register *reg, uint8_t mask) noexcept
    {
        reg->DDR &= ~mask;
        reg->PIN &= ~mask;
        reg->PORT &= ~mask;
    }

    /// Sets the mode for the given pin.
    [[ maybe_unused ]] void GPIO_SetMode (GPIO_Register *reg, uint8_t mask, GPIO_Mode mode) noexcept
    {
        if (mode == GPIO_Mode::Input)
        {
            reg->DDR &= ~mask;
            return;
        }

        reg->DDR |= mask;
    }

    /// Sets the resistors for the given pin.
    [[ maybe_unused ]] void GPIO_SetResistors (GPIO_Register *reg, uint8_t mask, GPIO_Resistors resistors) noexcept
    {
        if (!(reg->DDR & mask))
        { // Only set resistors mode/modes is/are input/inputs.
            return;
        }

        if (resistors == GPIO_Resistors::None)
        {
            reg->PORT &= ~mask;
            return;
        }

        reg->PORT |= mask;
    }

    /// Sets the state for the given pin.
    [[ maybe_unused ]] void GPIO_WriteDigital (GPIO_Register *reg, uint8_t mask, GPIO_State state) noexcept
    {
        if (state == GPIO_State::High)
        {
            reg->PORT |= mask;
            return;
        }

        reg->PORT &= ~mask;
    }

    /// Reads the value of the given pin.
    [[ maybe_unused ]] GPIO_State GPIO_ReadDigital (GPIO_Register *reg, uint8_t mask) noexcept
    {
        return (reg->PIN & mask) ? GPIO_State::High : GPIO_State::Low;
    }
}
