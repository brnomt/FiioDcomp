/**
 * FUN_030ae06a @ 0x030ae06a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030ae06a(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_r8;
  int iVar7;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  piVar2 = DAT_030ae31c;
  if (param_1 != (int *)0x0) {
    unaff_r8 = *param_1;
  }
  if (param_1 == (int *)0x0 || unaff_r8 == 0) {
    return -2;
  }
  iVar5 = 0;
  iVar7 = 1;
  uStack_2c = param_2;
  uStack_28 = param_3;
  uStack_24 = param_4;
  do {
    iVar3 = FUN_030b1990(param_1,&uStack_2c,&uStack_28,&uStack_24);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = 0;
    iVar6 = *(int *)(*piVar2 + param_1[10] * 4);
    iVar5 = iVar5 + iVar6;
    if (0 < iVar6) {
      do {
        iVar4 = FUN_030b27e4(param_1,&uStack_2c,&uStack_28,&uStack_24);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar6);
    }
  } while ((param_1[10] != 7) && (bVar1 = iVar7 < 0x100, iVar7 = iVar7 + 1, bVar1));
  if (0 < iVar5) {
    *(int *)(unaff_r8 + 0x870) = iVar5;
    param_1[0x10] = iVar5;
    *(undefined4 *)(unaff_r8 + 0x874) = 1;
    return 0;
  }
  return -7;
}


