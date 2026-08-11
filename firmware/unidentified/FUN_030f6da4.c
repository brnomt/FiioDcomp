/**
 * FUN_030f6da4 @ 0x030f6da4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030f6da4(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = DAT_030f7150;
  if (DAT_030f7150[4] == 1) {
    hifi_busy_delay_ovl_0f53(1);
    iVar4 = DAT_030f7158;
    do {
      if (piVar1[4] != 1) goto LAB_030f6dcc;
      hifi_busy_delay_ovl_0f53(1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_030f50a4(DAT_030f7160);
  }
LAB_030f6dcc:
  piVar1[5] = 0;
  iVar4 = DAT_030f715c;
  iVar2 = piVar1[6];
  *(undefined4 *)(DAT_030f715c + iVar2 * 4) = 0;
  piVar1[7] = iVar2;
  iVar2 = 1 - iVar2;
  piVar1[6] = iVar2;
  if (*(int *)(iVar4 + iVar2 * 4) == 0) {
    *(undefined1 *)(DAT_030f7154 + 1) = 1;
    uVar3 = FUN_030f49d4(iVar2 * piVar1[3] + *piVar1,piVar1[3],param_1);
    *(undefined4 *)(iVar4 + piVar1[6] * 4) = uVar3;
  }
  FUN_030f81dc(0xf2);
  return;
}


