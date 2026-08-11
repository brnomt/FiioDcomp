/**
 * FUN_030c3da8 @ 0x030c3da8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c3da8(uint *param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
  puVar1 = (undefined4 *)FUN_030ca4a0(*param_1 << 2);
  iVar6 = 0;
  if (0 < param_4) {
    do {
      iVar2 = FUN_030c3a52(param_1,param_3,puVar1,param_5);
      if (iVar2 != 0) {
        FUN_030ca488();
        return 0xffffffff;
      }
      if (0 < (int)*param_1) {
        puVar3 = (undefined4 *)(param_2 + iVar6 * 4);
        puVar4 = puVar3 + -1;
        puVar5 = puVar1 + -1;
        if ((*param_1 & 1) != 0) {
          *puVar3 = *puVar1;
          puVar4 = puVar3;
          puVar5 = puVar1;
        }
        for (iVar2 = (int)*param_1 >> 1; iVar2 != 0; iVar2 = iVar2 + -1) {
          puVar4[1] = puVar5[1];
          puVar5 = puVar5 + 2;
          puVar4 = puVar4 + 2;
          *puVar4 = *puVar5;
        }
        iVar6 = iVar6 + *param_1;
      }
    } while (iVar6 < param_4);
  }
  FUN_030ca488();
  return 0;
}


