/**
 * FUN_0306f944 @ 0x0306f944
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


bool FUN_0306f944(char *param_1)

{
  byte bVar1;
  
  if ((((*param_1 == -1) && (bVar1 = param_1[1], (~bVar1 & 0xe0) == 0)) &&
      ((bVar1 & 0x18) != 8 && (bVar1 & 6) != 0)) &&
     ((bVar1 = param_1[2], (bVar1 & 0xf0) != 0 && ((~bVar1 & 0xf0) != 0)))) {
    return (~bVar1 & 0xc) != 0;
  }
  return false;
}


