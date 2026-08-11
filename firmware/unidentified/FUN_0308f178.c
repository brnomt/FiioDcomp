/**
 * FUN_0308f178 @ 0x0308f178
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308f178(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined2 param_5,undefined4 param_6,undefined2 param_7,undefined4 param_8,
                undefined4 param_9,int param_10,undefined4 param_11)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x50) = param_4;
  *(undefined4 *)(param_1 + 0x9c) = param_3;
  *(undefined4 *)(param_1 + 0x40) = param_2;
  *(undefined2 *)(param_1 + 0x26) = param_5;
  *(undefined4 *)(param_1 + 0x58) = param_6;
  *(undefined2 *)(param_1 + 0x6a) = param_7;
  *(undefined4 *)(param_1 + 0x44) = param_11;
  *(undefined4 *)(param_1 + 0x54) = param_9;
  *(undefined4 *)(param_1 + 100) = param_8;
  *(int *)(param_1 + 0x10) = param_10 << 3;
  *(int *)(param_1 + 0x1b0) = (param_10 << 3) >> 3;
  iVar1 = wma_floor_log2();
  *(int *)(param_1 + 0x1a8) = iVar1 + 1;
  iVar1 = wma_floor_log2(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(int *)(param_1 + 0x1ac) = iVar1 + 1;
  *(undefined4 *)(param_1 + 0x1c4) = 5;
  *(undefined4 *)(param_1 + 0x1c8) = 5;
  iVar1 = FUN_0308ed9e(param_1);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (*(char *)(param_1 + 0x60) == '=') {
    *(undefined1 **)(param_1 + 0x170) = &LAB_0308f140_1;
    *(undefined1 **)(param_1 + 0x174) = &LAB_0308f13a_1;
  }
  iVar1 = FUN_0308eff6(param_1);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0309077e(param_1);
  if (iVar1 < 0) {
    return iVar1;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x148) = 0;
  wma_memclr(*(undefined4 *)(param_1 + 0xf8),(uint)*(ushort *)(param_1 + 0x26) << 2);
  wma_memclr(*(undefined4 *)(param_1 + 0xdc),
             (*(int *)(param_1 + 0x9c) * 3 & 0x3fffffffU) * 2 * (uint)*(ushort *)(param_1 + 0x26));
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  wma_memclr(*(undefined4 *)(param_1 + 0xfc),(uint)*(ushort *)(param_1 + 0x26) << 2);
  wma_memclr(*(undefined4 *)(param_1 + 0x100),(uint)*(ushort *)(param_1 + 0x26) << 2);
  wma_memclr(*(undefined4 *)(param_1 + 0x104),(uint)*(ushort *)(param_1 + 0x26) << 2);
  *(undefined4 *)(param_1 + 0xc4) = 0x40;
  return 0;
}


