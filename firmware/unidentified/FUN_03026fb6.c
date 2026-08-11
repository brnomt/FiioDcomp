/**
 * FUN_03026fb6 @ 0x03026fb6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03026fb6(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  
  iVar6 = mp3_bitstream_getbits(0x10);
  iVar7 = mp3_bitstream_getbits(8);
  if (iVar7 != 8) {
    return 0xffffff33;
  }
  sVar5 = mp3_bitstream_getbits(0x10);
  *DAT_030273d8 = sVar5;
  if ((int)sVar5 - 1U < 8000) {
    sVar5 = mp3_bitstream_getbits(0x10);
    *DAT_030273dc = sVar5;
    if ((int)sVar5 - 1U < 8000) {
      iVar8 = mp3_bitstream_getbits(8);
      piVar1 = DAT_030273e0;
      *DAT_030273e0 = iVar8;
      iVar4 = DAT_030273f0;
      iVar3 = DAT_030273ec;
      iVar2 = DAT_030273e8;
      iVar7 = DAT_030273e4;
      if (3 < iVar8) {
        return 0xffffff30;
      }
      if (iVar8 * 3 + 8 != iVar6) {
        return 0xffffff2f;
      }
      iVar6 = 0;
      if (0 < iVar8) {
        do {
          uVar9 = mp3_bitstream_getbits(8);
          *(undefined4 *)(iVar7 + iVar6 * 4) = uVar9;
          uVar9 = mp3_bitstream_getbits(4);
          *(undefined4 *)(iVar2 + iVar6 * 4) = uVar9;
          uVar9 = mp3_bitstream_getbits(4);
          *(undefined4 *)(iVar3 + iVar6 * 4) = uVar9;
          uVar9 = mp3_bitstream_getbits(8);
          *(undefined4 *)(iVar4 + iVar6 * 4) = uVar9;
          iVar6 = iVar6 + 1;
        } while (iVar6 < *piVar1);
      }
      return 0;
    }
  }
  return 0xffffff32;
}


