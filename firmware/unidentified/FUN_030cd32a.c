/**
 * FUN_030cd32a @ 0x030cd32a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


longlong FUN_030cd32a(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  longlong *plVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  
  lVar12 = 0;
  lVar1 = 0;
  if (*(int *)(param_1 + 0x68) < 2) {
    return -0x83;
  }
  if (*(int *)(param_1 + 4) != 0) {
    lVar9 = FUN_030cbfda(param_1,0xffffffff);
    lVar10 = FUN_030cc9c8(param_1,0xffffffff);
    iVar3 = *(int *)(param_1 + 0x1c);
    do {
      lVar1 = lVar10;
      lVar12 = lVar9;
      iVar3 = iVar3 + -1;
      if (iVar3 < 0) break;
      plVar4 = (longlong *)(*(int *)(param_1 + 0x2c) + iVar3 * 0x10 + 8);
      lVar2 = lVar12 - *plVar4;
      iVar7 = (int)((ulonglong)lVar2 >> 0x20);
      lVar9 = lVar12 - *plVar4;
      lVar12 = lVar12 - *plVar4;
      lVar11 = FUN_030cc9c8(param_1,iVar3);
      lVar10 = lVar1 - lVar11;
      lVar1 = lVar1 - lVar11;
      iVar6 = *(int *)(param_1 + 100);
      bVar8 = *(uint *)(param_1 + 0x60) < (uint)lVar2;
    } while ((int)((iVar6 - iVar7) - (uint)bVar8) < 0 !=
             (SBORROW4(iVar6,iVar7) != SBORROW4(iVar6 - iVar7,(uint)bVar8)));
  }
  lVar9 = (ulonglong)*(uint *)(param_1 + 0x60) * 1000;
  uVar5 = (uint)lVar9;
  lVar12 = FUN_030c0ef0(uVar5 - (uint)lVar12,
                        ((*(int *)(param_1 + 100) * 1000 + (int)((ulonglong)lVar9 >> 0x20)) -
                        (int)((ulonglong)lVar12 >> 0x20)) - (uint)(uVar5 < (uint)lVar12),
                        *(int *)(param_1 + 0x38),*(int *)(param_1 + 0x38) >> 0x1f);
  return lVar1 + lVar12;
}


