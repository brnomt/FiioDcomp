/**
 * FUN_03019a08 @ 0x03019a08
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03019a08(void)

{
  short sVar1;
  char *pcVar2;
  int *piVar3;
  undefined2 *puVar4;
  uint *puVar5;
  ushort *puVar6;
  short *psVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  ushort *puVar11;
  ushort uVar12;
  ushort uVar13;
  int iVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  int iVar18;
  uint uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  uint extraout_r3;
  ushort *unaff_r4;
  uint unaff_r5;
  ushort unaff_r6;
  undefined2 *unaff_r7;
  uint unaff_r8;
  char *unaff_r9;
  ushort *unaff_r10;
  bool bVar22;
  short sStack00000008;
  short sStack0000000a;
  short sStack0000000c;
  short sStack0000000e;
  ushort in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined1 in_stack_00000018;
  undefined1 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  uint in_stack_0000002c;
  
  FUN_03005abe();
  func_0x03005aa0();
  if (*(char *)(DAT_03019dcc + 0x224) == '\0') {
    return;
  }
  func_0x02fde8f6();
  func_0x02fde8f6(DAT_0300677c,0,0x100);
  FUN_0300490a();
  uVar13 = (ushort)unaff_r5;
  if ((*DAT_03006780 == 0) && (*(int *)(unaff_r7 + 0x22) != 1)) {
    *unaff_r9 = '\x01';
    FUN_02ff2de4(0x4f);
    iVar14 = func_0x02fde968(DAT_03006778,DAT_03006774,0x100);
    if (iVar14 == 0) {
      *DAT_03006774 = uVar13;
    }
    FUN_02ff2e26(0x46);
  }
  else {
    FUN_02ff2de4(0x1b0);
    *unaff_r9 = (char)unaff_r5;
  }
  iVar14 = FUN_02ff2e00(0x48);
  if (iVar14 == 1) {
    RecordGetFileName(unaff_r7[1],*unaff_r7);
  }
  FUN_02ff2e00(0x41);
  iVar14 = FUN_02ff2e00(0x42);
  if (iVar14 == 1) {
    if (*unaff_r10 == 0) {
      uVar21 = 0x53;
    }
    else {
      uVar21 = 0x52;
    }
    FUN_02fef2b2(uVar21,5,0x98);
  }
  uVar15 = FUN_02ff2e00(0x1b0);
  bVar22 = uVar15 == 1;
  if (bVar22) {
    uVar15 = (uint)*unaff_r10;
  }
  if (bVar22 && uVar15 == 0) {
    *(int *)(unaff_r9 + 0x10) = *(int *)(unaff_r9 + 0x10) + 1;
  }
  iVar14 = FUN_02ff2e00(0x46);
  piVar3 = DAT_03006784;
  if (iVar14 == 1) {
    FUN_02ff2de4(0x43);
    *unaff_r4 = unaff_r6;
    FUN_03005bd2();
    uVar21 = 1;
    iVar14 = *piVar3;
    if (*DAT_03006788 < 8) {
      uVar21 = *(undefined4 *)(iVar14 + 0x9c);
      uVar20 = *(undefined4 *)(iVar14 + 8);
      uVar16 = *(undefined4 *)(iVar14 + 0xc);
    }
    else {
      uVar20 = *(undefined4 *)(iVar14 + 8);
      uVar16 = *(undefined4 *)(iVar14 + 0xc);
    }
    FUN_03005e54(uVar16,uVar20,uVar21);
  }
  iVar14 = FUN_02ff2e00(0x45);
  if (iVar14 == 1) {
    FUN_02fef2b2(*(byte *)(*piVar3 + 0x28) + 0xbc,0xf0,3);
    FUN_02fef2b2(*(byte *)(DAT_0300678c + 0x358) + 0x102,0x88,4);
  }
  iVar14 = FUN_02ff2e00(0x48);
  if (iVar14 == 1) {
    *unaff_r4 = *DAT_03006790;
  }
  iVar14 = FUN_02ff2e00(0x4c);
  if (iVar14 == 1) {
    puVar17 = (undefined4 *)*piVar3;
    if (*(int *)(unaff_r7 + 0x22) == 1) {
      if ((uint)puVar17[1] < *(uint *)(unaff_r7 + 0x24)) {
        puVar17[1] = *(uint *)(unaff_r7 + 0x24);
      }
      uVar15 = (uint)((puVar17[1] - *(int *)(unaff_r7 + 0x24)) * 0x121) /
               (uint)(*(int *)(unaff_r7 + 0x26) - *(int *)(unaff_r7 + 0x24));
    }
    else {
      uVar15 = func_0x02fdfb60((int)((ulonglong)(uint)puVar17[1] * 0x121),
                               (int)((ulonglong)(uint)puVar17[1] * 0x121 >> 0x20),*puVar17,0);
    }
    *(uint *)(unaff_r9 + 8) = uVar15;
    *(uint *)(unaff_r9 + 0xc) = uVar15;
    if (uVar15 < 0x123) {
      FUN_03005b44((ushort)DAT_03006794[2] + 0x13,(ushort)DAT_03006794[3] + 0x98,
                   (ushort)DAT_03006794[2] + 0x136,(ushort)DAT_03006794[3] + 0x9c);
      puVar4 = DAT_03006794;
      in_stack_00000010 = uVar13;
      if (unaff_r5 < *(uint *)(unaff_r9 + 8)) {
        do {
          FUN_02feeb60(puVar4[2] + in_stack_00000010 + 0x14,puVar4[3] + 0x99,*puVar4,puVar4[1]);
          in_stack_00000010 = in_stack_00000010 + 1;
        } while ((uint)in_stack_00000010 < *(uint *)(unaff_r9 + 8));
      }
      in_stack_0000002c = (uint)in_stack_00000010;
      if (in_stack_0000002c < 0x122) {
        do {
          FUN_02feeb60(DAT_03006794[2] + in_stack_00000010 + 0x14,DAT_03006794[3] + 0x99,
                       *DAT_03006794,DAT_03006794[1]);
          in_stack_00000010 = in_stack_00000010 + 1;
        } while (in_stack_00000010 < 0x122);
      }
      FUN_02fef2b2(0xf6,(int)(short)((short)in_stack_0000002c + 0x13 + DAT_03006794[2]),
                   (int)(short)(DAT_03006794[3] + 0x98));
    }
  }
  iVar14 = FUN_02ff2e00(0x40);
  if (iVar14 == 1) {
    if (*(int *)(unaff_r7 + 0x22) == 1) {
      uVar15 = *(int *)(unaff_r7 + 0x26) - *(int *)(unaff_r7 + 0x24);
    }
    else {
      uVar15 = *(uint *)*piVar3;
    }
    unaff_r8 = uVar15 / 1000;
    FUN_02fe1968(unaff_r8,&stack0x00000010,&stack0x00000018,&stack0x0000001c);
    FUN_0300584c(in_stack_00000010,in_stack_00000018,in_stack_0000001c,1);
  }
  iVar14 = FUN_02ff2e00(0x3f);
  puVar5 = DAT_03006c1c;
  if (iVar14 == 1) {
    if (*(uint *)(*piVar3 + 4) != unaff_r8) {
      unaff_r8 = *(uint *)(*piVar3 + 4);
    }
    uVar15 = unaff_r8 / 1000;
    if (uVar15 != *DAT_03006c1c) {
      FUN_02ff2de4(0x4c);
      if (*(int *)(unaff_r7 + 0x22) == 1) {
        uVar19 = *(uint *)(unaff_r7 + 0x24) / 1000;
        if (uVar15 < uVar19) {
          uVar15 = uVar19;
        }
        uVar15 = uVar15 - uVar19;
      }
      *puVar5 = uVar15;
      FUN_02fe1968(uVar15,&stack0x00000010,&stack0x00000018,&stack0x0000001c);
      FUN_0300584c(in_stack_00000010,in_stack_00000018,in_stack_0000001c,0);
    }
  }
  iVar18 = FUN_02ff2e00(0x49);
  psVar7 = DAT_03006c28;
  iVar14 = DAT_03006c24;
  puVar6 = DAT_03006c20;
  uVar12 = uVar13;
  if (iVar18 == 1) {
    do {
      in_stack_00000010 = uVar12;
      uVar15 = (uint)in_stack_00000010;
      psVar7[uVar15] = *(short *)(iVar14 + uVar15 * 2 + 0x60);
      iVar18 = DAT_03006c2c;
      in_stack_00000010 = (ushort)(uVar15 + 1);
      uVar12 = in_stack_00000010;
    } while ((uVar15 + 1 & 0xffff) < 0x80);
    uVar12 = uVar13;
    if (*psVar7 == 0) {
      do {
        in_stack_00000010 = uVar12;
        uVar15 = (uint)in_stack_00000010;
        sVar1 = *(short *)(iVar18 + uVar15 * 2);
        if (sVar1 == 0) {
          psVar7[in_stack_00000010] = uVar13;
          if (psVar7[uVar15 - 4] == 0x2e) {
            psVar7[uVar15 - 4] = uVar13;
          }
          if (psVar7[uVar15 - 5] == 0x2e) {
            psVar7[uVar15 - 5] = uVar13;
          }
          break;
        }
        psVar7[uVar15] = sVar1;
        in_stack_00000010 = (ushort)(uVar15 + 1);
        uVar12 = in_stack_00000010;
      } while ((uVar15 + 1 & 0xffff) < 0x80);
    }
    sStack0000000c = 0x140;
    sStack00000008 = 0xa2;
    sStack0000000e = 0x2b;
    sStack0000000a = 0x1c;
    FUN_02fef2b2(0x148);
    uVar15 = FUN_02fed6a6(DAT_03006c28);
    if (uVar15 < ((int)sStack0000000c - (int)sStack00000008) - 0x10U) {
      FUN_02ff2e26(0x4a);
    }
    else {
      FUN_02fee2a8(&stack0x00000008,CONCAT22(sStack0000000a,sStack00000008),
                   unaff_r5 & 0xffff | 0x100000,extraout_r3 & 0xffff0000 | 0x148);
      FUN_02ff2de4(0x4a);
    }
    *unaff_r4 = *puVar6;
    FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03006c28,2);
    *unaff_r4 = unaff_r6;
  }
  if (*unaff_r9 == '\x01') {
    FUN_030041b4(0);
    iVar14 = FUN_02ff2e00(0x4f);
    if (iVar14 == 1) {
      FUN_02fef2b2(0x146,0xa1,0x32);
      FUN_02fee544(1);
      uVar12 = FUN_02fed6a6(DAT_03006c30);
      if (uVar12 < 0x9b) {
        sStack00000008 = 0xa5;
        sStack0000000a = 0x40;
        sStack0000000c = 0x13f;
        sStack0000000e = 0x56;
      }
      else {
        sStack0000000a = 0x37;
        sStack0000000e = 0x4d;
        if (uVar12 < 0x135) {
          uVar15 = (uVar12 >> 1) + 0xc;
          if (0x9a < uVar15) {
            uVar15 = 0x9a;
          }
          sStack00000008 = (short)((int)(0x9b - uVar15) / 2) + 0xa5;
          sStack0000000c = (short)uVar15 + sStack00000008;
        }
        else {
          sStack00000008 = 0xa5;
          sStack0000000c = 0x13f;
        }
      }
      if (*(char *)(DAT_03006c34 + 0x34f) == '\x01') {
        uVar12 = 0x94b2;
      }
      else {
        uVar12 = 0x528a;
      }
      *unaff_r4 = uVar12;
      FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03006c30,2);
      uVar12 = FUN_02fed6a6(DAT_03006c38);
      sStack0000000a = 0x50;
      sStack0000000e = 0x71;
      if (uVar12 < 0x1ce) {
        if (uVar12 < 0x134) {
          if (uVar12 < 0x9b) {
            sStack00000008 = 0xa5;
            sStack0000000c = 0x140;
            uVar12 = 1;
          }
          else {
            uVar15 = (uVar12 >> 1) + 0xc;
            uVar12 = 2;
            if (0x9a < uVar15) {
              uVar15 = 0x9a;
            }
            sStack00000008 = (short)((int)(0x9b - uVar15) / 2) + 0xa5;
            sStack0000000c = (short)uVar15 + sStack00000008;
          }
        }
        else {
          uVar12 = 3;
          sStack00000008 = 0xa5;
          sStack0000000c = 0x140;
        }
      }
      else {
        sStack0000000c = 0x140;
        uVar12 = 4;
        sStack00000008 = 0xa5;
        sStack0000000e = 0x8a;
      }
      if (*(char *)(DAT_03006c34 + 0x34f) == '\x04') {
        *unaff_r4 = unaff_r6;
      }
      else if (*(char *)(DAT_03006c34 + 0x34f) == '\x03') {
        *unaff_r4 = uVar13;
      }
      else {
        *unaff_r4 = *puVar6;
      }
      FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03006c38,2);
      func_0x02fde8f6(DAT_03006c30,DAT_03006c38,0x100);
      *DAT_03006c40 = *DAT_03006c3c;
      *DAT_03006c48 = *DAT_03006c44;
      FUN_030041b4();
      FUN_02ff2e00(0x4f);
      *DAT_03006c3c = *DAT_03006c40;
      *DAT_03006c44 = *DAT_03006c48;
      func_0x02fde8f6(DAT_03006c4c,DAT_03006c38,0x100);
      func_0x02fde8f6(DAT_03006c38,DAT_03006c30,0x100);
      if (*(char *)(DAT_03006c34 + 0x34f) == '\x01') {
        uVar13 = 0x94b2;
      }
      else {
        uVar13 = 0x528a;
      }
      *unaff_r4 = uVar13;
      if (uVar12 < 4) {
        sStack0000000a = uVar12 * 0xc + 0x52;
      }
      else {
        sStack0000000a = 0x76;
      }
      sStack0000000e = sStack0000000a + 0x16;
      uVar13 = FUN_02fed6a6(DAT_03006c4c);
      if ((uVar13 < 0x134) && (0x9a < uVar13)) {
        uVar15 = (uVar13 >> 1) + 0xc;
        if (0x9a < uVar15) {
          uVar15 = 0x9a;
        }
        sStack00000008 = (short)((int)(0x9b - uVar15) / 2) + 0xa5;
        sStack0000000c = (short)uVar15 + sStack00000008;
      }
      else {
        sStack00000008 = 0xa5;
        sStack0000000c = 0x140;
      }
      if (uVar12 < 4) {
        FUN_02feda18(&stack0x00000008,&stack0x00000008,DAT_03006c4c,2);
      }
      FUN_02fee544(2);
      iVar14 = FUN_02ff2e44(1);
      if (iVar14 != 0) {
        FUN_02ff2de4(0x33);
      }
    }
  }
  iVar14 = FUN_02ff2e00(0x3b);
  puVar9 = DAT_03006c58;
  puVar8 = DAT_03006c54;
  puVar5 = DAT_03006c50;
  if (iVar14 == 0) {
LAB_03006bc8:
    puVar10 = DAT_03006c5c;
    uVar15 = *puVar5;
    bVar22 = uVar15 != 1;
    if (!bVar22) {
      uVar15 = *puVar8;
    }
    if (bVar22 || uVar15 != 0) goto LAB_03006cd2;
    if (*puVar9 == 0) {
      if (*DAT_03006c5c == 0) {
        iVar14 = 0xff;
      }
      else {
        iVar14 = FUN_0300b832();
        FUN_02ff2de4(0x11c);
      }
      uVar15 = *puVar10 + 1;
      *puVar10 = uVar15;
      if (uVar15 == 1) {
        FUN_02fef2b2(0x15c,0x11,0x16);
      }
      FUN_02fefb54();
      if (iVar14 != 0) goto LAB_03006cd2;
    }
  }
  else {
    *DAT_03006c5c = unaff_r5;
    *puVar5 = unaff_r5;
    *puVar8 = unaff_r5;
    *puVar9 = unaff_r5;
    FUN_02ff2e26(0x11c);
    if (*(int *)(unaff_r7 + 0x22) != 0) {
      *puVar5 = unaff_r5;
LAB_03006bc2:
      FUN_02ff2de4(0x43);
      goto LAB_03006bc8;
    }
    FUN_03005968();
    if (*puVar5 != 1) goto LAB_03006bc2;
    if (*puVar8 == 1) goto LAB_03006cd2;
    if (*puVar8 != 0) goto LAB_03006bc2;
    if (*puVar9 == 0) {
      FUN_02ff2c88(0x1a);
      goto LAB_03006bc8;
    }
  }
  FUN_02ff2cd4(0x1a);
  pcVar2 = DAT_03007074;
  FUN_02fe3c0c((int)*DAT_03007074);
  pcVar2[0] = -1;
  puVar11 = DAT_03007078;
  pcVar2[1] = -1;
  pcVar2[2] = -1;
  pcVar2[3] = -1;
  func_0x02fde8f6(DAT_0300707c + (uint)*DAT_03007078 * 0x15e00,DAT_0300707c,0x15e00);
  func_0x02fde8f6(DAT_03007080 + (uint)*puVar11 * 0x4b00,DAT_03007080,0x4b00);
  *puVar8 = 1;
  *puVar9 = 1;
  FUN_02ff2e26(0x11c);
  *DAT_03007084 = unaff_r5;
LAB_03006cd2:
  iVar14 = FUN_02ff2e44(0x4a);
  if (iVar14 == 1) {
    in_stack_00000014 = FUN_02fee544(2);
    *unaff_r4 = *puVar6;
    FUN_02fee180(DAT_03007088);
    *unaff_r4 = unaff_r6;
  }
  iVar14 = FUN_02ff2e44(0xae);
  if (iVar14 == 1) {
    in_stack_00000014 = FUN_02fee544();
    *unaff_r4 = *puVar6;
    FUN_02fedc4e(DAT_0300708c,0);
    *unaff_r4 = unaff_r6;
  }
  iVar14 = FUN_02ff2e44(0xaf);
  if (iVar14 == 1) {
    in_stack_00000014 = FUN_02fee544();
    *unaff_r4 = *puVar6;
    FUN_02fedd96(DAT_03007090,0);
    *unaff_r4 = unaff_r6;
  }
  iVar14 = FUN_02ff2e44(0xb0);
  if (iVar14 == 1) {
    in_stack_00000014 = FUN_02fee544();
    *unaff_r4 = *puVar6;
    FUN_02fedede(DAT_03007094,0);
    *unaff_r4 = unaff_r6;
  }
  FUN_02fee568(in_stack_00000020);
  unaff_r4[1] = (ushort)in_stack_00000024;
  *unaff_r4 = (ushort)in_stack_00000028;
  FUN_02fee544(in_stack_00000014);
  return;
}


