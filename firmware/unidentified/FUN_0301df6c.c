/**
 * FUN_0301df6c @ 0x0301df6c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301df6c(undefined4 *param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  param_1[3] = 0;
  iVar5 = DAT_0301e314;
  if (param_1[5] != 0) {
    iVar2 = *(int *)(DAT_0301e314 + 8);
    while (iVar2 != 0) {
      uVar3 = param_1[8];
      if (uVar3 < 0x10) {
        ape_rom_seek_thunk(-(*(int *)(iVar5 + 0x18) + 0x400),3,param_1[1]);
        uVar3 = ape_rom_read_thunk(param_1 + 9,0x400,param_1[1]);
        if (uVar3 < 0x10) {
          return 2;
        }
        *(uint *)(iVar5 + 0x18) = uVar3;
      }
      param_1[8] = uVar3 - 0x10;
      iVar2 = *(int *)(iVar5 + 8) + -1;
      *(int *)(iVar5 + 8) = iVar2;
      sVar1 = *(short *)((int)param_1 + uVar3 + 0x16);
      if (sVar1 == 0x6277) {
        if (param_1[5] != 0) {
          param_1[5] = param_1[5] + -1;
          uVar6 = *(uint *)(DAT_0301e318 + 0xc);
          uVar4 = FUN_0301d680(*param_1);
          if (uVar4 < uVar6) {
            uVar4 = 0;
          }
          else {
            uVar4 = uVar4 - uVar6;
          }
          uVar6 = (uint)*(byte *)((int)param_1 + uVar3 + 0x1c) |
                  *(int *)((int)param_1 + uVar3 + 0x1d) << 8;
          param_1[6] = uVar6;
          uVar3 = (uint)*(byte *)((int)param_1 + uVar3 + 0x20) |
                  *(int *)((int)param_1 + uVar3 + 0x21) << 8;
          param_1[7] = uVar3;
          if (uVar4 < uVar6 + 8) {
            iVar5 = 8;
          }
          else {
            iVar5 = uVar4 - uVar6;
          }
          param_1[3] = iVar5 + -8;
          param_1[4] = uVar3;
          return 1;
        }
        return 2;
      }
      if (sVar1 != 0x6364) {
        return 0xffffffff;
      }
    }
  }
  return 2;
}


