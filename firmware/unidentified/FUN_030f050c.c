/**
 * FUN_030f050c @ 0x030f050c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030f050c(int *param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  param_1[3] = param_1[3] - param_2;
  uVar6 = param_1[2];
  uVar5 = (1 << (uVar6 & 0xff)) - 1;
  iVar4 = *param_1;
  iVar3 = param_1[1];
  if ((int)uVar6 < param_2) {
    bVar1 = *(byte *)(iVar4 + iVar3);
    uVar7 = param_2 - uVar6 & 0xff;
    param_1[1] = iVar3 + 1;
    param_1[2] = 8;
    bVar2 = *(byte *)(iVar4 + iVar3 + 1);
    uVar6 = 8 - uVar7;
    param_1[2] = uVar6;
    return (uint)(bVar2 >> (uVar6 & 0xff)) + ((uVar5 & bVar1) << uVar7) & 0xff;
  }
  bVar1 = *(byte *)(iVar4 + iVar3);
  param_1[2] = uVar6 - param_2;
  return (bVar1 & uVar5) >> (uVar6 - param_2 & 0xff);
}


