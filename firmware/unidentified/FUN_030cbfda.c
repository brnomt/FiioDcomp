/**
 * FUN_030cbfda @ 0x030cbfda
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


longlong FUN_030cbfda(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  longlong lVar5;
  
  if (1 < *(int *)(param_1 + 0x68)) {
    bVar4 = *(int *)(param_1 + 4) != 0;
    iVar3 = 0;
    iVar2 = 0;
    if (bVar4) {
      iVar2 = *(int *)(param_1 + 0x1c);
      iVar3 = iVar2 - param_2;
    }
    if ((bVar4 && iVar2 != param_2) && iVar3 < 0 == (bVar4 && SBORROW4(iVar2,param_2))) {
      if (-1 < param_2) {
        return *(longlong *)(param_2 * 0x10 + 8 + *(int *)(param_1 + 0x2c));
      }
      lVar5 = 0;
      iVar3 = 0;
      lVar1 = 0;
      if (0 < iVar2) {
        do {
          lVar5 = FUN_030cbfda(param_1,iVar3);
          lVar5 = lVar5 + lVar1;
          iVar3 = iVar3 + 1;
          lVar1 = lVar5;
        } while (iVar3 < *(int *)(param_1 + 0x1c));
      }
      return lVar5;
    }
  }
  return -0x83;
}


