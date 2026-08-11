/**
 * FUN_030643c0 @ 0x030643c0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030643c0(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = DAT_03064474;
  iVar3 = *(int *)(DAT_03064474 + 0x14);
  uVar1 = *(ushort *)(iVar3 + 0x54);
  uVar4 = uVar1 + 1;
  *(short *)(iVar3 + 0x54) = (short)uVar4;
  uVar6 = (uint)*(ushort *)(iVar2 + 4);
  uVar5 = (uint)*(ushort *)(iVar2 + 6);
  while ((uVar4 & 0xffff) != (uint)uVar1) {
    if (0x1d < (uVar4 & 0xffff)) {
      *(undefined2 *)(iVar3 + 0x54) = 0;
    }
    uVar4 = (uint)*(ushort *)(iVar3 + (uint)*(ushort *)(iVar3 + 0x54) * 2 + 0x14);
    *(uint *)(iVar3 + 0xc) = uVar4;
    if ((uVar5 <= uVar4) && (uVar4 <= uVar6)) break;
    uVar4 = *(ushort *)(iVar3 + 0x54) + 1;
    *(short *)(iVar3 + 0x54) = (short)uVar4;
  }
  if (0x1d < *(ushort *)(iVar3 + 0x54)) {
    *(undefined2 *)(iVar3 + 0x54) = 0;
  }
  uVar4 = (uint)*(ushort *)(iVar3 + (uint)*(ushort *)(iVar3 + 0x54) * 2 + 0x14);
  *(uint *)(iVar3 + 0xc) = uVar4;
  if ((uVar4 < uVar5) || (uVar6 < uVar4)) {
    *(undefined2 *)(iVar3 + 0x54) = 0;
  }
  uVar4 = (uint)*(ushort *)(iVar3 + (uint)*(ushort *)(iVar3 + 0x54) * 2 + 0x14);
  *(uint *)(iVar3 + 0xc) = uVar4;
  if ((uVar5 <= uVar4) && (uVar4 <= uVar6)) {
    return;
  }
  *(uint *)(iVar3 + 0xc) = uVar5;
  return;
}


