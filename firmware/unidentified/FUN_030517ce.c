/**
 * FUN_030517ce @ 0x030517ce
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030517ce(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 2000;
  if (*DAT_03051a8c == 1) {
    *DAT_03051a8c = 2;
    iVar1 = FUN_03027fa8(5);
    while (iVar1 == 1) {
      FUN_03037668(1);
      FUN_03033740();
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) break;
      iVar1 = FUN_03027fa8(5);
    }
    FUN_03022304(0,2);
    FUN_03024598(3,1);
    FUN_030516d2();
    iVar2 = DAT_03051a88;
    *(ushort *)(DAT_03051a88 + 0xc) = *(ushort *)(DAT_03051a88 + 0xc) & 0xfffd;
    *(undefined4 *)(iVar2 + 0x30) = 0;
    *(undefined4 *)(iVar2 + 0x34) = 0;
  }
  return 1;
}


