/**
 * FUN_03019cec @ 0x03019cec
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03019cec(void)

{
  int iVar1;
  int unaff_r4;
  undefined1 unaff_r5;
  undefined4 unaff_r6;
  undefined1 *unaff_r7;
  int unaff_r8;
  undefined4 *unaff_r9;
  undefined1 in_stack_00000008;
  undefined2 uStack00000009;
  
  iVar1 = unaff_r4 - DAT_03019df8;
  if (unaff_r4 == DAT_03019df8) {
    iVar1 = FUN_02ff7890(*unaff_r9,DAT_03019fec);
    if ((iVar1 == 1) && (*(char *)(unaff_r8 + 0x12) != '\0')) {
      *(char *)(unaff_r8 + 0x12) = *(char *)(unaff_r8 + 0x12) + -1;
      FUN_03025c4c(0xff,0);
    }
    iVar1 = FUN_02ff7890(*unaff_r9,DAT_03019fe8);
    if ((iVar1 == 1) && (*(char *)(unaff_r8 + 0x12) != '\0')) {
      *(char *)(unaff_r8 + 0x12) = *(char *)(unaff_r8 + 0x12) + -1;
      FUN_03032ac2(0xb6,0);
    }
  }
  else if (unaff_r4 < DAT_03019df8) {
    if ((iVar1 != -0x1e) && (iVar1 == -0x10)) {
      iVar1 = FUN_02ff7890(*unaff_r9,DAT_03019e04);
      if ((iVar1 == 1) && (*(byte *)(unaff_r8 + 0x12) < *(byte *)(unaff_r8 + 0x1e))) {
        *(byte *)(unaff_r8 + 0x12) = *(byte *)(unaff_r8 + 0x12) + 1;
        FUN_03025c4c(0xff,0);
      }
      iVar1 = FUN_02ff7890(*unaff_r9,DAT_03019fe8);
      if ((iVar1 == 1) && (*(byte *)(unaff_r8 + 0x12) < *(byte *)(unaff_r8 + 0x1e))) {
        *(byte *)(unaff_r8 + 0x12) = *(byte *)(unaff_r8 + 0x12) + 1;
        FUN_03032ac2(0xb6,0);
      }
    }
  }
  else if (iVar1 + DAT_03019dfc == 0) {
    func_0x0301eabe(0x163,0);
    FUN_02ff77e8(DAT_03019de4,DAT_03019de0);
    iVar1 = FUN_03008864(0x157);
    if (iVar1 == 0) {
      in_stack_00000008 = 4;
    }
    else {
      in_stack_00000008 = 6;
    }
    uStack00000009 = *(undefined2 *)(unaff_r8 + 0x221);
    func_0x03008a2e(9,&stack0x00000008);
    unaff_r6 = 1;
  }
  else if ((iVar1 + DAT_03019dfc == 2) && (*(char *)(unaff_r8 + 0x224) == '\0')) {
    *unaff_r7 = unaff_r5;
    func_0x0301eabe(0x163,0);
    func_0x0301eabe(0x165,1);
    FUN_03008804(0x15f);
  }
  return unaff_r6;
}


