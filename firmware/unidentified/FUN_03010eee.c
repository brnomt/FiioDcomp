/**
 * FUN_03010eee @ 0x03010eee
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03010eee(void)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar3 = DAT_03011008;
  if (*DAT_03011008 == '\x02') {
    FUN_02ffe220();
    uVar4 = DAT_03011010;
    *(int *)(pcVar3 + 4) = *(int *)(pcVar3 + 4) + 1;
    pcVar7 = pcVar3 + 0xc;
    uVar5 = (uint)((ulonglong)uVar4 * (ulonglong)*DAT_0301100c >> 0x25);
    if (*(uint *)(pcVar3 + 8) != uVar5) {
      *(uint *)(pcVar3 + 8) = uVar5;
      if ((byte)pcVar3[0xe] < 0x3b) {
        pcVar3[0xe] = pcVar3[0xe] + 1;
      }
      else {
        pcVar3[0xe] = '\0';
        pcVar3[0xd] = pcVar3[0xd] + '\x01';
      }
      if (pcVar3[0xd] == '<') {
        pcVar3[0xd] = '\0';
        *pcVar7 = *pcVar7 + '\x01';
      }
      FUN_02fffbc8(0x1ae);
    }
    if (*(uint *)(pcVar3 + 4) +
        (uint)((ulonglong)uVar4 * (ulonglong)*(uint *)(pcVar3 + 4) >> 0x24) * -0x32 == 0) {
      cVar1 = pcVar3[0xf];
      pcVar3[0xf] = cVar1 + 3U;
      if (0x62 < (byte)(cVar1 + 3U)) {
        pcVar3[0xf] = '\0';
      }
      FUN_02fffbc8(0x1af);
    }
    iVar6 = DAT_03010ffc;
    bVar2 = pcVar3[1];
    *(char *)(DAT_03010ffc + (uint)bVar2 * 4) = *pcVar7;
    iVar6 = iVar6 + (uint)bVar2 * 4;
    *(char *)(iVar6 + 1) = pcVar3[0xd];
    *(char *)(iVar6 + 2) = pcVar3[0xe];
    *(char *)(iVar6 + 3) = pcVar3[0xf];
  }
  return 0;
}


