/**
 * FUN_030cc9c8 @ 0x030cc9c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


longlong FUN_030cc9c8(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  bool bVar5;
  longlong lVar6;
  
  if (1 < *(int *)(param_1 + 0x68)) {
    bVar5 = *(int *)(param_1 + 4) != 0;
    iVar4 = 0;
    iVar2 = 0;
    if (bVar5) {
      iVar2 = *(int *)(param_1 + 0x1c);
      iVar4 = iVar2 - param_2;
    }
    if ((bVar5 && iVar2 != param_2) && iVar4 < 0 == (bVar5 && SBORROW4(iVar2,param_2))) {
      if (-1 < param_2) {
        puVar3 = (uint *)(*(int *)(param_1 + 0x2c) + param_2 * 0x10 + 8);
        lVar6 = (ulonglong)*puVar3 * 1000;
        lVar6 = FUN_030c0ef0((int)lVar6,puVar3[1] * 1000 + (int)((ulonglong)lVar6 >> 0x20),
                             *(int *)(param_1 + 0x38),*(int *)(param_1 + 0x38) >> 0x1f);
        return lVar6;
      }
      lVar6 = 0;
      iVar4 = 0;
      lVar1 = 0;
      if (0 < iVar2) {
        do {
          lVar6 = FUN_030cc9c8(param_1,iVar4);
          lVar6 = lVar6 + lVar1;
          iVar4 = iVar4 + 1;
          lVar1 = lVar6;
        } while (iVar4 < *(int *)(param_1 + 0x1c));
      }
      return lVar6;
    }
  }
  return -0x83;
}


