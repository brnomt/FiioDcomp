/**
 * FUN_0306b608 @ 0x0306b608
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306b608(ushort param_1)

{
  ushort uVar1;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  byte local_d;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  byte local_9;
  
  local_10 = (undefined1)((ushort)*(undefined2 *)(DAT_0306b664 + 4) >> 8);
  local_f = (undefined1)*(undefined2 *)(DAT_0306b664 + 4);
  local_e = (undefined1)((ushort)*(undefined2 *)(DAT_0306b664 + 6) >> 8);
  local_d = (byte)*(undefined2 *)(DAT_0306b664 + 6) & 0xef;
  local_c = (undefined1)((ushort)*(undefined2 *)(DAT_0306b664 + 8) >> 8);
  local_b = (undefined1)*(undefined2 *)(DAT_0306b664 + 8);
  uVar1 = *(ushort *)(DAT_0306b664 + 10);
  local_a = (undefined1)(uVar1 >> 8);
  local_9 = (byte)uVar1 & 0xf0 | (byte)(param_1 & 0xf);
  *(ushort *)(DAT_0306b664 + 10) = uVar1 & 0xfff0 | param_1 & 0xf;
  FUN_0306b24a(&local_10,8);
  return;
}


