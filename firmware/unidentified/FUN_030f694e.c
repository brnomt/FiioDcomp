/**
 * FUN_030f694e @ 0x030f694e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030f694e(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = LZCOUNT(param_1);
  uVar1 = param_1 << iVar3;
  if (uVar1 == 0 && param_2 == 0) {
    return uVar1;
  }
  if (param_2 != 0) {
    uVar1 = uVar1 | (uint)(param_2 << iVar3 != 0) | param_2 >> (0x20U - iVar3 & 0xff);
  }
  iVar3 = (param_4 - iVar3) + 7;
  if (-1 < iVar3) {
    uVar2 = (uVar1 >> 8) + iVar3 * 0x800000 + param_3;
    if ((int)(uVar1 * 0x1000000) < 0) {
      uVar2 = uVar2 + 1;
      if ((uVar1 & 0x7f) == 0) {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return uVar2;
    }
    return uVar2;
  }
  return 0;
}


