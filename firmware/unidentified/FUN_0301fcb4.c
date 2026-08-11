/**
 * FUN_0301fcb4 @ 0x0301fcb4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301fcb4(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0301fcdc;
  *DAT_0301fcd8 = DAT_0301fcdc;
  iVar3 = DAT_0301fce0;
  do {
    uVar1 = UnsignedSaturate(iVar3,8);
    UnsignedDoesSaturate(iVar3,8);
    *(short *)(iVar2 + iVar3 * 2) = (short)uVar1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x200);
  return;
}


