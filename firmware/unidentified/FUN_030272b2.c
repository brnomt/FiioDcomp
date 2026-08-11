/**
 * FUN_030272b2 @ 0x030272b2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030272b2(int param_1)

{
  int iVar1;
  int unaff_r4;
  int unaff_r6;
  int unaff_r7;
  char in_ZR;
  
  while (in_ZR == '\0' || param_1 != 0xd8) {
    unaff_r4 = unaff_r4 + -1;
    if (unaff_r4 == 0) goto LAB_030272c4;
    iVar1 = mp3_bitstream_getbits(8);
    in_ZR = param_1 == 0xff;
    param_1 = iVar1;
  }
  if (*DAT_030273f8 >> 8 != 0xff) {
LAB_030272c4:
    unaff_r6 = unaff_r7;
  }
  if (unaff_r6 != 0) {
    return unaff_r6;
  }
  iVar1 = FMControlTask_Enter();
  if (iVar1 == 0xc0 || iVar1 == 0xc1) {
    iVar1 = AudioShellTest();
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else if (iVar1 == 0xc2) {
    return -0xea;
  }
  return 0;
}


