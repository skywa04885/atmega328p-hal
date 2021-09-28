#pragma once

namespace HAL
{
    inline void EnableInterrupts (void) noexcept
    {
        __asm__ ("sei\n\t");
    }

    inline void DisableInterrupts (void) noexcept
    {
        __asm__ ("cli\n\t");
    }
}
