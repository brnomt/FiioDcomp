/**
 * FUN_0301c3de @ 0x0301c3de
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301c3de(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (char *)FUN_0301c85a(param_1 + 0x1c);
  for (; (pcVar1 < (char *)(*(int *)(param_1 + 4) + -1) &&
         ((*pcVar1 != -1 || ((pcVar1[1] & 0xe0U) != 0xe0)))); pcVar1 = pcVar1 + 1) {
  }
  if (*(int *)(param_1 + 4) - (int)pcVar1 < 8) {
    uVar2 = 0xffffffff;
  }
  else {
    FUN_0301c834(param_1 + 0x1c,pcVar1);
    uVar2 = 0;
  }
  return uVar2;
}


