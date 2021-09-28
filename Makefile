# Executables
TOOLCHAIN 		?= avr
AVR_LD 			?= $(TOOLCHAIN)-ld
AVR_AS 			?= $(TOOLCHAIN)-as
AVR_GCC 		?= $(TOOLCHAIN)-gcc
AVR_GPP			?= $(TOOLCHAIN)-g++
AVR_SIZE		?= $(TOOLCHAIN)-size
AVR_OBJCOPY		?= $(TOOLCHAIN)-objcopy

# Settings
MCU				?= atmega328p
LINKER_SCRIPT	?= ./src/HAL_Linker.ld
ELF_OUTPUT		?= firmware.elf
HEX_OUTPUT		?= firmware.hex

# Assembler Arguments
AVR_AS_ARGS		+= -mmcu=$(MCU)

# GCC Arguments
AVR_GPP_ARGS	+= -mmcu=$(MCU)
AVR_GPP_ARGS	+= -Wall
AVR_GPP_ARGS	+= -Werror
AVR_GPP_ARGS	+= -I./inc
AVR_GPP_ARGS	+= -nostartfiles
AVR_GPP_ARGS	+= -Os

# Size arguments
AVR_SIZE_ARGS	+= --format=avr
AVR_SIZE_ARGS	+= --mcu=$(MCU)

# Source files
ASM_SOURCES		+= $(shell find ./ -name *.asm)
CPP_SOURCES		+= $(shell find ./ -name *.cpp)

OBJECTS			+= $(ASM_SOURCES:.asm=.o)
OBJECTS			+= $(CPP_SOURCES:.cpp=.o)

# Make Rules
%.o: %.asm
	$(AVR_AS) $(AVR_AS_ARGS) -c $< -o $@

%.o: %.cpp
	$(AVR_GPP) $(AVR_GPP_ARGS) -fdata-sections -ffunction-sections -c $< -o $@

all: $(OBJECTS)
	$(AVR_GPP) -Wl,--gc-sections -T$(LINKER_SCRIPT) $(AVR_GPP_ARGS) $(OBJECTS) -o $(ELF_OUTPUT)
hex:
	$(AVR_OBJCOPY) -O ihex $(ELF_OUTPUT) $(HEX_OUTPUT)
size:
	$(AVR_SIZE) $(AVR_SIZE_ARGS) $(ELF_OUTPUT)
clean:
	rm -rf $(OBJECTS)

