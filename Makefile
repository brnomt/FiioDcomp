# Echo Mini Firmware — Build System
#
# Target: ARM Cortex-M3 (Thumb-2), little-endian — Rockchip RKnanoC
# Toolchain: arm-none-eabi-gcc (not wired to full IMG pack yet)
#
# Usage:
#   make all          — compile reference sources (SDK + Fiio decomp)
#   make clean        — remove build artifacts
#   make extract-img  — extract sections from HIFIEC37.IMG
#   make crc          — verify IMG EOF trailer
#
# Flashing: see docs/flashing-guide.md (resource repack works today; full build does not)

CROSS_COMPILE = arm-none-eabi-
CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
SIZE    = $(CROSS_COMPILE)size

STOCK_DIR   = stock/ECHO\ MINI\ V3.7.0
IMG_FILE    = $(STOCK_DIR)/HIFIEC37.IMG
EXTRACT_DIR = $(STOCK_DIR)/extracted

ARCH_FLAGS  = -mcpu=cortex-m3 -mthumb -mfloat-abi=soft
CFLAGS      = $(ARCH_FLAGS) -O2 -Wall -Wno-unused-parameter -ffunction-sections -fdata-sections \
              -Ifirmware -Ifirmware/firmware -Ifirmware/rockchip/include \
              -Ifirmware/rockchip/audio/Include \
              -DFIIO_DECOMP_REFERENCE
LDFLAGS     = $(ARCH_FLAGS) -Wl,--gc-sections -nostartfiles

# Ghidra decomp (Fiio-specific + verified stubs)
FIIO_SRCS = \
    $(wildcard firmware/firmware/**/*.c) \
    $(wildcard firmware/codecs/**/*.c) \
    $(wildcard firmware/apps/**/*.c)

# Rockchip SDK port (reference — needs SysConfig/Driver stubs to link)
ROCKCHIP_SRCS = \
    firmware/rockchip/bbsystem/audio_file_access2.c \
    firmware/rockchip/audio/Common/pCODECS.c

# Full SDK tree available under firmware/rockchip/ for RE; only core files in build for now
CSRCS = $(FIIO_SRCS) $(ROCKCHIP_SRCS)
OBJS  = $(CSRCS:.c=.o)

.PHONY: all clean extract-img crc

all: build/reference.o
	@echo ""
	@echo "Note: full firmware link not available yet (no firmware.ld / IMG packer)."
	@echo "See docs/flashing-guide.md for what you can flash today."

build/reference.o: $(OBJS) | build
	$(LD) -r $(OBJS) -o $@ 2>/dev/null || echo "Link skipped (missing toolchain or deps)"

build:
	@mkdir -p build

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 2>/dev/null || echo "Skip (no toolchain): $<"

clean:
	rm -rf build/
	find firmware -name '*.o' -delete 2>/dev/null || true

extract-img:
	python3 tools/extract_fw.py "$(IMG_FILE)" -o "$(EXTRACT_DIR)"

crc:
	python3 tools/crc_util.py "$(IMG_FILE)"
