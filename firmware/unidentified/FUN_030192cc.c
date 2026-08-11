/**
 * FUN_030192cc @ 0x030192cc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030192cc(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(char *)(DAT_0301963c + 0x12) != '\0') {
    *(char *)(DAT_0301963c + 0x12) = *(char *)(DAT_0301963c + 0x12) + -1;
  }
  puVar1 = DAT_0301964c;
  iVar2 = FUN_02ff2834(*DAT_0301964c,DAT_03019648);
  if (iVar2 == 1) {
    FUN_03020bf0(0xff,0);
  }
  iVar2 = FUN_02ff2834(*puVar1,DAT_03019650);
  if (iVar2 == 1) {
    FUN_0302da66(0xb6,0);
  }
  func_0x030037a8(0x33);
  return 1;
}


