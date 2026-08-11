/**
 * FUN_030ddf76 @ 0x030ddf76
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ddf76(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_030de328;
  if (DAT_030de328[4] == 1) {
    hifi_busy_delay_ovl_0dc7(1);
    iVar4 = DAT_030de330;
    do {
      if (piVar1[4] != 1) goto LAB_030ddf9e;
      hifi_busy_delay_ovl_0dc7(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hifi_debug_printf_ovl_0dc5(DAT_030de338);
  }
LAB_030ddf9e:
  piVar1[5] = 0;
  iVar4 = DAT_030de334;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_030de334 + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_030de32c + 1) = 1;
    uVar3 = FUN_030dbed4(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_030e0430(0x102);
  return;
}


