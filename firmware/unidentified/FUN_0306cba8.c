/**
 * FUN_0306cba8 @ 0x0306cba8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306cba8(void)

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
  
  FUN_03073ba8(0,4);
  uVar10 = FUN_03073c4c(0,2);
  puVar2 = DAT_0306ce4c;
  *(undefined4 *)(DAT_0306ce4c + 4) = uVar10;
  pbVar11 = (byte *)FUN_03073c20(0,2);
  *(byte **)(puVar2 + 8) = pbVar11;
  puVar6 = DAT_0306ce60;
  puVar5 = DAT_0306ce5c;
  iVar4 = DAT_0306ce54;
  puVar3 = DAT_0306ce50;
  iVar12 = *(int *)(puVar2 + 4);
  if (iVar12 == 0x6c) {
    *puVar2 = 3;
    pcVar8 = DAT_0306ce70;
    if (*DAT_0306ce70 == '\0') {
      *(undefined4 *)(iVar4 + (uint)*(byte *)(DAT_0306ce74 + 8) * 4) =
           *(undefined4 *)(DAT_0306ce74 + 4);
      *(byte **)(DAT_0306ce78 + *DAT_0306ce7c * 4) = pbVar11;
      *DAT_0306ce80 = 0;
      *pcVar8 = '\x01';
    }
  }
  else if (iVar12 < 0x6d) {
    if (iVar12 == 0x65) {
      *DAT_0306ce58 = pbVar11;
      bVar1 = *pbVar11;
      *puVar5 = (uint)bVar1;
      *puVar6 = *(undefined4 *)(pbVar11 + 4);
      *(undefined4 *)(iVar4 + (uint)bVar1 * 4) = *(undefined4 *)(pbVar11 + 8);
      puVar5 = DAT_0306ce68;
      iVar12 = *(int *)(pbVar11 + 0x14);
      *DAT_0306ce64 = iVar12;
      puVar7 = DAT_0306ce6c;
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
      if (pbVar11 == (byte *)0x0) goto LAB_0306cc3e;
      uVar9 = 7;
    }
    else {
      if (iVar12 != 0xd1) {
        return;
      }
      if (pbVar11 == (byte *)0x0) goto LAB_0306cc3e;
      uVar9 = 9;
    }
    *puVar2 = uVar9;
  }
LAB_0306cc3e:
  *puVar3 = 1;
  return;
}


