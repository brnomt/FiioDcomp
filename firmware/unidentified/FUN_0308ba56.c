/**
 * FUN_0308ba56 @ 0x0308ba56
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined8 FUN_0308ba56(int param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  lVar1 = (longlong)param_1 * (longlong)param_1 + (longlong)param_2 * (longlong)param_2;
  uVar2 = (uint)lVar1;
  uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
  uVar7 = uVar2 >> 0x14 | uVar5 * 0x1000;
  iVar6 = 0;
  uVar3 = uVar5 >> 0x14;
  if ((uVar5 >> 0x14 == 0) && (iVar6 = 0x20, uVar3 = uVar7, uVar7 == 0)) {
    return CONCAT44(uVar5,0xffffffff);
  }
  for (; (uVar3 & 0xff000000) == 0; uVar3 = uVar3 << 8) {
    iVar6 = iVar6 + 8;
  }
  iVar6 = (*(byte *)(*DAT_0308bec4 + (uVar3 >> 0x19)) >> ((uVar3 >> 0x18 & 1) << 2) & 0xf) + iVar6;
  if (iVar6 + -0x13 < 0x21) {
    uVar3 = FUN_030827aa(uVar2,uVar5,0x20 - (iVar6 + -0x13));
  }
  else {
    uVar3 = FUN_0308278c(uVar2,uVar5,iVar6 + -0x33);
  }
  iVar4 = *(int *)(*DAT_0308bec8 + (uVar3 >> 0x18) * 4);
  lVar1 = (ulonglong)
          (uint)(iVar4 - (int)((ulonglong)(uVar3 << 8) *
                               (ulonglong)
                               (uint)(iVar4 - *(int *)(*DAT_0308bec8 + ((uVar3 >> 0x18) + 1) * 4))
                              >> 0x20)) * (ulonglong)*(uint *)(*DAT_0308becc + (iVar6 + 1) * 4);
  return CONCAT44((int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
}


