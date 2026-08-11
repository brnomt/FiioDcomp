/**
 * FUN_030a341c @ 0x030a341c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030a341c(undefined4 *param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar4 = *param_5;
  iVar5 = param_3 * param_4;
  uVar7 = param_5[1];
  if (uVar7 != 1) {
    iVar6 = 0;
    if ((int)uVar4 < 1) {
      return;
    }
    do {
      FUN_030a341c(param_1,param_2,param_3 * uVar4,param_4);
      iVar6 = iVar6 + 1;
      param_2 = param_2 + iVar5 * 4;
      param_1 = param_1 + uVar7;
    } while (iVar6 < (int)uVar4);
    return;
  }
  if (0 < (int)uVar4) {
    puVar2 = (undefined4 *)(param_2 + iVar5 * -4);
    puVar1 = param_1 + -1;
    if ((uVar4 & 1) != 0) {
      puVar2 = puVar2 + iVar5;
      *param_1 = *puVar2;
      puVar1 = param_1;
    }
    iVar6 = (int)uVar4 >> 1;
    if (iVar6 != 0) {
      do {
        puVar3 = puVar2 + iVar5;
        puVar2 = puVar2 + iVar5 * 2;
        puVar1[1] = *puVar3;
        puVar1 = puVar1 + 2;
        *puVar1 = *puVar2;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      return;
    }
    return;
  }
  return;
}


