/**
 * FUN_030e8bcc @ 0x030e8bcc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030e8bcc(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_030e8f78;
  if (DAT_030e8f78[4] == 1) {
    hifi_busy_delay_ovl_0e48(1);
    iVar4 = DAT_030e8f80;
    do {
      if (piVar1[4] != 1) goto LAB_030e8bf4;
      hifi_busy_delay_ovl_0e48(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_sync_ovl_0e45(DAT_030e8f88);
  }
LAB_030e8bf4:
  piVar1[5] = 0;
  iVar4 = DAT_030e8f84;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_030e8f84 + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_030e8f7c + 1) = 1;
    uVar3 = FUN_030e3e7c(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_030e9468(0xf2);
  return;
}


