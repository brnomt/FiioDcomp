/**
 * FUN_0304f57c @ 0x0304f57c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 * FUN_0304f57c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = DAT_0304f8d0;
  *DAT_0304f8d0 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  uVar2 = FUN_0304f8f0();
  *puVar1 = uVar2;
  puVar1[2] = 0xffffffff;
  return puVar1;
}


