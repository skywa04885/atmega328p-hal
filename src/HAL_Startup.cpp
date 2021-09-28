#include "HAL_Startup.hpp"

// External pointers to memory addresses.
extern uint8_t *_sbss;
extern uint8_t *_ebss;
extern uint8_t *_sdata;
extern uint8_t *_edata;
extern uint8_t *_sidata;

// Application methods.
extern "C" void App_Setup (void) noexcept;
extern "C" void App_Loop (void) noexcept;

/// The entry which gets called when the chip is ready for user code.
extern "C" void __attribute__ (( noreturn )) __HAL_Entry (void) noexcept
{
    // Clears the bss section.
    for (uint8_t *byte = _sbss; byte < _ebss; ++byte)
    {
        *byte = 0x00;
    }

    // Initializes the data section.
    for (uint8_t *ram = _sdata, *flash = _sidata; ram < _edata; ++ram, ++flash)
    {
        *ram = *flash;
    }

    // Calls the setup code.
    App_Setup ();

    // Runs the loop.
    for (;;)
    {
        App_Loop ();
    }
}
