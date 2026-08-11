/**
 * FUN_030fe982 @ 0x030fe982
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_030fe982(uint param_1,uint param_2)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  longlong lVar10;
  
  uVar6 = -param_1;
  if ((int)(-(uint)(param_1 != 0) - param_2) < 0 ==
      (SBORROW4(0,param_2) != SBORROW4(-param_2,(uint)(param_1 != 0)))) {
    return 0;
  }
  uVar5 = (param_2 & 0x7fffffff) >> 0x14;
  uVar7 = param_2 & 0xfffff | 0x100000;
  if ((uVar5 & 1) == 0) {
    bVar9 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    uVar7 = uVar7 * 2 + (uint)bVar9;
    uVar5 = uVar5 - 1;
  }
  lVar2 = 0;
  iVar8 = 0;
  do {
    lVar10 = FUN_030fe6bc(0,0x100000,iVar8,uVar6);
    lVar1 = lVar10 + lVar2 + lVar2;
    uVar6 = (uint)lVar1;
    uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
    if (uVar3 < uVar7 || uVar7 - uVar3 < (uint)(uVar6 <= param_1)) {
      bVar9 = param_1 < uVar6;
      param_1 = param_1 - uVar6;
      uVar7 = (uVar7 - uVar3) - (uint)bVar9;
      lVar2 = lVar10 + lVar2;
    }
    iVar4 = (int)((ulonglong)lVar2 >> 0x20);
    uVar3 = (uint)lVar2;
    bVar9 = CARRY4(param_1,param_1);
    param_1 = param_1 * 2;
    iVar8 = iVar8 + 1;
    uVar7 = uVar7 * 2 + (uint)bVar9;
  } while (iVar8 < 0x35);
  uVar6 = iVar4 * 2 + (uint)CARRY4(uVar3,uVar3);
  if (uVar7 < uVar6 || uVar6 - uVar7 < (uint)(param_1 <= uVar3 * 2)) {
    uVar6 = 0;
    iVar8 = 0;
  }
  else {
    uVar6 = 0xffffffff;
    iVar8 = -1;
  }
  iVar4 = iVar4 + (((int)uVar5 >> 1) + 0x1ff) * 0x100000;
  if (iVar8 < 0) {
    bVar9 = 0xfffffffe < uVar3;
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + (uint)bVar9;
    if ((uVar6 & 0x7fffffff) == 0 && iVar8 * 2 + (uint)CARRY4(uVar6,uVar6) == 0) {
      uVar3 = uVar3 & 0xfffffffe;
    }
  }
  return CONCAT44(iVar4,uVar3);
}


