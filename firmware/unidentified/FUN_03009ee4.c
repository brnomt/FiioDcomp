/**
 * FUN_03009ee4 @ 0x03009ee4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03009ee4(void)

{
  ushort *puVar1;
  int iVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort local_44 [30];
  
  uVar3 = *DAT_0300a14c;
  uVar7 = 0;
  uVar4 = *DAT_0300a150;
  uVar6 = 0;
  iVar8 = *DAT_0300a134;
  do {
    uVar5 = *(ushort *)(iVar8 + uVar6 * 2 + 0x14);
    if (uVar3 <= uVar5 && uVar5 <= uVar4) {
      local_44[uVar7] = uVar5;
      uVar7 = uVar7 + 1 & 0xff;
    }
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 0x1e);
  uVar6 = 0;
  do {
    iVar2 = uVar6 * 2;
    uVar6 = uVar6 + 1 & 0xff;
    *(undefined2 *)(iVar8 + iVar2 + 0x14) = 0;
  } while (uVar6 < 0x1e);
  uVar6 = 0;
  if (uVar7 != 0) {
    do {
      puVar1 = local_44 + uVar6;
      iVar2 = uVar6 * 2;
      uVar6 = uVar6 + 1 & 0xff;
      *(ushort *)(iVar8 + iVar2 + 0x14) = *puVar1;
    } while (uVar6 < uVar7);
    return;
  }
  return;
}


