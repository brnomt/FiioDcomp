/**
 * FUN_030c6afc @ 0x030c6afc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c6afc(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_18 [20];
  
  iVar1 = FUN_030c68e6(auStack_18,*param_1);
  if (iVar1 == 0) {
    uVar2 = sbuf_byte_at(auStack_18,4);
    return uVar2;
  }
  return 0xffffffff;
}


