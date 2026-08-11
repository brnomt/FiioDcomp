/**
 * FUN_030c6b24 @ 0x030c6b24
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030c6b24(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_18 [20];
  
  iVar1 = FUN_030c68e6(auStack_18,*param_1);
  if (iVar1 == 0) {
    uVar2 = sbuf_byte_at(auStack_18,5);
    return uVar2 & 1;
  }
  return 0xffffffff;
}


