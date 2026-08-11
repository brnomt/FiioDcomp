/**
 * FUN_0308aa9a @ 0x0308aa9a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308aa9a(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = *(int *)(param_2 + 0x40);
  iVar5 = *(int *)(*(int *)(param_2 + 0xc0) + 8);
  iVar6 = (int)*(short *)(iVar5 + *(short *)(param_2 + 0x7c) * 2);
  iVar5 = (int)*(short *)(iVar5 + *(short *)(param_2 + 0x7c) * 2 + -2);
  if (iVar6 < iVar5) {
    iVar1 = 0;
    if (0 < *(short *)(param_2 + 0x80)) {
      do {
        *(undefined4 *)(iVar9 + iVar1 * 4) = *(undefined4 *)(iVar9 + iVar1 * (iVar5 / iVar6) * 4);
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(short *)(param_2 + 0x80));
      return;
    }
    return;
  }
  if (iVar5 < iVar6) {
    uVar8 = iVar6 / iVar5;
    iVar1 = 0;
    iVar5 = (int)*(short *)(param_2 + 0x80) / (int)uVar8;
    iVar6 = 0;
    if (iVar5 < 1) {
      return;
    }
    do {
      if (0 < (int)uVar8) {
        uVar7 = *(undefined4 *)(iVar9 + (iVar1 + iVar5 + -1) * 4);
        puVar2 = (undefined4 *)(iVar9 + uVar8 * ((iVar5 + -1) - iVar6) * 4);
        puVar3 = puVar2 + -1;
        if ((uVar8 & 1) != 0) {
          *puVar2 = uVar7;
          puVar3 = puVar2;
        }
        for (iVar4 = (int)uVar8 >> 1; iVar4 != 0; iVar4 = iVar4 + -1) {
          puVar3[1] = uVar7;
          puVar3 = puVar3 + 2;
          *puVar3 = uVar7;
        }
      }
      iVar1 = iVar1 + -1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
    return;
  }
  return;
}


