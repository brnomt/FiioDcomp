/**
 * FUN_0305145e @ 0x0305145e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0305145e(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0302ebee(DAT_03051654 + 0x96,DAT_03051654 + 0x10);
  iVar1 = DAT_03051658;
  *(short *)(DAT_03051658 + 8) = (short)iVar2;
  iVar3 = DAT_0305165c;
  if (iVar2 == -1) {
    return 0;
  }
  iVar2 = DAT_0305165c + iVar2 * 0x27e;
  FUN_03051018(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x1c));
  iVar3 = FUN_0302edec(*(undefined4 *)(iVar1 + 0x60),
                       *(undefined4 *)(iVar3 + *(short *)(iVar1 + 8) * 0x27e + 0x10),0x1000,
                       (int)(char)*(short *)(iVar1 + 8));
  if (iVar3 == 0x1000) {
    *(undefined4 *)(iVar1 + 0x50) = 0x1000;
    return 1;
  }
  func_0x0302b260((int)*(char *)(iVar1 + 8));
  return 0;
}


