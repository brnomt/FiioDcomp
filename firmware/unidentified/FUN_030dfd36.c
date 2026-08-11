/**
 * FUN_030dfd36 @ 0x030dfd36
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030dfd36(byte *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = 0;
  if (0 < (int)(param_2 - 1)) {
    pbVar3 = param_1 + -1;
    if ((param_2 & 1) == 0) {
      uVar2 = (uint)*(byte *)(DAT_030dff1c + (uint)*param_1);
      pbVar3 = param_1;
    }
    bVar1 = pbVar3[1];
    for (iVar5 = (int)(param_2 - 1) >> 1; iVar5 != 0; iVar5 = iVar5 + -1) {
      uVar4 = (uint)bVar1;
      bVar1 = pbVar3[3];
      uVar2 = (uint)*(byte *)(DAT_030dff1c +
                             (uint)(*(byte *)(DAT_030dff1c + (uVar2 ^ uVar4)) ^ pbVar3[2]));
      pbVar3 = pbVar3 + 2;
    }
  }
  if ((int)(param_2 - 1) < 0) {
    return uVar2;
  }
  return (uint)*(byte *)(DAT_030dff1c + (uVar2 ^ param_1[param_2 - 1]));
}


