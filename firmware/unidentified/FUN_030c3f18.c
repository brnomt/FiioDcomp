/**
 * FUN_030c3f18 @ 0x030c3f18
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c3f18(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = DAT_030c431c;
  piVar1 = DAT_030c4318;
  iVar3 = 0;
  *DAT_030c4318 = param_1;
  iVar4 = DAT_030c4320;
  if (0 < *(int *)(param_1 + 4)) {
    iVar5 = DAT_030c4320 + 0x8000;
    do {
      *(int *)(iVar2 + iVar3 * 4) = iVar4 + iVar3 * 0x4000;
      *(int *)(iVar2 + 8 + iVar3 * 4) = iVar5 + iVar3 * 0x2000;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  iVar4 = 0;
  piVar1[0xb] = 0;
  piVar1[0xc] = 0;
  piVar1[7] = iVar2;
  piVar1[8] = iVar2 + 8;
  if (piVar1 != (int *)0x0) {
    iVar4 = *piVar1;
  }
  if (piVar1 != (int *)0x0 && iVar4 != 0) {
    if (*(int *)(iVar4 + 0x1c) != 0) {
      piVar1[10] = -1;
      piVar1[0xe] = -1;
      piVar1[0xf] = -1;
      piVar1[9] = -1;
      piVar1[0x10] = -1;
      piVar1[0x11] = -1;
      piVar1[0x12] = -1;
      piVar1[0x13] = -1;
      return;
    }
    return;
  }
  return;
}


