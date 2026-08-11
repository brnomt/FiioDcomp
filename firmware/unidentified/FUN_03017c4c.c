/**
 * FUN_03017c4c @ 0x03017c4c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_03017c4c(short param_1,int param_2,short *param_3,short param_4)

{
  int unaff_r4;
  
  param_3[5] = param_4 + param_1 * 10;
  *param_3 = (*(byte *)(param_2 + 8) & 0xf) + (ushort)(*(byte *)(param_2 + 8) >> 4) * 10 + 2000;
  param_3[2] = (*(byte *)(param_2 + 5) & 0xf) +
               (ushort)(((uint)*(byte *)(param_2 + 5) << 0x1a) >> 0x1e) * 10;
  param_3[1] = (*(byte *)(param_2 + 7) & 0xf) +
               (short)((int)((uint)*(byte *)(param_2 + 7) << 0x1b) >> 0x1f) * -10;
  *(undefined1 *)(unaff_r4 + 1) = 0;
  *(undefined1 *)(unaff_r4 + 2) = 0;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


