/**
 * FUN_0300dce0 @ 0x0300dce0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300dce0(byte *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  iVar5 = 0;
  bVar1 = *param_1;
  while (uVar3 = (uint)bVar1, uVar3 != 0) {
    if (uVar3 < 0x80) {
      pbVar4 = param_2 + 1;
      *param_2 = bVar1;
      iVar5 = iVar5 + 2;
      param_2 = param_2 + 2;
      *pbVar4 = 0;
    }
    else if ((uVar3 & 0x1fe0) == 0xc0) {
      param_1 = param_1 + 1;
      pbVar4 = param_2 + 1;
      *param_2 = *param_1 & 0x3f | (byte)((uVar3 & 0x1f) << 6);
      param_2 = param_2 + 2;
      *pbVar4 = (byte)((uVar3 & 0x1f) >> 2);
      iVar5 = iVar5 + 2;
    }
    else if ((uVar3 & 0xff0) == 0xe0) {
      bVar2 = param_1[1];
      param_1 = param_1 + 2;
      pbVar4 = param_2 + 1;
      *param_2 = *param_1 & 0x3f | (byte)((bVar2 & 0x3f) << 6);
      param_2 = param_2 + 2;
      *pbVar4 = bVar1 << 4 | (byte)((bVar2 & 0x3f) >> 2);
      iVar5 = iVar5 + 2;
    }
    param_1 = param_1 + 1;
    bVar1 = *param_1;
  }
  *param_2 = 0;
  param_2[1] = 0;
  *param_3 = iVar5 + 2;
  return 0;
}


