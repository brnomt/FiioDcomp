/**
 * FUN_030908e4 @ 0x030908e4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030908e4(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int unaff_r10;
  
  iVar11 = *(int *)(param_1 + 0x40);
  if (iVar11 < 3) {
    iVar14 = 0x19;
  }
  else {
    iVar14 = 0x1c;
  }
  iVar2 = *DAT_03090cf4;
  uVar3 = FUN_03082bfa(*(undefined4 *)(param_1 + 0x50));
  uVar3 = FUN_03082972(0x3f800000,uVar3);
  piVar10 = *(int **)(param_1 + 0xec);
  if (iVar11 == 1) {
    iVar11 = 0;
    *piVar10 = 0;
    if (iVar14 != 0) {
      do {
        uVar5 = FUN_03082c0c(*(int *)(param_1 + 0x98) * *(int *)(iVar2 + iVar11 * 4));
        uVar5 = FUN_03082906(uVar5,uVar3);
        FUN_03082856(uVar5,0x3f000000);
        iVar4 = FUN_03082c38();
        piVar10[iVar11 + 1] = iVar4;
        if (*(int *)(param_1 + 0x98) / 2 < iVar4) {
          piVar10[iVar11 + 1] = *(int *)(param_1 + 0x98) / 2;
          **(int **)(param_1 + 0xe8) = iVar11 + 1;
          break;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar14);
    }
  }
  else {
    uVar13 = 0;
    if (0 < *(int *)(param_1 + 0x90)) {
      do {
        *piVar10 = 0;
        iVar11 = *(int *)(param_1 + 0x98) / (1 << (uVar13 & 0xff));
        if (2 < *(int *)(param_1 + 0x40)) goto LAB_03090bb8;
        iVar4 = *(int *)(param_1 + 0x50);
        if (iVar4 < 0xac44) {
          if (31999 < iVar4) {
            if (iVar11 == 0x400) {
              *(undefined4 *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = 0x10;
              piVar10[1] = 6;
              piVar10[2] = 0xd;
              piVar10[3] = 0x14;
              piVar10[4] = 0x1d;
              piVar10[5] = 0x29;
              piVar10[6] = 0x37;
              piVar10[7] = 0x4a;
              piVar10[8] = 0x65;
              piVar10[9] = 0x8d;
              piVar10[10] = 0xaa;
              piVar10[0xb] = 0xcd;
              piVar10[0xc] = 0xf6;
              piVar10[0xd] = 0x130;
              piVar10[0xe] = 0x180;
              piVar10[0xf] = 0x1f0;
              piVar10[0x10] = 0x200;
            }
            else if (iVar11 == 0x200) {
              *(undefined4 *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = 0xf;
              piVar10[1] = 5;
              piVar10[2] = 10;
              piVar10[3] = 0xf;
              piVar10[4] = 0x14;
              piVar10[5] = 0x1c;
              piVar10[6] = 0x25;
              piVar10[7] = 0x32;
              piVar10[8] = 0x46;
              piVar10[9] = 0x55;
              piVar10[10] = 0x66;
              piVar10[0xb] = 0x7b;
              piVar10[0xc] = 0x98;
              piVar10[0xd] = 0xc0;
              piVar10[0xe] = 0xf8;
              piVar10[0xf] = 0x100;
            }
            else {
              if (iVar11 != 0x100) goto LAB_03090bb8;
              *(undefined4 *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = 0xb;
              piVar10[1] = 4;
              piVar10[2] = 9;
              piVar10[3] = 0xe;
              piVar10[4] = 0x13;
              piVar10[5] = 0x19;
              piVar10[6] = 0x23;
              piVar10[7] = 0x33;
              piVar10[8] = 0x4c;
              piVar10[9] = 0x60;
              piVar10[10] = 0x7c;
              piVar10[0xb] = 0x80;
            }
            goto LAB_03090cb2;
          }
          if (0x5621 < iVar4) {
            if (iVar11 == 0x200) {
              *(undefined4 *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = 0xe;
              piVar10[1] = 5;
              piVar10[2] = 0xc;
              piVar10[3] = 0x12;
              piVar10[4] = 0x19;
              piVar10[5] = 0x22;
              piVar10[6] = 0x2e;
              piVar10[7] = 0x3f;
              piVar10[8] = 0x56;
              piVar10[9] = 0x66;
              piVar10[10] = 0x7b;
              piVar10[0xb] = 0x95;
              piVar10[0xc] = 0xb3;
              piVar10[0xd] = 0xdd;
              piVar10[0xe] = 0x100;
            }
            else {
              if (iVar11 != 0x100) goto LAB_03090bb8;
              *(undefined4 *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = 10;
              piVar10[1] = 5;
              piVar10[2] = 0xb;
              piVar10[3] = 0x11;
              piVar10[4] = 0x17;
              piVar10[5] = 0x1f;
              piVar10[6] = 0x2b;
              piVar10[7] = 0x3e;
              piVar10[8] = 0x59;
              piVar10[9] = 0x6e;
              piVar10[10] = 0x80;
            }
            goto LAB_03090cb2;
          }
LAB_03090bb8:
          uVar5 = FUN_03082bfa(iVar11);
          uVar5 = FUN_03082906(uVar5,uVar3);
          iVar12 = 0;
          iVar4 = 1;
          do {
            if (*(int *)(param_1 + 0x40) < 3) {
              iVar7 = iVar12 * 4;
              iVar12 = iVar12 + 1;
              uVar6 = FUN_03082c0c(*(undefined4 *)(iVar2 + iVar7));
              uVar6 = FUN_03082906(uVar6,uVar5);
              uVar6 = FUN_03082856(uVar6,0x40000000);
              FUN_030829f2(uVar6,0xfffffffe);
              iVar7 = FUN_03082c38();
              unaff_r10 = iVar7 << 2;
            }
            if (piVar10[iVar4 + -1] < unaff_r10) {
              piVar10[iVar4] = unaff_r10;
              iVar4 = iVar4 + 1;
            }
          } while ((iVar12 < iVar14) && (piVar10[iVar4 + -1] < iVar11 / 2));
          piVar10[iVar4 + -1] = iVar11 / 2;
          *(int *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = iVar4 + -1;
        }
        else {
          if (iVar11 == 0x400) {
            *(undefined4 *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = 0x11;
            piVar10[1] = 5;
            piVar10[2] = 0xc;
            piVar10[3] = 0x12;
            piVar10[4] = 0x19;
            piVar10[5] = 0x22;
            piVar10[6] = 0x2e;
            piVar10[7] = 0x36;
            piVar10[8] = 0x3f;
            piVar10[9] = 0x56;
            piVar10[10] = 0x66;
            piVar10[0xb] = 0x7b;
            piVar10[0xc] = 0x95;
            piVar10[0xd] = 0xb3;
            piVar10[0xe] = 0xdd;
            piVar10[0xf] = 0x117;
            piVar10[0x10] = 0x168;
            piVar10[0x11] = 0x200;
          }
          else if (iVar11 == 0x200) {
            *(undefined4 *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = 0xf;
            piVar10[1] = 5;
            piVar10[2] = 0xb;
            piVar10[3] = 0x11;
            piVar10[4] = 0x17;
            piVar10[5] = 0x1f;
            piVar10[6] = 0x25;
            piVar10[7] = 0x2b;
            piVar10[8] = 0x33;
            piVar10[9] = 0x3e;
            piVar10[10] = 0x4a;
            piVar10[0xb] = 0x59;
            piVar10[0xc] = 0x6e;
            piVar10[0xd] = 0x8b;
            piVar10[0xe] = 0xb4;
            piVar10[0xf] = 0x100;
          }
          else {
            if (iVar11 != 0x100) goto LAB_03090bb8;
            *(undefined4 *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) = 0xc;
            piVar10[1] = 4;
            piVar10[2] = 9;
            piVar10[3] = 0xc;
            piVar10[4] = 0x10;
            piVar10[5] = 0x15;
            piVar10[6] = 0x1a;
            piVar10[7] = 0x25;
            piVar10[8] = 0x2d;
            piVar10[9] = 0x37;
            piVar10[10] = 0x46;
            piVar10[0xb] = 0x5a;
            piVar10[0xc] = 0x80;
          }
LAB_03090cb2:
          uVar9 = *(uint *)(*(int *)(param_1 + 0xe8) + uVar13 * 4);
          if (0 < (int)uVar9) {
            piVar8 = piVar10;
            if ((uVar9 & 1) != 0) {
              piVar10[1] = ((piVar10[1] + 2) / 4) * 4;
              piVar8 = piVar10 + 1;
            }
            for (iVar11 = *(int *)(*(int *)(param_1 + 0xe8) + uVar13 * 4) >> 1; iVar11 != 0;
                iVar11 = iVar11 + -1) {
              piVar8[1] = ((piVar8[1] + 2) / 4) * 4;
              piVar1 = piVar8 + 2;
              piVar8 = piVar8 + 2;
              *piVar8 = ((*piVar1 + 2) / 4) * 4;
            }
          }
        }
        piVar10 = piVar10 + 0x1d;
        uVar13 = uVar13 + 1;
      } while ((int)uVar13 < *(int *)(param_1 + 0x90));
    }
  }
  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(param_1 + 200) = **(undefined4 **)(param_1 + 0xe8);
  for (iVar11 = 0; iVar11 < *(int *)(param_1 + 0x90); iVar11 = iVar11 + 1) {
  }
  return;
}


