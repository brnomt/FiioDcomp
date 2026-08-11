/**
 * FUN_030013ea @ 0x030013ea
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030013ea(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_38 [8];
  int iStack_30;
  ushort local_28 [2];
  int iStack_24;
  int aiStack_20 [2];
  
  uVar4 = 0;
  iVar3 = func_0x02fdf118(*DAT_03001658,DAT_03001654);
  if ((iVar3 == 1) && (*DAT_03001620 == 1)) {
    FUN_02ff5614(DAT_03001640 + 0x1a1,*DAT_03001640,DAT_03001640[3],
                 (uint)*(ushort *)(DAT_0300161c + (uint)*(ushort *)(DAT_0300161c + 10) * 2 + 2) +
                 param_1);
    piVar2 = DAT_03001660;
    iVar3 = DAT_0300165c;
    uVar4 = DAT_0300164c;
    piVar1 = DAT_03001644;
    if (*(short *)(DAT_0300165c + 0xf2) == 10) {
      FUN_02ff0378(DAT_0300164c,
                   *DAT_03001644 * 0x200 +
                   (*(int *)(DAT_0300165c + 0x34) + *(int *)(DAT_0300165c + 0x38)) * 2 + 0xa5ffffe,2
                   ,local_28);
      FUN_02ff0378(uVar4,*piVar1 * 0x200 + 0x8000000 +
                         (*(int *)(iVar3 + 0x34) + (uint)local_28[0]) * 0x10,0x10,auStack_38);
      FUN_02ff0378(uVar4,*piVar1 * 0x200 + iStack_30 * 0x800,4,&iStack_24);
      FUN_02ff0378(uVar4,*piVar1 * 0x200 + iStack_30 * 0x800 + 4,4,aiStack_20);
      if (*piVar2 != iStack_24) {
        return 0;
      }
      if (piVar2[1] != aiStack_20[0]) {
        return 0;
      }
    }
    else {
      if (*DAT_03001660 != *(int *)(DAT_0300165c + 0x34)) {
        return 0;
      }
      if (DAT_03001660[1] != *(int *)(DAT_0300165c + 0x38)) {
        return 0;
      }
    }
    uVar4 = 1;
  }
  return uVar4;
}


