/**
 * FUN_03070742 @ 0x03070742
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03070742(int param_1)

{
  char *pcVar1;
  
  pcVar1 = (char *)FUN_03070b86(param_1 + 0x1c);
  while ((pcVar1 < (char *)(*(int *)(param_1 + 4) + -1) &&
         ((*pcVar1 != -1 || ((~pcVar1[1] & 0xe0U) != 0))))) {
    pcVar1 = pcVar1 + 1;
  }
  if (7 < *(int *)(param_1 + 4) - (int)pcVar1) {
    FUN_03070b64(param_1 + 0x1c);
    return 0;
  }
  return 0xffffffff;
}


