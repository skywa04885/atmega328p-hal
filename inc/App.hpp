#pragma once

#include "HAL_GPIO.hpp"
#include "HAL_Interrupts.hpp"
#include "HAL_USART.hpp"

#define LED_GPIO    HAL_GPIOB
#define LED_PIN     HAL_GPIO_PIN0

/// Gets called to setup the device.
extern "C" void App_Setup (void) noexcept;

/// Gets called forever.
extern "C" void App_Loop (void) noexcept;
