/**
 * FUN_030646f8 @ 0x030646f8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030646f8(void)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = DAT_03064894;
  puVar1 = DAT_0306487c;
  iVar4 = *(int *)(DAT_0306487c + 10);
  uVar3 = (uint)*(byte *)(DAT_03064894 + 0x1c0);
  *(uint *)(iVar4 + 4) = uVar3;
  *(undefined1 *)(iVar4 + 8) = *(undefined1 *)(iVar2 + 0x1c1);
  if (uVar3 == 2) {
    puVar1[3] = 0x1db0;
    puVar1[2] = 9000;
  }
  else {
    puVar1[3] = 0x222e;
    puVar1[2] = 0x2a30;
  }
  *puVar1 = (ushort)(uVar3 == 2);
  return;
}


