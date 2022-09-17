.PHONY: clean test all begin gccversion sizebefore build sizeafter end \
		elf hex eep lss sym clean_list program

firmware = $(notdir $(CURDIR))

mcu = atmega8
f_cpu = 1000000

# Output format. (can be srec, ihex, binary)
format = ihex

build_dir = ./build

src = $(shell find src -name '*.c' -type f)

inc_dir = ./inc
inc_dir += ./inc/button
inc_dir += ./inc/lcd
inc_dir += ./inc/timer

objects := $(addprefix $(build_dir)/, $(src))
objects := $(objects:.c=.o)

ccompiler = avr-gcc
size = avr-size
objcopy = avr-objcopy
objdump = avr-objdump
ar = avr-ar rcs
nm = avr-nm
remove = rm -f
removedir = rm -rf

defines = -DF_CPU=1000000UL \
		  -D__AVR_ATmega8__

cflags = -O1 -g
cflags += $(addprefix -I, $(inc_dir))
cflags += -mmcu=$(mcu)
cflags += -fpack-struct
cflags += -Wall
cflags += -Wa,-adhlns=$(<:%.c=$(build_dir)/%.lst)
cflags += $(defines)

ldflags = -Wl,-Map=$(build_dir)/$(firmware).map,--cref
ldflags += -Wl,--gc-sections

#----------- Programming Options (avrdude) ------------
avrdude_programmer = usbasp
avrdude_port = usb
avrdude_write_flash = -U flash:w:$(build_dir)/$(firmware).hex
#avrdude_write_eeprom = -U eeprom:w:$(build_dir)/$(firmware).eep
avrdude_flags = -p $(mcu) -P $(avrdude_port) -c $(avrdude_programmer)
avrdude_flags += $(avrdude_no_verify)
avrdude_flags += $(avrdude_verbose)
avrdude_flags += $(avrdude_erase_counter)

#----------- Debugging Options ------------
debug_mfreq = $(f_cpu)
#debug_ui = gdb
debug_ui = insight
debug_backend = avarice
#degug_backend = simulavr
gdbinit_file = __avr_gdbinit
jtag_dev = /dev/com1
debug_port = 4242
debug_host = localhost

message_errors_none = Errors: none
message_begin = -------- begin --------
message_end = --------  end  --------
message_size_before = Size before:
message_size_after = Size after:
message_coff = Converting to AVR COFF:
message_entended_coff = Converting to AVR Extended COFF:
message_flash = Creating load file for Flash:
message_eeprom = Creating load file for EEPROM:
message_extended_listing = Creating Extended Listing:
message_symbol_table = Creating Symbol Table:
message_linking = Linking:
message_compiling_c = Compiling C:
message_compiling_cpp = Compiling C++:
message_assembling = Assebmling:
message_cleaning = Cleaning project:
message_creating_library = Creating library:

all: begin gccversion sizebefore build sizeafter end

build: elf hex eep lss sym

elf: $(build_dir)/$(firmware).elf
hex: $(build_dir)/$(firmware).hex
eep: $(build_dir)/$(firmware).eep
lss: $(build_dir)/$(firmware).lss
sym: $(build_dir)/$(firmware).sym

begin:
	@echo $(message_begin)
	@echo "Source files: $(src)"
	@echo "Object files: $(objects)"

end:
	@echo $(message_end)

hexsize = $(size) --target=$(format) $(build_dir)/$(firmware).hex
elfsize = $(size) --mcu=$(mcu) --format=avr $(build_dir)/$(firmware).elf

sizebefore:
	@if test -f $(build_dir)/$(firmware).elf; then echo; \
	echo $(message_size_before); $(elfsize); \
	2>/dev/null; fi

sizeafter:
	@if test -f $(build_dir)/$(firmware).elf; then echo; \
	echo $(message_size_after); $(elfsize); \
	2>/dev/null; fi

gccversion:
	@$(ccompiler) --version

program: $(build_dir)/$(firmware).hex $(build_dir)/$(firmware).eep
	avrdude $(avrdude_flags) $(avrdude_write_flash) $(avrdude_write_eeprom)

.SECONDARY: $(build_dir)/$(firmware).elf
.PRECIOUS: $(objects)
%.elf: $(objects)
	@echo
	@echo $(message_linking) $@
	$(ccompiler) $(cflags) $^ -o $@ $(ldflags)

%.hex: %.elf
	@echo
	@echo $(message_flash) $@
	$(objcopy) -O $(format) -R .eeprom -R .fuse -R .lock -R .signature $< $@

%.eep: %.elf
	@echo
	@echo $(message_eeprom) $@
	-$(objcopy) -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O $(format) $< $@ || exit 0

%.lss: %.elf
	@echo
	@echo $(message_extended_listing) $@
	$(objdump) -h -S -z $< > $@

%.sym: %.elf
	@echo
	@echo $(message_symbol_table) $@
	$(objdump) -h -S -z $< > $@

$(build_dir)/%.o: %.c
	$(shell [ ! -d "$(build_dir)" ] && mkdir $(build_dir))
	$(shell [ ! -d "$(build_dir)/$(dir $<)" ] && mkdir $(build_dir)/$(dir $<))
	@echo
	@echo $(message_compiling_c) $<
	$(ccompiler) -c $(cflags) $< -o $@
	$(ccompiler) -MM $(cflags) $< > $(build_dir)/$*.d

$(build_dir)/%.s: %.c
	$(shell [ ! -d "$(build_dir)" ] && mkdir $(build_dir))
	$(shell [ ! -d "$(build_dir)/$(dir $<)" ] && mkdir $(build_dir)/$(dir $<))
	$(ccompiler) -S $(cflags) $< -o $@

clean: begin clean_list end

clean_list:
	@echo
	@echo $(message_cleaning)
	$(remove) $(build_dir)/$(firmware).hex
	$(remove) $(build_dir)/$(firmware).eep
	$(remove) $(build_dir)/$(firmware).cof
	$(remove) $(build_dir)/$(firmware).elf
	$(remove) $(build_dir)/$(firmware).map
	$(remove) $(build_dir)/$(firmware).sym
	$(remove) $(build_dir)/$(firmware).lss
	$(remove) $(objects)
	$(remove) $(objects:%.o=%.lst)
	$(removedir) $(build_dir)

test:
	echo $(inc_dir)

-include $(objects:.o=.d)
