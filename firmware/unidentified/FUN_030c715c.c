/**
 * FUN_030c715c @ 0x030c715c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c715c(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  *(undefined4 *)(param_2 + 0x48) = 0;
  if (*(int *)(param_2 + 0x30) <= *(int *)(param_2 + 0x44)) {
    return;
  }
  do {
    iVar1 = *(int *)(param_2 + 0x44);
    *(int *)(param_2 + 0x44) = iVar1 + 1;
    iVar1 = sbuf_byte_at(param_1,iVar1 + 0x1b);
    uVar2 = *(int *)(param_2 + 0x48) + iVar1;
    *(uint *)(param_2 + 0x48) = uVar2;
    if (iVar1 < 0xff) {
      *(uint *)(param_2 + 0x48) = uVar2 | 0x80000000;
      *(undefined4 *)(param_2 + 0x40) = 1;
      return;
    }
  } while (*(int *)(param_2 + 0x44) < *(int *)(param_2 + 0x30));
  return;
}


