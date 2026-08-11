/**
 * FUN_0302a2be @ 0x0302a2be
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0302a2be(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  rom_memzero(DAT_0302a380,0x556,param_3,param_4,param_4);
  iVar1 = DAT_0302a388;
  if (*DAT_0302a384 != 1) {
    *DAT_0302a38c = *(undefined1 *)(DAT_0302a388 + 0x5c);
    iVar2 = FUN_02ffd00e(iVar1 + 0x14,*(undefined4 *)(iVar1 + 0x34),*(int *)(iVar1 + 0x38) + -1,3,
                         DAT_0302a390);
    if (iVar2 != -1) {
      FUN_03011996(iVar2,DAT_0302a380,iVar1 + 0x1c);
    }
    FUN_02ffd4dc((int)(char)iVar2);
  }
  iVar1 = DAT_0302a380;
  if ((*(short *)(DAT_0302a380 + 0x15e) == 0) && (*(short *)(DAT_0302a380 + 0x458) != 0)) {
    iVar2 = 0;
    do {
      iVar3 = iVar1 + iVar2 * 2;
      *(undefined2 *)(iVar3 + 0x15e) = *(undefined2 *)(iVar3 + 0x458);
      iVar2 = (int)(char)((char)iVar2 + '\x01');
    } while (iVar2 < 0x7f);
  }
  return 0;
}


