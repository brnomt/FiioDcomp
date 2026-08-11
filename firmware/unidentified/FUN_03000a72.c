/**
 * FUN_03000a72 @ 0x03000a72
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03000a72(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_03000e44;
  if (param_1 < *(byte *)(DAT_03000e44 + 4)) {
    if (*(byte *)(DAT_03000e44 + 2) != param_1) {
      *(byte *)(DAT_03000e44 + 3) = *(byte *)(DAT_03000e44 + 2);
      *(char *)(iVar1 + 2) = (char)param_1;
      *(byte *)(iVar1 + 5) = (char)param_1 + (*(byte *)(iVar1 + 5) / 6) * '\x06';
      rom_hw_init2(0x171);
      FUN_03000546();
      FUN_02febbec();
    }
    uVar2 = DAT_03000e48;
    rom_hw_init2(0x3e);
    return uVar2;
  }
  return 0;
}


