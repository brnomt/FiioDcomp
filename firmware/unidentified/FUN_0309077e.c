/**
 * FUN_0309077e @ 0x0309077e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0309077e(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    uVar2 = FUN_03082bfa(*(undefined4 *)(param_1 + 0x50));
    uVar3 = FUN_03082972(0x3f800000,uVar2);
    uVar2 = DAT_030908d8;
    iVar9 = *(int *)(param_1 + 0xec);
    if (*(int *)(param_1 + 0x40) == 1) {
      iVar5 = 0;
      **(int **)(param_1 + 0x130) = **(int **)(param_1 + 0xe8) + -1;
      piVar1 = DAT_030908dc;
      iVar9 = **(int **)(param_1 + 0xe8);
      if (0 < iVar9) {
        uVar8 = FUN_03082c6a(*(undefined4 *)(param_1 + 0x120));
        do {
          if (uVar8 < *(uint *)(*piVar1 + iVar5 * 4)) {
            **(int **)(param_1 + 0x130) = iVar5;
            break;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar9);
      }
      if (**(int **)(param_1 + 0xe8) == iVar5) {
        *(undefined4 *)(param_1 + 0x2c) = 0;
      }
      if (**(int **)(param_1 + 0x130) < 1) {
        return uVar2;
      }
    }
    else {
      uVar8 = 0;
      if (0 < *(int *)(param_1 + 0x90)) {
        do {
          *(int *)(*(int *)(param_1 + 0x130) + uVar8 * 4) =
               *(int *)(*(int *)(param_1 + 0xe8) + uVar8 * 4) + -1;
          uVar4 = FUN_03082bfa(*(int *)(param_1 + 0x98) / (1 << (uVar8 & 0xff)));
          uVar4 = FUN_03082906(uVar4,*(undefined4 *)(param_1 + 0x120));
          uVar4 = FUN_03082906(uVar4,uVar3);
          FUN_03082856(uVar4,0x3f000000);
          iVar5 = FUN_03082c38();
          iVar6 = 1;
          iVar7 = *(int *)(*(int *)(param_1 + 0xe8) + uVar8 * 4);
          if (1 < iVar7) {
            do {
              if (iVar5 < *(int *)(iVar9 + iVar6 * 4)) {
                *(int *)(*(int *)(param_1 + 0x130) + uVar8 * 4) = iVar6 + -1;
                break;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 < iVar7);
          }
          if (*(int *)(*(int *)(param_1 + 0x130) + uVar8 * 4) < 1) {
            return uVar2;
          }
          iVar9 = iVar9 + 0x74;
          uVar8 = uVar8 + 1;
        } while ((int)uVar8 < *(int *)(param_1 + 0x90));
      }
    }
    *(undefined4 *)(param_1 + 0x124) = **(undefined4 **)(param_1 + 0x130);
  }
  return 0;
}


