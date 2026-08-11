/**
 * FUN_030515da @ 0x030515da
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030515da(void)

{
  int iVar1;
  ushort *puVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = DAT_03051664;
  uVar5 = *(uint *)(DAT_03051664 + 4) + 0x1ff & 0xfe00;
  uVar4 = 0;
  if (uVar5 != *(uint *)(DAT_03051664 + 4)) {
    do {
      uVar3 = puVar2[2];
      uVar4 = uVar4 + 1 & 0xffff;
      *(undefined1 *)((int)puVar2 + (uVar3 - 0xc000)) = 0;
      *(uint *)(puVar2 + 2) = (uVar3 + 1) % 0xc000;
    } while (uVar4 < uVar5 - *(int *)(puVar2 + 4));
  }
  iVar1 = DAT_03051658;
  uVar3 = FUN_0302edec((int)puVar2 + (*puVar2 - 0xc000),
                       *(undefined4 *)(DAT_0305165c + *(short *)(DAT_03051658 + 8) * 0x27e + 0x10),
                       uVar5,(int)(char)*(short *)(DAT_03051658 + 8));
  if (uVar5 != uVar3) {
    return;
  }
  *(uint *)(iVar1 + 0x50) = (uint)uVar3 + *(int *)(iVar1 + 0x50);
  return;
}


