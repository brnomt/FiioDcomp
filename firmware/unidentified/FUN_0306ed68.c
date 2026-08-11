/**
 * FUN_0306ed68 @ 0x0306ed68
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0306ed68(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = DAT_0306f164;
  iVar3 = 0;
  if (DAT_0306f164[8] != 1) {
    return;
  }
  iVar4 = DAT_0306f164[7];
  iVar2 = *DAT_0306f164;
  do {
    if (iVar4 == 1) {
      do {
        while (*(int *)(iVar2 + 0x34) != *(int *)(iVar2 + 0x38)) {
          if (piVar1[8] != 1) {
            return;
          }
        }
        iVar3 = iVar3 + 1;
        if (0x400 < iVar3) {
          *(undefined4 *)(iVar2 + 0x34) = 0;
          *(undefined4 *)(iVar2 + 0x38) = 0;
          *(undefined4 *)(iVar2 + 0x3c) = 0;
          *(undefined4 *)(iVar2 + 0x40) = 0;
          piVar1[8] = 0;
        }
      } while (piVar1[8] == 1);
      return;
    }
    iVar3 = iVar3 + 1;
    if (0x5000 < iVar3) {
      *(undefined4 *)(iVar2 + 0x34) = 0;
      *(undefined4 *)(iVar2 + 0x38) = 0;
      *(undefined4 *)(iVar2 + 0x3c) = 0;
      *(undefined4 *)(iVar2 + 0x40) = 0;
      piVar1[8] = 0;
    }
  } while (piVar1[8] == 1);
  return;
}


