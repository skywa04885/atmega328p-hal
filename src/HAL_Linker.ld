ENTRY (__HAL_Entry)

MEMORY
{
    FLASH (rwx) : ORIGIN = 0x0000, LENGTH = 32k,
    SRAM (rw!x) : ORIGIN = 0x0100, LENGTH = 2k
}

SECTIONS
{
    .text :
    {
        /* ISR Vector */
        KEEP (*(.vector))
        *(.vector)
        /* Program */
        _stext = .;
        *(.text)
        *(.text*)
        _etext = .;
        /* Read-Only Data */
        _srodata = .;
        *(.rodata)
        *(.rodata*)
        _erodata = .;
    } > FLASH

    _sidata = LOADADDR (.data);

    .data :
    {
        _sdata = .;
        *(.data)
        *(.data*)
        _edata = .;
    } > SRAM AT> FLASH

    .bss :
    {
        _sbss = .;
        *(.bss)
        *(.bss*)
        _ebss = .;
    } > SRAM
}
