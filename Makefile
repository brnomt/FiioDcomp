# ReChord — Echo Mini custom firmware build system
#
# Target: ARM Cortex-M3 (Thumb-2), Rockchip RKnanoC
# Toolchain: arm-none-eabi-gcc (GNU Arm Embedded)
#
# Goal: compile the Rockchip RKnanoD SDK + ReChord layer from source,
# produce a flashable section_3 via tools/pack_img.py.
# Windows: use mingw32-make (e.g. C:\winlibs\mingw64\bin\mingw32-make.exe)
#
# Usage:
#   make toolchain     — verify arm-none-eabi-gcc
#   make build-sdk     — compile all SDK .c files to build/objs/*.o
#   make link-firmware — link objects into build/rechord_full.elf + section3_custom.bin
#   make all           — build-sdk + link-firmware
#   make pack-img      — splice section_3 into HIFIEC37.IMG (identity test)
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

CROSS_COMPILE = arm-none-eabi-
CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
SIZE    = $(CROSS_COMPILE)size

STOCK_DIR   = stock/3.7.0/ECHO MINI V3.7.0
IMG_FILE    = $(STOCK_DIR)/HIFIEC37.IMG
BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/objs
LINKER      = firmware/firmware.ld

ARCH_FLAGS  = -mcpu=cortex-m3 -mthumb -mfloat-abi=soft
SDK_INCLUDES = -include firmware/rockchip/include/armcc_compat.h \
               -Ifirmware/rockchip/include \
               -Ifirmware/rockchip \
               -Ifirmware/rockchip/audio/Include \
               -Ifirmware/rockchip/audio/AudioControl \
               -Ifirmware/rockchip/audio/Common \
               -Ifirmware/rockchip/audio/RkEQ/Effect \
               -Ifirmware/rockchip/audio/RecordControl \
               -Ifirmware/rockchip/audio/ID3 \
               -Ifirmware/rockchip/audio/Wav/WAV_LIB \
               -Ifirmware/rockchip/audio/SSRC/resampler \
               -Ifirmware/rockchip/system/os \
               -Ifirmware/rockchip/system/fileseek \
               -Ifirmware/rockchip/system/module_overlay \
               -Ifirmware/rockchip/system/sysservice \
               -Ifirmware/rockchip/bbsystem
SDK_CFLAGS = $(ARCH_FLAGS) -Os -Wall -Wno-unused-parameter -Wno-unused-variable \
             -ffunction-sections -fdata-sections $(SDK_INCLUDES)

# SDK sources (all .c under firmware/rockchip)
SDK_SRCS := $(shell find firmware/rockchip -name '*.c' 2>/dev/null)

# Exclude duplicate non-*2 variants — the SDK ships both audio_file_access.c
# and audio_file_access2.c etc.; only the *2 (RKnano 2) versions link.
NON2_EXCLUDE = Delay.c SysTickHandler.c audio_file_access.c pAAC.c pDSDIFF.c \
               pDSF.c pMP3.c pOGG.c p_hifi_Ape.c p_hifi_alac.c p_hifi_flac.c \
               interrupt.c

# Files that need special compile recipes (section conflicts / asm dupes) —
# see docs/STATUS.md. They are linked from the prebuilt .o set.
SPECIAL_EXCLUDE = systick2.c pCODECS2.c RecordControl.c PowerManager.c \
                 AsicToUnicode.c cue.c ID3.c AsicToUnicodeTable.c

SDK_SRCS := $(filter-out $(addprefix %/,$(NON2_EXCLUDE) $(SPECIAL_EXCLUDE)),$(SDK_SRCS))

# objects mirror source subdirs so the pattern rule matches
SDK_OBJS = $(patsubst firmware/rockchip/%.c,$(OBJ_DIR)/%.o,$(SDK_SRCS))

.PHONY: all clean toolchain build-sdk link-firmware compile-check pack-img extract-section3

all: build-sdk link-firmware
	@echo ""
	@echo "ReChord firmware built:"
	@$(SIZE) $(BUILD_DIR)/rechord_full.elf

toolchain:
	@$(CC) --version | head -1
	@echo "Toolchain OK."

$(OBJ_DIR):
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path 'build/objs' | Out-Null"

# ---- compile SDK ----
build-sdk: toolchain $(OBJ_DIR) $(SDK_OBJS)
	@echo "SDK compiled: $(words $(SDK_OBJS)) objects"

$(OBJ_DIR)/%.o: firmware/rockchip/%.c | $(OBJ_DIR)
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(SDK_CFLAGS) -c $< -o $@

# ---- link firmware ----
link-firmware: $(OBJ_DIR) $(BUILD_DIR)/startup.o $(BUILD_DIR)/stubs.o $(BUILD_DIR)/fault.o
	$(CC) $(ARCH_FLAGS) -T $(LINKER) -nostartfiles -ffreestanding \
		$(BUILD_DIR)/startup.o $(BUILD_DIR)/stubs.o $(BUILD_DIR)/fault.o $(SDK_OBJS) \
		-o $(BUILD_DIR)/rechord_full.elf
	$(OBJCOPY) -O binary -j .fw_header -j .text $(BUILD_DIR)/rechord_full.elf $(BUILD_DIR)/section3_custom.bin
	@echo "Built: $(BUILD_DIR)/section3_custom.bin (splice with pack-img)"

$(BUILD_DIR)/startup.o: firmware/startup/startup.c | $(OBJ_DIR)
	$(CC) $(SDK_CFLAGS) -c $< -o $@

$(BUILD_DIR)/stubs.o: firmware/stubs.c | $(OBJ_DIR)
	$(CC) $(SDK_CFLAGS) -c $< -o $@

$(BUILD_DIR)/fault.o: firmware/fault.c | $(OBJ_DIR)
	$(CC) $(SDK_CFLAGS) -c $< -o $@

# ---- checks / packaging ----
compile-check: toolchain
	$(PYTHON) tools/compile_check.py

pack-img:
	$(PYTHON) tools/pack_img.py --identity-test

extract-section3:
	$(PYTHON) tools/pack_img.py --extract -o $(BUILD_DIR)/section3_stock.bin

clean:
	@powershell -NoProfile -Command "if (Test-Path 'build') { Remove-Item -Recurse -Force 'build' }"
