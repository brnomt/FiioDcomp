/**
 * FUN_03051954 @ 0x03051954
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03051954(void)

{
  char cVar1;
  char *pcVar2;
  short *psVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  pcVar2 = DAT_03051a88;
  DAT_03051a88[3] = '\0';
  pcVar2[4] = '\0';
  pcVar2[2] = '\x01';
  pcVar2[1] = '\0';
  pcVar2[0x5c] = -1;
  pcVar2[0x5d] = -1;
  pcVar2[0x5e] = -1;
  pcVar2[0x5f] = -1;
  FUN_0303a2dc(0x1c);
  FUN_03037668(10);
  FUN_0303fc78(0x4c);
  FUN_0303aa84(0x40,7);
  FUN_03051c78();
  FUN_03051d88();
  FUN_03051680();
  iVar6 = FUN_0305145e();
  if (iVar6 == 0) {
    FUN_0303a328(0x1c);
    FUN_0303a438(0x6f);
    return;
  }
  pcVar2[0x68] = '\0';
  pcVar2[0x69] = '\0';
  pcVar2[0x6a] = '\0';
  pcVar2[0x6b] = '\0';
  *(undefined2 *)(pcVar2 + 0x68) = *(undefined2 *)(pcVar2 + 8);
  *(undefined4 *)(pcVar2 + 0x6c) = *(undefined4 *)(pcVar2 + 0x50);
  iVar6 = DAT_03051aa8;
  *pcVar2 = '\0';
  FUN_03040224(0x67,0,2);
  FUN_030401f8(pcVar2 + 0x68,0,2);
  cVar1 = *pcVar2;
  while (cVar1 == '\0') {
    FUN_03033740();
    FUN_03025174();
    FUN_03037644(1);
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) break;
    cVar1 = *pcVar2;
  }
  *pcVar2 = '\0';
  pcVar2[0x30] = '\0';
  pcVar2[0x31] = '\0';
  pcVar2[0x32] = '\0';
  pcVar2[0x33] = '\0';
  iVar6 = 2000;
  pcVar2[0x34] = '\0';
  pcVar2[0x35] = '\0';
  pcVar2[0x36] = '\0';
  pcVar2[0x37] = '\0';
  iVar7 = FUN_03027fa8(5);
  while (iVar7 == 1) {
    FUN_03037668(1);
    FUN_03033740();
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) break;
    iVar7 = FUN_03027fa8(5);
  }
  uVar8 = FUN_03021f9a(0);
  uVar5 = DAT_03051aac;
  psVar3 = DAT_03051a8c;
  if (*DAT_03051a8c == 0) {
    *(ushort *)(pcVar2 + 0xc) = *(ushort *)(pcVar2 + 0xc) | 2;
    uVar4 = DAT_03051a90;
    pcVar2[0x34] = '\x01';
    pcVar2[0x35] = '\0';
    pcVar2[0x36] = '\0';
    pcVar2[0x37] = '\0';
    FUN_0303238c(5,uVar8,*(undefined4 *)(pcVar2 + 0x44),*(uint *)(pcVar2 + 0x3c) >> 1,uVar4,uVar5);
    *psVar3 = 1;
    *(ushort *)(pcVar2 + 10) = *(ushort *)(pcVar2 + 10) & 0xfffe | 2;
    FUN_03022252(0,2);
    if (*(int *)(pcVar2 + 0x2c) == 0) {
      FUN_030234d6(0,*(undefined4 *)(pcVar2 + 0x24),0,1);
      FUN_030506de(*(undefined4 *)(pcVar2 + 0x14));
      FUN_0303323e(*(undefined4 *)(pcVar2 + 0x18));
    }
  }
  if (*(int *)(pcVar2 + 0x10) == 5) {
    FUN_030506de(*(undefined4 *)(pcVar2 + 0x14));
  }
  return;
}


