/**
 * FUN_030bfad4 @ 0x030bfad4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030bfad4(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  pbVar3 = param_1;
  if (*param_1 == 0x2d || *param_1 == 0x2b) {
    pbVar3 = param_1 + 1;
  }
  bVar1 = *pbVar3;
  while ((uVar2 = (uint)bVar1, uVar2 != 0 && (uVar2 - 0x30 < 10))) {
    iVar4 = iVar4 * 10 + -0x30 + uVar2;
    pbVar3 = pbVar3 + 1;
    bVar1 = *pbVar3;
  }
  if (*param_1 == 0x2d) {
    iVar4 = -iVar4;
  }
  return iVar4;
}


