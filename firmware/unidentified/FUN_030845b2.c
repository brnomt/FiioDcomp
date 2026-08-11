/**
 * FUN_030845b2 @ 0x030845b2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030845b2(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = 8 - param_2;
  if ((*(int *)(param_1 + 0x30) == 0) && (*(int *)(param_1 + 0x28) + uVar2 < 0x21)) {
    while( true ) {
      if (*(int *)(param_1 + 0x20) == 0) {
        return;
      }
      uVar2 = *(int *)(param_1 + 0x28) + (8 - param_2);
      if (0x20 < uVar2) break;
      pbVar3 = *(byte **)(param_1 + 0x1c);
      *(byte **)(param_1 + 0x1c) = pbVar3 + 1;
      bVar1 = *pbVar3;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
      *(uint *)(param_1 + 0x24) =
           ((uint)bVar1 << (param_2 & 0xff) & 0xff) >> (param_2 & 0xff) |
           *(int *)(param_1 + 0x24) << (8 - param_2 & 0xff);
      *(uint *)(param_1 + 0x28) = uVar2;
      param_2 = 0;
    }
    return;
  }
  pbVar3 = *(byte **)(param_1 + 0x1c);
  *(byte **)(param_1 + 0x1c) = pbVar3 + 1;
  bVar1 = *pbVar3;
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  *(uint *)(param_1 + 0x2c) =
       *(int *)(param_1 + 0x2c) << (uVar2 & 0xff) |
       ((uint)bVar1 << (param_2 & 0xff) & 0xff) >> (param_2 & 0xff);
  *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar2;
  return;
}


