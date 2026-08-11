/**
 * FUN_03008160 @ 0x03008160
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03008160(void)

{
  undefined4 unaff_r4;
  int unaff_r6;
  undefined4 unaff_r8;
  bool in_ZR;
  bool in_CY;
  
  if (!in_CY || in_ZR) {
    *DAT_03008500 = (short)unaff_r4;
    *DAT_03008504 = unaff_r8;
    *DAT_03008508 = unaff_r8;
    *(undefined4 *)(unaff_r6 + 8) = unaff_r4;
    DSP_GOODEF_Reload(0x110);
  }
  return;
}


