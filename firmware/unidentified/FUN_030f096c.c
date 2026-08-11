/**
 * FUN_030f096c @ 0x030f096c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030f096c(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = DAT_030f0cac;
  if (DAT_030f0cac[4] == 1) {
    hifi_busy_delay_ovl_0ed6(1);
    iVar3 = DAT_030f0cb4;
    do {
      if (piVar1[4] != 1) goto LAB_030f0994;
      hifi_busy_delay_ovl_0ed6(1);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    log_printf_ts(s_AudioFileInput2__timeout___030f0cc0);
  }
LAB_030f0994:
  *(undefined1 *)(DAT_030f0cb0 + 1) = 0;
  piVar1[4] = 1;
  uVar2 = FUN_030ecd50(piVar1[7] * piVar1[3] + *piVar1,piVar1[3],param_1);
  *(undefined4 *)(DAT_030f0cb8 + piVar1[7] * 4) = uVar2;
  return 0;
}


