/**
 * FUN_0308e460 @ 0x0308e460
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_0308e460(uint *param_1,int param_2,int param_3,undefined1 *param_4,uint param_5,
            undefined4 *param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  uint *puVar4;
  undefined1 *puVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 local_60 [64];
  
  if (((param_2 != 0 && param_3 != 0) &&
      ((param_4 != (undefined1 *)0x0 && param_5 != 0) && param_6 != (undefined4 *)0x0)) &&
     ((int)param_5 < 0x41)) {
    wma_memclr(param_1 + 0xad,0x60);
    FUN_03083faa(param_1 + 0x2b,param_3,param_2);
    FUN_03083f5c(param_1 + 0x2b,0x60,param_1 + 0xad);
    if (0 < (int)(param_5 - 1)) {
      puVar3 = param_4 + -1;
      puVar5 = (undefined1 *)((int)&local_64 + 3);
      if ((param_5 & 1) == 0) {
        local_60[0] = *param_4;
        puVar3 = param_4;
        puVar5 = local_60;
      }
      uVar1 = puVar3[1];
      for (iVar7 = (int)(param_5 - 1) >> 1; iVar7 != 0; iVar7 = iVar7 + -1) {
        uVar2 = puVar3[2];
        puVar5[1] = uVar1;
        uVar1 = puVar3[3];
        puVar5 = puVar5 + 2;
        *puVar5 = uVar2;
        puVar3 = puVar3 + 2;
      }
    }
    iVar7 = param_5 - 1;
    if (-1 < iVar7) {
      local_60[iVar7] = param_4[iVar7];
    }
    iVar8 = (int)(short)((short)param_5 + 7U & 0xfff8) >> 2;
    puVar4 = param_1 + 0xac;
    iVar7 = 6;
    puVar6 = param_1;
    do {
      iVar7 = iVar7 + -1;
      puVar6[1] = puVar4[1] | 1;
      puVar4 = puVar4 + 2;
      puVar6 = puVar6 + 2;
      *puVar6 = *puVar4 | 1;
    } while (iVar7 != 0);
    FUN_030903c0(local_60,iVar8,&local_68,param_1 + 1);
    *param_6 = local_68;
    param_6[1] = local_64;
    puVar4 = param_1 + 0xba;
    param_1[1] = param_1[0xad] + 0xc | 1;
    puVar6 = param_1 + 2;
    param_1[2] = param_1[0xba] | 1;
    iVar7 = 5;
    do {
      iVar7 = iVar7 + -1;
      puVar6[1] = puVar4[1] | 1;
      puVar4 = puVar4 + 2;
      puVar6 = puVar6 + 2;
      *puVar6 = *puVar4 | 1;
    } while (iVar7 != 0);
    FUN_030903c0(local_60,iVar8,&local_68,param_1 + 1);
    param_6[2] = local_68;
    param_6[3] = local_64;
    return 0;
  }
  return 1;
}


