/**
 * FUN_0301de88 @ 0x0301de88
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301de88(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  iVar3 = DAT_0301df68;
  param_1[3] = 0;
  uVar1 = 0x400;
  if ((uint)param_1[5] < *(uint *)(iVar3 + 4)) {
    do {
      uVar4 = param_1[8];
      if (uVar4 < uVar1) {
        puVar6 = (undefined4 *)((int)param_1 + uVar4 + 0x24);
        param_1[8] = uVar4 + 0x10;
      }
      else {
        uVar1 = ape_rom_read_thunk(param_1 + 9,0x400,param_1[1]);
        if (uVar1 < 0x10) {
          return 2;
        }
        *(uint *)(iVar3 + 0x18) = uVar1;
        puVar6 = param_1 + 9;
        param_1[8] = 0x10;
      }
      *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
      if (*(short *)((int)puVar6 + 2) == 0x6277) {
        iVar2 = param_1[5];
        param_1[5] = iVar2 + 1U;
        if (iVar2 + 1U <= *(uint *)(iVar3 + 4)) {
          uVar4 = *(uint *)(DAT_0301df60 + 0xc);
          uVar1 = FUN_0301d680(*param_1);
          if (uVar1 < uVar4) {
            uVar1 = 0;
          }
          else {
            uVar1 = uVar1 - uVar4;
          }
          uVar4 = (uint)*(byte *)(puVar6 + 2) | *(int *)((int)puVar6 + 9) << 8;
          param_1[6] = uVar4;
          uVar5 = (uint)*(byte *)(puVar6 + 3) | *(int *)((int)puVar6 + 0xd) << 8;
          param_1[7] = uVar5;
          if (uVar4 < uVar1) {
            iVar3 = -8;
          }
          else {
            iVar3 = uVar4 - uVar1;
          }
          param_1[3] = iVar3 + 8;
          param_1[4] = uVar5;
          return 1;
        }
        return 2;
      }
      if (*(short *)((int)puVar6 + 2) != 0x6364) {
        return 0xffffffff;
      }
    } while (param_1[5] != *(int *)(iVar3 + 4));
  }
  return 2;
}


