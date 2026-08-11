/**
 * FUN_0306fc20 @ 0x0306fc20
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0306fc20(uint *param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  
  uVar6 = DAT_0306fd94;
  iVar4 = DAT_0306fd90;
  param_2 = param_2 & DAT_0306fd94;
  iVar12 = DAT_0306fd90 + -0x2c0;
  sVar7 = 0x5a0;
  iVar14 = DAT_0306fd90 + 0x20;
  iVar13 = DAT_0306fd90 + -0x300;
  puVar5 = param_1;
  do {
    if ((char)*puVar5 == -1) {
      bVar1 = *(byte *)((int)puVar5 + 1);
      uVar8 = (uint)bVar1;
      if ((((((~uVar8 & 0xe0) == 0) && ((uVar8 & 0x18) != 8 && (bVar1 & 6) != 0)) &&
           (bVar2 = *(byte *)((int)puVar5 + 2), (bVar2 & 0xf0) != 0)) &&
          (((~bVar2 & 0xf0) != 0 && ((~bVar2 & 0xc) != 0)))) &&
         (uVar10 = *puVar5,
         ((uVar10 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
          (uint)*(byte *)((int)puVar5 + 3)) & uVar6) == param_2)) {
        bVar1 = bVar1 >> 1;
        uVar10 = bVar1 & 0xc;
        uVar8 = (uVar8 & 7) >> 1;
        if (uVar8 == 1) {
          *DAT_030701a0 = 2;
          if ((bVar1 & 0xc) != 0 && uVar10 != 8) goto LAB_0306fcce;
          *DAT_030701a4 = 0x240;
        }
        else {
          if (uVar8 == 2) {
            *DAT_0306fd6c = 1;
          }
          else {
            if (uVar8 == 3) {
              *DAT_030701a0 = 0;
              *DAT_030701a4 = 0x180;
              goto LAB_0306fcd6;
            }
            *DAT_0306fd6c = 2;
          }
LAB_0306fcce:
          *DAT_0306fd70 = 0x480;
        }
LAB_0306fcd6:
        uVar11 = (uint)*(byte *)((int)puVar5 + 2);
        uVar9 = (uint)(*(byte *)((int)puVar5 + 2) >> 4);
        uVar15 = (uVar11 & 0xf) >> 2;
        if (uVar8 == 1) {
          if ((bVar1 & 0xc) != 0) {
            uVar10 = uVar10 - 4 & 0xff;
          }
          uVar8 = (uint)*(ushort *)(DAT_030701a8 + (uVar10 | uVar15) * 0x20 + uVar9 * 2) -
                  ((int)(uVar11 << 0x1e) >> 0x1f) & 0xffff;
        }
        else if (uVar8 == 2) {
          if ((bVar1 & 0xc) != 0) {
            uVar10 = uVar10 - 8 & 0xff;
          }
          uVar8 = (uint)*(ushort *)(DAT_030701ac + (uVar10 | uVar15) * 0x20 + uVar9 * 2) -
                  ((int)(uVar11 << 0x1e) >> 0x1f) & 0xffff;
        }
        else {
          if ((bVar1 & 0xc) != 0) {
            uVar10 = uVar10 - 8 & 0xff;
          }
          uVar8 = (uint)*(ushort *)(DAT_0306fd78 + (uVar10 | uVar15) * 0x20 + uVar9 * 2) -
                  ((int)(uVar11 << 0x1e) >> 0x1f) & 0xffff;
        }
        uVar10 = (*(byte *)((int)puVar5 + 1) & 7) >> 1;
        if ((*(byte *)((int)puVar5 + 1) >> 1 & 0xc) == 0xc) {
          if (uVar10 == 3) {
            uVar10 = (uint)*(ushort *)(iVar4 + uVar9 * 2);
          }
          else {
            if (uVar10 == 2) {
              uVar3 = *(ushort *)(iVar12 + (uVar9 | 0x10) * 2);
            }
            else {
              uVar3 = *(ushort *)(iVar13 + (uVar9 | 0x10) * 2);
            }
            uVar10 = (uint)uVar3;
          }
        }
        else if (uVar10 == 3) {
          uVar10 = (uint)*(ushort *)(iVar14 + uVar9 * 2);
        }
        else if (uVar10 == 2) {
          uVar10 = (uint)*(ushort *)(iVar12 + uVar9 * 2);
        }
        else {
          uVar10 = (uint)*(ushort *)(iVar13 + uVar9 * 2);
        }
        puVar5 = (uint *)((int)puVar5 + uVar8);
        if (0x7fb < (uint)((int)puVar5 - (int)param_1)) {
          *param_1 = param_1[0x1ff];
          (*(code *)*DAT_0306fd9c)(param_1 + 1,0x600,*DAT_0306fd98);
          puVar5 = (uint *)((int)param_1 + (((int)puVar5 - (int)param_1) - 0x7fcU));
        }
        if ((char)*puVar5 == -1) {
          bVar1 = *(byte *)((int)puVar5 + 1);
          uVar8 = (uint)bVar1;
          if ((((~uVar8 & 0xe0) == 0) && ((uVar8 & 0x18) != 8 && (bVar1 & 6) != 0)) &&
             ((bVar2 = *(byte *)((int)puVar5 + 2), (bVar2 & 0xf0) != 0 &&
              (((~bVar2 & 0xf0) != 0 && ((~bVar2 & 0xc) != 0)))))) {
            uVar8 = (uVar8 & 7) >> 1;
            uVar6 = (uint)(*(byte *)((int)puVar5 + 2) >> 4);
            if ((bVar1 >> 1 & 0xc) == 0xc) {
              if (uVar8 == 3) {
                uVar6 = (uint)*(ushort *)(iVar4 + uVar6 * 2);
              }
              else {
                if (uVar8 == 2) {
                  uVar3 = *(ushort *)(iVar12 + (uVar6 | 0x10) * 2);
                }
                else {
                  uVar3 = *(ushort *)(iVar13 + (uVar6 | 0x10) * 2);
                }
                uVar6 = (uint)uVar3;
              }
            }
            else if (uVar8 == 3) {
              uVar6 = (uint)*(ushort *)(iVar14 + uVar6 * 2);
            }
            else if (uVar8 == 2) {
              uVar6 = (uint)*(ushort *)(iVar12 + uVar6 * 2);
            }
            else {
              uVar6 = (uint)*(ushort *)(iVar13 + uVar6 * 2);
            }
            return uVar6 + uVar10;
          }
        }
      }
    }
    sVar7 = sVar7 + -1;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (sVar7 == 0) {
      return 0;
    }
  } while( true );
}


