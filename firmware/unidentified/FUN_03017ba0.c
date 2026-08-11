/**
 * FUN_03017ba0 @ 0x03017ba0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03017ba0(void)

{
  undefined1 local_28;
  undefined2 local_27;
  undefined2 local_25;
  
  local_28 = 0;
  local_27 = 0x38;
  if ((*DAT_03017f64 & 0xff0000) == 0xe80000) {
    local_25 = 0xe0;
  }
  else {
    local_25 = 0x40;
  }
  FUN_02ff26a4(DAT_03017f6c,DAT_03017f68,&local_28);
  func_0x030037a8(0xc1);
  func_0x030037a8(0xb8);
  return 0;
}


