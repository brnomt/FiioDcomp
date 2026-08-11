/**
 * FUN_030f08fa @ 0x030f08fa
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f08fa(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_030f0cac;
  if (DAT_030f0cac[4] == 1) {
    hifi_busy_delay_ovl_0ed6(1);
    iVar4 = DAT_030f0cb4;
    do {
      if (piVar1[4] != 1) goto LAB_030f0922;
      hifi_busy_delay_ovl_0ed6(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    log_printf_ts(DAT_030f0cbc);
  }
LAB_030f0922:
  piVar1[5] = 0;
  iVar4 = DAT_030f0cb8;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_030f0cb8 + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_030f0cb0 + 1) = 1;
    uVar3 = FUN_030ecd50(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_030f11a8(0x115);
  return;
}


