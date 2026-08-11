/**
 * FUN_03007896 @ 0x03007896
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_03007896(void)

{
  ushort uVar1;
  char cVar2;
  int *piVar3;
  short *psVar4;
  char *pcVar5;
  int *piVar6;
  short *psVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  short sVar11;
  undefined2 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int extraout_r1;
  int extraout_r1_00;
  ushort *puVar17;
  bool bVar18;
  undefined4 local_48;
  undefined1 auStack_44 [28];
  int local_28;
  
  local_28 = 0;
  iVar13 = FUN_02fec8d6();
  psVar7 = DAT_03007da0;
  psVar4 = DAT_03007990;
  piVar6 = DAT_03007984;
  piVar3 = DAT_03007980;
  iVar15 = DAT_0300797c;
  if ((*(byte *)(DAT_0300797c + 0x34c) < 2) && (0x28 < (uint)(*DAT_03007980 - *DAT_03007988))) {
    if (*DAT_0300798c == '\x01') {
      *DAT_03007990 = 0;
      *DAT_03007994 = 0;
    }
    else if ((*DAT_03007990 == 1) || (*DAT_03007994 == 1)) {
      if (*(byte *)(DAT_0300797c + 0x34c) == 0) {
        *DAT_03007990 = 0;
        *psVar7 = 0;
        FUN_02ff2e26(0x11c);
        FUN_02ff2de4(1);
        *piVar6 = *piVar3;
        FUN_02ff2de4(0x39);
      }
      else {
        iVar14 = FUN_02ff2e44(1);
        psVar7 = DAT_03007994;
        if (iVar14 == 0) {
          if (*DAT_03007da0 == 1) {
            iVar13 = DAT_03007da4;
          }
          if (*psVar4 == 1) {
            iVar13 = DAT_03007da8;
          }
        }
        *psVar4 = 0;
        *psVar7 = 0;
      }
    }
    *DAT_03007990 = 0;
    *DAT_03007994 = 0;
  }
  iVar14 = FUN_02ff2e00(0x1ce);
  puVar9 = DAT_0300820c;
  pcVar5 = DAT_03007978;
  if (iVar14 != 0) {
    iVar13 = DAT_03007998;
  }
  if (*(char *)(iVar15 + 0x34c) == '\x02') {
    iVar14 = iVar13 - DAT_03007dac;
    if (iVar13 == DAT_03007dac) {
      iVar13 = FUN_02ff2e44(1);
      if (iVar13 == 0) {
        FUN_02ff2de4(0x39);
      }
      FUN_02ff2de4(1);
      *piVar6 = *piVar3;
LAB_03007ad0:
      iVar13 = FUN_02ff2e44(1);
      if (iVar13 == 0) {
        return 0;
      }
      FUN_02ff2e26(0x11c);
      *piVar6 = *piVar3;
      iVar13 = FUN_02ff2e44(1);
      if (iVar13 == 0) {
        FUN_02ff2de4(0x39);
      }
      FUN_02ff2de4(1);
      cVar2 = *(char *)(iVar15 + 0x35a);
joined_r0x03008332:
      if (cVar2 != '\x01') goto LAB_0300811c;
      goto LAB_03008114;
    }
    if (iVar13 < DAT_03007dac) {
      if (iVar13 == DAT_03007db0) goto LAB_03007ad0;
      if (iVar13 < DAT_03007db0) {
        if (iVar13 == 0x20000002) {
          iVar15 = FUN_02fef5da(0);
          if (iVar15 == 0) goto LAB_03007d3c;
LAB_03007d48:
          FUN_02fef68e(0);
LAB_03007d4e:
          FUN_02ff82a6();
          uVar16 = 0x43;
          goto LAB_03007d54;
        }
        if (iVar13 != 0x20000004) {
          if (iVar13 != 0x20000008) {
            return 0;
          }
          iVar14 = FUN_02ff2e44(1);
          psVar4 = DAT_03007dc0;
          iVar13 = DAT_03007dbc;
          piVar8 = DAT_03007db8;
          if (iVar14 != 0) {
            FUN_02ff2e26(0x11c);
            *piVar6 = *piVar3;
            FUN_02ff2de4(1);
            cVar2 = *(char *)(iVar15 + 0x35a);
            goto joined_r0x03007b3a;
          }
          if (((*(uint *)(*DAT_03007db8 + 4) < 3000) && (*(int *)(DAT_03007dbc + 0x44) == 0)) ||
             ((*(uint *)(*DAT_03007db8 + 4) - *(int *)(DAT_03007dbc + 0x48) < 3000 &&
              (*(int *)(DAT_03007dbc + 0x44) == 1)))) {
            iVar15 = *DAT_03007dc4;
            piVar3 = DAT_03007dc4;
            goto joined_r0x03007b8c;
          }
          sVar11 = *DAT_03007dc0;
          if (sVar11 == 3) {
            pcVar5[4] = '\b';
            pcVar5[5] = '\0';
          }
          else if (sVar11 == 0) {
            pcVar5[4] = '\x06';
            pcVar5[5] = '\0';
            FUN_02ff2de4(0x40);
          }
          DSP_GOODEF_Reload(0xed,0);
          FUN_02ff2de4(0x19d);
          FUN_02ff0014(100);
          *DAT_03007dc8 = 8000;
          DSP_GOODEF_Reload(0xfa);
          FUN_02ff2de4(0x4c);
          iVar15 = *(int *)(iVar13 + 0x44);
          bVar18 = iVar15 == 1;
          iVar14 = extraout_r1;
          if (bVar18) {
            iVar15 = *(int *)(iVar13 + 0x48);
            iVar14 = *piVar8;
          }
          if (bVar18) {
            *(int *)(iVar14 + 4) = iVar15;
          }
          else {
            iVar15 = *piVar8;
          }
          if (!bVar18) {
            *(undefined4 *)(iVar15 + 4) = 0;
          }
          *DAT_03007dcc = 0;
          func_0x0301191e();
          goto joined_r0x030084b8;
        }
        iVar13 = FUN_02ff2e44(1);
        if (iVar13 != 0) {
          FUN_02ff2e26(0x11c);
          *piVar6 = *piVar3;
          FUN_02ff2de4(1);
          cVar2 = *(char *)(iVar15 + 0x35a);
          goto joined_r0x03008332;
        }
        iVar15 = *DAT_03007dc4;
        piVar3 = DAT_03007dc4;
        goto joined_r0x03008356;
      }
      if (iVar13 - DAT_03007db0 != 4) {
        if ((iVar13 - DAT_03007db0) + DAT_03007db4 != 0) {
          return 0;
        }
        FUN_02ff2e26(0x11c);
        iVar15 = FUN_02ff2e44(1);
joined_r0x03007fb8:
        if (iVar15 == 0) {
          local_48 = CONCAT22(local_48._2_2_,1);
          FUN_02ff300e(10,&local_48);
          return 1;
        }
LAB_03007fdc:
        FUN_02ff2de4(0x2f);
        FUN_02ff2e26(1);
        return 0;
      }
    }
    else {
      if (iVar14 == 0xffc) {
        FUN_02ff2e26(0x11c);
        iVar13 = FUN_02ff2e44(1);
        if (iVar13 == 0) {
          iVar13 = FUN_02ff2e44(0x56);
          if (iVar13 != 0) {
            iVar13 = FUN_02ff2e00(0x57);
            if (iVar13 == 0) {
              return 0;
            }
            FUN_02ff2e26(0x56);
            FUN_02ff2e26(0x57);
          }
          iVar14 = FUN_02ff2e00(0xca);
          iVar13 = DAT_03007dbc;
          if (iVar14 != 0) {
LAB_03007f14:
            local_48 = CONCAT22(local_48._2_2_,7);
            FUN_02ff300e(10,&local_48);
            return 1;
          }
          sVar11 = *(short *)(DAT_03007dbc + 0xf2);
          if (sVar11 != 99 && sVar11 != 10) {
LAB_03007cae:
            *DAT_03007dd4 = sVar11;
            local_48 = CONCAT22(*DAT_03007dd8,sVar11);
            func_0x02fdfc5e(auStack_44,iVar15 + 0x4a,0x1c);
            *DAT_03007ddc = 0;
            FUN_02ff300e(2,&local_48);
            return 1;
          }
          local_48._0_3_ = CONCAT21(*(undefined2 *)(DAT_03007dbc + 2),1);
          local_48 = (uint)(uint3)local_48;
          iVar15 = *(int *)(*DAT_03007db8 + 0x1c);
          if ((iVar15 == 2 || iVar15 == 0) || (iVar15 == 3 || iVar15 == 1)) {
            uVar12 = FUN_02fe6040(*(undefined2 *)(DAT_03007dbc + 2),
                                  *(undefined4 *)(DAT_03007dbc + 0x34),DAT_03007de4,3);
            local_48._0_3_ = CONCAT21(uVar12,(undefined1)local_48);
          }
joined_r0x03007f8a:
          if (local_48._1_2_ == 0) {
            local_48._3_1_ = (undefined1)(local_48 >> 0x18);
            local_48 = CONCAT31(CONCAT12(local_48._3_1_,*(undefined2 *)(iVar13 + 2)),1);
          }
          FUN_02ff300e(9,&local_48);
          return 1;
        }
        goto LAB_03007fdc;
      }
      if (0xffc < iVar14) {
        if (iVar14 != 0xfffffc) {
          if (iVar14 != 0x1fffffc) {
            return 0;
          }
          goto LAB_030084d0;
        }
        goto LAB_030084c0;
      }
      if (iVar14 != 4) {
        if (iVar14 != 0x3c) {
          return 0;
        }
        FUN_02ff2e26(0x11c);
        iVar13 = FUN_02ff2e44(1);
        if (iVar13 != 0) goto LAB_03007fdc;
        if (*DAT_03007dc4 != 0) {
          *DAT_03007dc4 = 0;
          FUN_03011d76(0xfe,0);
          FUN_02ff2de4(0x41);
        }
        if (*DAT_03007dc0 == 0) {
          pcVar5[6] = '\0';
          pcVar5[7] = '\0';
          pcVar5[2] = '\x01';
          puVar17 = DAT_030081f8;
          if (*(char *)(iVar15 + 0x34a) != '\0') {
            if (*DAT_030081f8 == 0 || *DAT_030081f8 == 2) {
              FUN_02ff1708(0x87);
              iVar15 = FUN_02ff2e00(0x1ca);
              if (iVar15 != 0) {
                FUN_02ff173a(DAT_03008200,(int)*DAT_030081fc);
              }
            }
            *puVar17 = 1;
          }
          DSP_GOODEF_Reload(0xed,0);
          FUN_02ff2de4(0x42);
          goto LAB_0300800c;
        }
        if (*DAT_03007dc0 != 3) goto LAB_0300800c;
        pcVar5[6] = '\x03';
        pcVar5[7] = '\0';
        pcVar5[2] = '\x01';
        puVar17 = DAT_030081f8;
        if (*(char *)(iVar15 + 0x34a) != '\0') {
          if (*DAT_030081f8 < 2) {
            FUN_02ff1708(0x86);
            iVar15 = FUN_02ff2e00(0x1ca);
            goto joined_r0x0300809e;
          }
          goto LAB_03007e70;
        }
        goto LAB_03007e74;
      }
      iVar13 = FUN_02ff2e44(1);
      if (iVar13 == 0) {
        FUN_02ff2de4(0x39);
      }
      FUN_02ff2de4(1);
      *piVar6 = *piVar3;
    }
    iVar13 = FUN_02ff2e44(1);
    if (iVar13 == 0) {
      return 0;
    }
    FUN_02ff2e26(0x11c);
    *piVar6 = *piVar3;
    iVar13 = FUN_02ff2e44(1);
    if (iVar13 == 0) {
      FUN_02ff2de4(0x39);
    }
    FUN_02ff2de4(1);
    cVar2 = *(char *)(iVar15 + 0x35a);
  }
  else {
    iVar14 = iVar13 - DAT_0300799c;
    if (iVar13 == DAT_0300799c) {
      FUN_02ff2e26(0x11c);
      iVar13 = FUN_02ff2e44(1);
      if (iVar13 != 0) goto LAB_03007fdc;
      if (*DAT_03008220 != 0) {
        *DAT_03008220 = 0;
        FUN_03011d76(0xfe,0);
        FUN_02ff2de4(0x41);
      }
      if (*DAT_03008224 == 0) {
        pcVar5[6] = '\0';
        pcVar5[7] = '\0';
        pcVar5[2] = '\x01';
        puVar17 = DAT_030081f8;
        if (*(char *)(iVar15 + 0x34a) != '\0') {
          if (*DAT_030081f8 == 0 || *DAT_030081f8 == 2) {
            FUN_02ff1708(0x87);
            iVar15 = FUN_02ff2e00(0x1ca);
            if (iVar15 != 0) {
              FUN_02ff173a(DAT_03008200,(int)*DAT_030081fc);
            }
            local_28 = 1;
          }
          *puVar17 = 1;
        }
        DSP_GOODEF_Reload(0xed,0);
        if (local_28 != 0) {
          FUN_02ff0014(100);
        }
        FUN_02ff2de4(0x42);
        goto LAB_0300800c;
      }
      if (*DAT_03008224 != 3) goto LAB_0300800c;
      pcVar5[6] = '\x03';
      pcVar5[7] = '\0';
      pcVar5[2] = '\x01';
      puVar17 = DAT_030081f8;
      if (*(char *)(iVar15 + 0x34a) != '\0') {
        if (*DAT_030081f8 < 2) {
          FUN_02ff1708(0x86);
          iVar15 = FUN_02ff2e00(0x1ca);
joined_r0x0300809e:
          if (iVar15 != 0) {
            FUN_02ff173a(DAT_03008200,(int)*DAT_030081fc);
          }
          FUN_02ff0014(100);
        }
LAB_03007e70:
        *puVar17 = 2;
      }
LAB_03007e74:
      DSP_GOODEF_Reload(0xee,0);
      pcVar5[0x1c] = '(';
      pcVar5[0x1d] = '\0';
      pcVar5[0x1e] = '\0';
      pcVar5[0x1f] = '\0';
LAB_0300800c:
      uVar16 = FUN_02ff22d6();
      *(undefined4 *)(pcVar5 + 0x14) = uVar16;
      return 0;
    }
    if (DAT_0300799c <= iVar13) {
      iVar13 = iVar14 - DAT_03008208;
      if (iVar14 == DAT_03008208) {
LAB_030084c0:
        local_48 = (uint)local_48._2_2_ << 0x10;
        FUN_02fe1ce0(DAT_03008524,DAT_03008520,&local_48);
        return 0;
      }
      if (DAT_03008208 <= iVar14) {
        if (iVar13 != 0x1000000) {
          if (iVar13 == 0xf000004) {
            FUN_02ff2e26(0x11c);
            iVar15 = FUN_02ff2e44(1);
            if (iVar15 == 0) {
              FUN_0301197c();
              DSP_GOODEF_Reload(0xee,0);
              if ((*pcVar5 == '\x01') && (*DAT_030084e8 < 7)) {
                DSP_GOODEF_Reload(0xed,0);
                *DAT_030084ec = 1000;
                DSP_GOODEF_Reload(0xfa);
                FUN_0301197c();
                DSP_GOODEF_Reload(0xee,0);
              }
              *DAT_030084ec = 8000;
              uVar16 = FUN_02ff22d6();
              *puVar9 = uVar16;
              FUN_02ff2de4(0x43);
              FUN_02ff2de4(0x44);
              FUN_02ff2de4(0x45);
              FUN_02ff2de4(0x21);
              FUN_02ff2de4(0x42);
              puVar10 = DAT_030084f0;
              pcVar5[4] = '\0';
              pcVar5[5] = '\0';
              *puVar10 = 0;
              *DAT_030084f4 = 0;
              return 0;
            }
            return 0;
          }
          if (iVar13 == 0xf000008) {
            FUN_02ff2e26(0x11c);
            iVar15 = FUN_02ff2e44(1);
            if (iVar15 == 0) {
              *DAT_030084ec = 8000;
              func_0x0301191e();
              DSP_GOODEF_Reload(0xee,0);
              uVar16 = FUN_02ff22d6();
              *puVar9 = uVar16;
              FUN_02ff2de4(0x43);
              FUN_02ff2de4(0x44);
              FUN_02ff2de4(0x45);
              FUN_02ff2de4(0x21);
              FUN_02ff2de4(0x42);
              puVar10 = DAT_030084f0;
              pcVar5[4] = '\0';
              pcVar5[5] = '\0';
              *puVar10 = 0;
              *DAT_030084f4 = 0;
              return 0;
            }
            return 0;
          }
          return 0;
        }
LAB_030084d0:
        local_48 = CONCAT22(local_48._2_2_,1);
        FUN_02fe1ce0(DAT_03008524,DAT_03008520,&local_48);
        return 0;
      }
      if (iVar14 == 0x3c0) {
LAB_030083d8:
        psVar4 = DAT_03008518;
        iVar15 = DAT_03008514;
        piVar3 = DAT_03008510;
        if (((*(uint *)(*DAT_03008510 + 4) < 3000) && (*(int *)(DAT_03008514 + 0x44) == 0)) ||
           ((*(uint *)(*DAT_03008510 + 4) - *(int *)(DAT_03008514 + 0x48) < 3000 &&
            (*(int *)(DAT_03008514 + 0x44) == 1)))) {
          iVar15 = *DAT_030084fc;
          piVar3 = DAT_030084fc;
joined_r0x03007b8c:
          if (iVar15 != 0) {
            *piVar3 = 0;
            FUN_03011d76(0xfe,0);
            FUN_02ff2de4(0x41);
          }
          *DAT_03008500 = 0;
          *DAT_03008504 = 1;
          FUN_02ff2de4(0x1db);
          *DAT_03008508 = 0xffffffff;
          pcVar5[8] = '\0';
          pcVar5[9] = '\0';
          pcVar5[10] = '\0';
          pcVar5[0xb] = '\0';
          DSP_GOODEF_Reload(0x110);
          uVar16 = FUN_02ff22d6();
          *(undefined4 *)(pcVar5 + 0x18) = uVar16;
          return 0;
        }
        sVar11 = *DAT_03008518;
        if (sVar11 == 3) {
          pcVar5[4] = '\b';
          pcVar5[5] = '\0';
        }
        else if (sVar11 == 0) {
          pcVar5[4] = '\x06';
          pcVar5[5] = '\0';
          FUN_02ff2de4(0x40);
        }
        DSP_GOODEF_Reload(0xed,0);
        FUN_02ff2de4(0x19d);
        FUN_02ff0014(100);
        *DAT_030084ec = 8000;
        DSP_GOODEF_Reload(0xfa);
        FUN_02ff2de4(0x4c);
        iVar13 = *(int *)(iVar15 + 0x44);
        bVar18 = iVar13 == 1;
        iVar14 = extraout_r1_00;
        if (bVar18) {
          iVar13 = *(int *)(iVar15 + 0x48);
          iVar14 = *piVar3;
        }
        if (bVar18) {
          *(int *)(iVar14 + 4) = iVar13;
        }
        else {
          iVar13 = *piVar3;
        }
        if (!bVar18) {
          *(undefined4 *)(iVar13 + 4) = 0;
        }
        *DAT_0300851c = 0;
        func_0x0301191e();
joined_r0x030084b8:
        if (sVar11 == 3) {
          *DAT_03007dd0 = 0xffffffff;
        }
        else {
          DSP_GOODEF_Reload(0xee,0);
        }
        *psVar4 = sVar11;
        uVar16 = 0x4c;
        goto LAB_03007d54;
      }
      if (iVar14 != 0x7c0) {
        if (iVar14 != 0xfc0) {
          return 0;
        }
        FUN_02ff2e26(0x11c);
        iVar13 = FUN_02ff2e44(1);
        if (iVar13 == 0) {
          iVar13 = FUN_02ff2e44(0x56);
          if (iVar13 != 0) {
            iVar13 = FUN_02ff2e00(0x57);
            if (iVar13 == 0) {
              return 0;
            }
            FUN_02ff2e26(0x56);
            FUN_02ff2e26(0x57);
          }
          iVar14 = FUN_02ff2e00(0xca);
          iVar13 = DAT_03008210;
          if (iVar14 != 0) goto LAB_03007f14;
          sVar11 = *(short *)(DAT_03008210 + 0xf2);
          if (sVar11 != 99 && sVar11 != 10) goto LAB_03007cae;
          local_48._0_3_ = CONCAT21(*(undefined2 *)(DAT_03008210 + 2),1);
          local_48 = (uint)(uint3)local_48;
          iVar15 = *(int *)(*DAT_03008214 + 0x1c);
          if ((iVar15 == 2 || iVar15 == 0) || (iVar15 == 3 || iVar15 == 1)) {
            uVar12 = FUN_02fe6040(*(undefined2 *)(DAT_03008210 + 2),
                                  *(undefined4 *)(DAT_03008210 + 0x34),DAT_0300821c,3);
            local_48._0_3_ = CONCAT21(uVar12,(undefined1)local_48);
          }
          goto joined_r0x03007f8a;
        }
        goto LAB_03007fdc;
      }
LAB_03008350:
      iVar15 = *DAT_030084fc;
      piVar3 = DAT_030084fc;
joined_r0x03008356:
      if (iVar15 != 0) {
        *piVar3 = 0;
        FUN_03011d76(0xfe,0);
        FUN_02ff2de4(0x41);
      }
LAB_0300835a:
      *DAT_03008500 = 0;
      *DAT_03008504 = 1;
      *DAT_03008508 = 1;
      pcVar5[8] = '\0';
      pcVar5[9] = '\0';
      pcVar5[10] = '\0';
      pcVar5[0xb] = '\0';
      DSP_GOODEF_Reload(0x110,1);
      return 0;
    }
    if (iVar13 != DAT_030079a0) {
      if (DAT_030079a0 <= iVar13) {
        iVar13 = (iVar13 - DAT_030079a0) + DAT_03008204;
        if (iVar13 == 0) {
          FUN_02ff2e26(0x11c);
          iVar15 = FUN_02ff2e44(1);
          goto joined_r0x03007fb8;
        }
        if (iVar13 == 2) {
          FUN_02ff2e26(0x11c);
          iVar13 = FUN_02ff2e44(1);
          if (iVar13 != 0) {
            *piVar6 = *piVar3;
            cVar2 = *(char *)(iVar15 + 0x35a);
            goto joined_r0x03008332;
          }
          if (*(char *)(iVar15 + 0x34c) == '\0') {
            if (*DAT_030084f8 < 2) {
              return 0;
            }
            *DAT_030084f8 = 0;
            goto LAB_03008350;
          }
          if (*(char *)(iVar15 + 0x34c) != '\x01') {
            return 0;
          }
          uVar1 = *DAT_030084f8;
          puVar17 = DAT_030084f8;
        }
        else {
          if (iVar13 != 6) {
            return 0;
          }
          FUN_02ff2e26(0x11c);
          iVar13 = FUN_02ff2e44(1);
          if (iVar13 != 0) {
            *piVar6 = *piVar3;
            cVar2 = *(char *)(iVar15 + 0x35a);
            goto joined_r0x03007b3a;
          }
          if (*(char *)(iVar15 + 0x34c) == '\0') {
            if (*DAT_0300850c < 2) {
              return 0;
            }
            *DAT_0300850c = 0;
            goto LAB_030083d8;
          }
          if (*(char *)(iVar15 + 0x34c) != '\x01') {
            return 0;
          }
          uVar1 = *DAT_0300850c;
          puVar17 = DAT_0300850c;
        }
        if (uVar1 < 2) {
          return 0;
        }
        *puVar17 = 0;
        FUN_02ff2e26(0x11c);
        FUN_02ff2de4(1);
        *piVar6 = *piVar3;
        uVar16 = 0x39;
        goto LAB_03007d54;
      }
      if (iVar13 == 0x20000002) {
        iVar15 = FUN_02fef5da(0);
        if (iVar15 != 0) goto LAB_03007d48;
LAB_03007d3c:
        FUN_02fef7b8(0,0);
        goto LAB_03007d4e;
      }
      if (iVar13 == 0x20000004) {
        FUN_02ff2e26(0x11c);
        iVar15 = FUN_02ff2e44(1);
        if (iVar15 != 0) {
          return 0;
        }
        if (*DAT_03008224 == 3) {
          uVar12 = 7;
LAB_0300818c:
          *(undefined2 *)(pcVar5 + 4) = uVar12;
        }
        else if (*DAT_03008224 == 0) {
          pcVar5[4] = '\x05';
          pcVar5[5] = '\0';
          FUN_02ff2de4(0x4c);
          FUN_02ff2de4(0x49);
          FUN_02ff2de4(0x40);
        }
      }
      else {
        if (iVar13 != 0x20000008) {
          if (iVar13 != 0x30000004) {
            return 0;
          }
          iVar13 = FUN_02ff2e44(1);
          if (iVar13 == 0) {
            *DAT_03008228 = 1;
            *DAT_0300822c = 1;
            *DAT_03008230 = 8000;
            DSP_GOODEF_Reload(0xf9);
            FUN_02ff2de4(0x4c);
            FUN_02ff2de4(0x3f);
            if (*(int *)(DAT_03008210 + 0x44) == 1) {
              if (*(uint *)(*DAT_03008214 + 4) < *(uint *)(DAT_03008210 + 0x4c)) {
                return 0;
              }
            }
            else if (((uint *)*DAT_03008214)[1] < *(uint *)*DAT_03008214) {
              return 0;
            }
            goto LAB_0300835a;
          }
          FUN_02ff2de4(0x2f);
          FUN_02ff2de4(1);
          FUN_02ff2de4(0x39);
          *piVar6 = *piVar3;
          cVar2 = *(char *)(iVar15 + 0x35a);
          goto joined_r0x03008332;
        }
        iVar15 = FUN_02ff2e44(1);
        if (iVar15 != 0) {
          return 0;
        }
        if (*DAT_03008224 == 3) {
          uVar12 = 8;
          goto LAB_0300818c;
        }
        if (*DAT_03008224 == 0) {
          pcVar5[4] = '\x06';
          pcVar5[5] = '\0';
          FUN_02ff2de4(0x40);
        }
      }
      DSP_GOODEF_Reload(0xed,0);
      uVar16 = 0x19d;
LAB_03007d54:
      FUN_02ff2de4(uVar16);
      return 0;
    }
    iVar13 = FUN_02ff2e44(1);
    if (iVar13 == 0) {
      *DAT_03008228 = 1;
      *DAT_0300822c = 1;
      *DAT_03008230 = 8000;
      DSP_GOODEF_Reload(0xfa);
      FUN_02ff2de4(0x4c);
      uVar16 = 0x3f;
      goto LAB_03007d54;
    }
    FUN_02ff2de4(0x2f);
    FUN_02ff2de4(1);
    FUN_02ff2de4(0x39);
    *piVar6 = *piVar3;
    cVar2 = *(char *)(iVar15 + 0x35a);
  }
joined_r0x03007b3a:
  if (cVar2 != '\0') {
LAB_0300811c:
    FUN_0300785e();
    return 0;
  }
LAB_03008114:
  FUN_03007824();
  return 0;
}


