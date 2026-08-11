/**
 * FUN_03082906 @ 0x03082906
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03082906(uint param_1,uint param_2)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 << 1 != 0) && (param_2 << 1 != 0)) {
    iVar4 = ((param_1 & 0x7fffffff) >> 0x17) + ((param_2 & 0x7fffffff) >> 0x17);
    uVar1 = (ulonglong)((param_1 << 1 & 0xffffff) >> 1 | 0x800000) *
            (ulonglong)((param_2 << 1 & 0xffffff) >> 1 | 0x800000);
    iVar5 = iVar4 + -0x7f;
    uVar2 = (int)(uVar1 >> 0x20) * 0x10000;
    if ((uVar1 & 0xffff) != 0) {
      uVar2 = uVar2 + 1;
    }
    uVar2 = uVar2 | (uint)uVar1 >> 0x10;
    if (-1 < (int)uVar2) {
      uVar2 = uVar2 << 1;
      iVar5 = iVar4 + -0x80;
    }
    uVar3 = iVar5 * 0x1000000 + (uVar2 >> 7) + 1 >> 1;
    if ((uVar2 & 0xff) == 0x80) {
      uVar3 = uVar3 & 0xfffffffe;
    }
    if (iVar5 < 0) {
      uVar3 = 0;
    }
    return uVar3 | (param_1 ^ param_2) & 0x80000000;
  }
  return 0;
}


