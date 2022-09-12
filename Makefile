# File name
ELF=$(notdir $(CURDIR)).elf

# Tools
CCOMPILER=avr-gcc

# Compiler flags
CFLAGS=-O1 -g

# Search paths
vpath %.c ./src/
vpath %.c ./src/button/
vpath %.c ./src/lcd/
vpath %.c ./src/timer/

Dual_channel_LPS: main.o mcu_util.o interrupts.o init.o timer_util.o lcd_util.o button_util.o
	avr-gcc -o Fual_channel_LPS.elf main.o mcu_util.o interrupts.o init.o \
									timer_util.o lcd_util.o button_util.o

main.o: $(INCLUDE_DIR)/main.h "avr/io.h" $(INCLUDE_DIR)/init.h $(INCLUDE_DIR)/lcd/lcd_util.h \
		$(INCLUDE_DIR)/button/button_util.h $(INCLUDE_DIR)/mcu_util.h $(INCLUDE_DIR)/channel_struct.h \
		$(INCLUDE_DIR)/config.h $(INCLUDE_DIR)/lcd/custom_symbols/custom_symbols.h $(INCLUDE_DIR)/interrupts.h \
		$(INCLUDE_DIR)/timer/timer_util.h

