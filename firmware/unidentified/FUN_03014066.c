/**
 * FUN_03014066 @ 0x03014066
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03014066(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 uStack_28;
  undefined2 uStack_27;
  undefined2 uStack_25;
  
  uVar2 = 0;
  iVar4 = *DAT_03014448;
  if (*(ushort *)((int)DAT_03014448 + 0x1ee) != 0) {
    do {
      iVar4 = *(int *)(iVar4 + 4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(ushort *)((int)DAT_03014448 + 0x1ee));
  }
  if (*(char *)(iVar4 + 0x4e) == '\0') {
    return;
  }
  iVar3 = FUN_03013a86(iVar4,1);
  iVar1 = DAT_03014458;
  if (iVar3 == 0) {
    return;
  }
  if ((*(char *)(iVar4 + 0x4e) == '\x01') &&
     (*(char *)(DAT_03014454 + 0xf) == *(char *)(DAT_03014454 + 0xe))) {
    if (*(char *)(DAT_03014458 + 3) == '\x01') {
      *(undefined1 *)(DAT_03014458 + 3) = 2;
      *(undefined1 *)(iVar1 + 1) = 0;
      MediaLib_GetTotalFiles(0x14d);
      return;
    }
    *(undefined1 *)(DAT_03014458 + 3) = 1;
    return;
  }
  uStack_28 = 0;
  uStack_27 = 0x38;
  uStack_25 = 0x49;
  FUN_02fefe90(DAT_03014450,DAT_0301444c,&uStack_28);
  MediaLib_GetTotalFiles(0x155);
  MediaLib_GetTotalFiles_c(0x154);
  return;
}


