/**
 * FUN_0308f4b4 @ 0x0308f4b4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0308f4b4(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = *param_1;
  iVar4 = (int)*(short *)(iVar3 + 0x154);
  wma_memclr(param_1[2],(uint)*(ushort *)(iVar3 + 0x26) << 3);
  iVar2 = 0;
  if (*(short *)(iVar3 + 0x26) == 0) {
    return;
  }
  do {
    puVar1 = (undefined4 *)(*(int *)(iVar3 + 0xd8) + iVar2 * 0xfc);
    *puVar1 = 0;
    puVar1[1] = *(int *)(iVar3 + 0xe0) + iVar2 * 0x70;
    iVar5 = *(int *)(iVar3 + 0xe4);
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[2] = iVar5 + iVar2 * 0x70;
    puVar1[8] = 0;
    puVar1[0xb] = *(int *)(iVar3 + 0xa8) - *(int *)(iVar3 + 0xa4);
    puVar1[0xc] = 0;
    puVar1[0xf] = 0;
    iVar5 = ((iVar4 * 3) / 2) * iVar2 * 4 + (iVar4 / 2) * 4 + *(int *)(iVar3 + 0xdc);
    puVar1[0x11] = iVar5;
    puVar1[0x27] = iVar5;
    puVar1[0x13] = 0;
    *(undefined2 *)((int)puVar1 + 0x52) = 0x7fff;
    puVar1[0x15] = 0;
    puVar1[0x16] = 0;
    puVar1[0x17] = 0;
    puVar1[0x18] = 0;
    puVar1[0x19] = 0;
    puVar1[0x1a] = 0;
    puVar1[0x1b] = 0;
    puVar1[0x1c] = 0;
    puVar1[0x1d] = 0;
    puVar1[0x1e] = 0;
    *(undefined2 *)(puVar1 + 0x21) = 0;
    *(undefined2 *)((int)puVar1 + 0x86) = 0;
    *(undefined2 *)(puVar1 + 0x22) = 0;
    *(undefined2 *)((int)puVar1 + 0x8a) = 0;
    *(undefined2 *)(puVar1 + 0x23) = 0;
    *(undefined2 *)((int)puVar1 + 0x8e) = 0;
    *(undefined2 *)(puVar1 + 0x24) = 0;
    *(undefined2 *)(puVar1 + 0x1f) = 0;
    *(undefined2 *)(puVar1 + 0x20) = 0;
    puVar1[0x29] = 0;
    if (*(int *)(iVar3 + 0xb4) == 0) {
      puVar1[0x10] = *(int *)(iVar3 + 0x144) + iVar4 * iVar2 * 4;
      iVar5 = *(int *)(iVar3 + 0x144) + iVar4 * iVar2 * 4;
    }
    else {
      iVar5 = iVar2 * 0xfc + 4;
      puVar1[0x10] = *(undefined4 *)(*(int *)(iVar3 + 0xd8) + iVar5);
      iVar5 = *(int *)(*(int *)(iVar3 + 0xd8) + iVar5);
    }
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[0x28] = iVar5;
    puVar1[5] = 0;
    puVar1[3] = *(int *)(iVar3 + 200) * iVar2 + *(int *)(iVar3 + 0x134);
    puVar1[4] = *(int *)(iVar3 + 0x138) + *(int *)(iVar3 + 200) * iVar2 * 8;
    puVar1[5] = *(int *)(iVar3 + 0x13c) + *(int *)(iVar3 + 200) * iVar2 * 4;
    *(undefined2 *)puVar1[0x30] = 1;
    **(undefined2 **)(puVar1[0x30] + 8) = *(undefined2 *)(iVar3 + 0x9c);
    *(undefined2 *)(*(int *)(puVar1[0x30] + 8) + -2) = *(undefined2 *)(iVar3 + 0x9c);
    **(undefined2 **)(puVar1[0x30] + 0xc) = 0;
    *(undefined4 *)(*(int *)(iVar3 + 0xd8) + iVar2 * 0xfc + 0xb8) = 0;
    iVar2 = (int)(short)((short)iVar2 + 1);
  } while (iVar2 < (int)(uint)*(ushort *)(iVar3 + 0x26));
  return;
}


