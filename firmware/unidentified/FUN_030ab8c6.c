/**
 * FUN_030ab8c6 @ 0x030ab8c6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030ab8c6(uint param_1,undefined2 *param_2,undefined1 *param_3,char *param_4)

{
  *param_2 = (short)(param_1 / 0xe10);
  *param_3 = (char)((param_1 % 0xe10) / 0x3c);
  *param_4 = (char)param_1 +
             (char)(uint)((ulonglong)DAT_030ab908 * (ulonglong)param_1 >> 0x25) * -0x3c;
  return;
}


