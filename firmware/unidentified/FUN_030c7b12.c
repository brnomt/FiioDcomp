/**
 * FUN_030c7b12 @ 0x030c7b12
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c7b12(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_030c8f90(*(undefined4 *)(iVar1 + 0x20));
  iVar2 = 0;
  if (0 < *(int *)(iVar1 + 0x10)) {
    do {
      if (*(char *)(*(int *)(iVar1 + 0x24) + iVar2) == '\0') {
        FUN_030c49ce(*(undefined4 *)(*(int *)(iVar1 + 0x28) + iVar2 * 4));
      }
      else {
        FUN_030c4d94();
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(iVar1 + 0x10));
  }
  FUN_030ca4d8(*(undefined4 *)(iVar1 + 0x2c));
  FUN_030c27f4(*(undefined4 *)(iVar1 + 0x30));
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  memset_byte(DAT_030c7bac,0,2);
  memset_byte(DAT_030c7bb0,0,2);
  memset_byte(DAT_030c7bb4,0,2);
  memset_byte(DAT_030c7bb8,0,2);
  memset_byte(DAT_030c7bbc,0,0x2c);
  memset_byte(DAT_030c7ba8,0,0x34);
  memset_byte(param_1,0,0x20);
  return;
}


