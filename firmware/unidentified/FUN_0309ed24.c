/**
 * FUN_0309ed24 @ 0x0309ed24
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0309ed24(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint *puVar6;
  undefined2 *puVar7;
  char *pcVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  int iVar12;
  
  FUN_030a5530(0,4);
  uVar10 = FUN_030a55d4(0,2);
  puVar2 = DAT_0309efe0;
  *(undefined4 *)(DAT_0309efe0 + 4) = uVar10;
  pbVar11 = (byte *)FUN_030a55a8(0,2);
  *(byte **)(puVar2 + 8) = pbVar11;
  puVar7 = DAT_0309f004;
  iVar4 = DAT_0309efe8;
  puVar3 = DAT_0309efe4;
  iVar12 = *(int *)(puVar2 + 4);
  if (iVar12 == 0x6c) {
    *puVar2 = 3;
    pcVar8 = DAT_0309f00c;
    if (*DAT_0309f00c == '\0') {
      *(undefined4 *)(iVar4 + (uint)*(byte *)(DAT_0309f010 + 8) * 4) =
           *(undefined4 *)(DAT_0309f010 + 4);
      *(byte **)(DAT_0309f014 + *DAT_0309f018 * 4) = pbVar11;
      *DAT_0309f01c = 0;
      *pcVar8 = '\x01';
    }
  }
  else if (iVar12 < 0x6d) {
    if (iVar12 == 0x65) {
      *DAT_0309efec = pbVar11;
      puVar5 = DAT_0309eff4;
      bVar1 = *pbVar11;
      *DAT_0309eff0 = (uint)bVar1;
      *puVar5 = *(undefined4 *)(pbVar11 + 4);
      *(undefined4 *)(iVar4 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar11 + 8);
      puVar6 = DAT_0309f000;
      iVar12 = *(int *)(pbVar11 + 0x14);
      *DAT_0309eff8 = iVar12;
      if (iVar12 == 2 || iVar12 == 7) {
        bVar1 = pbVar11[1];
        *DAT_0309effc = (uint)bVar1;
        *(undefined4 *)(iVar4 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar11 + 0xc);
        bVar1 = pbVar11[2];
        *puVar6 = (uint)bVar1;
        *(undefined4 *)(iVar4 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar11 + 0x10);
      }
      *puVar2 = 1;
      return;
    }
    if (0x65 < iVar12) {
      if (iVar12 == 0x67) {
        DAT_0309efec[1] = pbVar11;
        *puVar7 = *(undefined2 *)pbVar11;
        *DAT_0309f008 = *(undefined4 *)(pbVar11 + 4);
        *puVar2 = 8;
        return;
      }
      if (iVar12 == 0x6a) {
        *puVar2 = 2;
        *puVar3 = 1;
        return;
      }
      return;
    }
    if (iVar12 != 0x10 && iVar12 != 0x12) {
      return;
    }
  }
  else {
    if (iVar12 == 0x72) {
      *puVar2 = 6;
      *puVar3 = 1;
      return;
    }
    if (iVar12 < 0x73) {
      if (iVar12 == 0x6e) {
        *puVar2 = 4;
        *puVar3 = 1;
        return;
      }
      if (iVar12 == 0x70) {
        *puVar2 = 5;
        *puVar3 = 1;
        return;
      }
      return;
    }
    if (iVar12 == 0x74) {
      if (pbVar11 == (byte *)0x0) goto LAB_0309eda4;
      uVar9 = 7;
    }
    else {
      if (iVar12 != 0xd1) {
        return;
      }
      if (pbVar11 == (byte *)0x0) goto LAB_0309eda4;
      uVar9 = 9;
    }
    *puVar2 = uVar9;
  }
LAB_0309eda4:
  *puVar3 = 1;
  return;
}


