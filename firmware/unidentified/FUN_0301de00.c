/**
 * FUN_0301de00 @ 0x0301de00
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301de00(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *unaff_r4;
  int unaff_r5;
  uint uVar4;
  int unaff_r7;
  int unaff_r8;
  uint unaff_r9;
  int unaff_r10;
  uint unaff_r11;
  
  do {
    *(int *)(unaff_r8 + 0x10) = *(int *)(unaff_r8 + 0x10) + -1;
    if (*(ushort *)(unaff_r5 + 2) == unaff_r9) {
      if (unaff_r4[5] == 0) {
        return 2;
      }
      unaff_r4[5] = unaff_r4[5] + -1;
      uVar4 = *(uint *)(unaff_r10 + 0xc);
      uVar1 = FUN_0301d680(*unaff_r4);
      if (uVar1 < uVar4) {
        uVar1 = 0;
      }
      else {
        uVar1 = uVar1 - uVar4;
      }
      uVar4 = (uint)*(byte *)(unaff_r5 + 8) | *(int *)(unaff_r5 + 9) << 8;
      unaff_r4[6] = uVar4;
      uVar3 = (uint)*(byte *)(unaff_r5 + 0xc) | *(int *)(unaff_r5 + 0xd) << 8;
      unaff_r4[7] = uVar3;
      if (uVar1 < uVar4 + 8) {
        iVar2 = 8;
      }
      else {
        iVar2 = uVar1 - uVar4;
      }
      unaff_r4[3] = iVar2 + -8;
      unaff_r4[4] = uVar3;
      if (uVar3 == 0) {
        return 3;
      }
      if (*(char *)(unaff_r5 + 4) != '\0' || (*(uint *)(unaff_r5 + 5) & 0xffffff) != 0) {
        return 1;
      }
    }
    else if (*(ushort *)(unaff_r5 + 2) != unaff_r11) {
      return 0xffffffff;
    }
    if (*(int *)(unaff_r8 + 0x10) == 0) {
      return 0xffffffff;
    }
    uVar1 = unaff_r4[8];
    if (uVar1 < 0x10) {
      ape_rom_seek_thunk(-(*(int *)(unaff_r8 + 0x1c) + 0x400),3,unaff_r4[1]);
      uVar1 = ape_rom_read_thunk(unaff_r4 + 9,0x400,unaff_r4[1]);
      if (uVar1 < 0x10) {
        return 2;
      }
      *(uint *)(unaff_r8 + 0x1c) = uVar1;
    }
    unaff_r5 = (uVar1 - 0x10) + unaff_r7;
    unaff_r4[8] = uVar1 - 0x10;
  } while( true );
}


