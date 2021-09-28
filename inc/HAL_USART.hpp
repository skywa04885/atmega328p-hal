#pragma once

#include <string.h>
#include <avr/io.h>
#include <stdint.h>

#include "HAL_Base.hpp"

#define USART(BASE) \
    reinterpret_cast <HAL::USART_Registers *> (BASE)

#define USART0_BASE 0xC0
#define USART0 USART (USART0_BASE)

namespace HAL
{
    enum class USART_Mode : uint8_t
    {
        Asynchronous = 0b00,
        Synchronous = _BV8 (UMSEL00),
        Reserved =  _BV8 (UMSEL01),
        MasterSPI =  _BV8 (UMSEL01) | _BV8 (UMSEL00)
    };

    enum class USART_Parity : uint8_t
    {
        Disabled = 0b00,
        Reserved = _BV8 (UPM00),
        Even = _BV8 (UPM01),
        Odd = _BV8 (UPM01) | _BV8 (UPM00)
    };

    enum class USART_Stopbits : uint8_t
    {
        SB1 = 0b0,
        SB2 = _BV8 (USBS0)
    };

    enum class USART_CharacterSize : uint8_t
    {
        CS8 = _BV8 (UCSZ01) | _BV8 (UCSZ00)
    };

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

    /// Configures the given USART.
    [[ maybe_unused ]] inline void USART_Configure (USART_Registers *usart, USART_Mode mode, USART_Parity parity, USART_Stopbits stopBits, USART_CharacterSize charSize)
    {
        usart->UCSRC = static_cast <uint8_t> (mode) | static_cast <uint8_t> (parity) | static_cast <uint8_t> (stopBits) | static_cast <uint8_t> (charSize);
    }
    /// Calculates and sets the BAUD for the given USART.
    [[ maybe_unused ]] void USART_SetBaud (USART_Registers *usart, const unsigned long BAUD) noexcept;

    /// Starts the USART in RX/TX Mode.
    [[ maybe_unused ]] inline void USART_StartRXTX (USART_Registers *usart) noexcept
    {
        usart->UCSRB |= (_BV8 (RXEN0) | _BV8 (TXEN0));
    }

    /// Stops the USART>
    [[ maybe_unused ]] inline void USART_Stop (USART_Registers *usart) noexcept
    {
        usart->UCSRB &= ~(_BV8 (RXEN0) | _BV8 (TXEN0));
    }

    /// Writes one single byte to the USART.
    [[ maybe_unused ]] void USART_WriteByte (USART_Registers *usart, uint8_t byte) noexcept;

    /// Writes an null terminated string to the USART>
    [[ maybe_unused ]] void USART_WriteString (USART_Registers *usart, const char *p) noexcept;

    /// Reads one single byte from the USART.
    [[ maybe_unused ]] uint8_t USART_ReadByte (USART_Registers *usart) noexcept;
}