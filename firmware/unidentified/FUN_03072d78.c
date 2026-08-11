/**
 * FUN_03072d78 @ 0x03072d78
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03072d78(int param_1,int param_2)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  byte local_d8 [32];
  byte abStack_b8 [32];
  byte local_98 [68];
  uint local_54;
  uint local_50;
  int local_4c;
  int local_48;
  int iStack_2c;
  int local_28;
  
  local_4c = *(int *)(param_2 + 0x24);
  local_48 = local_4c + 0x600;
  if (*(char *)(param_2 + 1) == '\0') {
    uVar9 = 1;
  }
  else {
    uVar9 = 2;
  }
  iStack_2c = param_1;
  local_28 = param_2;
  FUN_0306e300();
  local_50 = 0x20;
  if (*(char *)(param_2 + 1) == '\x02') {
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 0x100;
    local_50 = *(int *)(param_2 + 4) * 4 + 4;
  }
  if ((*(byte *)(param_2 + 0x18) & 0x10) != 0) {
    uVar3 = FUN_03070b9a(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x20),
                         (local_50 * uVar9 + (0x20 - local_50)) * 4,*(undefined2 *)(param_2 + 0x14))
    ;
    *(short *)(param_2 + 0x14) = (short)uVar3;
    if ((uVar3 != *(ushort *)(param_2 + 0x16)) && ((*(byte *)(local_28 + 0x20) & 1) == 0)) {
      *(undefined2 *)(param_1 + 0x3c) = 0x201;
      return 0xffffffff;
    }
  }
  uVar11 = 0;
  uVar3 = local_50;
  if (local_50 != 0) {
    do {
      uVar3 = 0;
      if (uVar9 != 0) {
        do {
          iVar4 = bitstream_getbits_be(param_1 + 0x1c,4);
          if (iVar4 == 0xf) goto LAB_03072fb8;
          if (iVar4 != 0) {
            iVar4 = iVar4 + 1;
          }
          iVar12 = uVar3 * 0x20;
          uVar3 = uVar3 + 1;
          local_d8[uVar11 + iVar12] = (byte)iVar4;
        } while (uVar3 < uVar9);
      }
      uVar11 = uVar11 + 1;
      uVar3 = local_50;
    } while (uVar11 < local_50);
  }
  do {
    if (0x1f < uVar3) {
      uVar3 = 0;
      do {
        uVar11 = 0;
        if (uVar9 != 0) {
          do {
            if (local_d8[uVar3 + uVar11 * 0x20] != 0) {
              bVar2 = bitstream_getbits_be(param_1 + 0x1c,6);
              local_98[uVar3 + uVar11 * 0x20] = bVar2;
            }
            uVar11 = uVar11 + 1;
          } while (uVar11 < uVar9);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x20);
      local_54 = 0;
      do {
        uVar3 = 0;
        if (local_50 != 0) {
          iVar12 = local_4c + local_54 * 0x80;
          iVar4 = local_48 + local_54 * 0x80;
          do {
            uVar11 = 0;
            if (uVar9 != 0) {
              do {
                uVar10 = (uint)local_d8[uVar3 + uVar11 * 0x20];
                if (uVar11 == 0) {
                  if (uVar10 == 0) {
                    iVar5 = 0;
                  }
                  else {
                    uVar6 = bitstream_getbits_be(param_1 + 0x1c,uVar10);
                    uVar7 = 1 << (uVar10 - 1 & 0xff);
                    iVar5 = (*(int *)(DAT_030732f8 + uVar10 * 4 + -8) *
                             ((int)(((-(uVar7 & ~uVar6) | uVar7 ^ uVar6) << (0x1d - uVar10 & 0xff))
                                   + (0x10000000U >> (uVar10 - 1 & 0xff))) >> 0xc) >> 0xc) *
                            *(int *)(DAT_030732fc + (uint)local_98[uVar3] * 4);
                  }
                  *(int *)(iVar12 + uVar3 * 4) = iVar5;
                }
                else {
                  if (uVar10 == 0) {
                    iVar5 = 0;
                  }
                  else {
                    uVar6 = bitstream_getbits_be(param_1 + 0x1c,uVar10);
                    uVar7 = 1 << (uVar10 - 1 & 0xff);
                    iVar5 = (((int)(((-(uVar7 & ~uVar6) | uVar7 ^ uVar6) << (0x1d - uVar10 & 0xff))
                                   + (0x10000000U >> (uVar10 - 1 & 0xff))) >> 0xc) *
                             *(int *)(DAT_030732f8 + uVar10 * 4 + -8) >> 0xc) *
                            *(int *)(DAT_030732fc + (uint)local_98[uVar3 + uVar11 * 0x20] * 4);
                  }
                  *(int *)(iVar4 + uVar3 * 4) = iVar5;
                }
                uVar11 = uVar11 + 1;
              } while (uVar11 < uVar9);
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < local_50);
        }
        if (local_50 < 0x20) {
          iVar12 = local_4c + local_54 * 0x80;
          iVar4 = local_48 + local_54 * 0x80;
          uVar3 = local_50;
          do {
            uVar11 = (uint)local_d8[uVar3];
            if (uVar11 == 0) {
              uVar11 = 0;
              if (uVar9 != 0) {
                do {
                  *(undefined4 *)(iVar4 + uVar3 * 4) = 0;
                  while( true ) {
                    uVar11 = uVar11 + 1;
                    if (uVar9 <= uVar11) goto LAB_03073060;
                    if (uVar11 == 0) break;
                    *(undefined4 *)(iVar12 + uVar3 * 4) = 0;
                  }
                } while( true );
              }
            }
            else {
              uVar10 = bitstream_getbits_be(param_1 + 0x1c,uVar11);
              iVar5 = DAT_030732fc;
              uVar7 = 1 << (uVar11 - 1 & 0xff);
              uVar6 = 0;
              if (uVar9 != 0) {
                iVar8 = ((int)(((-(uVar7 & ~uVar10) | uVar7 ^ uVar10) << (0x1d - uVar11 & 0xff)) +
                              (0x10000000U >> (uVar11 - 1 & 0xff))) >> 0xc) *
                        *(int *)(DAT_030732f8 + uVar11 * 4 + -8) >> 0xc;
                do {
                  *(int *)(iVar12 + uVar3 * 4) = iVar8 * *(int *)(iVar5 + (uint)local_98[uVar3] * 4)
                  ;
                  while( true ) {
                    uVar6 = uVar6 + 1;
                    if (uVar9 <= uVar6) goto LAB_03073060;
                    if (uVar6 == 0) break;
                    *(int *)(iVar4 + uVar3 * 4) =
                         iVar8 * *(int *)(iVar5 + (uint)local_98[uVar3 + uVar6 * 0x20] * 4);
                  }
                } while( true );
              }
            }
LAB_03073060:
            uVar3 = uVar3 + 1;
          } while (uVar3 < 0x20);
        }
        piVar1 = DAT_03073300;
        local_54 = local_54 + 1;
        if (0xb < local_54) {
          do {
          } while (*DAT_03073300 == 1);
          FUN_03070b00(local_28,0,0xc);
          if (1 < uVar9) {
            do {
            } while (*piVar1 == 1);
            hifi_memmove(local_4c,local_48,0x600);
            FUN_03070b00(local_28,1,0xc,0);
          }
          FUN_0306f366(local_28);
          FUN_0306e302();
          return 0;
        }
      } while( true );
    }
    iVar4 = bitstream_getbits_be(param_1 + 0x1c,4);
    if (iVar4 == 0xf) {
LAB_03072fb8:
      *(undefined2 *)(param_1 + 0x3c) = 0x211;
      return 0xffffffff;
    }
    if (iVar4 != 0) {
      iVar4 = iVar4 + 1;
    }
    abStack_b8[uVar3] = (byte)iVar4;
    local_d8[uVar3] = (byte)iVar4;
    uVar3 = uVar3 + 1;
  } while( true );
}


