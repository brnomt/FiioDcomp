/**
 * FUN_030b0272 @ 0x030b0272
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030b0272(undefined4 param_1,int param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puStack_20;
  
  iVar1 = DAT_030b03dc;
  iVar4 = 0;
  if ((param_2 != 0 && param_3 != (uint *)0x0) && (param_4 == (uint *)0x0)) {
    return -1;
  }
  if (*(int *)(param_2 + 0x84) == 0) {
    uVar5 = *param_4;
    puStack_20 = param_4;
    if ((uVar5 == *(int *)(DAT_030b03dc + 0x10) + 1U) &&
       (*param_3 == *(uint *)(DAT_030b03dc + 0x14))) {
      puVar2 = *(undefined4 **)(DAT_030b03dc + 0x2c);
      buffered_fseek(*puVar2,(uVar5 - puVar2[2]) * 4 + -4,1);
      puVar2[2] = uVar5;
      buffered_fread(&puStack_20,1,4,*puVar2);
      iVar4 = *(int *)(iVar1 + 0x18) +
              ((int)puStack_20 << 0x18 | ((uint)puStack_20 >> 8 & 0xff) << 0x10 |
               ((uint)puStack_20 >> 0x10 & 0xff) << 8 | (uint)puStack_20 >> 0x18);
    }
    else {
      uVar3 = *param_3;
      if (uVar3 <= uVar5) {
        do {
          puVar2 = *(undefined4 **)(iVar1 + 0x2c);
          buffered_fseek(*puVar2,(uVar3 - puVar2[2]) * 4 + -4,1);
          puVar2[2] = uVar3;
          buffered_fread(&puStack_20,1,4,*puVar2);
          uVar3 = uVar3 + 1;
          iVar4 = iVar4 + ((int)puStack_20 << 0x18 | ((uint)puStack_20 >> 8 & 0xff) << 0x10 |
                           ((uint)puStack_20 >> 0x10 & 0xff) << 8 | (uint)puStack_20 >> 0x18);
        } while (uVar3 <= *param_4);
      }
    }
  }
  else {
    iVar4 = ((*param_4 - *param_3) + 1) * *(int *)(param_2 + 0x84);
  }
  *(uint *)(iVar1 + 0x10) = *param_4;
  *(uint *)(iVar1 + 0x14) = *param_3;
  *(int *)(iVar1 + 0x18) = iVar4;
  return iVar4;
}


