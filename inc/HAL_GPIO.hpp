#pragma once

#include <stdint.h>

#include "HAL_Base.hpp"

#define HAL_GPIO(BASE) \
    reinterpret_cast <HAL::GPIO_Register *> (BASE)

#define HAL_GPIOB_BASE 0x23
#define HAL_GPIOB HAL_GPIO (HAL_GPIOB_BASE)

#define HAL_GPIOC_BASE 0x26
#define HAL_GPIOC HAL_GPIO (HAL_GPIOC_BASE)

#define HAL_GPIOD_BASE 0x29
#define HAL_GPIOD HAL_GPIO (HAL_GPIOD_BASE)

#define HAL_GPIO_PIN0 (_BV8(0))
#define HAL_GPIO_PIN1 (_BV8(1))
#define HAL_GPIO_PIN2 (_BV8(2))
#define HAL_GPIO_PIN3 (_BV8(3))
#define HAL_GPIO_PIN4 (_BV8(4))
#define HAL_GPIO_PIN5 (_BV8(5))
#define HAL_GPIO_PIN6 (_BV8(6))
#define HAL_GPIO_PIN7 (_BV8(7))

namespace HAL
{
    enum class GPIO_Pin : uint8_t
    {

    };

    enum class GPIO_Mode : uint8_t
    {
        Input,
        Output
    };

    enum class GPIO_Resistors : uint8_t
    {
        None,
        Pullup
    };

    enum class GPIO_State : uint8_t
    {
        High,
        Low
    };

    struct  __attribute__ (( packed )) GPIO_Register
    {
        uint8_t PIN;
        uint8_t DDR;
        uint8_t PORT;
    };

    /// Resets the given pin.
    [[ maybe_unused ]] void GPIO_Reset (GPIO_Register *reg, uint8_t mask) noexcept;

    /// Sets the mode for the given pin.
    [[ maybe_unused ]] void GPIO_SetMode (GPIO_Register *reg, uint8_t mask, GPIO_Mode mode) noexcept;

    /// Sets the resistors for the given pin.
    [[ maybe_unused ]] void GPIO_SetResistors (GPIO_Register *reg, uint8_t mask, GPIO_Resistors resistors) noexcept;

    /// Sets the state for the given pin.
    [[ maybe_unused ]] void GPIO_WriteDigital (GPIO_Register *reg, uint8_t mask, GPIO_State state) noexcept;

    /// Reads the value of the given pin.
    [[ maybe_unused ]] GPIO_State GPIO_ReadDigital (GPIO_Register *reg, uint8_t mask) noexcept;
}
