/**
 * FUN_0306e990 @ 0x0306e990
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0306e990(void)

{
  ushort uVar1;
  longlong lVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  
  piVar4 = DAT_0306ed20;
  iVar3 = DAT_0306ed1c;
  iVar7 = 0;
  *(int *)(DAT_0306ed1c + -0x34) = *(int *)(DAT_0306ed1c + 0x14) + 0x40;
  do {
    while( true ) {
      if (*piVar4 == 1) goto LAB_0306ea86;
      if ((*(short *)(*(int *)(iVar3 + -0x38) + 0x3c) == 1) &&
         (iVar5 = (**(code **)(iVar3 + 0x1c))(*(undefined4 *)(iVar3 + 0x18)), iVar5 != 0)) break;
LAB_0306e9ee:
      while( true ) {
        iVar5 = FUN_0306f87e(*(undefined4 *)(iVar3 + -0x34),*(undefined4 *)(iVar3 + -0x38));
        if (iVar5 != -1) {
          *(undefined4 *)(iVar3 + -0x3c) = 0;
          piVar4[3] = 0;
          goto LAB_0306ea46;
        }
        uVar1 = *(ushort *)(*(int *)(iVar3 + -0x38) + 0x3c);
        if (uVar1 == 1) break;
        if ((uVar1 & 0xff00) == 0) goto LAB_0306ea86;
        iVar7 = iVar7 + 1;
        *(int *)(iVar3 + -0x14) = *(int *)(iVar3 + -0x14) + *(int *)(iVar3 + -0x18);
        if (0x80 < iVar7) {
          hifi_debug_printf(s_dec_error_cnt_>_128_0306ed24);
          goto LAB_0306ea86;
        }
        iVar5 = (**(code **)(iVar3 + -0x2c))
                          (*(undefined4 *)(iVar3 + -0x40),*(int *)(iVar3 + -0x38),
                           *(undefined4 *)(iVar3 + -0x34));
        if (iVar5 != 0) {
          if (iVar5 == 0x10 || iVar5 == 0x11) goto LAB_0306ea86;
          if (iVar5 != 0x20) goto LAB_0306ea46;
        }
      }
    }
    if (iVar5 == 0x10) {
      lVar2 = (ulonglong)*(uint *)(iVar3 + -0x1c) * (ulonglong)*(uint *)(iVar3 + -0x28);
      uVar6 = FUN_0306d2d6((int)lVar2,
                           ((int)*(uint *)(iVar3 + -0x1c) >> 0x1f) * *(uint *)(iVar3 + -0x28) +
                           (int)((ulonglong)lVar2 >> 0x20),1000,0);
      *(undefined4 *)(iVar3 + -0x14) = uVar6;
LAB_0306ea86:
      FUN_0306f378();
      uVar8 = *(int *)(iVar3 + -0x14) + *(int *)(iVar3 + -0x18);
      *(uint *)(iVar3 + -0x14) = uVar8;
      lVar2 = (ulonglong)*(uint *)(iVar3 + -0x1c) * (ulonglong)*(uint *)(iVar3 + -0x28);
      uVar9 = FUN_0306d2d6((int)lVar2,
                           ((int)*(uint *)(iVar3 + -0x1c) >> 0x1f) * *(uint *)(iVar3 + -0x28) +
                           (int)((ulonglong)lVar2 >> 0x20),1000,0);
      if ((int)((ulonglong)uVar9 >> 0x20) < (int)(uint)((uint)uVar9 < uVar8)) {
        *(uint *)(iVar3 + -0x14) = (uint)uVar9;
      }
      return 0;
    }
    if (iVar5 == 0x11) goto LAB_0306ea86;
    if (iVar5 != 0x20) goto LAB_0306e9ee;
    if (*(short *)(*(int *)(iVar3 + -0x38) + 0x3c) != 1) {
LAB_0306ea46:
      uVar8 = *(int *)(iVar3 + -0x14) + *(int *)(iVar3 + -0x18);
      *(uint *)(iVar3 + -0x14) = uVar8;
      lVar2 = (ulonglong)*(uint *)(iVar3 + -0x1c) * (ulonglong)*(uint *)(iVar3 + -0x28);
      uVar9 = FUN_0306d2d6((int)lVar2,
                           ((int)*(uint *)(iVar3 + -0x1c) >> 0x1f) * *(uint *)(iVar3 + -0x28) +
                           (int)((ulonglong)lVar2 >> 0x20),1000,0);
      if ((int)((ulonglong)uVar9 >> 0x20) < (int)(uint)((uint)uVar9 < uVar8)) {
        *(uint *)(iVar3 + -0x14) = (uint)uVar9;
        *piVar4 = *piVar4 + 1;
      }
      *DAT_0306ed38 = *DAT_0306ed38 + 1;
      return 1;
    }
  } while( true );
}


