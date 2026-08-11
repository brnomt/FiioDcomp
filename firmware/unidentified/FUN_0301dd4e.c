/**
 * FUN_0301dd4e @ 0x0301dd4e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301dd4e(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *unaff_r4;
  undefined4 *unaff_r5;
  uint unaff_r6;
  int unaff_r8;
  int unaff_r9;
  uint unaff_r10;
  int unaff_r11;
  
  do {
    param_3 = param_3 | *(int *)((int)unaff_r5 + 0xd) << 8;
    unaff_r4[7] = param_3;
    if (param_1 <= param_2) {
      unaff_r4[3] = (param_2 - param_1) + 8;
      unaff_r4[4] = param_3;
      if (param_3 == 0) {
        return 3;
      }
      if (*(char *)(unaff_r5 + 1) != '\0' || (*(uint *)((int)unaff_r5 + 5) & 0xffffff) != 0) {
        return 1;
      }
    }
    while( true ) {
      if (unaff_r4[5] == *(int *)(unaff_r8 + 0xc)) {
        return 2;
      }
      uVar1 = unaff_r4[8];
      if (uVar1 < unaff_r6) {
        unaff_r5 = (undefined4 *)(uVar1 + unaff_r9);
        unaff_r4[8] = uVar1 + 0x10;
      }
      else {
        unaff_r6 = ape_rom_read_thunk(unaff_r4 + 9,0x400,unaff_r4[1]);
        if (unaff_r6 < 0x10) {
          return 2;
        }
        *(uint *)(unaff_r8 + 0x1c) = unaff_r6;
        unaff_r5 = unaff_r4 + 9;
        unaff_r4[8] = 0x10;
      }
      *(int *)(unaff_r8 + 0x10) = *(int *)(unaff_r8 + 0x10) + 1;
      if (*(ushort *)((int)unaff_r5 + 2) == unaff_r10) break;
      if (*(ushort *)((int)unaff_r5 + 2) != 0x6277) {
        return 0xffffffff;
      }
    }
    iVar2 = unaff_r4[5];
    unaff_r4[5] = iVar2 + 1U;
    if (*(uint *)(unaff_r8 + 0xc) < iVar2 + 1U) {
      return 2;
    }
    uVar1 = *(uint *)(unaff_r11 + 0xc);
    param_1 = FUN_0301d680(*unaff_r4);
    if (param_1 < uVar1) {
      param_1 = 0;
    }
    else {
      param_1 = param_1 - uVar1;
    }
    param_2 = (uint)*(byte *)(unaff_r5 + 2) | *(int *)((int)unaff_r5 + 9) << 8;
    unaff_r4[6] = param_2;
    param_3 = (uint)*(byte *)(unaff_r5 + 3);
  } while( true );
}


