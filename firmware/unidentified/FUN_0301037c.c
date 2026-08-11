/**
 * FUN_0301037c @ 0x0301037c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030103ca) */
/* WARNING: Removing unreachable block (ram,0x030103c8) */

undefined4 FUN_0301037c(void)

{
  undefined1 *puVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  byte *pbVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  
  bVar5 = false;
  *DAT_030104f4 = *DAT_030104f0;
  FUN_02ffcca0();
  iVar9 = FUN_02ffe664(0xdf);
  puVar8 = DAT_030104fc;
  pbVar7 = DAT_030104f8;
  iVar10 = DAT_030104ec;
  if (iVar9 != 0) {
    if (*(char *)(DAT_030104ec + 0x1bc) == '\x01') {
      if (*(char *)(DAT_030104ec + 0x1ba) != '\0') {
        *(char *)(DAT_030104ec + 0x1ba) = *(char *)(DAT_030104ec + 0x1ba) + -1;
      }
      if (*pbVar7 == 0) {
        *(undefined1 *)(iVar10 + 0x1b8) = 0;
      }
      else {
        *pbVar7 = *pbVar7 - 1;
      }
    }
    else if (*(char *)(DAT_030104ec + 0x1bc) == '\0') {
      uVar3 = *DAT_030104fc;
      uVar11 = (uint)uVar3;
      uVar13 = uVar11 - 0x61;
      iVar9 = 0;
      while (((iVar6 = DAT_030104dc, puVar8[iVar9] != 10 || (puVar8[iVar9 + 1] != 10)) &&
             (iVar9 == 0))) {
        bVar15 = 0x1f < uVar11;
        bVar14 = uVar11 != 0x20;
        if (bVar14) {
          bVar15 = 0x18 < uVar13;
        }
        if (bVar15 && (bVar14 && uVar13 != 0x19)) {
          bVar5 = true;
        }
        if (!bVar15 || (!bVar14 || uVar13 == 0x19)) {
          *(char *)(iVar10 + 0x1b8) = (char)uVar3;
        }
        iVar9 = 1;
      }
      if (bVar5) {
        *(undefined1 *)(*(int *)(DAT_030104dc + 8) + (uint)*pbVar7) = 0;
        bVar2 = *pbVar7;
        iVar9 = *(int *)(iVar6 + 8);
        uVar11 = 0;
        do {
          iVar12 = iVar10 + uVar11;
          puVar1 = (undefined1 *)(iVar9 + uVar11);
          uVar11 = uVar11 + 1 & 0xff;
          *(undefined1 *)(iVar12 + 0x1b8) = *puVar1;
        } while (uVar11 <= bVar2);
        *(undefined1 *)(iVar9 + (uint)bVar2) = 0x7c;
        *(undefined1 *)(*(int *)(iVar6 + 8) + *pbVar7 + 1) = 0;
      }
      else {
        *(undefined1 *)(iVar9 + iVar10 + 0x1b8) = 0;
      }
      *(undefined1 *)(*(int *)(iVar6 + 8) + (uint)*pbVar7) = 0x7c;
      *(undefined1 *)(*(int *)(iVar6 + 8) + *pbVar7 + 1) = 0;
      cVar4 = *(char *)(iVar10 + 0x1ba);
      *(char *)(iVar10 + 0x1ba) = cVar4 + '\x01';
      if (cVar4 != -1) {
        *(undefined1 *)(iVar10 + 0x1ba) = 1;
      }
    }
    rom_post_event(0x32);
  }
  iVar10 = FUN_02ffe664(0xe0);
  if (iVar10 != 0) {
    rom_post_event(0x32);
  }
  iVar10 = FUN_02ffe664(0xe3);
  if (iVar10 != 0) {
    rom_post_event(0x32);
  }
  return 0;
}


