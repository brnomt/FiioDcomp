/**
 * FUN_0308d6c4 @ 0x0308d6c4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0308d6c4(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  uVar8 = param_2 - 0x18;
  if ((uVar8 < 8) || (iVar2 = wma_input_cache_read(param_1,8,*param_1,param_1[1]), iVar2 != 8)) {
    return 3;
  }
  uVar6 = 8;
  uVar5 = (uint)Reset + (uint)DAT_00000007 * 0x1000000 +
          (uint)bRam00000006 * 0x10000 + (uint)bRam00000005 * 0x100;
  param_1[0x36] = uVar5;
  puVar1 = DAT_0308d978;
  if (uVar8 < uVar5 + 8) {
    return 7;
  }
  if (uVar5 < 0x101) {
    param_1[0x37] = DAT_0308d974;
    uVar7 = 0;
    if (*puVar1 < uVar5) {
      do {
        uVar3 = *puVar1;
        if (uVar5 <= uVar3) {
          uVar3 = uVar5;
        }
        uVar4 = wma_input_cache_read
                          (param_1,param_1[1],*param_1 + uVar6,
                           param_1[1] + (uint)CARRY4(*param_1,uVar6));
        if (uVar4 != uVar3) {
          return 3;
        }
        uVar5 = uVar5 - uVar4;
        uVar6 = uVar6 + uVar4;
        if (param_1[0x36] < uVar7 + uVar4) {
          return 3;
        }
        wma_memmove(param_1[0x37] + uVar7,8);
        uVar7 = uVar7 + uVar4;
      } while (uVar5 != 0);
    }
    else {
      uVar6 = wma_input_cache_read
                        (param_1,param_1[1],*param_1 + 8,param_1[1] + (uint)(0xfffffff7 < *param_1))
      ;
      if (uVar6 != uVar5) {
        return 3;
      }
      wma_memmove(param_1[0x37],8,uVar6);
    }
    uVar5 = *param_1;
    *param_1 = uVar5 + uVar8;
    param_1[1] = param_1[1] + (uint)CARRY4(uVar5,uVar8);
    return 0;
  }
  return 5;
}


