/**
 * FUN_030017b4 @ 0x030017b4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

void FUN_030017b4(int param_1)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  
  puVar4 = DAT_03001ac0;
  iVar3 = DAT_03001abc;
  puVar2 = DAT_03001ab4;
  uVar8 = (uint)DAT_03001ab4[DAT_03001ab4[5] + 6] - (uint)DAT_03001ab4[0xb] & 0xffff;
  if (param_1 == 0) {
    *DAT_03001ac0 = 0;
    iVar10 = DAT_03001ac4;
    puVar4[1] = 0;
    uVar6 = 0;
    do {
      uVar5 = 0;
      iVar7 = iVar10 + uVar6 * 0x10c;
      do {
        iVar1 = uVar5 * 2;
        uVar5 = uVar5 + 1 & 0xffff;
        *(undefined2 *)(iVar7 + iVar1 + 0xc) = 0;
      } while (uVar5 < 0x80);
      *(undefined2 *)(iVar7 + 10) = 0xffff;
      uVar6 = uVar6 + 1 & 0xffff;
      *(undefined2 *)(iVar7 + 8) = 0xffff;
    } while (uVar6 < 6);
    uVar6 = 0;
    *(int *)(puVar2 + 0xe) = iVar10;
    do {
      if ((uint)*puVar2 <= uVar6 + uVar8) {
        return;
      }
      uVar5 = (uint)puVar2[5];
      if (puVar2[uVar5 - 0x330] == 0x600) {
        if (uVar5 == 0) goto LAB_030018ec;
        if (uVar8 != 0 || uVar6 != 0) {
          FUN_03001592(iVar10 + 0xc,(uVar8 + uVar6) - 1 & 0xffff);
          uVar5 = 0;
          if (*(short *)(iVar10 + 0xc) == 0) {
            do {
              if (*(short *)(iVar10 + 0xc + uVar5 * 2) != 0) break;
              uVar5 = uVar5 + 1;
            } while (uVar5 < 0x80);
            goto joined_r0x030019a0;
          }
          goto LAB_030019c4;
        }
        if (*(char *)(iVar3 + 0x10) == '\0') goto LAB_030018ac;
LAB_030018c4:
        func_0x02fdcf06(iVar10 + 0xc,u_Play_All_Album_03001ad8,0x1e);
LAB_03001974:
        puVar4[1] = 1;
LAB_030019c0:
        if (*(short *)(iVar10 + 0xc) != 0) goto LAB_030019c4;
LAB_030019ca:
        if (*DAT_03001b30 == 2) {
          *(undefined2 *)(iVar10 + 0xc) = 0x4e;
          *(undefined2 *)(iVar10 + 0xe) = 0x55;
          *(undefined2 *)(iVar10 + 0x10) = 0x4c;
          *(undefined2 *)(iVar10 + 0x12) = 0x4c;
          *(undefined2 *)(iVar10 + 0x14) = 0;
        }
      }
      else {
        if (puVar2[uVar5 - 0x330] == 0x500) {
          if (uVar5 == 2) {
            if (uVar8 == 0 && uVar6 == 0) {
              if (*(char *)(iVar3 + 0x10) != '\0') goto LAB_030018c4;
LAB_030018ac:
              *(undefined4 *)(iVar10 + 0xc) = DAT_03001ac8;
              *(undefined4 *)(iVar10 + 0x10) = DAT_03001acc;
              *(undefined4 *)(iVar10 + 0x14) = DAT_03001ad0;
              *(undefined4 *)(iVar10 + 0x18) = DAT_03001ad4;
              *(undefined4 *)(iVar10 + 0x1c) = u_Play_All_Album_03001ad8._0_4_;
              goto LAB_03001974;
            }
            FUN_03001592(iVar10 + 0xc,(uVar8 + uVar6) - 1 & 0xffff);
            uVar5 = 0;
            if (*(short *)(iVar10 + 0xc) != 0) goto LAB_030019c4;
            do {
              if (*(short *)(iVar10 + 0xc + uVar5 * 2) != 0) break;
              uVar5 = uVar5 + 1;
            } while (uVar5 < 0x80);
            goto joined_r0x030019a0;
          }
          if (uVar5 != 1) goto LAB_030018ec;
          if (uVar8 == 0 && uVar6 == 0) {
            if (*(char *)(iVar3 + 0x10) == '\0') {
              *(undefined4 *)(iVar10 + 0xc) = DAT_03001b1c;
              *(undefined4 *)(iVar10 + 0x10) = DAT_03001b20;
              *(undefined4 *)(iVar10 + 0x14) = DAT_03001b24;
              *(undefined4 *)(iVar10 + 0x18) = DAT_03001b28;
              *(undefined4 *)(iVar10 + 0x1c) = DAT_03001b2c;
            }
            else {
              func_0x02fdcf06(iVar10 + 0xc,u_Play_All_Single_03001af8,0x1e);
            }
            goto LAB_03001974;
          }
          FUN_03001592(iVar10 + 0xc,(uVar8 + uVar6) - 1 & 0xffff);
          uVar5 = 0;
          if (*(short *)(iVar10 + 0xc) == 0) {
            do {
              if (*(short *)(iVar10 + 0xc + uVar5 * 2) != 0) break;
              uVar5 = uVar5 + 1;
            } while (uVar5 < 0x80);
            goto joined_r0x030019a0;
          }
        }
        else {
LAB_030018ec:
          FUN_03001592(iVar10 + 0xc,uVar8 + uVar6 & 0xffff);
          uVar5 = 0;
          if (*(short *)(iVar10 + 0xc) == 0) {
            do {
              if (*(short *)(iVar10 + 0xc + uVar5 * 2) != 0) break;
              uVar5 = uVar5 + 1;
            } while (uVar5 < 0x80);
joined_r0x030019a0:
            if (uVar5 == 0x80) {
              FUN_02feb762(0x18,iVar10 + 0xc,0x80);
              *puVar4 = 1;
            }
            goto LAB_030019c0;
          }
        }
LAB_030019c4:
        if (*(short *)(iVar10 + 0xc) == 0xe5) goto LAB_030019ca;
      }
      *(undefined2 *)(iVar10 + 8) = 1;
      if (4 < uVar6) {
        return;
      }
      iVar10 = *(int *)(iVar10 + 4);
      uVar6 = uVar6 + 1 & 0xffff;
      if (5 < uVar6) {
        return;
      }
    } while( true );
  }
  piVar9 = *(int **)(DAT_03001ab4 + 0xe);
  if (param_1 != 1) {
    return;
  }
  *DAT_03001ac0 = 0;
  puVar4[1] = 0;
  iVar10 = *piVar9;
  uVar6 = 0;
  *(int *)(puVar2 + 0xe) = iVar10;
  do {
    iVar7 = uVar6 * 2;
    uVar6 = uVar6 + 1 & 0xffff;
    *(undefined2 *)(iVar10 + iVar7 + 0xc) = 0;
  } while (uVar6 < 0x80);
  uVar6 = (uint)puVar2[5];
  if (puVar2[uVar6 - 0x330] == 0x600) {
    if (uVar6 != 0) {
      if (uVar8 == 0) {
        if (*(char *)(iVar3 + 0x10) == '\0') {
          *(undefined4 *)(iVar10 + 0xc) = DAT_03001ac8;
          *(undefined4 *)(iVar10 + 0x10) = DAT_03001acc;
          *(undefined4 *)(iVar10 + 0x14) = DAT_03001ad0;
          *(undefined4 *)(iVar10 + 0x18) = DAT_03001ad4;
          *(undefined4 *)(iVar10 + 0x1c) = u_Play_All_Album_03001ad8._0_4_;
        }
        else {
          func_0x02fdcf06(iVar10 + 0xc,u_Play_All_Album_03001ad8,0x1e);
        }
        goto LAB_03001b48;
      }
      goto LAB_03001a94;
    }
  }
  else if (puVar2[uVar6 - 0x330] == 0x500 && uVar6 == 1) {
    if (uVar8 == 0) {
      if (*(char *)(iVar3 + 0x10) == '\0') {
        *(undefined4 *)(iVar10 + 0xc) = DAT_03001b1c;
        *(undefined4 *)(iVar10 + 0x10) = DAT_03001b20;
        *(undefined4 *)(iVar10 + 0x14) = DAT_03001b24;
        *(undefined4 *)(iVar10 + 0x18) = DAT_03001b28;
        *(undefined4 *)(iVar10 + 0x1c) = DAT_03001b2c;
      }
      else {
        func_0x02fdcf06(iVar10 + 0xc,u_Play_All_Single_03001af8,0x1e);
      }
LAB_03001b48:
      puVar4[1] = 1;
      goto LAB_03001a8c;
    }
LAB_03001a94:
    FUN_03001592(iVar10 + 0xc,uVar8 - 1 & 0xffff);
    FUN_03001562(iVar10 + 0xc);
    goto LAB_03001a8c;
  }
  FUN_03001592(iVar10 + 0xc,uVar8);
  FUN_03001562(iVar10 + 0xc);
LAB_03001a8c:
  *(undefined2 *)(iVar10 + 8) = 1;
  return;
}


