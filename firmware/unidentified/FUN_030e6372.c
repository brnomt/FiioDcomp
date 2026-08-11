/**
 * FUN_030e6372 @ 0x030e6372
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030e6372(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_030e595c();
  iVar2 = iVar1;
  if (iVar1 < 0) {
    iVar1 = hifi_debug_printf_sync_ovl_0e45(&LAB_030e63f4);
    iVar2 = 0;
  }
  if (param_2 <= iVar2) {
    return iVar1;
  }
  iVar2 = iVar2 + 7 >> 3;
  FUN_030e41fe(*param_1,*param_1 + (param_1[2] >> 3),iVar2);
  iVar2 = (*(code *)*DAT_030e63ec)(*param_1 + iVar2,0x4000 - iVar2,*DAT_030e63d4);
  iVar1 = param_1[2] % 8;
  param_1[2] = iVar1;
  if (iVar2 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}


