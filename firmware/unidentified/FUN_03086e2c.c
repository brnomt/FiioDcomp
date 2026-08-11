/**
 * FUN_03086e2c @ 0x03086e2c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_03086e2c(int *param_1)

{
  char cVar1;
  ushort uVar2;
  undefined1 uVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  int *piVar17;
  undefined4 uVar18;
  uint uVar19;
  int iVar20;
  bool bVar21;
  uint local_2c;
  int local_28;
  
  iVar13 = *param_1;
  piVar17 = param_1 + 0xd;
  cVar1 = (char)param_1[8];
  iVar14 = 0;
  iVar15 = *(int *)(iVar13 + 0x9c);
joined_r0x03086e46:
  if (cVar1 == '\n') {
    return iVar14;
  }
  do {
    cVar1 = (char)param_1[8];
    switch(cVar1) {
    case '\0':
      if (*(int *)(iVar13 + 0x74) != 0) {
        uVar19 = 0;
        uVar10 = *(uint *)(iVar13 + 0x80);
        while (1 < uVar10) {
          uVar19 = uVar19 + 1;
          uVar10 = *(uint *)(iVar13 + 0x80) >> (uVar19 & 0xff);
        }
        uVar10 = 0;
        uVar11 = uVar19;
        while (1 < uVar11) {
          uVar10 = uVar10 + 1;
          uVar11 = uVar19 >> (uVar10 & 0xff);
        }
        iVar14 = wma_bitreader_getbits(param_1 + 0x21,uVar10 + 1,&local_2c);
        if (iVar14 < 0) {
          return iVar14;
        }
        iVar6 = *(int *)(iVar13 + 0x9c);
        iVar15 = iVar6 / (1 << (local_2c & 0xff));
        iVar12 = *(int *)(iVar13 + 0x88);
        bVar21 = SBORROW4(iVar15,iVar12);
        iVar14 = iVar15 - iVar12;
        if (iVar12 <= iVar15) {
          bVar21 = SBORROW4(iVar6,iVar15);
          iVar14 = iVar6 - iVar15;
        }
        if (iVar14 < 0 != bVar21) {
          return DAT_03086ffc;
        }
      }
      uVar2 = *(ushort *)(iVar13 + 0x26);
      *(ushort *)(iVar13 + 0x188) = uVar2;
      if (uVar2 != 0) {
        uVar19 = uVar2 & 1;
        bVar21 = (uVar2 & 1) != 0;
        if (bVar21) {
          **(undefined2 **)(iVar13 + 0x18c) = 0;
        }
        uVar10 = (uint)bVar21;
        if (uVar19 < *(ushort *)(iVar13 + 0x26)) {
          do {
            uVar19 = (uint)(short)((short)uVar19 + 2);
            *(short *)(*(int *)(iVar13 + 0x18c) + uVar10 * 2) = (short)uVar10;
            *(short *)(*(int *)(iVar13 + 0x18c) + (uVar10 + 1) * 2) = (short)(uVar10 + 1);
            uVar10 = uVar10 + 2;
          } while ((int)uVar19 < (int)(uint)*(ushort *)(iVar13 + 0x26));
        }
      }
      iVar14 = FUN_03086aa2(param_1,iVar15);
      if (iVar14 < 0) {
        return iVar14;
      }
      iVar14 = FUN_03085f4e(iVar13);
      if (iVar14 < 0) {
        return iVar14;
      }
      iVar14 = FUN_03086b6a(iVar13);
      if (iVar14 < 0) {
        return iVar14;
      }
      uVar3 = 0x33;
      goto LAB_03086f54;
    case '\x01':
    case '\x02':
    case '\n':
    case '\v':
    case '\f':
    case '\r':
    case '\x0e':
    case '\x0f':
    case '\x10':
    case '\x13':
    case '\x14':
    case '\x15':
    case '\x16':
    case '\x17':
    case '\x18':
    case '\x19':
    case '\x1a':
    case '\x1b':
    case '\x1f':
    case '!':
    case '\"':
    case '*':
    case '.':
    case '0':
    case '1':
    case '2':
      goto switchD_03086e56_caseD_1;
    case '\x03':
      *(undefined1 *)(param_1 + 8) = 0x12;
    case '\x12':
      *(undefined1 *)(param_1 + 8) = 0x1c;
switchD_03086e56_caseD_1c:
      *(undefined2 *)(param_1 + 0xd) = 0;
      *(undefined1 *)(param_1 + 8) = 0x20;
      *(undefined1 *)((int)param_1 + 0x21) = 0;
      goto switchD_03086e56_caseD_20;
    case '\x04':
    case '\x1d':
    case '\x1e':
      iVar14 = FUN_030873fc(param_1);
      if (iVar14 < 0) {
        return iVar14;
      }
      FUN_03088060(iVar13,*(undefined4 *)(iVar13 + 0xc4));
      *(short *)piVar17 = -1;
      uVar2 = *(ushort *)(iVar13 + 0x188);
      if ((short)uVar2 < 1) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar2 & 1;
      }
      for (; (short)uVar5 < (short)uVar2; uVar5 = uVar5 + 2) {
      }
      *(undefined1 *)(param_1 + 8) = 5;
LAB_0308715e:
      *(undefined2 *)((int)param_1 + 0x36) = *(undefined2 *)(iVar13 + 0x124);
      *(short *)piVar17 = 0;
      *(undefined1 *)(param_1 + 8) = 6;
LAB_03087170:
      if ((*(int *)(iVar13 + 0x2c) == 1) && (iVar14 = FUN_030898fe(param_1), iVar14 < 0)) {
        return iVar14;
      }
      *(undefined1 *)(param_1 + 8) = 8;
LAB_03087188:
      iVar14 = FUN_03088390(param_1 + 0x21,1);
      if (iVar14 < 0) {
        return iVar14;
      }
      uVar19 = 1;
      if ((*(int *)(iVar13 + 0x74) != 0) && (1 < **(short **)(*(int *)(iVar13 + 0xd8) + 0xc0))) {
        iVar14 = wma_bitreader_getbits(param_1 + 0x21,1,&local_2c);
        if (iVar14 < 0) {
          return iVar14;
        }
        uVar19 = local_2c;
        if ((*(short *)(*(int *)(iVar13 + 0xd8) + 0x7c) == 0) && (local_2c != 1)) {
          return DAT_030873f4;
        }
      }
      iVar15 = 0;
      if (0 < *(short *)(iVar13 + 0x188)) {
        do {
          iVar6 = (int)*(short *)(*(int *)(iVar13 + 0x18c) + iVar15 * 2);
          piVar16 = (int *)(*(int *)(iVar13 + 0xd8) + iVar6 * 0xfc);
          iVar8 = param_1[2];
          iVar12 = piVar16[0x11] + (short)piVar16[0x20] * 4 + piVar16[0xb] * -4;
          *piVar16 = iVar12;
          wma_memclr(iVar12,piVar16[0xb] << 2);
          *(undefined4 *)(iVar8 + iVar6 * 8 + 4) = 0;
          **(undefined1 **)(piVar16[0x30] + 0x10) = (char)uVar19;
          iVar15 = (int)(short)((short)iVar15 + 1);
        } while (iVar15 < *(short *)(iVar13 + 0x188));
      }
      *(short *)piVar17 = 0;
      *(undefined2 *)((int)param_1 + 0x36) = 0;
      *(undefined1 *)(param_1 + 8) = 9;
LAB_03087248:
      if (*(int *)(iVar13 + 0xb4) != 1) {
        iVar14 = FUN_030897d8(param_1);
        if (iVar14 < 0) {
          return iVar14;
        }
        if (*(int *)(iVar13 + 0x2c) == 1) {
          FUN_03089bec(param_1);
        }
        goto switchD_03086e56_caseD_20;
      }
      if (*(short *)(iVar13 + 0x188) <= (short)*piVar17) goto switchD_03086e56_caseD_20;
      do {
        iVar15 = *(int *)(iVar13 + 0xd8) +
                 *(short *)(*(int *)(iVar13 + 0x18c) + (short)*piVar17 * 2) * 0xfc;
        cVar1 = **(char **)(*(int *)(iVar15 + 0xc0) + 0x10);
        if ((*(int *)(iVar15 + 0x30) == 0) && (*(int *)(iVar13 + 0x40) < 3)) {
          if (cVar1 == '\x01') {
            wma_memclr(*(undefined4 *)(iVar15 + 4),*(int *)(iVar13 + 200) << 2);
            *(undefined4 *)(iVar15 + 0x4c) = 0;
          }
        }
        else {
          piVar16 = *(int **)(iVar15 + 4);
          uVar18 = *DAT_030873f8;
          if (cVar1 == '\x01') {
            if (*(int *)(iVar13 + 0x40) == 1) {
              iVar14 = wma_bitreader_getbits(param_1 + 0x21,5,&local_2c);
              if (iVar14 < 0) {
                return iVar14;
              }
              *piVar16 = local_2c + 10;
              *(short *)((int)param_1 + 0x36) = *(short *)((int)param_1 + 0x36) + 1;
            }
            if ((int)*(short *)((int)param_1 + 0x36) < *(int *)(iVar13 + 200)) {
              do {
                iVar14 = FUN_03084a2c(uVar18,param_1 + 0x21,&local_2c,&local_28,0);
                if (iVar14 < 0) {
                  return iVar14;
                }
                iVar14 = FUN_030848dc(param_1 + 0x21,local_2c);
                if (iVar14 < 0) {
                  return iVar14;
                }
                local_28 = local_28 + -0x3c;
                iVar6 = (int)*(short *)((int)param_1 + 0x36);
                if (iVar6 == 0) {
                  iVar12 = 0x24;
                }
                else {
                  iVar12 = piVar16[iVar6 + -1];
                }
                piVar16[iVar6] = iVar12 + local_28;
                sVar4 = *(short *)((int)param_1 + 0x36) + 1;
                *(short *)((int)param_1 + 0x36) = sVar4;
              } while ((int)sVar4 < *(int *)(iVar13 + 200));
            }
            *(int *)(iVar13 + 0x7c) =
                 (int)*(short *)(*(int *)(*(int *)(iVar15 + 0xc0) + 8) +
                                *(short *)(iVar15 + 0x7c) * 2);
            *(undefined2 *)((int)param_1 + 0x36) = 0;
          }
          else if (cVar1 == '\0') goto LAB_030873cc;
          uVar19 = *(uint *)(iVar13 + 200);
          iVar6 = *piVar16;
          if (0 < (int)(uVar19 - 2)) {
            piVar9 = piVar16;
            if ((uVar19 & 1) != 0) {
              if (iVar6 < piVar16[1]) {
                iVar6 = piVar16[1];
              }
              piVar9 = piVar16 + 1;
            }
            iVar8 = piVar9[1];
            for (iVar12 = (int)(uVar19 - 2) >> 1; iVar12 != 0; iVar12 = iVar12 + -1) {
              iVar20 = piVar9[2];
              if (iVar6 < iVar8) {
                iVar6 = iVar8;
              }
              iVar8 = piVar9[3];
              if (iVar6 < iVar20) {
                iVar6 = iVar20;
              }
              piVar9 = piVar9 + 2;
            }
          }
          if ((-1 < (int)(uVar19 - 2)) && (iVar6 < piVar16[uVar19 - 1])) {
            iVar6 = piVar16[uVar19 - 1];
          }
          *(int *)(iVar15 + 0x4c) = iVar6;
          *(undefined4 *)(iVar15 + 200) = 1;
        }
LAB_030873cc:
        sVar4 = (short)*piVar17 + 1;
        *(short *)piVar17 = sVar4;
      } while (sVar4 < *(short *)(iVar13 + 0x188));
      goto switchD_03086e56_caseD_20;
    case '\x05':
      goto LAB_0308715e;
    case '\x06':
    case '\a':
      goto LAB_03087170;
    case '\b':
      goto LAB_03087188;
    case '\t':
      goto LAB_03087248;
    case '\x11':
      goto switchD_03086e56_caseD_11;
    case '\x1c':
      goto switchD_03086e56_caseD_1c;
    case ' ':
      goto switchD_03086e56_caseD_20;
    case '#':
    case '&':
      goto switchD_03086e56_caseD_23;
    case '$':
      goto switchD_03086e56_caseD_24;
    case '%':
      goto switchD_03086e56_caseD_25;
    case '\'':
    case '(':
      *(undefined1 *)(param_1 + 8) = 0x29;
    case ')':
      *(undefined1 *)(param_1 + 8) = 0x26;
switchD_03086e56_caseD_23:
      *(undefined1 *)(param_1 + 8) = 0x2f;
switchD_03086e56_caseD_2f:
      *(undefined1 *)(param_1 + 8) = 0x11;
switchD_03086e56_caseD_11:
      *(undefined1 *)(param_1 + 8) = 0x25;
switchD_03086e56_caseD_25:
      *(undefined1 *)(param_1 + 8) = 0x24;
switchD_03086e56_caseD_24:
      *(undefined1 *)(param_1 + 8) = 0x2b;
switchD_03086e56_caseD_2b:
      *(undefined1 *)(param_1 + 8) = 0x2d;
switchD_03086e56_caseD_2d:
      *(undefined1 *)(param_1 + 8) = 0x2c;
switchD_03086e56_caseD_2c:
      uVar3 = 8;
LAB_03086f54:
      *(undefined1 *)(param_1 + 8) = uVar3;
      break;
    case '+':
      goto switchD_03086e56_caseD_2b;
    case ',':
      goto switchD_03086e56_caseD_2c;
    case '-':
      goto switchD_03086e56_caseD_2d;
    case '/':
      goto switchD_03086e56_caseD_2f;
    case '3':
      iVar14 = FUN_03088390(param_1 + 0x21,*(ushort *)(iVar13 + 0x26) + 1);
      if (iVar14 < 0) {
        return iVar14;
      }
      if (*(short *)(iVar13 + 0x26) != 1) {
        iVar14 = wma_bitreader_getbits(param_1 + 0x21,1,&local_2c);
        if (iVar14 < 0) {
          return iVar14;
        }
        *(char *)(*(int *)(iVar13 + 0xd8) + 0x50) = (char)local_2c;
        *(char *)(*(int *)(iVar13 + 0xd8) + 0x14c) = (char)local_2c;
        iVar14 = wma_bitreader_getbits(param_1 + 0x21,1,&local_2c);
        if (iVar14 < 0) {
          return iVar14;
        }
        *(uint *)(*(int *)(iVar13 + 0xd8) + 0x30) = local_2c;
        iVar14 = wma_bitreader_getbits(param_1 + 0x21,1,&local_2c);
        if (iVar14 < 0) {
          return iVar14;
        }
        *(uint *)(*(int *)(iVar13 + 0xd8) + 300) = local_2c;
        iVar6 = *(int *)(iVar13 + 0xd8);
        iVar12 = *(int *)(iVar6 + 0x30);
        bVar21 = local_2c != 0;
        if (*(char *)(iVar6 + 0x50) == '\x01') {
          FUN_03084338(param_1,iVar6 + 0xfc,1);
        }
        else {
          FUN_03084338(param_1,iVar6 + 0xfc,0);
        }
        *(undefined4 *)(iVar13 + 0xc4) = 1;
        if (iVar12 != 0 || bVar21) goto LAB_03087118;
LAB_0308707c:
        if (*(int *)(iVar13 + 0xb4) == 0) {
          *(undefined2 *)(param_1 + 0xd) = 0;
          if (0 < *(short *)(iVar13 + 0x188)) {
            do {
              iVar14 = *(int *)(iVar13 + 0xd8) +
                       *(short *)(*(int *)(iVar13 + 0x18c) + (short)param_1[0xd] * 2) * 0xfc;
              puVar7 = *(undefined1 **)(*(int *)(iVar14 + 0xc0) + 0x10);
              if (*(short *)(iVar14 + 0x7c) < 1) {
                *puVar7 = 1;
              }
              else {
                *puVar7 = 0;
              }
              sVar4 = (short)param_1[0xd] + 1;
              *(short *)(param_1 + 0xd) = sVar4;
            } while (sVar4 < *(short *)(iVar13 + 0x188));
          }
          *(undefined2 *)(param_1 + 0xd) = 0;
          iVar14 = FUN_030897d8(param_1);
          if (iVar14 < 0) {
            return iVar14;
          }
        }
        goto switchD_03086e56_caseD_20;
      }
      iVar14 = wma_bitreader_getbits(param_1 + 0x21,1,&local_2c);
      if (iVar14 < 0) {
        return iVar14;
      }
      *(uint *)(*(int *)(iVar13 + 0xd8) + 0x30) = local_2c;
      *(undefined1 *)(*(int *)(iVar13 + 0xd8) + 0x50) = 0;
      *(undefined4 *)(iVar13 + 0xc4) = 1;
      if (local_2c == 0) goto LAB_0308707c;
LAB_03087118:
      *(undefined1 *)(param_1 + 8) = 4;
      break;
    default:
      goto joined_r0x03086e46;
    }
  } while( true );
switchD_03086e56_caseD_1:
  goto joined_r0x03086e46;
switchD_03086e56_caseD_20:
  *(undefined1 *)(param_1 + 8) = 10;
  return iVar14;
}


