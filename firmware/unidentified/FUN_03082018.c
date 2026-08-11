/**
 * FUN_03082018 @ 0x03082018
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03082018(void)

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
  
  FUN_03090f48(0,4);
  uVar10 = FUN_03090fec(0,2);
  puVar2 = DAT_030822bc;
  *(undefined4 *)(DAT_030822bc + 4) = uVar10;
  pbVar11 = (byte *)FUN_03090fc0(0,2);
  *(byte **)(puVar2 + 8) = pbVar11;
  puVar6 = DAT_030822d0;
  puVar5 = DAT_030822cc;
  iVar4 = DAT_030822c4;
  puVar3 = DAT_030822c0;
  iVar12 = *(int *)(puVar2 + 4);
  if (iVar12 == 0x6c) {
    *puVar2 = 3;
    pcVar8 = DAT_030822e0;
    if (*DAT_030822e0 == '\0') {
      *(undefined4 *)(iVar4 + (uint)*(byte *)(DAT_030822e4 + 8) * 4) =
           *(undefined4 *)(DAT_030822e4 + 4);
      *(byte **)(DAT_030822e8 + *DAT_030822ec * 4) = pbVar11;
      *DAT_030822f0 = 0;
      *pcVar8 = '\x01';
    }
  }
  else if (iVar12 < 0x6d) {
    if (iVar12 == 0x65) {
      *DAT_030822c8 = pbVar11;
      bVar1 = *pbVar11;
      *puVar5 = (uint)bVar1;
      *puVar6 = *(undefined4 *)(pbVar11 + 4);
      *(undefined4 *)(iVar4 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar11 + 8);
      puVar5 = DAT_030822d8;
      iVar12 = *(int *)(pbVar11 + 0x14);
      *DAT_030822d4 = iVar12;
      puVar7 = DAT_030822dc;
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
      if (pbVar11 == (byte *)0x0) goto LAB_030820ae;
      uVar9 = 7;
    }
    else {
      if (iVar12 != 0xd1) {
        return;
      }
      if (pbVar11 == (byte *)0x0) goto LAB_030820ae;
      uVar9 = 9;
    }
    *puVar2 = uVar9;
  }
LAB_030820ae:
  *puVar3 = 1;
  return;
}


