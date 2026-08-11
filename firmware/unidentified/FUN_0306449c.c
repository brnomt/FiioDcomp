/**
 * FUN_0306449c @ 0x0306449c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306449c(void)

{
  int iVar1;
  
  iVar1 = DAT_0306487c;
  FUN_0306444c(*(undefined2 *)(*(int *)(DAT_0306487c + 0x14) + 2),10);
  iVar1 = *(int *)(iVar1 + 0x14);
  *(uint *)(iVar1 + 0xc) =
       (uint)((ulonglong)DAT_03064880 * (ulonglong)*(uint *)(iVar1 + 0xc) >> 0x23) * 10;
  *(undefined2 *)(iVar1 + 10) = 0;
  return;
}


