/**
 * FUN_03004382 @ 0x03004382
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03004382(void)

{
  char *pcVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  
  iVar3 = DAT_03004704;
  pcVar1 = DAT_03004700;
  puVar6 = (ushort *)(DAT_03004704 + -300);
  if (*(char *)(DAT_03004704 + (uint)*(ushort *)(DAT_03004704 + -0x128)) == '[') {
    uVar5 = 0;
    do {
      if ((uint)*(ushort *)(iVar3 + -0x12a) <= *(ushort *)(iVar3 + -0x128) + uVar5) {
        if ((*(byte *)puVar6 & 1) != 0) {
          return 0xffffffff;
        }
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            *(undefined1 *)(iVar3 + uVar4) = *(undefined1 *)(iVar3 + (0x800 - uVar5) + uVar4);
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar5);
        }
        uVar2 = FUN_02fe3d26(iVar3 + uVar5,0x800 - uVar5,(int)*pcVar1);
        *(ushort *)(iVar3 + -0x12a) = uVar2;
        if ((uint)uVar2 < 0x800 - uVar5) {
          *puVar6 = *puVar6 | 1;
        }
        else {
          *(undefined2 *)(iVar3 + -0x12a) = 0x800;
        }
        *(undefined2 *)(iVar3 + -0x128) = 0;
      }
      uVar5 = uVar5 + 1;
    } while (*(char *)(iVar3 + *(ushort *)(iVar3 + -0x128) + uVar5) != ']');
    uVar5 = (uint)*(ushort *)(iVar3 + -0x128);
    if ((((*(char *)(iVar3 + uVar5) == '[') && (uVar5 = uVar5 + iVar3, *(char *)(uVar5 + 3) == ':'))
        && (*(byte *)(uVar5 + 1) - 0x30 < 10)) &&
       (((*(byte *)(uVar5 + 2) - 0x30 < 10 && (*(byte *)(uVar5 + 4) - 0x30 < 10)) &&
        (uVar5 = *(byte *)(uVar5 + 5) - 0x30, uVar5 < 10)))) {
      return 0;
    }
    iVar3 = FUN_03004338(uVar5);
  }
  else {
    iVar3 = FUN_03004338();
  }
  if (iVar3 == -1) {
    return 0xffffffff;
  }
  return 1;
}


