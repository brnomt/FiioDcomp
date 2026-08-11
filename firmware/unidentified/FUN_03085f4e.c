/**
 * FUN_03085f4e @ 0x03085f4e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03085f4e(int param_1)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar10 = 0;
  if (0 < *(short *)(param_1 + 0x188)) {
    do {
      iVar7 = *(int *)(param_1 + 0xd8) + *(short *)(*(int *)(param_1 + 0x18c) + iVar10 * 2) * 0xfc;
      psVar3 = *(short **)(iVar7 + 0xc0);
      sVar1 = *(short *)(*(int *)(psVar3 + 4) + *(short *)(iVar7 + 0x7c) * 2);
      iVar8 = (int)sVar1;
      *(short *)(iVar7 + 0x86) = sVar1;
      *(undefined2 *)(iVar7 + 0x84) =
           *(undefined2 *)(*(int *)(psVar3 + 4) + *(short *)(iVar7 + 0x7c) * 2 + -2);
      *(undefined2 *)(iVar7 + 0x88) =
           *(undefined2 *)(*(int *)(psVar3 + 4) + *(short *)(iVar7 + 0x7c) * 2 + 2);
      if (*psVar3 < 2) {
        iVar9 = 0;
        *(undefined4 *)(param_1 + 200) = **(undefined4 **)(param_1 + 0xe8);
        *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0xec);
        uVar5 = **(undefined4 **)(param_1 + 0xf4);
      }
      else {
        sVar2 = wma_floor_log2(*(int *)(param_1 + 0x9c) / iVar8);
        iVar9 = (int)sVar2;
        if (*(int *)(param_1 + 0x90) <= iVar9) {
          return DAT_0308613c;
        }
        if (0 < iVar9) {
          for (iVar4 = iVar9 >> 1; iVar4 != 0; iVar4 = iVar4 + -1) {
          }
        }
        *(undefined4 *)(param_1 + 200) = *(undefined4 *)(*(int *)(param_1 + 0xe8) + iVar9 * 4);
        *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xec) + iVar9 * 0x74;
        uVar5 = *(undefined4 *)(*(int *)(param_1 + 0xf4) + iVar9 * 4);
      }
      *(undefined4 *)(param_1 + 0xd0) = uVar5;
      *(int *)(param_1 + 0xa4) = (*(int *)(param_1 + 0xac) * iVar8) / *(int *)(param_1 + 0x9c);
      *(int *)(param_1 + 0xa8) = (iVar8 * *(int *)(param_1 + 0xb0)) / *(int *)(param_1 + 0x9c);
      *(short *)(iVar7 + 0x80) = sVar1;
      *(int *)(iVar7 + 0x2c) = *(int *)(param_1 + 0xa8) - *(int *)(param_1 + 0xa4);
      if (*(int *)(param_1 + 0x2c) == 1) {
        uVar5 = FUN_03082bfa(*(undefined4 *)(param_1 + 0x50));
        uVar6 = FUN_03082bfa(iVar8);
        uVar6 = FUN_03082906(uVar6,*(undefined4 *)(param_1 + 0x120));
        uVar6 = FUN_030829f2(uVar6,1);
        uVar5 = FUN_03082972(uVar6,uVar5);
        FUN_03082856(uVar5,0x3f000000);
        iVar8 = FUN_03082c38();
        *(int *)(param_1 + 0x128) = iVar8;
        if (*(short *)(iVar7 + 0x80) < iVar8) {
          iVar8 = (int)*(short *)(iVar7 + 0x80);
        }
        *(int *)(param_1 + 0x128) = iVar8;
        *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(*(int *)(param_1 + 0x130) + iVar9 * 4);
      }
      *(short *)(iVar7 + 0x82) = *(short *)(iVar7 + 0x80);
      *(int *)(iVar7 + 0x98) = (int)*(short *)(iVar7 + 0x80);
      if (iVar10 == 0) {
        *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_1 + 0x98);
        *(undefined4 *)(param_1 + 0x154) = *(undefined4 *)(param_1 + 0x9c);
        *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(param_1 + 0xa8);
      }
      FUN_03087f6e(param_1,1,(int)*(short *)(iVar7 + 0x84),(int)*(short *)(iVar7 + 0x86),
                   iVar7 + 0x8a,iVar7 + 0x8c);
      FUN_03087f9c(param_1,1,(int)*(short *)(iVar7 + 0x86),(int)*(short *)(iVar7 + 0x88),
                   *(undefined4 *)(iVar7 + 0x98),iVar7 + 0x8e,iVar7 + 0x90);
      iVar10 = (int)(short)((short)iVar10 + 1);
    } while (iVar10 < *(short *)(param_1 + 0x188));
  }
  FUN_03087fd0(param_1);
  return 0;
}


