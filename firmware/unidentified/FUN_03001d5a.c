/**
 * FUN_03001d5a @ 0x03001d5a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03001d5a(void)

{
  ushort *puVar1;
  ushort uVar2;
  
  uVar2 = FUN_03001220();
  puVar1 = DAT_03001e48;
  *DAT_03001e48 = uVar2;
  uVar2 = FUN_030012e6();
  puVar1[puVar1[5] + 1] = uVar2;
  uVar2 = *puVar1;
  if (6 < uVar2) {
    uVar2 = 6;
  }
  puVar1[0xd] = uVar2;
  FUN_030017b4(0);
  return;
}


