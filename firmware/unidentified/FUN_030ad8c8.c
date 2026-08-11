/**
 * FUN_030ad8c8 @ 0x030ad8c8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030ad8c8(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  
  uVar1 = *DAT_030adbfc;
  uVar7 = (uVar1 & 0xffffff) >> 0x10;
  uVar5 = (uVar1 & 0xffff) >> 8;
  uVar1 = uVar1 & 0xff;
  if ((int)param_2 < 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = ~param_2 & 1;
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        if (*(byte *)(param_1 + uVar4) == uVar7) {
          uVar6 = param_1 + uVar4;
          bVar8 = *(byte *)(uVar6 + 1) == uVar5;
          if (bVar8) {
            uVar6 = (uint)*(byte *)(uVar6 + 2);
          }
          if (bVar8 && uVar6 == uVar1) {
            return uVar4;
          }
        }
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < (int)uVar2);
    }
  }
  while( true ) {
    if ((int)(param_2 - 1) <= (int)uVar2) {
      return 0xffffffff;
    }
    if (*(byte *)(param_1 + uVar2) == uVar7) {
      uVar4 = param_1 + uVar2;
      bVar8 = *(byte *)(uVar4 + 1) == uVar5;
      if (bVar8) {
        uVar4 = (uint)*(byte *)(uVar4 + 2);
      }
      if (bVar8 && uVar4 == uVar1) {
        return uVar2;
      }
    }
    iVar3 = param_1 + uVar2;
    uVar4 = (uint)*(byte *)(iVar3 + 1);
    bVar8 = uVar4 == uVar7;
    if (bVar8) {
      uVar4 = (uint)*(byte *)(iVar3 + 2);
    }
    bVar9 = bVar8 && uVar4 == uVar5;
    if (bVar8 && uVar4 == uVar5) {
      bVar9 = *(byte *)(iVar3 + 3) == uVar1;
    }
    if (bVar9) break;
    uVar2 = uVar2 + 2;
  }
  return uVar2 + 1;
}


