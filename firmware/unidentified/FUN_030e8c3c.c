/**
 * FUN_030e8c3c @ 0x030e8c3c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e8c3c(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_030e8f78;
  if (DAT_030e8f78[4] == 1) {
    hifi_busy_delay_ovl_0e48(1);
    iVar3 = DAT_030e8f80;
    do {
      if (piVar1[4] != 1) goto LAB_030e8c64;
      hifi_busy_delay_ovl_0e48(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    hifi_debug_printf_sync_ovl_0e45(s_AudioFileInput2__timeout___030e8f8c);
  }
LAB_030e8c64:
  *(undefined1 *)(DAT_030e8f7c + 1) = 0;
  piVar1[4] = 1;
  uVar2 = FUN_030e3e7c(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_030e8f84 + piVar1[7] * 4) = uVar2;
  return 0;
}


