/**
 * FUN_0308d2e8 @ 0x0308d2e8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0308d2e8(uint *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  uVar4 = param_2 - 0x18;
  param_1[0x25] = 0;
  if ((3 < uVar4) && (iVar1 = wma_input_cache_read(param_1,param_2,*param_1,param_1[1]), iVar1 == 4)
     ) {
    uVar5 = 4;
    uVar6 = (uint)MasterStackPointer + (uint)bRam00000003 * 0x1000000 +
            (uint)bRam00000002 * 0x10000 + (uint)bRam00000001 * 0x100;
    param_1[0x25] = uVar6;
    if (uVar6 < 0x21) {
      if (uVar6 != 0) {
        if (uVar4 < uVar6 + 4) {
          return 3;
        }
        uVar2 = wma_input_cache_read
                          (param_1,param_1[1],*param_1 + 4,
                           param_1[1] + (uint)(0xfffffffb < *param_1));
        if (uVar2 != uVar6) {
          return 3;
        }
        uVar5 = uVar2 + 4;
        if (0x20 < uVar2) {
          return 3;
        }
        wma_memmove((int)param_1 + 0x72,4);
      }
      if ((uVar5 + 4 <= uVar4) &&
         (iVar1 = wma_input_cache_read
                            (param_1,param_1[1],*param_1 + uVar5,
                             param_1[1] + (uint)CARRY4(*param_1,uVar5)), iVar1 == 4)) {
        uVar5 = uVar5 + 4;
        uVar6 = (uint)Reset + (uint)DAT_00000007 * 0x1000000 +
                (uint)bRam00000006 * 0x10000 + (uint)bRam00000005 * 0x100;
        if (uVar6 != 0) {
          if (uVar4 < uVar5 + uVar6) {
            return 3;
          }
          uVar2 = wma_input_cache_read
                            (param_1,param_1[1],*param_1 + uVar5,
                             param_1[1] + (uint)CARRY4(*param_1,uVar5));
          if (uVar2 != uVar6) {
            return 3;
          }
          uVar5 = uVar5 + uVar2;
          if (0x10 < uVar2) {
            return 3;
          }
          wma_memmove(param_1 + 0x26,8);
        }
        if ((uVar5 + 4 <= uVar4) &&
           (iVar1 = wma_input_cache_read
                              (param_1,param_1[1],*param_1 + uVar5,
                               param_1[1] + (uint)CARRY4(*param_1,uVar5)), iVar1 == 4)) {
          uVar5 = uVar5 + 4;
          uVar6 = (uint)NMI + (uint)DAT_0000000b * 0x1000000 +
                  (uint)bRam0000000a * 0x10000 + (uint)DAT_00000009 * 0x100;
          if (uVar6 != 0) {
            if (uVar4 < uVar5 + uVar6) {
              return 3;
            }
            uVar2 = wma_input_cache_read
                              (param_1,param_1[1],*param_1 + uVar5,
                               param_1[1] + (uint)CARRY4(*param_1,uVar5));
            if (uVar2 != uVar6) {
              return 3;
            }
            uVar5 = uVar5 + uVar2;
            if (0x20 < uVar2) {
              return 3;
            }
            wma_memmove(param_1 + 0x2a,0xc);
          }
          if ((uVar5 + 4 <= uVar4) &&
             (iVar1 = wma_input_cache_read
                                (param_1,param_1[1],*param_1 + uVar5,
                                 param_1[1] + (uint)CARRY4(*param_1,uVar5)), iVar1 == 4)) {
            uVar5 = uVar5 + 4;
            iVar1 = (uint)HardFault + (uint)bRam0000000f * 0x1000000 +
                    (uint)bRam0000000e * 0x10000 + (uint)DAT_0000000d * 0x100;
            if (iVar1 != 0) {
              if (uVar4 < uVar5 + iVar1) {
                return 3;
              }
              do {
                iVar3 = wma_input_cache_read
                                  (param_1,param_1[1],*param_1 + uVar5,
                                   param_1[1] + (uint)CARRY4(*param_1,uVar5));
                uVar5 = uVar5 + iVar3;
                iVar1 = iVar1 - iVar3;
              } while (iVar1 != 0);
            }
            uVar5 = *param_1;
            *param_1 = uVar5 + uVar4;
            param_1[1] = param_1[1] + (uint)CARRY4(uVar5,uVar4);
            return 0;
          }
        }
      }
    }
  }
  return 3;
}


