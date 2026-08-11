/**
 * FUN_0300da7c @ 0x0300da7c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


short FUN_0300da7c(void)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 *puVar4;
  short sVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  
  sVar5 = 5000;
  FUN_02fe6ae0(2,7,0);
  FUN_02fea8e0(2,7,1);
  FUN_02fea91a(2,7,1);
  pcVar3 = DAT_0300dea4;
  iVar2 = DAT_0300dea0;
  *(undefined1 *)(DAT_0300dea0 + 0x34b) = 1;
  puVar4 = DAT_0300dea8;
  do {
    FUN_02ff5bac();
    iVar6 = FUN_02ffc8c0(0x1c5);
    if (iVar6 != 0) {
      FUN_02ffc8a4(0x1c6);
      cVar1 = *pcVar3;
      bVar7 = cVar1 == 'C';
      if (bVar7) {
        cVar1 = pcVar3[1];
      }
      bVar8 = bVar7 && cVar1 == 'V';
      if (bVar7 && cVar1 == 'V') {
        bVar8 = pcVar3[2] == '1';
      }
      if (bVar8) {
        if (pcVar3[3] == '5') {
          *DAT_0300deac = 5;
        }
        else {
          *DAT_0300deac = 0;
        }
        *puVar4 = 0;
        if (sVar5 != 0) goto LAB_0300db4a;
        goto LAB_0300dae6;
      }
    }
    sVar5 = sVar5 + -1;
    FUN_02ff9ad4(1);
    if (sVar5 == 0) {
LAB_0300dae6:
      *puVar4 = 7;
      FUN_02fe6ae0(2,7,0);
      FUN_02fea8e0(2,7,1);
      FUN_02fea91a(2,7,0);
      FUN_02fe6ae0(2,0x11,0);
      FUN_02fea8e0(2,0x11,1);
      FUN_02fea91a(2,0x11,0);
      FUN_02fe6ae0(2,0x10,0);
      FUN_02fea8e0(2,0x10,1);
      FUN_02fea91a(2,0x10,0);
      *(undefined1 *)(iVar2 + 0x34b) = 0;
LAB_0300db4a:
      FUN_02ff9ad4(10);
      return sVar5;
    }
  } while( true );
}


