#include "App.hpp"

/// Gets called to setup the device.
extern "C" void App_Setup (void) noexcept
{
    HAL::GPIO_SetMode (LED_GPIO, LED_PIN, HAL::GPIO_Mode::Output);
    HAL::GPIO_WriteDigital (LED_GPIO, LED_PIN, HAL::GPIO_State::High);

    HAL::USART_Reset ();

    HAL::EnableInterrupts ();
}

/// Gets called forever.
extern "C" void App_Loop (void) noexcept
{

}
