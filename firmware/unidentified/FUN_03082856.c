/**
 * FUN_03082856 @ 0x03082856
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_03082856(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar4 = param_1 ^ param_2;
  uVar1 = param_1;
  if (param_1 << 1 < param_2 << 1) {
    uVar1 = param_2;
    param_2 = param_1;
  }
  if ((param_2 & 0x7fffffff) == 0) {
    return uVar1;
  }
  uVar6 = uVar1 >> 0x17;
  uVar7 = (uVar6 & 0xff) - ((param_2 & 0x7fffffff) >> 0x17);
  if ((int)uVar7 < 0x20) {
    uVar5 = param_2 & 0x7fffff | 0x800000;
    if ((int)uVar4 < 0) {
      uVar5 = -uVar5;
    }
    uVar3 = uVar5 << (0x20 - uVar7 & 0xff);
    uVar1 = uVar1 + ((int)uVar5 >> (uVar7 & 0xff));
    if (uVar6 != uVar1 >> 0x17) {
      if ((int)uVar4 < 0) {
        iVar2 = uVar1 + uVar6 * -0x800000;
        if ((int)uVar7 < 2) {
          iVar2 = iVar2 + 0x800000;
          iVar8 = LZCOUNT(iVar2);
          uVar1 = iVar2 << iVar8;
          if (uVar1 == 0 && uVar3 == 0) {
            return uVar1;
          }
          if (uVar3 != 0) {
            uVar1 = uVar1 | (uint)(uVar3 << iVar8 != 0) | uVar3 >> (0x20U - iVar8 & 0xff);
          }
          iVar2 = ((uVar6 & 0xff) - iVar8) + 7;
          if (-1 < iVar2) {
            uVar4 = (uVar1 >> 8) + iVar2 * 0x800000 + (uVar6 & 0x100) * 0x800000;
            if ((int)(uVar1 * 0x1000000) < 0) {
              uVar4 = uVar4 + 1;
              if ((uVar1 & 0x7f) == 0) {
                uVar4 = uVar4 & 0xfffffffe;
              }
              return uVar4;
            }
            return uVar4;
          }
          return 0;
        }
        uVar1 = iVar2 * 2 + uVar6 * 0x800000 | uVar3 >> 0x1f;
        uVar3 = uVar3 << 1;
      }
      else {
        uVar3 = uVar3 >> 1 | uVar1 * -0x80000000;
        uVar1 = (uVar1 + uVar6 * -0x800000 + 0x800000 >> 1) + uVar6 * 0x800000;
      }
    }
  }
  else {
    uVar3 = ((int)uVar4 >> 0x1f) * 2 + 1;
    uVar1 = uVar1 + ((int)uVar4 >> 0x1f);
  }
  if ((int)uVar3 < 0) {
    uVar1 = uVar1 + 1;
    if ((uVar3 & 0x7fffffff) == 0) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    return uVar1;
  }
  return uVar1;
}


