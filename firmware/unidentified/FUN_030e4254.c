/**
 * FUN_030e4254 @ 0x030e4254
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e4254(byte *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    param_3 = 0;
    bVar2 = *param_1;
    pbVar3 = param_1;
    while (bVar2 != 0) {
      pbVar3 = pbVar3 + 1;
      param_3 = param_3 + 1;
      bVar2 = *pbVar3;
    }
    uVar4 = 0;
    bVar2 = *param_2;
    pbVar3 = param_2;
    while (bVar2 != 0) {
      pbVar3 = pbVar3 + 1;
      uVar4 = uVar4 + 1;
      bVar2 = *pbVar3;
    }
    if (uVar4 < param_3) {
      return 1;
    }
    if (param_3 < uVar4) {
      return 0xffffffff;
    }
  }
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    param_3 = param_3 - 1;
    bVar2 = *param_1;
    if (bVar2 == 0) {
      if (*param_2 != 0) {
        return 0xffffffff;
      }
      return 0;
    }
    bVar1 = *param_2;
    if (bVar1 == 0) {
      return 1;
    }
    if (bVar2 >= bVar1 && bVar2 != bVar1) break;
    if (bVar2 < bVar1) {
      return 0xffffffff;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return 1;
}


