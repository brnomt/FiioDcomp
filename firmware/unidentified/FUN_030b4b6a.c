/**
 * FUN_030b4b6a @ 0x030b4b6a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b4b6a(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_030b4f1c;
  if (DAT_030b4f1c[4] == 1) {
    hifi_busy_delay_ovl_0ab8(1);
    iVar4 = DAT_030b4f24;
    do {
      if (piVar1[4] != 1) goto LAB_030b4b92;
      hifi_busy_delay_ovl_0ab8(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_ovl(DAT_030b4f2c);
  }
LAB_030b4b92:
  piVar1[5] = 0;
  iVar4 = DAT_030b4f28;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_030b4f28 + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_030b4f20 + 1) = 1;
    uVar3 = FUN_030ab020(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_030b5418(0x102);
  return;
}


