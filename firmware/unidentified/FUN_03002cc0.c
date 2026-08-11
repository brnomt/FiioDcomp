/**
 * FUN_03002cc0 @ 0x03002cc0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03002cc0(uint param_1)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 unaff_r6;
  int unaff_r7;
  undefined2 unaff_r9;
  undefined2 *unaff_r10;
  char in_ZR;
  
  if (in_ZR != '\0') {
    return;
  }
  *(undefined2 *)(unaff_r7 + 0x18) = *(undefined2 *)(unaff_r7 + 0x16);
  iVar3 = unaff_r7 + (uint)*(ushort *)(unaff_r7 + 10) * 2;
  if (*(short *)(iVar3 + 0xc) == 0) {
    sVar1 = (short)param_1 + -1;
    *(short *)(iVar3 + 0xc) = sVar1;
    if (6 < param_1) {
      *(undefined2 *)(unaff_r7 + 0x16) = unaff_r9;
      FUN_03001d5a(param_1);
      FUN_02ff008c(0x173);
      FUN_02ff00ce(0x1d8);
      FUN_02ff00ce(0x1d9);
      *unaff_r10 = unaff_r6;
      goto LAB_03002cf6;
    }
    *(short *)(unaff_r7 + 0x16) = sVar1;
    uVar2 = 0x174;
  }
  else {
    *(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + -1;
    if (*(short *)(unaff_r7 + 0x16) != 0) {
      *(short *)(unaff_r7 + 0x16) = *(short *)(unaff_r7 + 0x16) + -1;
      FUN_02ff008c(0x174);
      goto LAB_03002cf6;
    }
    FUN_030017b4(1);
    uVar2 = 0x173;
  }
  FUN_02ff008c(uVar2);
LAB_03002cf6:
  FUN_02ff008c(0x18d);
  return;
}


