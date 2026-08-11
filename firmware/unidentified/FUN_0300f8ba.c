/**
 * FUN_0300f8ba @ 0x0300f8ba
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300f8ba(char *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint unaff_r6;
  uint uVar6;
  undefined4 uVar7;
  undefined1 auStack_820 [68];
  undefined4 local_7dc;
  uint local_7d8;
  byte local_420 [1024];
  
  uVar7 = 0;
  FUN_02ffe4ec(0x23);
  if (param_1 != (char *)0x0) {
    uVar5 = 0;
    if (*param_1 != -1) {
      unaff_r6 = *(uint *)(param_1 + 4);
    }
    if (*param_1 != -1 && unaff_r6 != 0) {
      do {
        uVar6 = uVar5 + (unaff_r6 - uVar5 >> 1);
        FUN_02feb510(auStack_820,0x400);
        FUN_02fefa82(*(int *)(param_1 + 8) + uVar6 * 0x4c,0,(int)*param_1);
        FUN_02fef58a(auStack_820,0x4c,(int)*param_1);
        iVar1 = FUN_02feb54c(param_2,auStack_820);
        if (0 < iVar1) {
          uVar5 = uVar6 + 1;
        }
        if (iVar1 < 0) {
          unaff_r6 = uVar6;
        }
        if (iVar1 == 0) {
          uVar7 = 1;
          if (param_3 != 0) {
            FUN_02ff2dfe(&DAT_0300f9e4,param_3);
            iVar1 = FUN_02fef2aa(&DAT_0300f9e4,param_3,&LAB_0300f9f8);
            uVar7 = 1;
            if (iVar1 != -1) {
              FUN_02fefa82(local_7dc,0,(int)*param_1);
              if (0 < (int)local_7d8) goto LAB_0300f97e;
              goto LAB_0300f9c6;
            }
          }
          break;
        }
      } while (uVar5 < unaff_r6);
    }
  }
  goto LAB_0300f934;
  while( true ) {
    iVar3 = 0;
    do {
      local_420[iVar3] = local_420[iVar3] ^ 0xf;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
    uVar4 = FUN_02fefa20(iVar1);
    FUN_02ff2ffc(local_420,uVar4,iVar2,iVar1);
    local_7d8 = local_7d8 - iVar2;
    if ((int)local_7d8 < 1) break;
LAB_0300f97e:
    uVar5 = local_7d8;
    if (0x400 < local_7d8) {
      uVar5 = 0x400;
    }
    iVar2 = FUN_02fef58a(local_420,uVar5,(int)*param_1);
    if (iVar2 < 1) break;
  }
LAB_0300f9c6:
  FUN_02fef470(iVar1);
LAB_0300f934:
  FUN_02ffe538(0x23);
  return uVar7;
}


