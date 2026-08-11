/**
 * FUN_03088416 @ 0x03088416
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03088416(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  iVar2 = **(int **)(param_1 + 8);
  if ((*(int *)(iVar2 + 0x40) < 3) && (*(int *)(iVar2 + 0x70) != 0)) {
    uVar3 = (uint)(byte)(*(char *)(iVar2 + 0xc) + 0xb);
  }
  else {
    uVar3 = 0;
  }
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  uVar4 = uVar3 & 7;
  pbVar5 = (byte *)(*(int *)(param_1 + 0x14) + (uVar3 >> 3));
  iVar2 = *(int *)(param_1 + 0x18) - (uVar3 >> 3);
  *(byte **)(param_1 + 0x1c) = pbVar5 + 1;
  *(int *)(param_1 + 0x20) = iVar2;
  bVar1 = *pbVar5;
  *(int *)(param_1 + 0x20) = iVar2 + -1;
  *(uint *)(param_1 + 0x24) = ((uint)bVar1 << uVar4 & 0xff) >> uVar4;
  *(uint *)(param_1 + 0x28) = 8 - uVar4;
  return;
}


