/**
 * FUN_0300c2c4 @ 0x0300c2c4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300c2c4(char param_1)

{
  undefined1 unaff_r6;
  int unaff_r7;
  char in_ZR;
  
  if (in_ZR == '\0') {
    param_1 = param_1 + -1;
  }
  else {
    param_1 = '\x02';
  }
  *(char *)(unaff_r7 + 3) = param_1;
  if (*(char *)(unaff_r7 + 5) == '\x01') {
    *(undefined1 *)(unaff_r7 + 5) = unaff_r6;
  }
  FUN_02ffa694(0x149);
  FUN_02ffa6d6(0x14a);
  return;
}


