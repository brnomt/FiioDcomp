/**
 * hifi_busy_delay_ovl_0817 @ 0x0308175c
 * Tags: os, overlay
 * Auto-exported from Ghidra decompilation
 */

void hifi_busy_delay_ovl_0817(int param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = (uint)((ulonglong)DAT_030817e0 *
                 (ulonglong)((*(uint *)(DAT_030817d8 + 0x20) / DAT_030817dc) * param_1) >> 0x22);
  if (uVar1 == 0) {
    return;
  }
  do {
    bVar2 = uVar1 != 0;
    uVar1 = uVar1 - 1;
  } while (bVar2 && uVar1 != 0);
  return;
}
