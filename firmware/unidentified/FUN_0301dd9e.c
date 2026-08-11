/**
 * FUN_0301dd9e @ 0x0301dd9e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301dd9e(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  param_1[3] = 0;
  iVar3 = DAT_0301df68;
  iVar2 = DAT_0301df60;
  if (param_1[5] == 0) {
    return 2;
  }
  iVar4 = *(int *)(DAT_0301df68 + 0x10);
  do {
    if (iVar4 == 0) {
      return 0xffffffff;
    }
    uVar5 = param_1[8];
    if (uVar5 < 0x10) {
      ape_rom_seek_thunk(-(*(int *)(iVar3 + 0x1c) + 0x400),3,param_1[1]);
      uVar5 = ape_rom_read_thunk(param_1 + 9,0x400,param_1[1]);
      if (uVar5 < 0x10) {
        return 2;
      }
      *(uint *)(iVar3 + 0x1c) = uVar5;
    }
    param_1[8] = uVar5 - 0x10;
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + -1;
    sVar1 = *(short *)((int)param_1 + uVar5 + 0x16);
    if (sVar1 == 0x6364) {
      if (param_1[5] == 0) {
        return 2;
      }
      param_1[5] = param_1[5] + -1;
      uVar8 = *(uint *)(iVar2 + 0xc);
      uVar6 = FUN_0301d680(*param_1);
      if (uVar6 < uVar8) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 - uVar8;
      }
      uVar8 = (uint)*(byte *)((int)param_1 + uVar5 + 0x1c) |
              *(int *)((int)param_1 + uVar5 + 0x1d) << 8;
      param_1[6] = uVar8;
      uVar7 = (uint)*(byte *)((int)param_1 + uVar5 + 0x20) |
              *(int *)((int)param_1 + uVar5 + 0x21) << 8;
      param_1[7] = uVar7;
      if (uVar6 < uVar8 + 8) {
        iVar4 = 8;
      }
      else {
        iVar4 = uVar6 - uVar8;
      }
      param_1[3] = iVar4 + -8;
      param_1[4] = uVar7;
      if (uVar7 == 0) {
        return 3;
      }
      if (*(char *)((int)param_1 + uVar5 + 0x18) != '\0' ||
          (*(uint *)((int)param_1 + uVar5 + 0x19) & 0xffffff) != 0) {
        return 1;
      }
    }
    else if (sVar1 != 0x6277) {
      return 0xffffffff;
    }
    iVar4 = *(int *)(iVar3 + 0x10);
  } while( true );
}


