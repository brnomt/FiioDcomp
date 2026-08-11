/**
 * FUN_0306d42c @ 0x0306d42c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0306d42c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (((param_1 & 0x7fffffff) != 0) && ((param_2 & 0x7fffffff) != 0)) {
    iVar5 = ((param_1 & 0x7fffffff) >> 0x17) - ((param_2 & 0x7fffffff) >> 0x17);
    uVar2 = param_1 & 0x7fffff | 0x800000;
    uVar3 = param_2 & 0x7fffff | 0x800000;
    iVar6 = iVar5 + 0x7d;
    if (uVar2 < uVar3) {
      uVar2 = uVar2 << 1;
    }
    else {
      iVar6 = iVar5 + 0x7e;
    }
    if (-1 < iVar6) {
      uVar1 = 0x800000;
      uVar4 = 0;
      do {
        if (uVar3 <= uVar2) {
          uVar2 = uVar2 - uVar3;
          uVar4 = uVar4 | uVar1;
        }
        uVar1 = uVar1 >> 1;
        uVar2 = uVar2 * 2;
      } while (uVar1 != 0);
      uVar1 = 0;
      if (uVar2 != 0) {
        if (uVar2 == uVar3) {
          uVar1 = 0x80000000;
        }
        else if (uVar2 < uVar3) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0xfffffffe;
        }
      }
      uVar2 = uVar4 + iVar6 * 0x800000 + ((param_1 ^ param_2) & 0x80000000);
      if (-1 < (int)uVar1) {
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      if ((uVar1 & 0x7fffffff) == 0) {
        uVar2 = uVar2 & 0xfffffffe;
      }
      return uVar2;
    }
  }
  return 0;
}


