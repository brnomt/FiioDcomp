/**
 * FUN_0308ed36 @ 0x0308ed36
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4
FUN_0308ed36(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined2 param_5
            ,undefined4 param_6,undefined2 param_7,undefined4 param_8,undefined4 param_9,
            int param_10,undefined4 param_11)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x50) = param_4;
  *(undefined4 *)(param_1 + 0x9c) = param_3;
  *(undefined4 *)(param_1 + 0x40) = param_2;
  *(undefined2 *)(param_1 + 0x26) = param_5;
  *(undefined4 *)(param_1 + 0x58) = param_6;
  *(undefined2 *)(param_1 + 0x6a) = param_7;
  *(undefined4 *)(param_1 + 0x44) = param_11;
  *(undefined4 *)(param_1 + 100) = param_8;
  *(undefined4 *)(param_1 + 0x54) = param_9;
  *(int *)(param_1 + 0x10) = param_10 << 3;
  *(int *)(param_1 + 0x1b0) = (param_10 << 3) >> 3;
  iVar1 = wma_floor_log2();
  *(int *)(param_1 + 0x1a8) = iVar1 + 1;
  iVar1 = wma_floor_log2(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(int *)(param_1 + 0x1ac) = iVar1 + 1;
  *(undefined4 *)(param_1 + 0x1c4) = 5;
  *(undefined4 *)(param_1 + 0x1c8) = 5;
  return 0;
}


