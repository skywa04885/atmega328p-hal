#pragma once

#include <stdint.h>

#define USART(BASE) \
    reinterpret_cast <HAL::USART_Registers *> (BASE)

#define USART0_BASE 0xC0
#define USART0 USART (USART0_BASE)

namespace HAL
{
    struct __attribute__ (( packed )) USART_Registers
    {
        uint8_t UCSRA;
        uint8_t UCSRB;
        uint8_t UCSRC;
        uint8_t __RESErVED_0;
        uint8_t UBRRL;
        uint8_t UBRRH;
        uint8_t UDR;
    };

    /// Resets the USART peripheral.
    [[ maybe_unused ]] void USART_Reset (USART_Registers *usart) noexcept;

    /// Calculates and sets the BAUD for the given USART.
    [[ maybe_unused ]] void USART_SetBaud (USART_Registers *usart, const unsigned long BAUD) noexcept;

    /// Starts the USART in RX/TX Mode.
    [[ maybe_unused ]] void USART_StartRXTX (USART_Registers *usart);

    /// Writes one single byte to the USART.
    [[ maybe_unused ]] void USART_WriteByte (USART_Registers *usart, uint8_t byte) noexcept;

    /// Writes an null terminated string to the USART>
    [[ maybe_unused ]] void USART_WriteString (USART_Registers *usart, const char *p) noexcept;

    /// Reads one single byte from the USART.
    [[ maybe_unused ]] uint8_t USART_ReadByte (USART_Registers *usart) noexcept;
}