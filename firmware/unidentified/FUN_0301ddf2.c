/**
 * FUN_0301ddf2 @ 0x0301ddf2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301ddf2(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *unaff_r4;
  int iVar4;
  uint uVar5;
  int unaff_r7;
  int unaff_r8;
  uint unaff_r9;
  int unaff_r10;
  uint unaff_r11;
  char in_CY;
  
  do {
    if (in_CY == '\0') {
      return 2;
    }
    *(uint *)(unaff_r8 + 0x1c) = param_1;
    do {
      iVar4 = (param_1 - 0x10) + unaff_r7;
      unaff_r4[8] = param_1 - 0x10;
      *(int *)(unaff_r8 + 0x10) = *(int *)(unaff_r8 + 0x10) + -1;
      if (*(ushort *)(iVar4 + 2) == unaff_r9) {
        if (unaff_r4[5] == 0) {
          return 2;
        }
        unaff_r4[5] = unaff_r4[5] + -1;
        uVar5 = *(uint *)(unaff_r10 + 0xc);
        uVar1 = FUN_0301d680(*unaff_r4);
        if (uVar1 < uVar5) {
          uVar1 = 0;
        }
        else {
          uVar1 = uVar1 - uVar5;
        }
        uVar5 = (uint)*(byte *)(iVar4 + 8) | *(int *)(iVar4 + 9) << 8;
        unaff_r4[6] = uVar5;
        uVar3 = (uint)*(byte *)(iVar4 + 0xc) | *(int *)(iVar4 + 0xd) << 8;
        unaff_r4[7] = uVar3;
        if (uVar1 < uVar5 + 8) {
          iVar2 = 8;
        }
        else {
          iVar2 = uVar1 - uVar5;
        }
        unaff_r4[3] = iVar2 + -8;
        unaff_r4[4] = uVar3;
        if (uVar3 == 0) {
          return 3;
        }
        if (*(char *)(iVar4 + 4) != '\0' || (*(uint *)(iVar4 + 5) & 0xffffff) != 0) {
          return 1;
        }
      }
      else if (*(ushort *)(iVar4 + 2) != unaff_r11) {
        return 0xffffffff;
      }
      if (*(int *)(unaff_r8 + 0x10) == 0) {
        return 0xffffffff;
      }
      param_1 = unaff_r4[8];
    } while (0xf < param_1);
    ape_rom_seek_thunk(-(*(int *)(unaff_r8 + 0x1c) + 0x400),3,unaff_r4[1]);
    param_1 = ape_rom_read_thunk(unaff_r4 + 9,0x400,unaff_r4[1]);
    in_CY = 0xf < param_1;
  } while( true );
}


