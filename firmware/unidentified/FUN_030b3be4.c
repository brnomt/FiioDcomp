/**
 * FUN_030b3be4 @ 0x030b3be4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


byte * FUN_030b3be4(int param_1,int param_2,uint param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  param_1 = param_1 + *(int *)(param_2 + 0x18) * 2;
  iVar4 = 0;
  uVar1 = 0;
  uVar3 = 0x20;
  iVar2 = 0;
  pbVar7 = (byte *)(param_2 + 4);
  do {
    if (0x7fff < iVar2) {
      return (byte *)0x0;
    }
    iVar5 = iVar4 + uVar1;
    iVar4 = iVar5 * 2;
    param_1 = param_1 + uVar1 * 2;
    uVar3 = uVar3 - 1;
    pbVar8 = pbVar7 + 1;
    uVar1 = (uint)*pbVar7;
    uVar6 = (param_3 >> (uVar3 & 0xff)) + iVar5 * -2;
    iVar2 = iVar2 + 1;
    pbVar7 = pbVar8;
  } while (uVar1 <= uVar6);
  *param_4 = (int)*(short *)(param_1 + uVar6 * 2);
  return pbVar8 + (-4 - param_2);
}


