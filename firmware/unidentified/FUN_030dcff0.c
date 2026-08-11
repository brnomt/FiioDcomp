/**
 * FUN_030dcff0 @ 0x030dcff0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030dcff0(void)

{
  byte bVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint *puVar7;
  char *pcVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  int iVar12;
  
  FUN_030e0798(0,4);
  uVar10 = FUN_030e083c(0,2);
  puVar2 = DAT_030dd294;
  *(undefined4 *)(DAT_030dd294 + 4) = uVar10;
  pbVar11 = (byte *)FUN_030e0810(0,2);
  *(byte **)(puVar2 + 8) = pbVar11;
  puVar6 = DAT_030dd2a8;
  puVar5 = DAT_030dd2a4;
  iVar4 = DAT_030dd29c;
  puVar3 = DAT_030dd298;
  iVar12 = *(int *)(puVar2 + 4);
  if (iVar12 == 0x6c) {
    *puVar2 = 3;
    pcVar8 = DAT_030dd2b8;
    if (*DAT_030dd2b8 == '\0') {
      *(undefined4 *)(iVar4 + (uint)*(byte *)(DAT_030dd2bc + 8) * 4) =
           *(undefined4 *)(DAT_030dd2bc + 4);
      *(byte **)(DAT_030dd2c0 + *DAT_030dd2c4 * 4) = pbVar11;
      *DAT_030dd2c8 = 0;
      *pcVar8 = '\x01';
    }
  }
  else if (iVar12 < 0x6d) {
    if (iVar12 == 0x65) {
      *DAT_030dd2a0 = pbVar11;
      bVar1 = *pbVar11;
      *puVar5 = (uint)bVar1;
      *puVar6 = *(undefined4 *)(pbVar11 + 4);
      *(undefined4 *)(iVar4 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar11 + 8);
      puVar5 = DAT_030dd2b0;
      iVar12 = *(int *)(pbVar11 + 0x14);
      *DAT_030dd2ac = iVar12;
      puVar7 = DAT_030dd2b4;
      if (iVar12 == 2 || iVar12 == 7) {
        bVar1 = pbVar11[1];
        *puVar5 = (uint)bVar1;
        *(undefined4 *)(iVar4 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar11 + 0xc);
        bVar1 = pbVar11[2];
        *puVar7 = (uint)bVar1;
        *(undefined4 *)(iVar4 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar11 + 0x10);
      }
      *puVar2 = 1;
      return;
    }
    if (0x65 < iVar12) {
      if (iVar12 == 0x67) {
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
      if (pbVar11 == (byte *)0x0) goto LAB_030dd086;
      uVar9 = 7;
    }
    else {
      if (iVar12 != 0xd1) {
        return;
      }
      if (pbVar11 == (byte *)0x0) goto LAB_030dd086;
      uVar9 = 9;
    }
    *puVar2 = uVar9;
  }
LAB_030dd086:
  *puVar3 = 1;
  return;
}


