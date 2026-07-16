# Echo Mini Firmware — Build System
# 
# Target: ARM Cortex-M (Thumb-2), little-endian
# Toolchain: arm-none-eabi-gcc
# SDK: RKnano SDK 1.0
#
# Usage:
#   make all          — build firmware from decompiled C sources
#   make clean        — remove build artifacts
#   make dump-strings — extract all strings from IMG
#   make dump-symbols — export Ghidra symbol table
#   make extract-img  — extract sections from HIFIEC37.IMG
#   make crc          — verify/recalculate firmware CRC

# Toolchain
CROSS_COMPILE = arm-none-eabi-
CC      = $(CROSS_COMPILE)gcc
AS      = $(CROSS_COMPILE)as
LD      = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
SIZE    = $(CROSS_COMPILE)size

# Project paths
STOCK_DIR   = stock/ECHO\ MINI\ V3.7.0
IMG_FILE    = $(STOCK_DIR)/HIFIEC37.IMG
EXTRACT_DIR = $(STOCK_DIR)/extracted

# Cortex-M0/M0+/M3/M4 flags (exact RKnano core unknown — try M3)
ARCH_FLAGS  = -mcpu=cortex-m3 -mthumb -mfloat-abi=soft
CFLAGS      = $(ARCH_FLAGS) -O2 -Wall -Wextra -ffunction-sections -fdata-sections
LDFLAGS     = $(ARCH_FLAGS) -Wl,--gc-sections -nostartfiles -T firmware/firmware.ld

# Module directories
MODULES = \
    firmware/os \
    firmware/filesystem \
    firmware/dsp \
    firmware/media \
    firmware/usb \
    firmware/power \
    firmware/drivers \
    codecs/mp3 \
    codecs/wma \
    codecs/aac \
    codecs/flac \
    codecs/ape \
    codecs/wav \
    codecs/ogg \
    codecs/dsd \
    apps/audio \
    apps/ui \
    apps/recorder \
    apps/bluetooth \
    resource

# C sources from decompilation (to be populated as functions are decompiled)
CSRCS = $(foreach mod,$(MODULES),$(wildcard firmware/$(mod)/*.c))

OBJS  = $(CSRCS:.c=.o)

.PHONY: all clean dump-strings dump-symbols extract-img crc

all: build/firmware.elf

build/firmware.elf: $(OBJS)
	@mkdir -p build
	$(LD) $(LDFLAGS) $(OBJS) -o $@
	$(SIZE) $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/
	find firmware/ -name '*.o' -delete

# --- Analysis Tools ---

dump-strings:
	@echo "Extracting strings from $(IMG_FILE)..."
	strings -t x "$(IMG_FILE)" | head -20000 > $(EXTRACT_DIR)/strings_dump.txt
	wc -l $(EXTRACT_DIR)/strings_dump.txt
	@echo "Done: $(EXTRACT_DIR)/strings_dump.txt"

dump-symbols:
	@echo "TODO: Use Ghidra MCP to export function database"
	@echo "Run: analyzeHeadless <project> <folder> -postScript ExportFunctions.java"

extract-img:
	python3 tools/extract_sections.py "$(IMG_FILE)" "$(EXTRACT_DIR)"

crc:
	python3 tools/crc_util.py verify "$(IMG_FILE)"

# --- Ghidra Integration ---

.PHONY: ghidra-export ghidra-save

ghidra-export:
	@echo "Exporting Ghidra decompilation to C sources..."
	@echo "Use Ghidra MCP: batch_decompile to get all functions"
	@echo "Then: export to firmware/codecs/*/*.c"

ghidra-save:
	@echo "Saving Ghidra project..."
	@echo "Project is at: $(STOCK_DIR)/HIFIEC37.IMG.gpr"
