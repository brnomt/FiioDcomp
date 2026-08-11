/**
 * MusicPlay_PlayProcessDisplay @ 0x0301b27c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */

undefined4
MusicPlay_PlayProcessDisplay
          (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = DAT_0301b74c;
  switch(param_1) {
  case 3:
    uVar5 = FUN_0301b83c();
    *param_2 = uVar5;
    return 1;
  case 4:
    uVar5 = FUN_0301b830();
    *param_2 = uVar5;
    return 1;
  case 5:
    uVar5 = FUN_0301b836();
    *param_2 = uVar5;
    return 1;
  case 6:
    uVar5 = FUN_0301b842();
    *param_2 = uVar5;
    return 1;
  case 7:
    iVar8 = FUN_0301b830();
    iVar4 = FUN_0301b848();
    uVar5 = FUN_02ff5cbe((int)((longlong)iVar4 * 1000),
                         (int)((ulonglong)((longlong)iVar4 * 1000) >> 0x20),iVar8,iVar8 >> 0x1f);
    *param_2 = uVar5;
    break;
  case 8:
    *DAT_0301b754 = DAT_0301b750;
    *DAT_0301b75c = DAT_0301b758;
    *DAT_0301b764 = DAT_0301b760;
    *DAT_0301b76c = DAT_0301b768;
    *DAT_0301b774 = DAT_0301b770;
    *DAT_0301b77c = DAT_0301b778;
    *DAT_0301b784 = DAT_0301b780;
    *DAT_0301b78c = DAT_0301b788;
    *DAT_0301b790 = 0;
    *(undefined2 *)(iVar8 + 0x16) = 0;
    *(undefined4 *)(iVar8 + 0x20) = 0;
    *(undefined1 *)(iVar8 + 0x15) = 0;
    *(undefined4 *)(iVar8 + 0x1c) = 0;
    *(undefined4 *)(iVar8 + 0x24) = 0;
    FUN_02ff5da8(DAT_0301b730,0x1200,param_3,param_4,1,param_2,param_3,param_4);
    FUN_02ff5da8(DAT_0301b794,0x1200);
    *DAT_0301b73c = DAT_0301b730;
    *DAT_0301b724 = *DAT_0301b798;
    (*(code *)*DAT_0301b79c)(0,0,*DAT_0301b798);
    puVar3 = DAT_0301b7a4;
    *DAT_0301b7a4 = DAT_0301b7a0;
    puVar3[1] = 0x800;
    FUN_0301bd94(DAT_0301b7a8,DAT_0301b7a4,0x301b301,0,0,&LAB_0301b392_1,&LAB_0301b3c6_1,0);
    if (*(int *)(DAT_0301b7a8 + 0x1c) == 0) {
      uVar5 = 0;
    }
    else {
      if (*(int *)(DAT_0301b7a8 + 0x2c) == 0) {
        *DAT_0301b7ac = 0x301b399;
        *DAT_0301b7b0 = DAT_0301b7b4;
      }
      else {
        *DAT_0301b7ac = *(undefined4 *)(DAT_0301b7a8 + 0x2c);
        *DAT_0301b7b0 = *(undefined4 *)(DAT_0301b7a8 + 0x18);
      }
      iVar4 = DAT_0301b7a8;
      *(undefined4 *)(DAT_0301b7a8 + 0x14) = DAT_0301b7b8;
      *DAT_0301b7bc = *(int *)(iVar4 + 0x14);
      *DAT_0301b734 = *(int *)(DAT_0301b7a8 + 0x14) + 0x40;
      *DAT_0301b740 = *(int *)(DAT_0301b7a8 + 0x14) + 0x84;
      FUN_0301c374(*DAT_0301b7bc);
      FUN_0301be4e(*DAT_0301b734);
      FUN_0301c768(*DAT_0301b740);
      *(undefined4 *)(*DAT_0301b7bc + 0x38) = *(undefined4 *)(DAT_0301b7a8 + 4);
      (**(code **)(DAT_0301b7a8 + 0x1c))(*(undefined4 *)(DAT_0301b7a8 + 0x18),*DAT_0301b7bc);
      uVar5 = DAT_0301b730;
      *DAT_0301b72c = DAT_0301b730;
      *DAT_0301b738 = uVar5;
      *(undefined4 *)(*DAT_0301b734 + 0x2c) = *DAT_0301b72c;
      *(undefined4 *)(*DAT_0301b734 + 0x30) = *DAT_0301b738;
      *(undefined4 *)(*DAT_0301b734 + 0x34) = 0;
      *(undefined4 *)(*DAT_0301b734 + 0x38) = 0;
      uVar5 = 1;
      if (*(short *)(iVar8 + 0x16) == 0) {
        *(short *)(iVar8 + 0x16) = (short)*DAT_0301b7c0;
      }
      if (*(int *)(iVar8 + 0x20) == 0) {
        *(undefined4 *)(iVar8 + 0x20) = *DAT_0301b7c4;
      }
      if (*(char *)(iVar8 + 0x15) == '\0') {
        *(char *)(iVar8 + 0x15) = (char)*DAT_0301b7c8;
      }
      if (*(int *)(iVar8 + 0x20) == 0) {
        *DAT_0301b7d0 = 60000;
        *(undefined4 *)(iVar8 + 0x28) = 60000;
      }
      else if (*(int *)(iVar8 + 0x1c) == 0) {
        uVar7 = (*(code *)*DAT_0301b7cc)(*DAT_0301b798);
        lVar2 = ((ulonglong)uVar7 * 1000 & 0xffffffff) * 8;
        uVar6 = FUN_02ff5cbe((int)lVar2,
                             (int)((ulonglong)uVar7 * 1000 >> 0x20) * 8 +
                             (int)((ulonglong)lVar2 >> 0x20),*(undefined4 *)(iVar8 + 0x20),0);
        *(undefined4 *)(iVar8 + 0x28) = uVar6;
      }
      else {
        uVar1 = (ulonglong)*(uint *)(iVar8 + 0x1c) * 1000;
        lVar2 = (uVar1 & 0xffffffff) * 8;
        uVar6 = FUN_02ff5cbe((int)lVar2,(int)(uVar1 >> 0x20) * 8 + (int)((ulonglong)lVar2 >> 0x20),
                             *(undefined4 *)(iVar8 + 0x20));
        *(undefined4 *)(iVar8 + 0x28) = uVar6;
      }
      if (*DAT_0301b7d4 == 0) {
        *DAT_0301b7d4 = 0x480;
      }
      puVar3 = DAT_0301b7d8;
      *DAT_0301b7d8 = 0x480;
      *(undefined4 *)(iVar8 + 0x2c) = *puVar3;
      *(undefined4 *)(iVar8 + 0x24) = 0;
      *DAT_0301b7c0 = (uint)*(ushort *)(iVar8 + 0x16);
      *DAT_0301b7c4 = *(undefined4 *)(iVar8 + 0x20);
      *DAT_0301b7c8 = (uint)*(byte *)(iVar8 + 0x15);
      *DAT_0301b7d0 = *(undefined4 *)(iVar8 + 0x28);
      *DAT_0301b7dc = *(undefined4 *)(iVar8 + 0x24);
    }
    return uVar5;
  default:
    return 0;
  case 10:
    FUN_0301b678(param_2,param_3);
    break;
  case 0xc:
    *DAT_0301b734 = *(int *)(DAT_0301b7a8 + 0x14) + 0x40;
    do {
      if ((*(short *)(*DAT_0301b7bc + 0x3c) == 1) &&
         (iVar8 = (**(code **)(DAT_0301b7a8 + 0x1c))
                            (*(undefined4 *)(DAT_0301b7a8 + 0x18),*DAT_0301b7bc), iVar8 != 0)) {
        if ((iVar8 == 0x10) || (iVar8 == 0x11)) {
LAB_0301b826:
          FUN_0301c35e();
          return 0;
        }
        if (iVar8 != 0x20) goto LAB_0301b6d4;
      }
      else {
LAB_0301b6d4:
        while( true ) {
          iVar8 = FUN_0301c2de(*DAT_0301b734,*DAT_0301b7bc);
          if (iVar8 != -1) {
            *DAT_0301b994 = 0;
            goto LAB_0301b808;
          }
          if (*(short *)(*DAT_0301b7bc + 0x3c) == 1) break;
          if ((*(ushort *)(*DAT_0301b7bc + 0x3c) & 0xff00) == 0) goto LAB_0301b826;
          iVar8 = (*(code *)*DAT_0301b7ac)(*DAT_0301b7b0,*DAT_0301b7bc,*DAT_0301b734);
          if (iVar8 != 0) {
            if ((iVar8 == 0x10) || (iVar8 == 0x11)) goto LAB_0301b826;
            if (iVar8 != 0x20) goto LAB_0301b808;
          }
        }
      }
      if (*(short *)(*DAT_0301b998 + 0x3c) != 1) {
LAB_0301b808:
        *DAT_0301b99c = *DAT_0301b99c + *DAT_0301b9a0;
        *DAT_0301b9a4 = *DAT_0301b9a4 + 1;
        return 1;
      }
    } while( true );
  case 0xe:
    I2CSetSpeed(param_2);
    break;
  case 0xf:
    FUN_0301b84e();
  }
  return 1;
}
