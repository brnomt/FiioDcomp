/**
 * FUN_03001fc6 @ 0x03001fc6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03001fc6(int param_1,int param_2,int param_3,undefined2 param_4)

{
  undefined2 unaff_r4;
  undefined2 in_r12;
  char in_ZR;
  
  if (in_ZR != '\0') {
    *(int *)(param_3 + 0xc) = param_1 + 0x50000;
    return;
  }
  if (param_2 == 3) {
    *(undefined2 *)(param_3 + 4) = unaff_r4;
    *(undefined2 *)(param_3 + 6) = in_r12;
    *(undefined2 *)(param_3 + 8) = param_4;
    *(int *)(param_3 + 0xc) = param_1 + 0xa2020;
    *(int *)(param_3 + 0x10) = param_1 + 0xa2040;
    *(int *)(param_3 + 0x14) = param_1 + 0xa20c0;
    return;
  }
  return;
}


