/**
 * FUN_030ce3bc @ 0x030ce3bc
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_030ce3bc(int param_1,uint *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint unaff_r7;
  int iVar13;
  int iVar14;
  
  uVar11 = 0;
  uVar12 = *(uint *)(param_1 + 0xc);
  uVar4 = FUN_030ce7f0(param_2,uVar12);
  while ((int)uVar4 < 0) {
    while( true ) {
      if ((int)uVar12 < 2) {
        if ((int)uVar4 < 0) {
          return 0xffffffff;
        }
        goto LAB_030ce52c;
      }
      uVar12 = uVar12 - 1;
      uVar6 = *param_2;
      uVar4 = param_2[2];
      iVar14 = uVar6 + uVar12;
      pbVar7 = (byte *)param_2[1];
      if (iVar14 < (int)(uVar4 * 8)) break;
      piVar5 = (int *)param_2[3];
      if (-1 < (int)uVar4) {
        if (iVar14 == 0) goto LAB_030ce50e;
        while (uVar4 == 0) {
          piVar5 = (int *)piVar5[3];
          if (piVar5 == (int *)0x0) goto LAB_030ce4be;
          pbVar7 = (byte *)(*piVar5 + piVar5[1]);
          uVar4 = piVar5[2];
        }
        pbVar8 = pbVar7 + 1;
        unaff_r7 = (uint)(*pbVar7 >> (uVar6 & 0xff));
        if (iVar14 < 9) goto LAB_030ce50e;
        iVar13 = uVar4 - 1;
        while (iVar13 == 0) {
          piVar5 = (int *)piVar5[3];
          if (piVar5 == (int *)0x0) goto LAB_030ce4be;
          pbVar8 = (byte *)(*piVar5 + piVar5[1]);
          iVar13 = piVar5[2];
        }
        pbVar7 = pbVar8 + 1;
        unaff_r7 = (uint)*pbVar8 << (8 - uVar6 & 0xff) | unaff_r7;
        if (iVar14 < 0x11) goto LAB_030ce50e;
        iVar13 = iVar13 + -1;
        while (iVar13 == 0) {
          piVar5 = (int *)piVar5[3];
          if (piVar5 == (int *)0x0) goto LAB_030ce4be;
          pbVar7 = (byte *)(*piVar5 + piVar5[1]);
          iVar13 = piVar5[2];
        }
        pbVar8 = pbVar7 + 1;
        unaff_r7 = (uint)*pbVar7 << (0x10 - uVar6 & 0xff) | unaff_r7;
        if (iVar14 < 0x19) goto LAB_030ce50e;
        iVar13 = iVar13 + -1;
        while (iVar13 == 0) {
          piVar5 = (int *)piVar5[3];
          if (piVar5 == (int *)0x0) goto LAB_030ce4be;
          pbVar8 = (byte *)(*piVar5 + piVar5[1]);
          iVar13 = piVar5[2];
        }
        pbVar7 = pbVar8 + 1;
        unaff_r7 = (uint)*pbVar8 << (0x18 - uVar6 & 0xff) | unaff_r7;
        if ((iVar14 < 0x21) || (uVar6 == 0)) goto LAB_030ce50e;
        if (iVar13 != 1) {
LAB_030ce4ae:
          unaff_r7 = unaff_r7 | (uint)*pbVar7 << (0x20 - uVar6 & 0xff);
          goto LAB_030ce50e;
        }
        while (piVar5 = (int *)piVar5[3], piVar5 != (int *)0x0) {
          pbVar7 = (byte *)(*piVar5 + piVar5[1]);
          if (piVar5[2] != 0) goto LAB_030ce4ae;
        }
      }
LAB_030ce4be:
      uVar4 = 0xffffffff;
    }
    unaff_r7 = (uint)(*pbVar7 >> (uVar6 & 0xff));
    if ((((8 < iVar14) &&
         (unaff_r7 = unaff_r7 | (uint)pbVar7[1] << (8 - uVar6 & 0xff), 0x10 < iVar14)) &&
        (unaff_r7 = unaff_r7 | (uint)pbVar7[2] << (0x10 - uVar6 & 0xff), 0x18 < iVar14)) &&
       ((unaff_r7 = unaff_r7 | (uint)pbVar7[3] << (0x18 - uVar6 & 0xff), 0x20 < iVar14 &&
        (uVar6 != 0)))) {
      unaff_r7 = unaff_r7 | (uint)pbVar7[4] << (0x20 - uVar6 & 0xff);
    }
LAB_030ce50e:
    uVar4 = unaff_r7 & *(uint *)(DAT_030ce748 + uVar12 * 4);
    unaff_r7 = uVar4;
  }
LAB_030ce52c:
  if (*(int *)(param_1 + 0x14) == 1) {
    if (*(int *)(param_1 + 0x18) == 1) {
      iVar14 = *(int *)(param_1 + 0x10);
      uVar6 = 0;
      if ((int)uVar12 < 1) {
        uVar9 = uVar12;
        uVar10 = 0;
      }
      else {
        uVar9 = uVar12 & 1;
        uVar10 = uVar9;
      }
      if (0 < (int)uVar9) {
        do {
          bVar1 = *(byte *)(iVar14 + ((int)uVar4 >> (uVar6 & 0xff) & 1U | uVar11 << 1));
          uVar11 = (uint)bVar1;
          if ((bVar1 & 0x80) != 0) goto LAB_030ce604;
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < (int)uVar10);
      }
      while ((uVar6 = uVar10, (int)uVar10 < (int)uVar12 &&
             (bVar1 = *(byte *)(iVar14 + ((int)uVar4 >> (uVar10 & 0xff) & 1U | uVar11 << 1)),
             uVar11 = (uint)bVar1, (bVar1 & 0x80) == 0))) {
        bVar1 = *(byte *)(iVar14 + ((int)uVar4 >> (uVar10 + 1 & 0xff) & 1U | uVar11 << 1));
        uVar11 = (uint)bVar1;
        uVar6 = uVar10 + 1;
        if ((bVar1 & 0x80) != 0) break;
        uVar10 = uVar10 + 2;
      }
LAB_030ce604:
      uVar11 = uVar11 & 0x7f;
      goto LAB_030ce720;
    }
    iVar14 = *(int *)(param_1 + 0x10);
    uVar6 = 0;
    uVar9 = uVar11;
    if (0 < (int)uVar12) {
      do {
        uVar10 = (int)uVar4 >> (uVar6 & 0xff) & 1;
        iVar13 = uVar9 + uVar10;
        bVar1 = *(byte *)(iVar14 + iVar13);
        uVar11 = (uint)bVar1;
        if ((bVar1 & 0x80) != 0) {
          if ((uVar10 == 0) ||
             (uVar11 = *(byte *)(iVar14 + uVar9) & 0x80, (*(byte *)(iVar14 + uVar9) & 0x80) != 0)) {
            uVar11 = 1;
          }
          uVar11 = (uint)CONCAT11(bVar1,*(undefined1 *)(uVar11 + iVar13 + iVar14 + 1));
          break;
        }
        uVar6 = uVar6 + 1;
        uVar9 = uVar11;
      } while ((int)uVar6 < (int)uVar12);
    }
LAB_030ce6ca:
    uVar11 = uVar11 & 0x7fff;
  }
  else {
    if (*(int *)(param_1 + 0x14) == 2) {
      if (*(int *)(param_1 + 0x18) == 1) {
        uVar9 = 0;
        if ((int)uVar12 < 1) {
          uVar6 = 0;
        }
        else {
          uVar10 = uVar12 & 1;
          uVar6 = uVar10;
          if (uVar10 != 0) {
            do {
              uVar2 = *(ushort *)
                       (*(int *)(param_1 + 0x10) +
                       ((int)uVar4 >> (uVar9 & 0xff) & 1U | uVar11 << 1) * 2);
              uVar11 = (uint)uVar2;
              uVar6 = uVar9;
              if ((uVar2 & 0x8000) != 0) goto LAB_030ce6ca;
              uVar9 = uVar9 + 1;
              uVar6 = uVar10;
            } while ((int)uVar9 < (int)uVar10);
          }
        }
        if ((int)uVar6 < (int)uVar12) {
          uVar9 = uVar6;
          while (uVar2 = *(ushort *)
                          (*(int *)(param_1 + 0x10) +
                          ((int)uVar4 >> (uVar9 & 0xff) & 1U | uVar11 << 1) * 2),
                uVar11 = (uint)uVar2, uVar6 = uVar9, (uVar2 & 0x8000) == 0) {
            uVar6 = uVar9 + 1;
            uVar2 = *(ushort *)
                     (*(int *)(param_1 + 0x10) +
                     ((int)uVar4 >> (uVar6 & 0xff) & 1U | uVar11 << 1) * 2);
            uVar11 = (uint)uVar2;
            if (((uVar2 & 0x8000) != 0) ||
               (uVar6 = uVar9 + 2, uVar9 = uVar6, (int)uVar12 <= (int)uVar6)) break;
          }
        }
        goto LAB_030ce6ca;
      }
      iVar14 = *(int *)(param_1 + 0x10);
      uVar6 = 0;
      uVar9 = uVar11;
      if (0 < (int)uVar12) {
        do {
          uVar10 = (int)uVar4 >> (uVar6 & 0xff) & 1;
          uVar2 = *(ushort *)(iVar14 + (uVar9 + uVar10) * 2);
          uVar11 = (uint)uVar2;
          if ((uVar2 & 0x8000) != 0) {
            if ((uVar10 == 0) ||
               (uVar3 = *(ushort *)(iVar14 + uVar9 * 2), uVar11 = uVar3 & 0x8000,
               (uVar3 & 0x8000) != 0)) {
              uVar11 = 1;
            }
            uVar11 = CONCAT22(uVar2,*(undefined2 *)(iVar14 + (uVar11 + uVar10 + uVar9) * 2 + 2));
            break;
          }
          uVar6 = uVar6 + 1;
          uVar9 = uVar11;
        } while ((int)uVar6 < (int)uVar12);
      }
    }
    else {
      uVar6 = 0;
      if ((int)uVar12 < 1) {
        uVar9 = 0;
      }
      else {
        uVar9 = uVar12 & 1;
        if (uVar9 != 0) {
          do {
            uVar11 = *(uint *)(*(int *)(param_1 + 0x10) +
                              ((int)uVar4 >> (uVar6 & 0xff) & 1U | uVar11 << 1) * 4);
            if ((uVar11 & 0x80000000) != 0) goto LAB_030ce71c;
            uVar6 = uVar6 + 1;
          } while ((int)uVar6 < (int)uVar9);
        }
      }
      uVar6 = uVar9;
      if ((int)uVar6 < (int)uVar12) {
        uVar9 = uVar6;
        while (uVar11 = *(uint *)(*(int *)(param_1 + 0x10) +
                                 ((int)uVar4 >> (uVar9 & 0xff) & 1U | uVar11 << 1) * 4),
              uVar6 = uVar9, (uVar11 & 0x80000000) == 0) {
          uVar6 = uVar9 + 1;
          uVar11 = *(uint *)(*(int *)(param_1 + 0x10) +
                            ((int)uVar4 >> (uVar6 & 0xff) & 1U | uVar11 << 1) * 4);
          if (((uVar11 & 0x80000000) != 0) ||
             (uVar6 = uVar9 + 2, uVar9 = uVar6, (int)uVar12 <= (int)uVar6)) break;
        }
      }
    }
LAB_030ce71c:
    uVar11 = uVar11 & 0x7fffffff;
  }
LAB_030ce720:
  if ((int)uVar12 <= (int)uVar6) {
    FUN_030ce75e(param_2,uVar12);
    return 0xffffffff;
  }
  FUN_030ce75e(param_2,uVar6 + 1);
  return uVar11;
}


