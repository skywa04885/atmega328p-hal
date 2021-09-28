#include <string.h>
#include <avr/io.h>

#include "HAL_USART.hpp"
#include "HAL_Base.hpp"

namespace HAL
{
    /// Resets the USART peripheral.
    [[ maybe_unused ]] void USART_Reset (USART_Registers *usart) noexcept
    {
        memset (usart, 0, sizeof (USART_Registers));
    }

    /// Calculates and sets the BAUD for the given USART.
    [[ maybe_unused ]] void USART_SetBaud (USART_Registers *usart, const unsigned long BAUD) noexcept
    {
        // Calculates the value for the baudrate-register.
        unsigned long UBRR_VAL = (usart->UCSRA & _BV8 (U2X0))
            ? (F_CPU / (8UL * BAUD) - 1UL)
            : (F_CPU / (16UL * BAUD) - 1UL);

        // Sets the value in the baudrate-register.
        usart->UBRRL = static_cast <uint8_t> (UBRR_VAL & 0xF);
        usart->UBRRH = static_cast <uint8_t> ((UBRR_VAL >> 8) & 0xF);
    }

    /// Starts the USART in RX/TX Mode.
    [[ maybe_unused ]] void USART_StartRXTX (USART_Registers *usart) noexcept
    {
        usart->UCSRB |= (_BV8 (RXEN0) | _BV8 (TXEN0));
    }

    /// Stops the USART>
    [[ maybe_unused ]] void USART_Stop (USART_Registers *usart) noexcept
    {
        usart->UCSRB &= ~(_BV8 (RXEN0) | _BV8 (TXEN0));
    }

    /// Writes one single byte to the USART.
    [[ maybe_unused ]] void USART_WriteByte (USART_Registers *usart, uint8_t byte) noexcept
    {
        while (!(usart->UCSRA & _BV8 (UDRE0)));
        usart->UDR = byte;   
    }

    /// Writes an null terminated string to the USART>
    [[ maybe_unused ]] void USART_WriteString (USART_Registers *usart, const char *p) noexcept
    {
        // Fancy pointer fuckery ;P
        while (*p != '\0')
        {
            USART_WriteByte (usart, *reinterpret_cast <const char *> (*p++));
        }
    }

    /// Reads one single byte from the USART.
    [[ maybe_unused ]] uint8_t USART_ReadByte (USART_Registers *usart) noexcept
    {
        while (!(usart->UCSRA & _BV8 (RXC0)));
        return usart->UDR;
    }
}
