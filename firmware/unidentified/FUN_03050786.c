/**
 * FUN_03050786 @ 0x03050786
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Control flow encountered bad instruction data */

void FUN_03050786(void)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  int iVar4;
  
  psVar2 = DAT_030509a8;
  iVar1 = DAT_030509a4;
  if (*(int *)(DAT_030509a4 + 0x30) == 1) {
    *(undefined1 *)(DAT_030509a4 + 1) = 1;
    *(undefined4 *)(iVar1 + 0x34) = 0;
    return;
  }
  if (*DAT_030509a8 == 1) {
    uVar3 = FUN_03021f9a(0);
    *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(iVar1 + 0x44);
    iVar4 = 1 - *(int *)(iVar1 + 0x38);
    *(int *)(iVar1 + 0x38) = iVar4;
    iVar4 = *(int *)(iVar1 + 0x48) + iVar4 * 0x3000;
    *(int *)(iVar1 + 0x44) = iVar4;
    FUN_0303238c(5,uVar3,iVar4,*(uint *)(iVar1 + 0x3c) >> 1);
    *psVar2 = 1;
    *(undefined4 *)(iVar1 + 0x30) = 1;
    *(ushort *)(iVar1 + 10) = *(ushort *)(iVar1 + 10) & 0xfffe | 2;
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}


