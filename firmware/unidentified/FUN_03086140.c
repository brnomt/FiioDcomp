/**
 * FUN_03086140 @ 0x03086140
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03086140(int *param_1)

{
  undefined2 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar5 = *param_1;
  if (iVar5 == 0) {
    return 0;
  }
  FUN_030845a4(param_1 + 0x21);
  param_1[0x24] = 0;
  param_1[0x30] = 1;
  param_1[0x25] = 0;
  wma_memclr(*(undefined4 *)(iVar5 + 0xf8),(uint)*(ushort *)(iVar5 + 0x26) << 2);
  *(undefined1 *)(iVar5 + 0x48) = 3;
  *(undefined4 *)(iVar5 + 0x118) = 0;
  *(undefined4 *)(iVar5 + 0x11c) = 0;
  *(undefined4 *)(iVar5 + 8) = 0xfffffffe;
  iVar3 = 0;
  if (*(short *)(iVar5 + 0x26) != 0) {
    do {
      uVar1 = (undefined2)
              ((uint)((*(int *)(iVar5 + 0x9c) - (*(int *)(iVar5 + 0x9c) >> 0x1f)) * 0x8000) >> 0x10)
      ;
      *(undefined2 *)(*(int *)(iVar5 + 0xd8) + iVar3 * 0xfc + 0x84) = uVar1;
      iVar4 = iVar3 + 1;
      *(undefined2 *)(*(int *)(iVar5 + 0xd8) + iVar3 * 0xfc + 0x86) = uVar1;
      *(undefined2 *)(*(int *)(*(int *)(*(int *)(iVar5 + 0xd8) + iVar3 * 0xfc + 0xc0) + 8) + -2) =
           *(undefined2 *)(iVar5 + 0x9c);
      *(undefined2 *)(*(int *)(iVar5 + 0xd8) + iVar3 * 0xfc + 0x7e) = 0;
      iVar3 = iVar4;
    } while (iVar4 < (int)(uint)*(ushort *)(iVar5 + 0x26));
  }
  param_1[5] = 0;
  param_1[3] = 1;
  param_1[0x2e] = -2;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 2;
  param_1[10] = 0;
  if (param_1[0x21] == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  *(undefined1 *)(param_1 + 0x72) = uVar2;
  param_1[0x34] = 0;
  param_1[0xe] = 0;
  param_1[0x73] = 1;
  param_1[0x10] = 0;
  param_1[0x11] = -0x80000000;
  param_1[0x12] = 0;
  param_1[0x13] = -0x80000000;
  *(undefined2 *)(param_1 + 0xf) = 0;
  *(undefined1 *)((int)param_1 + 0x1e) = 0;
  *(undefined4 *)(iVar5 + 8) = 0;
  *(undefined4 *)(iVar5 + 0x148) = 0;
  wma_memclr(*(undefined4 *)(iVar5 + 0xf8),(uint)*(ushort *)(iVar5 + 0x26) << 2);
  wma_memclr(*(undefined4 *)(iVar5 + 0xdc),
             (*(int *)(iVar5 + 0x9c) * 3 & 0x3fffffffU) * 2 * (uint)*(ushort *)(iVar5 + 0x26));
  *(undefined4 *)(iVar5 + 0x118) = 0;
  *(undefined4 *)(iVar5 + 0x11c) = 0;
  *(undefined4 *)(iVar5 + 0x108) = 0;
  wma_memclr(*(undefined4 *)(iVar5 + 0xfc),(uint)*(ushort *)(iVar5 + 0x26) << 2);
  wma_memclr(*(undefined4 *)(iVar5 + 0x100),(uint)*(ushort *)(iVar5 + 0x26) << 2);
  wma_memclr(*(undefined4 *)(iVar5 + 0x104),(uint)*(ushort *)(iVar5 + 0x26) << 2);
  *(undefined4 *)(iVar5 + 0xc4) = 0x40;
  return 0;
}


