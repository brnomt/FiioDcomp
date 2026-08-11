/**
 * FUN_03064360 @ 0x03064360
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03064360(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  iVar4 = *(int *)(DAT_03064474 + 0x14);
  uVar1 = *(ushort *)(iVar4 + 0x54);
  uVar8 = (uint)uVar1;
  uVar2 = *(ushort *)(DAT_03064474 + 4);
  uVar7 = (uint)*(ushort *)(DAT_03064474 + 6);
  do {
    uVar3 = (uint)(short)(uVar1 - 1);
    if (uVar3 == uVar8) goto LAB_030643a2;
    if ((int)uVar3 < 0) {
      uVar3 = 0x1d;
    }
    iVar5 = iVar4 + uVar3 * 2;
    *(uint *)(iVar4 + 0xc) = (uint)*(ushort *)(iVar5 + 0x14);
    uVar6 = (uint)*(ushort *)(iVar5 + 0x14);
    uVar1 = (ushort)uVar3;
  } while (uVar6 < uVar7 || uVar2 < uVar6);
  *(ushort *)(iVar4 + 0x54) = uVar1;
LAB_030643a2:
  uVar8 = (uint)*(ushort *)(iVar4 + (uint)*(ushort *)(iVar4 + 0x54) * 2 + 0x14);
  *(uint *)(iVar4 + 0xc) = uVar8;
  if ((uVar7 <= uVar8) && (uVar8 <= uVar2)) {
    return;
  }
  *(uint *)(iVar4 + 0xc) = uVar7;
  return;
}


