/**
 * FUN_03002d56 @ 0x03002d56
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03002d56(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  ushort unaff_r6;
  ushort *unaff_r7;
  short *unaff_r8;
  ushort *unaff_r10;
  
  param_1 = param_1 * 2;
  if (*(ushort *)(param_1 + 0xc) < param_3) {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) + 1;
    if (unaff_r7[0xb] < 5) {
      unaff_r7[0xb] = unaff_r7[0xb] + 1;
      uVar1 = 0x174;
    }
    else {
      FUN_030017b4(2);
LAB_03002dc6:
      uVar1 = 0x173;
    }
  }
  else {
    *(ushort *)(param_1 + 0xc) = unaff_r6;
    unaff_r7[0xb] = unaff_r6;
    if (*unaff_r8 == 8 || *unaff_r8 == 0xc) {
      if (6 < *unaff_r7) {
        FUN_03001d5a();
        goto LAB_03002dc6;
      }
    }
    else if (6 < *unaff_r7) {
      FUN_03001d5a();
      FUN_02ff008c(0x173);
      FUN_02ff00ce(0x1d8);
      FUN_02ff00ce(0x1d9);
      *unaff_r10 = unaff_r6;
      goto LAB_03002db4;
    }
    uVar1 = 0x174;
  }
  FUN_02ff008c(uVar1);
LAB_03002db4:
  FUN_02ff008c(0x18d);
  return;
}


