/**
 * FUN_0308c8f8 @ 0x0308c8f8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
FUN_0308c8f8(undefined4 param_1,uint *param_2,uint param_3,uint param_4,ushort *param_5,int *param_6
            )

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_r1;
  uint uVar4;
  undefined4 uVar5;
  
  uVar4 = (uint)*param_5;
  uVar3 = param_2[1] + (uint)CARRY4(*param_2,uVar4);
  uVar5 = 0;
  if (uVar3 < param_4 || param_4 - uVar3 < (uint)(*param_2 + uVar4 <= param_3)) {
    iVar2 = *DAT_0308cd24;
    if (0x200 < uVar4 + iVar2) {
      uVar4 = 0x200 - iVar2;
    }
    iVar2 = DAT_0308cd28 + iVar2;
    if (iVar2 == 0) {
      uVar5 = 5;
      uVar3 = 0;
    }
    else {
      wma_memclr(iVar2,uVar4 + 2);
      uVar3 = wma_input_cache_read(param_1,extraout_r1,*param_2,param_2[1]);
      if (uVar3 == uVar4) {
        wma_memmove(iVar2,0,uVar3);
        *DAT_0308cd24 = *DAT_0308cd24 + uVar3;
      }
      else {
        uVar5 = 3;
        uVar3 = 0;
      }
    }
    uVar4 = *param_2;
    uVar1 = *param_5;
    *param_2 = uVar4 + uVar1;
    param_2[1] = param_2[1] + (uint)CARRY4(uVar4,(uint)uVar1);
    *param_5 = (ushort)uVar3;
    *param_6 = iVar2;
    return uVar5;
  }
  return 6;
}


