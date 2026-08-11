/**
 * FUN_030c7bd2 @ 0x030c7bd2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030c7bd2(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  undefined1 uVar10;
  uint unaff_r5;
  uint unaff_r6;
  uint unaff_r7;
  uint unaff_r8;
  int iVar11;
  uint unaff_r10;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uStack_40;
  int iStack_3c;
  int iStack_34;
  
  iVar11 = *(int *)(param_1 + 0x1c);
  if (iVar11 == 0) {
    return 0xffffff7f;
  }
  iVar1 = sbuf_read_bits(param_2,8);
  *(undefined4 *)(iVar11 + 0x30) = DAT_030c7ff4;
  iVar13 = 0;
  *(int *)(iVar11 + 0x18) = iVar1 + 1;
  if (0 < iVar1 + 1) {
    do {
      iVar1 = FUN_030c2814(param_2,*(int *)(iVar11 + 0x30) + iVar13 * 0x40);
      if (iVar1 != 0) goto LAB_030c8afc;
      iVar13 = iVar13 + 1;
    } while (iVar13 < *(int *)(iVar11 + 0x18));
  }
  iStack_34 = sbuf_read_bits(param_2,6);
  if (-1 < iStack_34) {
    uVar2 = *(uint *)(DAT_030c7ff8 + 0x40);
    do {
      uVar14 = *param_2;
      uVar9 = param_2[2];
      iVar1 = uVar14 + 0x10;
      if (iVar1 < (int)(uVar9 * 8)) {
        pbVar5 = (byte *)param_2[1];
        unaff_r10 = (uint)(*pbVar5 >> (uVar14 & 0xff));
        if ((((8 < iVar1) &&
             (unaff_r10 = (uint)pbVar5[1] << (8 - uVar14 & 0xff) | unaff_r10, 0x10 < iVar1)) &&
            (unaff_r10 = (uint)pbVar5[2] << (0x10 - uVar14 & 0xff) | unaff_r10, 0x18 < iVar1)) &&
           ((unaff_r10 = (uint)pbVar5[3] << (0x18 - uVar14 & 0xff) | unaff_r10, 0x20 < iVar1 &&
            (uVar14 != 0)))) {
          unaff_r10 = (uint)pbVar5[4] << (0x20 - uVar14 & 0xff) | unaff_r10;
        }
LAB_030c7d80:
        uVar9 = unaff_r10 & uVar2;
        unaff_r10 = uVar9;
      }
      else {
        pbVar5 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar9) {
          if (uVar14 != 0xfffffff0) {
            while (uVar9 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c7d2a;
              pbVar5 = (byte *)(piVar3[1] + *piVar3);
              uVar9 = piVar3[2];
            }
            pbVar6 = pbVar5 + 1;
            unaff_r10 = (uint)(*pbVar5 >> (uVar14 & 0xff));
            if (8 < iVar1) {
              iVar13 = uVar9 - 1;
              while (iVar13 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c7d2a;
                pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                iVar13 = piVar3[2];
              }
              pbVar5 = pbVar6 + 1;
              unaff_r10 = (uint)*pbVar6 << (8 - uVar14 & 0xff) | unaff_r10;
              if (0x10 < iVar1) {
                iVar13 = iVar13 + -1;
                while (iVar13 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c7d2a;
                  pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                  iVar13 = piVar3[2];
                }
                pbVar6 = pbVar5 + 1;
                unaff_r10 = (uint)*pbVar5 << (0x10 - uVar14 & 0xff) | unaff_r10;
                if (0x18 < iVar1) {
                  iVar13 = iVar13 + -1;
                  while (iVar13 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c7d2a;
                    pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                    iVar13 = piVar3[2];
                  }
                  pbVar5 = pbVar6 + 1;
                  unaff_r10 = (uint)*pbVar6 << (0x18 - uVar14 & 0xff) | unaff_r10;
                  if ((0x20 < iVar1) && (uVar14 != 0)) {
                    if (iVar13 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c7d2a;
                        pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                      } while (piVar3[2] == 0);
                    }
                    unaff_r10 = (uint)*pbVar5 << (0x20 - uVar14 & 0xff) | unaff_r10;
                  }
                }
              }
            }
          }
          goto LAB_030c7d80;
        }
LAB_030c7d2a:
        uVar9 = 0xffffffff;
      }
      *param_2 = uVar14 + 0x10 & 7;
      iVar1 = (int)(uVar14 + 0x10) >> 3;
      param_2[2] = param_2[2] - iVar1;
      param_2[1] = param_2[1] + iVar1;
      if ((int)param_2[2] < 1) {
        uVar14 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar14 < 1) {
          uVar15 = *param_2 & 7;
          uVar14 = param_2[2] - ((int)*param_2 >> 3);
          *param_2 = uVar15;
          param_2[2] = uVar14;
          uVar7 = param_2[3];
          if (*(int *)(uVar7 + 0xc) == 0) {
            if ((int)(uVar14 * 8) < (int)uVar15) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = param_2[5] + *(int *)(uVar7 + 8);
          piVar3 = *(int **)(uVar7 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar14)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar14;
          }
          uVar14 = piVar3[2] + uVar14;
          param_2[2] = uVar14;
        }
      }
      if (uVar9 != 0) goto LAB_030c8afc;
      iStack_34 = iStack_34 + -1;
    } while (-1 < iStack_34);
  }
  iVar13 = sbuf_read_bits(param_2,6);
  iVar1 = DAT_030c7ffc;
  *(int *)(iVar11 + 0x28) = DAT_030c7ffc;
  *(int *)(iVar11 + 0x10) = iVar13 + 1;
  iVar12 = 0;
  *(int *)(iVar11 + 0x24) = iVar1 + -8;
  if (0 < iVar13 + 1) {
    do {
      uVar9 = *param_2;
      uVar2 = param_2[2];
      iVar1 = uVar9 + 0x10;
      if (iVar1 < (int)(uVar2 * 8)) {
        pbVar5 = (byte *)param_2[1];
        unaff_r8 = (uint)(*pbVar5 >> (uVar9 & 0xff));
        if ((((8 < iVar1) &&
             (unaff_r8 = (uint)pbVar5[1] << (8 - uVar9 & 0xff) | unaff_r8, 0x10 < iVar1)) &&
            (unaff_r8 = (uint)pbVar5[2] << (0x10 - uVar9 & 0xff) | unaff_r8, 0x18 < iVar1)) &&
           ((unaff_r8 = (uint)pbVar5[3] << (0x18 - uVar9 & 0xff) | unaff_r8, 0x20 < iVar1 &&
            (uVar9 != 0)))) {
          unaff_r8 = (uint)pbVar5[4] << (0x20 - uVar9 & 0xff) | unaff_r8;
        }
LAB_030c7f94:
        uVar2 = unaff_r8 & *(uint *)(DAT_030c7ff8 + 0x40);
        unaff_r8 = uVar2;
      }
      else {
        pbVar5 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar2) {
          if (uVar9 != 0xfffffff0) {
            while (uVar2 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c7f3e;
              pbVar5 = (byte *)(*piVar3 + piVar3[1]);
              uVar2 = piVar3[2];
            }
            pbVar6 = pbVar5 + 1;
            unaff_r8 = (uint)(*pbVar5 >> (uVar9 & 0xff));
            if (8 < iVar1) {
              iVar13 = uVar2 - 1;
              while (iVar13 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c7f3e;
                pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                iVar13 = piVar3[2];
              }
              pbVar5 = pbVar6 + 1;
              unaff_r8 = (uint)*pbVar6 << (8 - uVar9 & 0xff) | unaff_r8;
              if (0x10 < iVar1) {
                iVar13 = iVar13 + -1;
                while (iVar13 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c7f3e;
                  pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                  iVar13 = piVar3[2];
                }
                pbVar6 = pbVar5 + 1;
                unaff_r8 = (uint)*pbVar5 << (0x10 - uVar9 & 0xff) | unaff_r8;
                if (0x18 < iVar1) {
                  iVar13 = iVar13 + -1;
                  while (iVar13 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c7f3e;
                    pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                    iVar13 = piVar3[2];
                  }
                  pbVar5 = pbVar6 + 1;
                  unaff_r8 = (uint)*pbVar6 << (0x18 - uVar9 & 0xff) | unaff_r8;
                  if ((0x20 < iVar1) && (uVar9 != 0)) {
                    if (iVar13 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c7f3e;
                        pbVar5 = (byte *)(piVar3[1] + *piVar3);
                      } while (piVar3[2] == 0);
                    }
                    unaff_r8 = (uint)*pbVar5 << (0x20 - uVar9 & 0xff) | unaff_r8;
                  }
                }
              }
            }
          }
          goto LAB_030c7f94;
        }
LAB_030c7f3e:
        uVar2 = 0xffffffff;
      }
      *param_2 = uVar9 + 0x10 & 7;
      iVar1 = (int)(uVar9 + 0x10) >> 3;
      param_2[2] = param_2[2] - iVar1;
      param_2[1] = param_2[1] + iVar1;
      if ((int)param_2[2] < 1) {
        uVar9 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar9 < 1) {
          uVar9 = param_2[2] - ((int)*param_2 >> 3);
          uVar7 = *param_2 & 7;
          *param_2 = uVar7;
          param_2[2] = uVar9;
          uVar14 = param_2[3];
          if (*(int *)(uVar14 + 0xc) == 0) {
            if ((int)(uVar9 * 8) < (int)uVar7) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = *(int *)(uVar14 + 8) + param_2[5];
          piVar3 = *(int **)(uVar14 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar9)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar9;
          }
          uVar9 = piVar3[2] + uVar9;
          param_2[2] = uVar9;
        }
      }
      *(char *)(*(int *)(iVar11 + 0x24) + iVar12) = (char)uVar2;
      if (1 < (uVar2 & 0xff)) goto LAB_030c8afc;
      if ((uVar2 & 0xff) == 0) {
        uVar4 = FUN_030c49d8(param_1,param_2);
        *(undefined4 *)(*(int *)(iVar11 + 0x28) + iVar12 * 4) = uVar4;
      }
      else {
        uVar4 = FUN_030c4f76();
        *(undefined4 *)(*(int *)(iVar11 + 0x28) + iVar12 * 4) = uVar4;
      }
      if (*(int *)(*(int *)(iVar11 + 0x28) + iVar12 * 4) == 0) goto LAB_030c8afc;
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(iVar11 + 0x10));
  }
  iVar1 = sbuf_read_bits(param_2,6);
  *(undefined4 *)(iVar11 + 0x2c) = DAT_030c8490;
  iVar13 = 0;
  *(int *)(iVar11 + 0x14) = iVar1 + 1;
  if (0 < iVar1 + 1) {
    do {
      iVar1 = FUN_030ca50a(*(int *)(iVar11 + 0x2c) + iVar13 * 0x1c,param_1,param_2);
      if (iVar1 != 0) goto LAB_030c8afc;
      iVar13 = iVar13 + 1;
    } while (iVar13 < *(int *)(iVar11 + 0x14));
  }
  iVar1 = sbuf_read_bits(param_2,6);
  *(undefined4 *)(iVar11 + 0x20) = DAT_030c8494;
  *(int *)(iVar11 + 0xc) = iVar1 + 1;
  iStack_3c = 0;
  if (0 < iVar1 + 1) {
    do {
      uVar9 = *param_2;
      uVar2 = param_2[2];
      iVar1 = uVar9 + 0x10;
      if (iVar1 < (int)(uVar2 * 8)) {
        pbVar5 = (byte *)param_2[1];
        unaff_r7 = (uint)(*pbVar5 >> (uVar9 & 0xff));
        if ((((8 < iVar1) &&
             (unaff_r7 = unaff_r7 | (uint)pbVar5[1] << (8 - uVar9 & 0xff), 0x10 < iVar1)) &&
            (unaff_r7 = unaff_r7 | (uint)pbVar5[2] << (0x10 - uVar9 & 0xff), 0x18 < iVar1)) &&
           ((unaff_r7 = unaff_r7 | (uint)pbVar5[3] << (0x18 - uVar9 & 0xff), 0x20 < iVar1 &&
            (uVar9 != 0)))) {
          unaff_r7 = unaff_r7 | (uint)pbVar5[4] << (0x20 - uVar9 & 0xff);
        }
LAB_030c8244:
        uVar2 = unaff_r7 & *(uint *)(DAT_030c8498 + 0x40);
        unaff_r7 = uVar2;
      }
      else {
        pbVar5 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar2) {
          if (uVar9 != 0xfffffff0) {
            while (uVar2 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c81ec;
              pbVar5 = (byte *)(*piVar3 + piVar3[1]);
              uVar2 = piVar3[2];
            }
            pbVar6 = pbVar5 + 1;
            unaff_r7 = (uint)(*pbVar5 >> (uVar9 & 0xff));
            if (8 < iVar1) {
              iVar13 = uVar2 - 1;
              while (iVar13 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c81ec;
                pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                iVar13 = piVar3[2];
              }
              pbVar5 = pbVar6 + 1;
              unaff_r7 = (uint)*pbVar6 << (8 - uVar9 & 0xff) | unaff_r7;
              if (0x10 < iVar1) {
                iVar13 = iVar13 + -1;
                while (iVar13 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c81ec;
                  pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                  iVar13 = piVar3[2];
                }
                pbVar6 = pbVar5 + 1;
                unaff_r7 = (uint)*pbVar5 << (0x10 - uVar9 & 0xff) | unaff_r7;
                if (0x18 < iVar1) {
                  iVar13 = iVar13 + -1;
                  while (iVar13 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c81ec;
                    pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                    iVar13 = piVar3[2];
                  }
                  pbVar5 = pbVar6 + 1;
                  unaff_r7 = (uint)*pbVar6 << (0x18 - uVar9 & 0xff) | unaff_r7;
                  if ((0x20 < iVar1) && (uVar9 != 0)) {
                    if (iVar13 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c81ec;
                        pbVar5 = (byte *)(piVar3[1] + *piVar3);
                      } while (piVar3[2] == 0);
                    }
                    unaff_r7 = unaff_r7 | (uint)*pbVar5 << (0x20 - uVar9 & 0xff);
                  }
                }
              }
            }
          }
          goto LAB_030c8244;
        }
LAB_030c81ec:
        uVar2 = 0xffffffff;
      }
      *param_2 = uVar9 + 0x10 & 7;
      iVar1 = (int)(uVar9 + 0x10) >> 3;
      param_2[2] = param_2[2] - iVar1;
      param_2[1] = param_2[1] + iVar1;
      if ((int)param_2[2] < 1) {
        uVar9 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar9 < 1) {
          uVar7 = *param_2 & 7;
          uVar9 = param_2[2] - ((int)*param_2 >> 3);
          *param_2 = uVar7;
          param_2[2] = uVar9;
          uVar14 = param_2[3];
          if (*(int *)(uVar14 + 0xc) == 0) {
            if ((int)(uVar9 * 8) < (int)uVar7) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = param_2[5] + *(int *)(uVar14 + 8);
          piVar3 = *(int **)(uVar14 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar9)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar9;
          }
          uVar9 = piVar3[2] + uVar9;
          param_2[2] = uVar9;
        }
      }
      if ((uVar2 != 0) ||
         (iVar1 = FUN_030c8fc2(*(int *)(iVar11 + 0x20) + iStack_3c * 0x14,param_1,param_2),
         iVar1 != 0)) goto LAB_030c8afc;
      iStack_3c = iStack_3c + 1;
    } while (iStack_3c < *(int *)(iVar11 + 0xc));
  }
  iVar13 = sbuf_read_bits(param_2,6);
  iVar1 = DAT_030c849c;
  *(int *)(iVar11 + 0x1c) = DAT_030c849c;
  iVar12 = 0;
  *(int *)(iVar11 + 8) = iVar13 + 1;
  if (0 < iVar13 + 1) {
    uVar2 = *(uint *)(iVar1 + 0x12);
    uVar9 = *(uint *)(iVar1 + 0x4e);
    do {
      uVar7 = *param_2;
      uVar14 = param_2[2];
      iVar1 = uVar7 + 1;
      if (iVar1 < (int)(uVar14 * 8)) {
        pbVar5 = (byte *)param_2[1];
        unaff_r5 = (uint)(*pbVar5 >> (uVar7 & 0xff));
        if ((((8 < iVar1) &&
             (unaff_r5 = unaff_r5 | (uint)pbVar5[1] << (8 - uVar7 & 0xff), 0x10 < iVar1)) &&
            (unaff_r5 = unaff_r5 | (uint)pbVar5[2] << (0x10 - uVar7 & 0xff), 0x18 < iVar1)) &&
           ((unaff_r5 = unaff_r5 | (uint)pbVar5[3] << (0x18 - uVar7 & 0xff), 0x20 < iVar1 &&
            (uVar7 != 0)))) {
          unaff_r5 = unaff_r5 | (uint)pbVar5[4] << (0x20 - uVar7 & 0xff);
        }
LAB_030c8468:
        unaff_r5 = unaff_r5 & uVar2;
        uVar10 = (undefined1)unaff_r5;
      }
      else {
        pbVar5 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar14) {
          if (uVar7 != 0xffffffff) {
            while (uVar14 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c841c;
              pbVar5 = (byte *)(*piVar3 + piVar3[1]);
              uVar14 = piVar3[2];
            }
            pbVar6 = pbVar5 + 1;
            unaff_r5 = (uint)(*pbVar5 >> (uVar7 & 0xff));
            if (8 < iVar1) {
              iVar13 = uVar14 - 1;
              while (iVar13 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c841c;
                pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                iVar13 = piVar3[2];
              }
              pbVar5 = pbVar6 + 1;
              unaff_r5 = unaff_r5 | (uint)*pbVar6 << (8 - uVar7 & 0xff);
              if (0x10 < iVar1) {
                iVar13 = iVar13 + -1;
                while (iVar13 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c841c;
                  pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                  iVar13 = piVar3[2];
                }
                pbVar6 = pbVar5 + 1;
                unaff_r5 = unaff_r5 | (uint)*pbVar5 << (0x10 - uVar7 & 0xff);
                if (0x18 < iVar1) {
                  iVar13 = iVar13 + -1;
                  while (iVar13 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c841c;
                    pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                    iVar13 = piVar3[2];
                  }
                  pbVar5 = pbVar6 + 1;
                  unaff_r5 = unaff_r5 | (uint)*pbVar6 << (0x18 - uVar7 & 0xff);
                  if ((0x20 < iVar1) && (uVar7 != 0)) {
                    if (iVar13 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c841c;
                        pbVar5 = (byte *)(piVar3[1] + *piVar3);
                      } while (piVar3[2] == 0);
                    }
                    unaff_r5 = unaff_r5 | (uint)*pbVar5 << (0x20 - uVar7 & 0xff);
                  }
                }
              }
            }
          }
          goto LAB_030c8468;
        }
LAB_030c841c:
        uVar10 = 0xff;
      }
      *param_2 = uVar7 + 1 & 7;
      iVar1 = (int)(uVar7 + 1) >> 3;
      param_2[2] = param_2[2] - iVar1;
      param_2[1] = param_2[1] + iVar1;
      if ((int)param_2[2] < 1) {
        uVar14 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar14 < 1) {
          uVar15 = *param_2 & 7;
          uVar14 = param_2[2] - ((int)*param_2 >> 3);
          *param_2 = uVar15;
          param_2[2] = uVar14;
          uVar7 = param_2[3];
          if (*(int *)(uVar7 + 0xc) == 0) {
            if ((int)(uVar14 * 8) < (int)uVar15) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = *(int *)(uVar7 + 8) + param_2[5];
          piVar3 = *(int **)(uVar7 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar14)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar14;
          }
          uVar14 = piVar3[2] + uVar14;
          param_2[2] = uVar14;
        }
      }
      *(undefined1 *)(*(int *)(iVar11 + 0x1c) + iVar12 * 2) = uVar10;
      uVar7 = *param_2;
      uVar14 = param_2[2];
      iVar1 = uVar7 + 0x10;
      if (iVar1 < (int)(uVar14 * 8)) {
        pbVar5 = (byte *)param_2[1];
        unaff_r6 = (uint)(*pbVar5 >> (uVar7 & 0xff));
        if (((8 < iVar1) &&
            (unaff_r6 = unaff_r6 | (uint)pbVar5[1] << (8 - uVar7 & 0xff), 0x10 < iVar1)) &&
           ((unaff_r6 = unaff_r6 | (uint)pbVar5[2] << (0x10 - uVar7 & 0xff), 0x18 < iVar1 &&
            ((unaff_r6 = unaff_r6 | (uint)pbVar5[3] << (0x18 - uVar7 & 0xff), 0x20 < iVar1 &&
             (uVar7 != 0)))))) {
          uVar14 = (uint)pbVar5[4] << (0x20 - uVar7 & 0xff);
LAB_030c866c:
          unaff_r6 = unaff_r6 | uVar14;
        }
LAB_030c866e:
        uVar14 = unaff_r6 & uVar9;
        unaff_r6 = uVar14;
      }
      else {
        pbVar5 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar14) {
          if (uVar7 != 0xfffffff0) {
            while (uVar14 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c8616;
              pbVar5 = (byte *)(*piVar3 + piVar3[1]);
              uVar14 = piVar3[2];
            }
            pbVar6 = pbVar5 + 1;
            unaff_r6 = (uint)(*pbVar5 >> (uVar7 & 0xff));
            if (8 < iVar1) {
              iVar13 = uVar14 - 1;
              while (iVar13 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c8616;
                pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                iVar13 = piVar3[2];
              }
              pbVar5 = pbVar6 + 1;
              unaff_r6 = (uint)*pbVar6 << (8 - uVar7 & 0xff) | unaff_r6;
              if (0x10 < iVar1) {
                iVar13 = iVar13 + -1;
                while (iVar13 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c8616;
                  pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                  iVar13 = piVar3[2];
                }
                pbVar6 = pbVar5 + 1;
                unaff_r6 = (uint)*pbVar5 << (0x10 - uVar7 & 0xff) | unaff_r6;
                if (0x18 < iVar1) {
                  iVar13 = iVar13 + -1;
                  while (iVar13 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c8616;
                    pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                    iVar13 = piVar3[2];
                  }
                  pbVar5 = pbVar6 + 1;
                  unaff_r6 = (uint)*pbVar6 << (0x18 - uVar7 & 0xff) | unaff_r6;
                  if ((0x20 < iVar1) && (uVar7 != 0)) {
                    if (iVar13 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c8616;
                        pbVar5 = (byte *)(piVar3[1] + *piVar3);
                      } while (piVar3[2] == 0);
                    }
                    uVar14 = (uint)*pbVar5 << (0x20 - uVar7 & 0xff);
                    goto LAB_030c866c;
                  }
                }
              }
            }
          }
          goto LAB_030c866e;
        }
LAB_030c8616:
        uVar14 = 0xffffffff;
      }
      *param_2 = uVar7 + 0x10 & 7;
      iVar1 = (int)(uVar7 + 0x10) >> 3;
      param_2[2] = param_2[2] - iVar1;
      param_2[1] = param_2[1] + iVar1;
      if ((int)param_2[2] < 1) {
        uVar7 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar7 < 1) {
          uVar16 = *param_2 & 7;
          uVar7 = param_2[2] - ((int)*param_2 >> 3);
          *param_2 = uVar16;
          param_2[2] = uVar7;
          uVar15 = param_2[3];
          if (*(int *)(uVar15 + 0xc) == 0) {
            if ((int)(uVar7 * 8) < (int)uVar16) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = param_2[5] + *(int *)(uVar15 + 8);
          piVar3 = *(int **)(uVar15 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar7)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar7;
          }
          uVar7 = piVar3[2] + uVar7;
          param_2[2] = uVar7;
        }
      }
      if (uVar14 != 0) goto LAB_030c8afc;
      uVar7 = *param_2;
      uVar14 = param_2[2];
      iVar1 = uVar7 + 0x10;
      if (iVar1 < (int)(uVar14 * 8)) {
        pbVar5 = (byte *)param_2[1];
        uStack_40 = (uint)(*pbVar5 >> (uVar7 & 0xff));
        if ((((8 < iVar1) &&
             (uStack_40 = uStack_40 | (uint)pbVar5[1] << (8 - uVar7 & 0xff), 0x10 < iVar1)) &&
            (uStack_40 = uStack_40 | (uint)pbVar5[2] << (0x10 - uVar7 & 0xff), 0x18 < iVar1)) &&
           ((uStack_40 = uStack_40 | (uint)pbVar5[3] << (0x18 - uVar7 & 0xff), 0x20 < iVar1 &&
            (uVar7 != 0)))) {
          uStack_40 = uStack_40 | (uint)pbVar5[4] << (0x20 - uVar7 & 0xff);
        }
LAB_030c8866:
        uVar14 = uStack_40 & uVar9;
        uStack_40 = uVar14;
      }
      else {
        pbVar5 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar14) {
          if (uVar7 != 0xfffffff0) {
            while (uVar14 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c8804;
              pbVar5 = (byte *)(piVar3[1] + *piVar3);
              uVar14 = piVar3[2];
            }
            pbVar6 = pbVar5 + 1;
            uStack_40 = (uint)(*pbVar5 >> (uVar7 & 0xff));
            if (8 < iVar1) {
              iVar13 = uVar14 - 1;
              while (iVar13 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c8804;
                pbVar6 = (byte *)(piVar3[1] + *piVar3);
                iVar13 = piVar3[2];
              }
              pbVar5 = pbVar6 + 1;
              uStack_40 = (uint)*pbVar6 << (8 - uVar7 & 0xff) | uStack_40;
              if (0x10 < iVar1) {
                iVar13 = iVar13 + -1;
                while (iVar13 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c8804;
                  pbVar5 = (byte *)(piVar3[1] + *piVar3);
                  iVar13 = piVar3[2];
                }
                pbVar6 = pbVar5 + 1;
                uStack_40 = (uint)*pbVar5 << (0x10 - uVar7 & 0xff) | uStack_40;
                if (0x18 < iVar1) {
                  iVar13 = iVar13 + -1;
                  while (iVar13 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c8804;
                    pbVar6 = (byte *)(piVar3[1] + *piVar3);
                    iVar13 = piVar3[2];
                  }
                  pbVar5 = pbVar6 + 1;
                  uStack_40 = (uint)*pbVar6 << (0x18 - uVar7 & 0xff) | uStack_40;
                  if ((0x20 < iVar1) && (uVar7 != 0)) {
                    if (iVar13 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c8804;
                        pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                      } while (piVar3[2] == 0);
                    }
                    uStack_40 = (uint)*pbVar5 << (0x20 - uVar7 & 0xff) | uStack_40;
                  }
                }
              }
            }
          }
          goto LAB_030c8866;
        }
LAB_030c8804:
        uVar14 = 0xffffffff;
      }
      *param_2 = uVar7 + 0x10 & 7;
      iVar1 = (int)(uVar7 + 0x10) >> 3;
      param_2[2] = param_2[2] - iVar1;
      param_2[1] = param_2[1] + iVar1;
      if ((int)param_2[2] < 1) {
        uVar15 = param_2[2] - ((int)*param_2 >> 3);
        while ((int)uVar15 < 1) {
          uVar7 = *param_2 & 7;
          uVar15 = param_2[2] - ((int)*param_2 >> 3);
          *param_2 = uVar7;
          param_2[2] = uVar15;
          uVar16 = param_2[3];
          if (*(int *)(uVar16 + 0xc) == 0) {
            if ((int)(uVar15 * 8) < (int)uVar7) {
              param_2[2] = 0xffffffff;
            }
            break;
          }
          param_2[5] = param_2[5] + *(int *)(uVar16 + 8);
          piVar3 = *(int **)(uVar16 + 0xc);
          param_2[3] = (uint)piVar3;
          if (0 < (int)(piVar3[2] + uVar15)) {
            param_2[1] = (*piVar3 + piVar3[1]) - uVar15;
          }
          uVar15 = piVar3[2] + uVar15;
          param_2[2] = uVar15;
        }
      }
      bVar8 = (byte)uVar7;
      if (uVar14 != 0) goto LAB_030c8afc;
      uVar7 = *param_2;
      uVar14 = param_2[2];
      uVar15 = uVar7 + 8;
      if ((int)uVar15 < (int)(uVar14 * 8)) {
        pbVar5 = (byte *)param_2[1];
        bVar8 = *pbVar5 >> (uVar7 & 0xff);
        if ((((8 < (int)uVar15) &&
             (bVar8 = bVar8 | pbVar5[1] << (8 - uVar7 & 0xff), 0x10 < (int)uVar15)) &&
            (bVar8 = bVar8 | pbVar5[2] << (0x10 - uVar7 & 0xff), 0x18 < (int)uVar15)) &&
           ((bVar8 = bVar8 | pbVar5[3] << (0x18 - uVar7 & 0xff), 0x20 < (int)uVar15 && (uVar7 != 0))
           )) {
          bVar8 = bVar8 | pbVar5[4] << (0x20 - uVar7 & 0xff);
        }
LAB_030c8a36:
        bVar8 = bVar8 & (byte)*(undefined4 *)(DAT_030c8cf0 + 0x20);
      }
      else {
        pbVar5 = (byte *)param_2[1];
        piVar3 = (int *)param_2[3];
        if (-1 < (int)uVar14) {
          uVar16 = uVar14;
          if (uVar15 != 0) {
            while (uVar16 == 0) {
              piVar3 = (int *)piVar3[3];
              if (piVar3 == (int *)0x0) goto LAB_030c89e2;
              pbVar5 = (byte *)(*piVar3 + piVar3[1]);
              uVar16 = piVar3[2];
            }
            pbVar6 = pbVar5 + 1;
            bVar8 = *pbVar5 >> (uVar7 & 0xff);
            if (8 < (int)uVar15) {
              iVar1 = uVar16 - 1;
              while (iVar1 == 0) {
                piVar3 = (int *)piVar3[3];
                if (piVar3 == (int *)0x0) goto LAB_030c89e2;
                pbVar6 = (byte *)(*piVar3 + piVar3[1]);
                iVar1 = piVar3[2];
              }
              pbVar5 = pbVar6 + 1;
              bVar8 = bVar8 | *pbVar6 << (8 - uVar7 & 0xff);
              if (0x10 < (int)uVar15) {
                iVar1 = iVar1 + -1;
                while (iVar1 == 0) {
                  piVar3 = (int *)piVar3[3];
                  if (piVar3 == (int *)0x0) goto LAB_030c89e2;
                  pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                  iVar1 = piVar3[2];
                }
                pbVar6 = pbVar5 + 1;
                bVar8 = bVar8 | *pbVar5 << (0x10 - uVar7 & 0xff);
                if (0x18 < (int)uVar15) {
                  iVar1 = iVar1 + -1;
                  while (iVar1 == 0) {
                    piVar3 = (int *)piVar3[3];
                    if (piVar3 == (int *)0x0) goto LAB_030c89e2;
                    pbVar6 = (byte *)(piVar3[1] + *piVar3);
                    iVar1 = piVar3[2];
                  }
                  pbVar5 = pbVar6 + 1;
                  bVar8 = bVar8 | *pbVar6 << (0x18 - uVar7 & 0xff);
                  if ((0x20 < (int)uVar15) && (uVar7 != 0)) {
                    if (iVar1 == 1) {
                      do {
                        piVar3 = (int *)piVar3[3];
                        if (piVar3 == (int *)0x0) goto LAB_030c89e2;
                        pbVar5 = (byte *)(*piVar3 + piVar3[1]);
                      } while (piVar3[2] == 0);
                    }
                    bVar8 = bVar8 | *pbVar5 << (0x20 - uVar7 & 0xff);
                  }
                }
              }
            }
          }
          goto LAB_030c8a36;
        }
LAB_030c89e2:
        bVar8 = 0xff;
      }
      uVar14 = uVar14 - ((int)uVar15 >> 3);
      *param_2 = uVar15 & 7;
      param_2[2] = uVar14;
      param_2[1] = param_2[1] + ((int)uVar15 >> 3);
      while ((int)uVar14 < 1) {
        uVar14 = param_2[2] - ((int)*param_2 >> 3);
        *param_2 = *param_2 & 7;
        param_2[2] = uVar14;
        uVar7 = param_2[3];
        if (*(int *)(uVar7 + 0xc) == 0) {
          if ((int)(param_2[2] * 8) < (int)*param_2) {
            param_2[2] = 0xffffffff;
          }
          break;
        }
        param_2[5] = param_2[5] + *(int *)(uVar7 + 8);
        piVar3 = *(int **)(uVar7 + 0xc);
        param_2[3] = (uint)piVar3;
        if (0 < (int)(piVar3[2] + uVar14)) {
          param_2[1] = (*piVar3 + piVar3[1]) - uVar14;
        }
        uVar14 = piVar3[2] + uVar14;
        param_2[2] = uVar14;
      }
      *(byte *)(*(int *)(iVar11 + 0x1c) + iVar12 * 2 + 1) = bVar8;
      if (*(int *)(iVar11 + 0xc) <= (int)(uint)bVar8) goto LAB_030c8afc;
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(iVar11 + 8));
  }
  iVar11 = sbuf_read_bits(param_2,1);
  if (iVar11 == 1) {
    return 0;
  }
LAB_030c8afc:
  FUN_030c7b12(param_1);
  return 0xffffff7b;
}


