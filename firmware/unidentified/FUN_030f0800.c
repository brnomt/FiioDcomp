/**
 * FUN_030f0800 @ 0x030f0800
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030f0800(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_030f089c;
  piVar1 = DAT_030f0898;
  iVar3 = *DAT_030f0898 + param_1;
  *DAT_030f0898 = iVar3;
  if (iVar2 <= iVar3) {
    log_printf_ts(s_malloc_buf_error__d__d_030f08a0,iVar3,param_1);
  }
  return (*piVar1 - param_1) + DAT_030f08bc;
}


