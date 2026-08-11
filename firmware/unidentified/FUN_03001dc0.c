/**
 * FUN_03001dc0 @ 0x03001dc0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03001dc0(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(byte *)(DAT_03001e54 + 0x12) < *(byte *)(DAT_03001e54 + 0x1e)) {
    *(byte *)(DAT_03001e54 + 0x12) = *(byte *)(DAT_03001e54 + 0x12) + 1;
  }
  puVar1 = DAT_03001e5c;
  iVar2 = func_0x02fdf118(*DAT_03001e5c,DAT_03001e58);
  if (iVar2 == 1) {
    FUN_0300d4d4(0xff,0);
  }
  iVar2 = func_0x02fdf118(*puVar1,DAT_03001e60);
  if (iVar2 == 1) {
    FUN_0301a34a(0xb6,0);
  }
  FUN_02ff008c(0x3e);
  return 1;
}


