#pragma once

namespace HAL
{
    /// Enables interrupts.
    inline void EnableInterrupts (void) noexcept
    {
        __asm__ ("sei\n\t");
    }

    /// Disables interrupts.
    inline void DisableInterrupts (void) noexcept
    {
        __asm__ ("cli\n\t");
    }
}
