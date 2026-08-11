/**
 * FUN_030b1532 @ 0x030b1532
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030b1532(undefined4 *param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  
  puVar2 = DAT_030b173c;
  iVar3 = param_1[3];
  if (iVar3 < 0) {
    param_1[3] = 0;
    *puVar2 = 1;
    return;
  }
  *DAT_030b173c = 0;
  if (3 < iVar3) {
    pbVar4 = (byte *)*param_1;
    *param_1 = pbVar4 + 1;
    bVar1 = *pbVar4;
    *param_1 = pbVar4 + 2;
    param_1[1] = (uint)bVar1 << 0x18;
    uVar5 = (uint)bVar1 << 0x18 | (uint)pbVar4[1] << 0x10;
    *param_1 = pbVar4 + 3;
    param_1[1] = uVar5;
    uVar5 = uVar5 | (uint)pbVar4[2] << 8;
    *param_1 = pbVar4 + 4;
    param_1[1] = uVar5;
    param_1[1] = pbVar4[3] | uVar5;
    param_1[2] = 0x20;
    param_1[3] = iVar3 + -4;
    return;
  }
  uVar5 = iVar3 - 1;
  param_1[1] = 0;
  if (-1 < (int)uVar5) {
    do {
      uVar5 = uVar5 - 1;
      bVar1 = *(byte *)*param_1;
      *param_1 = (byte *)*param_1 + 1;
      param_1[1] = (param_1[1] | (uint)bVar1) << 8;
    } while (uVar5 < 0x80000000);
  }
  param_1[1] = param_1[1] << ((3 - iVar3) * 8 & 0xffU);
  param_1[2] = iVar3 << 3;
  param_1[3] = 0;
  return;
}


