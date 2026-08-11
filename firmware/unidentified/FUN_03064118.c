/**
 * FUN_03064118 @ 0x03064118
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03064118(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_03064474;
  if (*(int *)(DAT_03064474 + 0x20) == 0) {
    uVar2 = FUN_03021ffe(0);
    FUN_030324b2(4,DAT_0306447c + (1 - *(int *)(DAT_03064478 + -0x334)) * 0x3000,uVar2,
                 *(undefined4 *)(iVar1 + 0x1c));
    return;
  }
  return;
}


