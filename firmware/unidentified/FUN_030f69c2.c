/**
 * FUN_030f69c2 @ 0x030f69c2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


ulonglong FUN_030f69c2(undefined4 param_1,int param_2,int param_3,int param_4,uint param_5,
                      int param_6,int param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  if (param_2 == 0) {
    iVar2 = LZCOUNT(param_1) + 0x20;
  }
  else {
    iVar2 = LZCOUNT(param_2);
  }
  uVar5 = FUN_030f6d28();
  uVar3 = (uint)(uVar5 >> 0x20);
  if (((uint)uVar5 != 0 || param_3 != 0) || (uVar3 != 0 || param_4 != 0)) {
    if (param_3 != 0 || param_4 != 0) {
      uVar6 = FUN_030f691c(param_3,param_4,0x40 - iVar2);
      lVar7 = FUN_030f6d28(param_3,param_4,iVar2);
      uVar5 = CONCAT44(uVar3 | (uint)((ulonglong)uVar6 >> 0x20),
                       (uint)uVar5 | (uint)uVar6 | (uint)(lVar7 != 0));
    }
    iVar2 = (param_7 - iVar2) + 10;
    uVar3 = (uint)(uVar5 >> 0xb);
    if (-1 < iVar2) {
      uVar1 = uVar3 + param_5;
      iVar2 = iVar2 * 0x100000 + (int)((uVar5 >> 0xb) >> 0x20) + param_6 +
              (uint)CARRY4(uVar3,param_5);
      if ((int)uVar5 * 0x200000 < 0) {
        bVar4 = 0xfffffffe < uVar1;
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 + (uint)bVar4;
        if ((uVar5 & 0x3ff) == 0) {
          uVar1 = uVar1 & 0xfffffffe;
        }
      }
      return CONCAT44(iVar2,uVar1);
    }
    uVar5 = 0;
  }
  return uVar5;
}


