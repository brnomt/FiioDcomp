/**
 * FUN_030e7fb8 @ 0x030e7fb8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e7fb8(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = (uint)*(byte *)(param_1 + 0x3a);
  uVar6 = 0;
  iVar4 = 0;
  if (0 < param_3) {
    do {
      FUN_030e6372(param_1,0x20);
      iVar1 = FUN_030e59fa((uVar5 >> 9) + 3 | 1);
      uVar3 = 0x1fU - iVar1;
      if ((int)(uint)*(byte *)(param_1 + 0x3b) < (int)(0x1fU - iVar1)) {
        uVar3 = (uint)*(byte *)(param_1 + 0x3b);
      }
      uVar2 = FUN_030e59c8(param_1);
      if (uVar2 < 9) {
        if (uVar3 != 1) {
          iVar1 = FUN_030e581a(param_1,uVar3);
          uVar2 = (uVar2 << (uVar3 & 0xff)) - uVar2;
          if (iVar1 < 2) {
            FUN_030e584a(param_1,uVar3 - 1);
          }
          else {
            uVar2 = (iVar1 + uVar2) - 1;
            FUN_030e584a(param_1,uVar3);
          }
        }
      }
      else {
        uVar2 = FUN_030e58a0(param_1,param_4);
      }
      uVar2 = uVar2 + uVar6;
      uVar6 = 0;
      *(uint *)(param_2 + iVar4 * 4) = -(uVar2 & 1) ^ uVar2 >> 1;
      if (uVar2 < 0x10000) {
        uVar5 = uVar5 + (uVar2 * param_5 - (uVar5 * param_5 >> 9));
        if ((uVar5 < 0x80) && (iVar4 + 1 < param_3)) {
          iVar1 = FUN_030e59fa(uVar5 | 1);
          uVar5 = (iVar1 + (uVar5 + 0x10 >> 6)) - 0x18;
          if ((int)(uint)*(byte *)(param_1 + 0x3b) < (int)uVar5) {
            uVar5 = (uint)*(byte *)(param_1 + 0x3b);
          }
          uVar6 = FUN_030e59c8(param_1);
          if (uVar6 < 9) {
            if (uVar5 != 1) {
              iVar1 = FUN_030e581a(param_1,uVar5);
              uVar6 = (uVar6 << (uVar5 & 0xff)) - uVar6;
              if (iVar1 < 2) {
                FUN_030e584a(param_1,uVar5 - 1);
              }
              else {
                uVar6 = (iVar1 + uVar6) - 1;
                FUN_030e584a(param_1,uVar5);
              }
            }
          }
          else {
            uVar6 = FUN_030e58a0(param_1,0x10);
          }
          if (0 < (int)uVar6) {
            if (param_3 - iVar4 <= (int)uVar6) {
              uVar6 = (param_3 - iVar4) - 1;
            }
            FUN_030e422e(param_2 + iVar4 * 4 + 4,0,uVar6 << 2);
            iVar4 = iVar4 + uVar6;
          }
          uVar6 = (uint)((int)uVar6 < 0x10000);
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 0xffff;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_3);
  }
  return 0;
}


