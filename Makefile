# ReChord — Echo Mini custom firmware build system
#
# Target: ARM Cortex-M3 (Thumb-2), Rockchip RKnanoC
# SDK: Rockchip RKnanoD MP3 v1.3
#
# The device contains two independently built firmware images:
#   AP (fw1)       — application, UI, filesystem, and hardware drivers
#   BB (section_3) — audio services, codecs, and DSP
#
# Never build the entire SDK as one target. The source manifests below are
# derived from the original Keil project and keep the AP and BB object graphs
# isolated.

ifeq ($(OS),Windows_NT)
    PYTHON ?= py -3
else
    PYTHON ?= python3
endif

CROSS_COMPILE ?= arm-none-eabi-
CC      := $(CROSS_COMPILE)gcc
OBJCOPY := $(CROSS_COMPILE)objcopy
SIZE    := $(CROSS_COMPILE)size

BUILD_DIR    := build
BB_BUILD_DIR := $(BUILD_DIR)/bb
AP_BUILD_DIR := $(BUILD_DIR)/ap
BB_OBJ_DIR   := $(BB_BUILD_DIR)/objs
AP_OBJ_DIR   := $(AP_BUILD_DIR)/objs
BB_LINKER    := firmware/firmware.ld

include firmware/rockchip/manifests/bb.mk
include firmware/rockchip/manifests/ap.mk

ARCH_FLAGS   := -mcpu=cortex-m3 -mthumb -mfloat-abi=soft
COMMON_FLAGS := $(ARCH_FLAGS) -Os -Wall -Wno-unused-parameter \
                -Wno-unused-variable -ffunction-sections -fdata-sections \
                -include firmware/rockchip/include/armcc_compat.h
BB_CFLAGS    := $(COMMON_FLAGS) -DRECHORD_BB_BUILD $(addprefix -I,$(BB_INCLUDE_DIRS))
AP_CFLAGS    := $(COMMON_FLAGS) -DRECHORD_AP_BUILD $(addprefix -I,$(AP_INCLUDE_DIRS))

BB_OBJS := $(foreach src,$(BB_SRCS),\
             $(BB_OBJ_DIR)/$(patsubst firmware/rockchip/%,%,$(src)).o)
AP_OBJS := $(foreach src,$(AP_SRCS),\
             $(AP_OBJ_DIR)/$(patsubst firmware/rockchip/%,%,$(src)).o)

BB_RECHORD_OBJS := \
    $(BB_BUILD_DIR)/startup.o \
    $(BB_BUILD_DIR)/stubs.o \
    $(BB_BUILD_DIR)/fault.o \
    $(BB_BUILD_DIR)/rechord_win.o \
    $(BB_BUILD_DIR)/rechord_app.o \
    $(BB_BUILD_DIR)/entry_stubs.o

BB_ELF := $(BB_BUILD_DIR)/rechord_bb.elf
BB_BIN := $(BB_BUILD_DIR)/section3_custom.bin
AP_ELF := $(AP_BUILD_DIR)/rechord_ap.elf

.PHONY: all bb ap build-bb build-ap link-bb link-ap build-sdk link-firmware \
        toolchain manifests compile-check pack-img pack-bb-img \
        extract-section3 clean

# The default remains the currently linkable BB firmware. AP is intentionally
# opt-in until its missing source modules and linker layout are restored.
all: bb

bb: build-bb link-bb
	@echo ""
	@echo "ReChord BB firmware built:"
	@$(SIZE) $(BB_ELF)

ap: build-ap

# Backward-compatible aliases used by existing documentation and scripts.
build-sdk: build-bb
link-firmware: link-bb

# ---- toolchain and manifest validation -----------------------------------
toolchain:
	@$(CC) -dumpversion
	@echo "Toolchain OK."

manifests:
	$(PYTHON) tools/check_sdk_manifests.py

# ---- BB / section_3 ------------------------------------------------------
build-bb: toolchain manifests $(BB_OBJS)
	@echo "BB SDK compiled: $(words $(BB_OBJS)) objects"

$(BB_OBJ_DIR)/%.o: firmware/rockchip/%
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(BB_CFLAGS) -c $< -o $@

$(BB_BUILD_DIR)/startup.o: firmware/startup/startup.c
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(BB_CFLAGS) -c $< -o $@

$(BB_BUILD_DIR)/stubs.o: firmware/stubs.c
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(BB_CFLAGS) -c $< -o $@

$(BB_BUILD_DIR)/fault.o: firmware/fault.c
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(BB_CFLAGS) -c $< -o $@

$(BB_BUILD_DIR)/rechord_win.o: firmware/rechord_win.c
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(BB_CFLAGS) -c $< -o $@

$(BB_BUILD_DIR)/rechord_app.o: firmware/rechord_app.c
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(BB_CFLAGS) -c $< -o $@

$(BB_BUILD_DIR)/entry_stubs.o: firmware/entry_stubs.S
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(ARCH_FLAGS) -c $< -o $@

link-bb: $(BB_RECHORD_OBJS) $(BB_OBJS)
	$(CC) $(ARCH_FLAGS) -T $(BB_LINKER) -nostartfiles -ffreestanding \
		$(BB_RECHORD_OBJS) $(BB_OBJS) -o $(BB_ELF)
	$(OBJCOPY) -O binary -j .fw_header -j .text $(BB_ELF) $(BB_BIN)
	@echo "Built: $(BB_BIN)"

# Attempt the AP (fw1) link to enumerate remaining undefined symbols.
link-ap: $(AP_OBJS)
	$(CC) $(ARCH_FLAGS) -T firmware/firmware_ap.ld -nostartfiles -ffreestanding \
		$(AP_OBJS) -o $(AP_ELF)
	@echo "AP link attempted: $(AP_ELF)"

# ---- AP / fw1 ------------------------------------------------------------
# This target compiles the 165 AP sources currently present in the repository.
# It does not link yet: AP_MISSING_SRCS documents 33 effective Keil inputs that
# must be imported or replaced first, and fw1 still needs its own linker script.
build-ap: toolchain manifests $(AP_OBJS)
	@echo "AP SDK compile check passed: $(words $(AP_OBJS)) imported objects"
	@echo "AP link remains blocked by $(words $(AP_MISSING_SRCS)) missing sources"

$(AP_OBJ_DIR)/%.o: firmware/rockchip/%
	@powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path '$(dir $@)' | Out-Null"
	$(CC) $(AP_CFLAGS) -c $< -o $@

# ---- checks and packaging ------------------------------------------------
compile-check: toolchain
	$(PYTHON) tools/compile_check.py

# Identity-test the stock section_3 splice operation.
pack-img:
	$(PYTHON) tools/pack_img.py --identity-test

# Produce a test IMG containing the custom BB while preserving the stock AP.
pack-bb-img: $(BB_BIN)
	$(PYTHON) tools/pack_img.py --pack $(BB_BIN) -o $(BUILD_DIR)/ReChord_BB.IMG

extract-section3:
	$(PYTHON) tools/pack_img.py --extract -o $(BUILD_DIR)/section3_stock.bin

clean:
	@powershell -NoProfile -Command "if (Test-Path 'build') { Remove-Item -Recurse -Force 'build' }"
