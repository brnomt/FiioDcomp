/**
 * FUN_030e632e @ 0x030e632e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030e632e(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = FUN_030e649a();
  iVar3 = DAT_030e63f0;
  if (iVar4 != *(int *)(DAT_030e63f0 + 0x34) + *(int *)(DAT_030e63f0 + 0x30)) {
    iVar4 = FUN_030e649a(param_1);
    buffered_fseek_ovl_0e64(param_1,(*(int *)(iVar3 + 0x34) + *(int *)(iVar3 + 0x30)) - iVar4,1);
  }
  puVar2 = DAT_030e63e4;
  uVar1 = DAT_030e63e0;
  *DAT_030e63e4 = DAT_030e63e0;
  puVar2[1] = 0x4000;
  (*(code *)*DAT_030e63ec)(uVar1,0x4000,*DAT_030e63d4);
  return 0;
}


