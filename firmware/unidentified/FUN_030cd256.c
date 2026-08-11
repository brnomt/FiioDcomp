/**
 * FUN_030cd256 @ 0x030cd256
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030cd256(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  
  lVar7 = FUN_030cbfda(param_1,0xffffffff);
  lVar8 = FUN_030cc9c8(param_1,0xffffffff);
  iVar2 = (int)((ulonglong)lVar8 >> 0x20);
  if (1 < *(int *)(param_1 + 0x68)) {
    if (*(int *)(param_1 + 4) == 0) {
      return -0x8a;
    }
    if ((-1 < param_4) &&
       (bVar6 = (uint)lVar8 < param_3,
       (int)((iVar2 - param_4) - (uint)bVar6) < 0 ==
       (SBORROW4(iVar2,param_4) != SBORROW4(iVar2 - param_4,(uint)bVar6)))) {
      iVar2 = *(int *)(param_1 + 0x1c);
      do {
        iVar2 = iVar2 + -1;
        if (iVar2 < 0) break;
        lVar7 = lVar7 - *(longlong *)(iVar2 * 0x10 + 8 + *(int *)(param_1 + 0x2c));
        lVar9 = FUN_030cc9c8(param_1,iVar2);
        lVar1 = lVar8 - lVar9;
        iVar5 = (int)((ulonglong)lVar1 >> 0x20);
        lVar8 = lVar8 - lVar9;
        bVar6 = param_3 < (uint)lVar1;
      } while ((int)((param_4 - iVar5) - (uint)bVar6) < 0 !=
               (SBORROW4(param_4,iVar5) != SBORROW4(param_4 - iVar5,(uint)bVar6)));
      iVar2 = FUN_030cbb76(param_1,iVar2);
      if (iVar2 == 0) {
        uVar4 = param_3 - (uint)lVar8;
        uVar3 = *(uint *)(param_1 + 0x38);
        lVar1 = (ulonglong)uVar4 * (ulonglong)uVar3;
        lVar8 = FUN_030c0ef0((int)lVar1,
                             uVar4 * ((int)uVar3 >> 0x1f) +
                             ((param_4 - (int)((ulonglong)lVar8 >> 0x20)) -
                             (uint)(param_3 < (uint)lVar8)) * uVar3 +
                             (int)((ulonglong)lVar1 >> 0x20),1000,0);
        iVar2 = FUN_030cca40(param_1,(int)((ulonglong)lVar8 >> 0x20),(int)(lVar7 + lVar8),
                             (int)((ulonglong)(lVar7 + lVar8) >> 0x20));
        return iVar2;
      }
      return iVar2;
    }
  }
  return -0x83;
}


