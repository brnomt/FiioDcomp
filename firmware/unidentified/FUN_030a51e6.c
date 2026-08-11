/**
 * FUN_030a51e6 @ 0x030a51e6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030a51e6(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  bool bVar9;
  
  piVar6 = *(int **)(param_1 + 0x91c);
  uVar8 = 0;
  if (piVar6 == (int *)0x0) {
    return 0;
  }
  do {
    if (param_3 < 1) break;
    iVar7 = 0;
    if (param_3 < 1) {
      return 0;
    }
    do {
      if ((piVar6[3] <= piVar6[5]) && (piVar6[2] <= piVar6[6])) {
        FUN_0309f6c4(param_2 + iVar7 * 2,(param_3 - iVar7) * 2);
        break;
      }
      if ((piVar6[2] <= piVar6[6]) && (iVar1 = FUN_030a4fa8(param_1,piVar6), iVar1 == 0)) {
        return 0;
      }
      iVar1 = (piVar6[2] - piVar6[6]) * *piVar6;
      if (param_3 - iVar7 <= iVar1) {
        iVar1 = param_3 - iVar7;
      }
      FUN_0309f692(param_2 + iVar7 * 2,piVar6[7] + piVar6[6] * *piVar6 * 2,iVar1 << 1);
      iVar7 = iVar7 + iVar1;
      piVar6[6] = iVar1 / *piVar6 + piVar6[6];
    } while (iVar7 < param_3);
    if (iVar7 == 0) {
      return 0;
    }
    uVar8 = uVar8 + iVar7;
    bVar9 = iVar7 == param_3;
    param_3 = param_3 - iVar7;
  } while (bVar9);
  if ((*(int *)(param_1 + 0x848) == 1) && (0 < (int)(uVar8 + 1))) {
    puVar2 = (undefined2 *)(param_2 + uVar8 * 2);
    puVar3 = (undefined2 *)(param_2 + uVar8 * 4);
    puVar4 = puVar3 + 2;
    puVar5 = puVar2 + 1;
    if ((uVar8 & 1) == 0) {
      *puVar3 = *puVar2;
      puVar3[1] = *puVar2;
      puVar4 = puVar3;
      puVar5 = puVar2;
    }
    for (iVar7 = (int)(uVar8 + 1) >> 1; iVar7 != 0; iVar7 = iVar7 + -1) {
      puVar4[-2] = puVar5[-1];
      puVar4[-1] = puVar5[-1];
      puVar5 = puVar5 + -2;
      puVar4[-4] = *puVar5;
      puVar4[-3] = *puVar5;
      puVar4 = puVar4 + -4;
    }
  }
  return uVar8;
}


