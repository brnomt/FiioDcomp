/**
 * FUN_0302d358 @ 0x0302d358
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_0302d358(uint *param_1,int param_2,int param_3,int param_4)

{
  longlong lVar1;
  longlong lVar2;
  ulonglong uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  longlong *plVar10;
  uint uVar11;
  int iVar12;
  
  plVar10 = (longlong *)(DAT_0302d470 + (param_3 + param_4 * 10) * 0x10);
  lVar1 = *plVar10;
  lVar2 = plVar10[1];
  iVar12 = DAT_0302d470 + param_3 * 0x14;
  puVar6 = param_1;
  iVar9 = param_2;
  do {
    iVar9 = iVar9 + -1;
    uVar11 = *puVar6;
    uVar3 = (longlong)*(int *)(iVar12 + 0x148) * (longlong)(int)uVar11 + lVar1 >> 10;
    uVar7 = (uint)uVar3;
    uVar8 = (uint)(uVar3 >> 0x20);
    uVar4 = *(uint *)(iVar12 + 0x140);
    lVar1 = (ulonglong)uVar4 * (uVar3 & 0xffffffff);
    iVar5 = uVar4 * uVar8 + ((int)uVar4 >> 0x1f) * uVar7 + (int)((ulonglong)lVar1 >> 0x20);
    lVar1 = (longlong)*(int *)(iVar12 + 0x14c) * (longlong)(int)uVar11 +
            lVar2 + CONCAT44(iVar5 >> 10,(uint)lVar1 >> 10 | iVar5 * 0x400000);
    uVar4 = *(uint *)(iVar12 + 0x144);
    lVar2 = (ulonglong)uVar4 * (uVar3 & 0xffffffff);
    iVar5 = uVar4 * uVar8 + ((int)uVar4 >> 0x1f) * uVar7 + (int)((ulonglong)lVar2 >> 0x20);
    lVar2 = (longlong)*(int *)(iVar12 + 0x150) * (longlong)(int)uVar11 +
            CONCAT44(iVar5 >> 10,(uint)lVar2 >> 10 | iVar5 * 0x400000);
    if ((longlong)uVar3 < 0) {
      if ((int)uVar8 >> 1 == -1) {
        uVar4 = uVar7 >> 10 | uVar8 * 0x400000;
      }
      else {
        uVar4 = 0xff800000;
      }
    }
    else if (uVar8 >> 1 == 0) {
      uVar4 = uVar7 >> 10 | uVar8 * 0x400000;
    }
    else {
      uVar4 = 0x7fffff;
    }
    *puVar6 = uVar4;
    puVar6 = puVar6 + 2;
  } while (iVar9 != 0);
  *plVar10 = lVar1;
  plVar10[1] = lVar2;
  return CONCAT44(param_2,param_1);
}


