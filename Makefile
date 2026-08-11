# ReChord — Echo Mini custom firmware build system
#
# Target: ARM Cortex-M3 (Thumb-2), Rockchip RKnanoC
# Toolchain: arm-none-eabi-gcc (GNU Arm Embedded)
#
# Goal: compile the Rockchip RKnanoD SDK + FiiO layer from source,
# produce a flashable section_3 via tools/pack_img.py.
# Windows: use mingw32-make (e.g. C:\winlibs\mingw64\bin\mingw32-make.exe)
#
# Usage:
#   make toolchain     — verify arm-none-eabi-gcc
#   make compile-check — compile all firmware/*.c, report status
#   make all           — compile reference objects (partial link)
#   make extract-img   — extract HIFIEC37.IMG sections
#   make clean

ifeq ($(OS),Windows_NT)
    MKDIR = if not exist $(subst /,\,$(1)) mkdir $(subst /,\,$(1))
    RM_RF = if exist $(subst /,\,$(1)) rmdir /s /q $(subst /,\,$(1))
    FIXPATH = $(subst /,\,$1)
    PYTHON ?= py -3
else
    MKDIR = mkdir -p $(1)
    RM_RF = rm -rf $(1)
    FIXPATH = $1
    PYTHON ?= python3
endif

# Prefer mingw32-make on Windows when `make` is missing
MAKE ?= make

CROSS_COMPILE = arm-none-eabi-
CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
SIZE    = $(CROSS_COMPILE)size

STOCK_DIR   = stock/3.7.0/ECHO MINI V3.7.0
IMG_FILE    = $(STOCK_DIR)/HIFIEC37.IMG
EXTRACT_DIR = $(STOCK_DIR)/extracted
BUILD_DIR   = build

ARCH_FLAGS  = -mcpu=cortex-m3 -mthumb -mfloat-abi=soft
INCLUDES    = -Ifirmware -Ifirmware/firmware \
              -Ifirmware/rockchip/include \
              -Ifirmware/rockchip/audio/Include \
              -Ifirmware/rockchip/audio/RkEQ/Effect \
              -Ifirmware/rockchip/audio/RkEQ \
              -Ifirmware/rockchip/audio/AudioControl \
              -Ifirmware/rockchip/audio/Common \
              -Ifirmware/rockchip/audio/RecordControl \
              -Ifirmware/rockchip/audio/ID3 \
              -Ifirmware/rockchip/audio/Wav/WAV_LIB \
              -Ifirmware/rockchip/audio/SSRC/resampler \
              -Ifirmware/rockchip/audio/HIFI/flac \
              -Ifirmware/rockchip/audio/HIFI/ape \
              -Ifirmware/rockchip/audio/HIFI/alac \
              -Ifirmware/rockchip/system/os \
              -Ifirmware/rockchip/system/fileseek \
              -Ifirmware/rockchip/system/module_overlay \
              -Ifirmware/rockchip/system/sysservice \
              -Ifirmware/rockchip/bbsystem
CFLAGS      = $(ARCH_FLAGS) -O2 -Wall -Wno-unused-parameter -Wno-unused-variable \
              -ffunction-sections -fdata-sections \
              $(INCLUDES) -DFIIO_DECOMP_REFERENCE
LDFLAGS     = $(ARCH_FLAGS) -Wl,--gc-sections -nostartfiles

# Core decomp + stubs (expand as headers/globals are filled in)
CORE_SRCS = \
    firmware/firmware/os/bitreader.c \
    firmware/firmware/os/softfloat.c \
    firmware/firmware/os/event_bitmap.c \
    firmware/firmware/os/entry.c \
    firmware/firmware/os/hifi_runtime.c \
    firmware/firmware/filesystem/buffered_io.c \
    firmware/firmware/filesystem/audio_file_buf.c \
    firmware/firmware/filesystem/hifi_file.c \
    firmware/stubs/rom_api_stubs.c \
    firmware/stubs/fiio_globals.c \
    firmware/startup/startup.c

# Full tree (compile-check tests everything)
ALL_SRCS := $(shell find firmware -name '*.c' 2>/dev/null)
ifeq ($(ALL_SRCS),)
ALL_SRCS := $(wildcard firmware/**/*.c)
endif

OBJS = $(addprefix $(BUILD_DIR)/,$(notdir $(CORE_SRCS:.c=.o)))

# Map flat build/*.o back to source paths
$(BUILD_DIR)/bitreader.o: firmware/firmware/os/bitreader.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/softfloat.o: firmware/firmware/os/softfloat.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/event_bitmap.o: firmware/firmware/os/event_bitmap.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/entry.o: firmware/firmware/os/entry.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/hifi_runtime.o: firmware/firmware/os/hifi_runtime.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/buffered_io.o: firmware/firmware/filesystem/buffered_io.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/audio_file_buf.o: firmware/firmware/filesystem/audio_file_buf.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/hifi_file.o: firmware/firmware/filesystem/hifi_file.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/rom_api_stubs.o: firmware/stubs/rom_api_stubs.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/fiio_globals.o: firmware/stubs/fiio_globals.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@
$(BUILD_DIR)/startup.o: firmware/startup/startup.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean toolchain compile-check extract-img crc link-test pack-img extract-section3

all: toolchain $(BUILD_DIR)/reference.o
	@echo ""
	@echo "Reference objects built under $(BUILD_DIR)/"
	@echo "Full IMG link still needs pack_img + byte-identical section_3 milestone."
	@echo "Run: make compile-check  (all sources)"
	@echo "See docs/flashing-guide.md"

toolchain:
	@$(CC) --version
	@echo "Toolchain OK."

compile-check: toolchain
	$(PYTHON) tools/compile_check.py

$(BUILD_DIR)/reference.o: $(OBJS) | $(BUILD_DIR)
	$(LD) -r $(OBJS) -o $@

$(BUILD_DIR):
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path 'build' | Out-Null"

link-test: $(BUILD_DIR)/reference.o
	@echo "Linker script: firmware/firmware.ld (not wired to full image yet)"
	$(CC) $(CFLAGS) -T firmware/firmware.ld -nostdlib $(OBJS) -o $(BUILD_DIR)/section3_test.elf || true

extract-img:
	$(PYTHON) tools/extract_fw.py "$(IMG_FILE)" -o "$(EXTRACT_DIR)"

crc:
	$(PYTHON) tools/crc_util.py "$(IMG_FILE)"

pack-img:
	$(PYTHON) tools/pack_img.py --identity-test

extract-section3:
	$(PYTHON) tools/pack_img.py --extract -o build/section3_stock.bin

clean:
	@powershell -NoProfile -Command "if (Test-Path 'build') { Remove-Item -Recurse -Force 'build' }"
