#include "App.hpp"

/// Gets called to setup the device.
extern "C" void App_Setup (void) noexcept
{
    // Configures the LED pin.
    HAL::GPIO_SetMode (LED_GPIO, LED_PIN, HAL::GPIO_Mode::Output);
    HAL::GPIO_WriteDigital (LED_GPIO, LED_PIN, HAL::GPIO_State::High);

    // Configures the USART.
    HAL::USART_Reset (USART0);
    HAL::USART_Configure (USART0, HAL::USART_Mode::Asynchronous,
        HAL::USART_Parity::Disabled, HAL::USART_Stopbits::SB1,
        HAL::USART_CharacterSize::CS8);
    HAL::USART_SetBaud (USART0, 9600UL);

    // Enables interrupts.
    HAL::EnableInterrupts ();
}

/// Gets called forever.
extern "C" void App_Loop (void) noexcept
{
    HAL::USART_WriteString (USART0, "Hello World\r\n");
}
