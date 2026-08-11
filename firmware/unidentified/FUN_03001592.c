/**
 * FUN_03001592 @ 0x03001592
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03001592(undefined2 *param_1,uint param_2)

{
  short sVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined4 uStack_88;
  int iStack_84;
  uint uStack_80;
  undefined1 auStack_40 [36];
  
  sVar1 = *(short *)(DAT_0300161c + 10);
  uVar2 = *DAT_03001620;
  if (sVar1 == 0) {
    if (uVar2 != 5) {
      if (5 < uVar2) {
        uVar3 = *DAT_03001628;
        uVar5 = (uint)*(ushort *)(DAT_03001624 + 0x3a);
        if (uVar2 == 8) {
LAB_030016ce:
          iStack_84 = 0;
          uVar6 = 0;
          uStack_88 = uVar3;
          uStack_80 = uVar5;
          if (param_2 != 0xffffffff) {
            do {
              FUN_02fe2a28(auStack_40,&uStack_88,DAT_03001ab0,2);
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_2 + 1);
          }
        }
        else {
          if (uVar2 != 9) {
            if (uVar2 != 0xc) {
              if (uVar2 != 100) goto LAB_0300160c;
              goto LAB_03001670;
            }
            goto LAB_030016ce;
          }
          iStack_84 = 0;
          uVar6 = 0;
          uStack_88 = uVar3;
          uStack_80 = uVar5;
          if (param_2 != 0xffffffff) {
            do {
              FUN_02fe2a28(auStack_40,&uStack_88,DAT_03001ab0,2);
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_2 + 1);
          }
        }
        FUN_02fe3024(uStack_88,iStack_84 + -1,2,param_1);
        goto LAB_0300179c;
      }
      if (uVar2 == 1) {
LAB_03001670:
        parse_v22_frame(param_1,*(undefined4 *)(DAT_0300161c + -0x664),
                        *(undefined4 *)(DAT_0300161c + -0x660),
                        *(undefined4 *)(DAT_0300161c + -0x65c),
                        *(undefined4 *)(DAT_0300161c + -0x658),
                        *(undefined4 *)(DAT_0300161c + -0x654),
                        *(undefined4 *)(DAT_0300161c + -0x650),
                        *(undefined4 *)(DAT_0300161c + -0x64c),param_2,0x80,sVar1,1);
        goto LAB_0300179c;
      }
      if (uVar2 == 2) {
        FUN_02ff55d8(DAT_03001aac,param_2,param_1);
        goto LAB_0300179c;
      }
      if (uVar2 != 3 && uVar2 != 4) {
LAB_0300160c:
        uVar5 = 0;
        puVar7 = param_1;
        do {
          uVar5 = uVar5 + 1;
          param_1 = puVar7 + 1;
          *puVar7 = 0;
          puVar7 = param_1;
        } while (uVar5 < 0x80);
        goto LAB_0300179c;
      }
    }
    parse_v22_frame(param_1,*(undefined4 *)(DAT_0300161c + -0x664),
                    *(undefined4 *)(DAT_0300161c + -0x660),*(undefined4 *)(DAT_0300161c + -0x65c),
                    *(undefined4 *)(DAT_0300161c + -0x658),*(undefined4 *)(DAT_0300161c + -0x654),
                    *(undefined4 *)(DAT_0300161c + -0x650),*(undefined4 *)(DAT_0300161c + -0x64c),
                    param_2 + *(ushort *)(DAT_0300161c + 2) & 0xffff,0x80,0,0);
    goto LAB_0300179c;
  }
  if (sVar1 == 1) {
    param_2 = param_2 + *(ushort *)(DAT_03001ab4 + 4);
    uVar4 = (undefined2)param_2;
    if (uVar2 != 3) {
      if (uVar2 == 4) {
        parse_v22_frame(param_1,*(undefined4 *)(DAT_0300161c + -0x664),
                        *(undefined4 *)(DAT_0300161c + -0x660),
                        *(undefined4 *)(DAT_0300161c + -0x65c),
                        *(undefined4 *)(DAT_0300161c + -0x658),
                        *(undefined4 *)(DAT_0300161c + -0x654),
                        *(undefined4 *)(DAT_0300161c + -0x650),
                        *(undefined4 *)(DAT_0300161c + -0x64c),param_2 & 0xffff,0x80,1,1);
        goto LAB_0300179c;
      }
      goto joined_r0x03001738;
    }
  }
  else {
    if (sVar1 != 2) {
      if (sVar1 == 3 && uVar2 == 5) {
        uVar3 = FUN_03001776(DAT_0300161c + -0x674,param_2 + *(ushort *)(DAT_03001ab4 + 8));
        return uVar3;
      }
      goto LAB_0300179c;
    }
    param_2 = param_2 + *(ushort *)(DAT_03001ab4 + 6);
    uVar4 = (undefined2)param_2;
    if (uVar2 == 3) {
      param_2 = param_2 & 0xffff;
      goto LAB_03001670;
    }
joined_r0x03001738:
    if (uVar2 != 5) goto LAB_0300179c;
  }
  parse_v22_frame(param_1,*(undefined4 *)(DAT_0300161c + -0x664),
                  *(undefined4 *)(DAT_0300161c + -0x660),*(undefined4 *)(DAT_0300161c + -0x65c),
                  *(undefined4 *)(DAT_0300161c + -0x658),*(undefined4 *)(DAT_0300161c + -0x654),
                  *(undefined4 *)(DAT_0300161c + -0x650),*(undefined4 *)(DAT_0300161c + -0x64c),
                  uVar4,0x80,sVar1,0);
LAB_0300179c:
  FUN_02fe2a80(param_1,DAT_03001ab8);
  return 0;
}


