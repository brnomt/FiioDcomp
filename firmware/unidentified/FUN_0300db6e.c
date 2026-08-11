/**
 * FUN_0300db6e @ 0x0300db6e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0300db6e(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  *DAT_0300deb0 = 0;
  FUN_02fe6ae0(2,7,0);
  FUN_02fea8e0(2,7,1);
  FUN_02fea91a(2,7,0);
  FUN_02fe6ae0(2,0x11,0);
  FUN_02fea8e0(2,0x11,1);
  FUN_02fea91a(2,0x11,0);
  FUN_02fe6ae0(2,0x10,0);
  FUN_02fea8e0(2,0x10,1);
  FUN_02fea91a(2,0x10,0);
  iVar1 = DAT_0300dea0;
  *(undefined1 *)(DAT_0300dea0 + 0x34b) = 0;
  FUN_02ff9ad4(100);
  FUN_02fe764a();
  iVar5 = FUN_0300da7c();
  iVar6 = FUN_02ffc904(0x1cf);
  puVar4 = DAT_0300deb8;
  puVar3 = DAT_0300deb4;
  puVar2 = DAT_0300dea8;
  if (iVar6 == 1) {
    if (*(char *)(iVar1 + 0x349) != '\0') {
      *DAT_0300deb8 = 0x43;
      puVar4[1] = 0x4c;
      uVar8 = 0;
      do {
        uVar7 = uVar8 + 1 & 0xffff;
        puVar4[uVar8 + 4] = *(undefined1 *)(iVar1 + uVar8 + 0x23e);
        uVar8 = uVar7;
      } while (uVar7 < 6);
      *(undefined1 *)(iVar1 + 0x349) = 1;
      puVar4[2] = 0x30;
      puVar4[3] = 0x36;
      *DAT_0300debc = 10;
      FUN_02ffc8a4(0x1ca);
      FUN_02ffc8a4(0x1c6);
      *puVar2 = 2;
      return;
    }
    if (iVar5 == 0) {
      return;
    }
    uVar8 = 0;
    do {
      uVar7 = 0;
      iVar5 = uVar8 * 0x26 + 0x2c;
      do {
        puVar3[uVar7 + iVar5] = 0;
        uVar7 = uVar7 + 1 & 0xff;
      } while (uVar7 < 6);
      uVar7 = 0;
      do {
        iVar6 = uVar7 + iVar5;
        uVar7 = uVar7 + 1 & 0xff;
        puVar3[iVar6 + 6] = 0;
      } while (uVar7 < 0x20);
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 6);
  }
  else {
    if (iVar5 == 0) {
      return;
    }
    uVar8 = 0;
    do {
      uVar7 = 0;
      iVar5 = uVar8 * 0x26 + 0x2c;
      do {
        puVar3[uVar7 + iVar5] = 0;
        uVar7 = uVar7 + 1 & 0xff;
      } while (uVar7 < 6);
      uVar7 = 0;
      do {
        iVar6 = uVar7 + iVar5;
        uVar7 = uVar7 + 1 & 0xff;
        puVar3[iVar6 + 6] = 0;
      } while (uVar7 < 0x20);
      uVar8 = uVar8 + 1 & 0xffff;
    } while (uVar8 < 6);
  }
  *puVar3 = 0;
  *(undefined1 *)(iVar1 + 0x349) = 0;
  FUN_02ffb1c8(0x53);
  *puVar2 = 1;
  return;
}


