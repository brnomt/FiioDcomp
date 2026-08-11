/**
 * FUN_0301dbc8 @ 0x0301dbc8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301dbc8(undefined4 param_1)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int unaff_r4;
  int unaff_r5;
  int *unaff_r6;
  int *unaff_r7;
  undefined *puStack00000000;
  
  puStack00000000 = (undefined *)param_1;
  iVar2 = FUN_02ff9eb2(unaff_r5 + 0x14,*(undefined4 *)(unaff_r5 + 0x34),
                       *(int *)(unaff_r5 + 0x38) + -1);
  unaff_r6[1] = iVar2;
  puStack00000000 = &DAT_0301df58;
  iVar2 = FUN_02ff9eb2(unaff_r5 + 0x14,*(undefined4 *)(unaff_r5 + 0x34),
                       *(int *)(unaff_r5 + 0x38) + -1,3);
  unaff_r7[1] = iVar2;
  iVar3 = *unaff_r7;
  if (((iVar3 != -1) && (*unaff_r6 != -1)) && (unaff_r6[1] != -1 && iVar2 != -1)) {
    iVar3 = FUN_0301d744(iVar3,DAT_0301df60);
    iVar2 = DAT_0301df64;
    puVar1 = DAT_0301df60;
    if ((iVar3 == 0) && (*DAT_0301df60 < 4)) {
      if ((uint)unaff_r7[1] < 8) {
        iVar3 = DAT_0301df64 + unaff_r7[1] * 0x27e;
        *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 0x20);
        *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar3 + 0x18);
      }
      if ((uint)unaff_r6[1] < 8) {
        iVar2 = iVar2 + unaff_r6[1] * 0x27e;
        *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar2 + 0x20);
        *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar2 + 0x18);
      }
      ape_rom_seek_thunk(*(undefined4 *)(puVar1 + 6),0,*unaff_r7);
      ape_rom_seek_thunk(*(undefined4 *)(puVar1 + 6),0,*unaff_r6);
      iVar2 = DAT_0301df68;
      *(undefined4 *)(DAT_0301df68 + 0x18) = 0x400;
      *(undefined4 *)(iVar2 + 0x1c) = 0x400;
      unaff_r7[5] = unaff_r4;
      unaff_r6[5] = unaff_r4;
      unaff_r7[8] = 0x400;
      unaff_r6[8] = 0x400;
      return 0;
    }
    FUN_0301d69c(*unaff_r7);
    FUN_0301d69c(*unaff_r6);
    FUN_0301d69c(unaff_r7[1]);
    FUN_0301d69c(unaff_r6[1]);
    return 0xffffffff;
  }
  FUN_0301d69c(iVar3);
  FUN_0301d69c(*unaff_r6);
  FUN_0301d69c(unaff_r7[1]);
  FUN_0301d69c(unaff_r6[1]);
  return 0xffffffff;
}


