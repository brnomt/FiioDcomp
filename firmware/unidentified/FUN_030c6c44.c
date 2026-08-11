/**
 * FUN_030c6c44 @ 0x030c6c44
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int * FUN_030c6c44(void)

{
  int *piVar1;
  
  piVar1 = DAT_030c701c;
  memset_byte(DAT_030c701c,0,0x1c);
  memset_byte(piVar1 + -4,0,0x10);
  *piVar1 = (int)(piVar1 + -4);
  return piVar1;
}


