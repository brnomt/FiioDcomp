/**
 * FUN_0305182a @ 0x0305182a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0305182a(void)

{
  sbyte sVar1;
  char cVar2;
  short sVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar7 = 2000;
  sVar3 = *DAT_03051a8c;
  if ((sVar3 != 1 && sVar3 != 2) && sVar3 != 3) {
    return;
  }
  *DAT_03051a8c = 5;
  iVar5 = FUN_03027fa8();
  while (iVar5 == 1) {
    FUN_03037668(1);
    FUN_03033740();
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) break;
    iVar5 = FUN_03027fa8(5);
  }
  FUN_03022304(0,2);
  FUN_03024598(3,1);
  FUN_030516d2();
  pcVar4 = DAT_03051a88;
  *(ushort *)(DAT_03051a88 + 0xc) = *(ushort *)(DAT_03051a88 + 0xc) & 0xfffd;
  pcVar4[0x30] = '\0';
  pcVar4[0x31] = '\0';
  pcVar4[0x32] = '\0';
  pcVar4[0x33] = '\0';
  pcVar4[0x34] = '\0';
  pcVar4[0x35] = '\0';
  pcVar4[0x36] = '\0';
  pcVar4[0x37] = '\0';
  if (*(short *)(pcVar4 + 8) != -1) {
    FUN_030515da();
    iVar7 = DAT_03051a94 + *(short *)(pcVar4 + 8) * 0x27e;
    iVar9 = *(int *)(iVar7 + 0x10);
    iVar7 = *(int *)(iVar7 + 0x14);
    sVar1 = *DAT_03051a98;
    iVar8 = iVar9 + -8;
    iVar5 = *(int *)(DAT_03051a9c + 0x1f);
    func_0x0302b260((int)(char)*(short *)(pcVar4 + 8));
    pcVar4[8] = -1;
    pcVar4[9] = -1;
    iVar9 = iVar9 + -0x1000;
    FUN_03051d88();
    iVar6 = *(int *)(pcVar4 + 0x60);
    *(char *)(iVar6 + 4) = (char)iVar8;
    *(char *)(iVar6 + 5) = (char)((uint)iVar8 >> 8);
    *(char *)(iVar6 + 6) = (char)((uint)iVar8 >> 0x10);
    *(char *)(iVar6 + 7) = (char)((uint)iVar8 >> 0x18);
    *(char *)(iVar6 + 0xffc) = (char)iVar9;
    *(char *)(iVar6 + 0xffd) = (char)((uint)iVar9 >> 8);
    *(char *)(iVar6 + 0xffe) = (char)((uint)iVar9 >> 0x10);
    *(char *)(iVar6 + 0xfff) = (char)((uint)iVar9 >> 0x18);
    if (iVar8 != 0) {
      FUN_0303ab26(*DAT_03051aa0,(iVar7 + -2 << sVar1) + iVar5,8);
    }
    iVar7 = DAT_03051aa8;
    *(undefined1 *)(DAT_03051aa4 + 0x6c) = 0;
    *pcVar4 = '\0';
    FUN_03040224(0xd1,0,2);
    FUN_030401f8(1,0,2);
    cVar2 = *pcVar4;
    while (cVar2 == '\0') {
      FUN_03033740();
      FUN_03025174();
      FUN_03037644(1);
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) break;
      cVar2 = *pcVar4;
    }
    *pcVar4 = '\0';
    FUN_0303fc58();
  }
  pcVar4[0x50] = '\0';
  pcVar4[0x51] = '\0';
  pcVar4[0x52] = '\0';
  pcVar4[0x53] = '\0';
  FUN_0303a328(0x1c);
  return;
}


