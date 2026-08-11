/**
 * FUN_03000a74 @ 0x03000a74
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03000a74(uint param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 < *(byte *)(param_3 + 4)) {
    if (*(byte *)(param_3 + 2) != param_1) {
      *(byte *)(param_3 + 3) = *(byte *)(param_3 + 2);
      *(char *)(param_3 + 2) = (char)param_1;
      *(byte *)(param_3 + 5) = (char)param_1 + (*(byte *)(param_3 + 5) / 6) * '\x06';
      rom_hw_init2(0x171);
      FUN_03000546();
      FUN_02febbec();
    }
    uVar1 = DAT_03000e48;
    rom_hw_init2(0x3e);
    return uVar1;
  }
  return 0;
}


