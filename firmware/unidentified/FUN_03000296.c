/**
 * FUN_03000296 @ 0x03000296
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03000296(undefined4 param_1,uint *param_2)

{
  ushort *unaff_r7;
  int unaff_r9;
  undefined2 uStack00000002;
  
  *param_2 = (uint)*(ushort *)(unaff_r9 + 0x19f);
  func_0x02fdb37c();
  uStack00000002 = *(undefined2 *)(DAT_030005d4 + (uint)*unaff_r7 * 6 + 2);
  FUN_02fef0a6(3);
  rom_hw_init(0x18c);
  return 1;
}


