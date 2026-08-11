/**
 * FUN_0304cb7c @ 0x0304cb7c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0304cb7c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0304cddc;
  iVar2 = 0x14;
  do {
    if (*(char *)(iVar1 + iVar2 + 10) == '\0') {
      FUN_0304c7a8(param_2,param_1,DAT_0304cdd4,iVar2 << 1,param_3);
    }
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}


