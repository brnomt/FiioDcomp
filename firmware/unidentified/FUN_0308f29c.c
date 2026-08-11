/**
 * FUN_0308f29c @ 0x0308f29c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308f29c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_0308f6a8;
  iVar1 = 0;
  if (param_1 != 0) {
    iVar1 = param_2;
  }
  if (-1 < iVar1) {
    wma_memclr(DAT_0308f6a8,0x1e0);
    return uVar2;
  }
  return 0;
}


