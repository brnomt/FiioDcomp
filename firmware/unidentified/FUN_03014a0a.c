/**
 * FUN_03014a0a @ 0x03014a0a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_03014a0a(void)

{
  byte bVar1;
  ushort *puVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  
  puVar2 = DAT_03014a8c;
  *(undefined4 *)(DAT_03014a88 + 0x10) = 0;
  puVar2[2] = 0;
  puVar2[1] = 0;
  puVar2[3] = 0;
  puVar2[7] = 0xffff;
  puVar2[6] = 0xff;
  puVar2[5] = 0;
  pbVar3 = DAT_03014a94;
  *(undefined4 *)(puVar2 + 8) = DAT_03014a90;
  iVar5 = DAT_03014a9c;
  iVar4 = DAT_03014a98;
  bVar1 = *pbVar3;
  uVar7 = 0;
  if (bVar1 != 0) {
    do {
      *(ushort *)(iVar5 + uVar7 * 2) = *(byte *)(iVar4 + uVar7) + 0x15e;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < bVar1);
  }
  FUN_02ffefb6(0xe7,*(undefined4 *)(puVar2 + 8));
  uVar6 = *(ushort *)(*(int *)(puVar2 + 8) + 0xe);
  if (6 < uVar6) {
    uVar6 = 6;
  }
  *puVar2 = uVar6;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


