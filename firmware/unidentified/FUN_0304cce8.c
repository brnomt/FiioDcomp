/**
 * FUN_0304cce8 @ 0x0304cce8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0304cce8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0304cddc;
  iVar2 = 9;
  do {
    if (*(char *)(iVar1 + iVar2) == '\0') {
      FUN_0304c68c(param_1,param_2,iVar2,param_3);
    }
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  return;
}


