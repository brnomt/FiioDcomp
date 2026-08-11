/**
 * FUN_03001694 @ 0x03001694
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03001694(int param_1,short param_2,undefined4 param_3,undefined4 param_4)

{
  short in_r12;
  undefined4 uStack00000000;
  undefined4 uStack00000004;
  undefined4 uStack00000008;
  undefined4 uStack0000000c;
  uint uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  
  uStack00000010 = (uint)(ushort)(param_2 + in_r12);
  uStack00000000 = *(undefined4 *)(param_1 + 0x1c);
  uStack00000004 = *(undefined4 *)(param_1 + 0x20);
  uStack00000008 = *(undefined4 *)(param_1 + 0x24);
  uStack0000000c = *(undefined4 *)(param_1 + 0x28);
  uStack00000014 = param_4;
  uStack00000018 = param_3;
  uStack0000001c = param_3;
  parse_v22_frame();
  FUN_02fe2a80();
  return 0;
}


