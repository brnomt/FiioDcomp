#!/usr/bin/env bash
# build_qemu_test.sh — build + run the ReChord QEMU test (firmware logic).
#
# Compiles the REAL firmware sources (rechord_app.c, Main2.c, stubs.c) with
# -DRECHORD_QEMU_TEST + QEMU ROM/MMIO stubs (qemu_echo_main.c), links at
# mps2-an385 addresses, runs in QEMU, and reads the telemetry via a TCP
# monitor. No device flashing involved.
#
# Usage: bash tools/build_qemu_test.sh
# Requires: arm-none-eabi-gcc, qemu-system-arm (set QEMU=... if needed).
set -e
cd "$(dirname "$0")/.."

QEMU="${QEMU:-C:\\Program Files\\qemu\\qemu-system-arm.exe}"
CROSS=arm-none-eabi-
SDK_INC="-include firmware/rockchip/include/armcc_compat.h \
  -Ifirmware/rockchip/include -Ifirmware/rockchip \
  -Ifirmware/rockchip/audio/Include -Ifirmware/rockchip/audio/AudioControl \
  -Ifirmware/rockchip/audio/Common -Ifirmware/rockchip/audio/RkEQ/Effect \
  -Ifirmware/rockchip/audio/RecordControl -Ifirmware/rockchip/audio/ID3 \
  -Ifirmware/rockchip/audio/Wav/WAV_LIB -Ifirmware/rockchip/audio/SSRC/resampler \
  -Ifirmware/rockchip/system/os -Ifirmware/rockchip/system/fileseek \
  -Ifirmware/rockchip/system/module_overlay -Ifirmware/rockchip/system/sysservice \
  -Ifirmware/rockchip/bbsystem"

echo "== build =="
${CROSS}gcc -mcpu=cortex-m3 -mthumb -Os -ffreestanding -nostdlib \
    -DRECHORD_QEMU_TEST $SDK_INC \
    -T firmware/qemu/qemu_echo_ld.ld \
    firmware/qemu/qemu_echo_main.c firmware/rechord_app.c \
    firmware/rockchip/bbsystem/Main2.c firmware/stubs.c \
    -o build/qemu_echo_test.elf
${CROSS}objcopy -j .text -O binary build/qemu_echo_test.elf build/qemu_echo_test.bin
echo "== run + verify (QEMU: $QEMU) =="
python tools/qemu_echo_read.py --qemu "$QEMU"
