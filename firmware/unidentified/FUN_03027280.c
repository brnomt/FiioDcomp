/**
 * FUN_03027280 @ 0x03027280
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03027280(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar1 = mp3_bitstream_getbits(8);
  iVar2 = mp3_bitstream_getbits(8);
  if (iVar1 != 0xff || iVar2 != 0xd8) {
    iVar4 = 0x200;
    iVar1 = -0xd9;
    do {
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) goto LAB_030272ca;
      iVar3 = mp3_bitstream_getbits(8);
      bVar5 = iVar2 != 0xff;
      iVar2 = iVar3;
    } while (bVar5 || iVar3 != 0xd8);
    if (*DAT_030273f8 >> 8 != 0xff) goto LAB_030272ca;
  }
  iVar1 = 0;
LAB_030272ca:
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar2 = FMControlTask_Enter();
  if (iVar2 == 0xc0 || iVar2 == 0xc1) {
    iVar2 = AudioShellTest();
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  else if (iVar2 == 0xc2) {
    return -0xea;
  }
  return 0;
}


