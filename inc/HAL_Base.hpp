#pragma once

#define _BV8(N) \
    (static_cast <uint8_t> (1) << static_cast <uint8_t> (N))

#ifndef F_CPU
#error "F_CPU Needs to be defined!"
#endif
