/**
 * FUN_0308458c @ 0x0308458c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


char FUN_0308458c(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((*(int *)(iVar1 + 0x40) < 3) && (*(int *)(iVar1 + 0x70) != 0)) {
    return *(char *)(iVar1 + 0xc) + '\v';
  }
  return '\0';
}


