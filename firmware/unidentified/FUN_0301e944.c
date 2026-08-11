/**
 * FUN_0301e944 @ 0x0301e944
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_0301e944(int param_1,uint *param_2,undefined4 *param_3,int *param_4,undefined4 *param_5,
                 undefined4 *param_6,undefined4 *param_7)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  byte abStack_138 [260];
  int iStack_34;
  uint *puStack_30;
  undefined4 *puStack_2c;
  int *piStack_28;
  
  uVar11 = 0;
  iVar5 = *(int *)(param_1 + 0x18);
  uVar12 = 0;
  bVar2 = false;
  piStack_28 = param_4;
  puStack_2c = param_3;
  puStack_30 = param_2;
  iStack_34 = param_1;
  do {
    if (iVar5 == 0) {
      return 0xffffffff;
    }
    if ((*(byte *)(param_1 + 0xc) & 7) != 0) {
      bitreader_refill(param_1,8 - (*(byte *)(param_1 + 0xc) & 7));
    }
    uVar6 = bitreader_peek(param_1,0x20);
    if (uVar6 == 0x1b0) {
      bitreader_refill(param_1,0x20);
      bitreader_peek(param_1,8);
      bitreader_refill(param_1,8);
    }
    else if (uVar6 == 0x1b1) {
LAB_0301eaf4:
      bitreader_refill(param_1,0x20);
    }
    else if (uVar6 == 0x1b5) {
      bitreader_refill(param_1,0x20);
      iVar5 = bitreader_peek(param_1,1);
      bitreader_refill(param_1,1);
      if (iVar5 == 0) {
        param_2[4] = 1;
      }
      else {
        uVar6 = bitreader_peek(param_1,4);
        bitreader_refill(param_1,4);
        param_2[4] = uVar6;
        bitreader_refill(param_1,3);
      }
      iVar5 = bitreader_peek(param_1,4);
      if (iVar5 != 1) {
        return 0xffffffff;
      }
      bitreader_refill(param_1,4);
      iVar5 = bitreader_peek(param_1,1);
      bitreader_refill(param_1,1);
      if (iVar5 != 0) {
        bitreader_refill(param_1,3);
        bitreader_refill(param_1,1);
        iVar5 = bitreader_peek(param_1,1);
        bitreader_refill(param_1,1);
        if (iVar5 != 0) {
          bitreader_refill(param_1,8);
          bitreader_refill(param_1,8);
          bitreader_refill(param_1,8);
        }
      }
    }
    else {
      if ((uVar6 & 0xffffffe0) == 0x100) goto LAB_0301eaf4;
      if ((uVar6 & 0xfffffff0) == 0x120) {
        bitreader_refill(param_1,0x20);
        bitreader_refill(param_1,1);
        bitreader_refill(param_1,8);
        iVar5 = bitreader_peek(param_1,1);
        bitreader_refill(param_1,1);
        if (iVar5 == 0) {
          uVar11 = param_2[4];
        }
        else {
          uVar11 = bitreader_peek(param_1,4);
          bitreader_refill(param_1,4);
          bitreader_refill(param_1,3);
        }
        uVar12 = bitreader_peek(param_1,4);
        bitreader_refill(param_1,4);
        param_2[0xe] = uVar12;
        if (uVar12 == 0xf) {
          uVar12 = bitreader_peek(param_1,8);
          bitreader_refill(param_1,8);
          param_2[0xf] = uVar12;
          uVar12 = bitreader_peek(param_1,8);
          bitreader_refill(param_1,8);
          param_2[0x10] = uVar12;
        }
        iVar5 = bitreader_peek(param_1,1);
        bitreader_refill(param_1,1);
        if (iVar5 == 0) {
          param_2[0x30] = param_2[0x31];
        }
        else {
          bitreader_refill(param_1,2);
          uVar12 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          param_2[0x30] = uVar12;
          iVar5 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          if (iVar5 != 0) {
            bitreader_peek(param_1,0xf);
            bitreader_refill(param_1,0xf);
            bitreader_refill(param_1,1);
            bitreader_peek(param_1,0xf);
            bitreader_refill(param_1,0xf);
            bitreader_refill(param_1,1);
            bitreader_peek(param_1,0xf);
            bitreader_refill(param_1,0xf);
            bitreader_refill(param_1,1);
            bitreader_peek(param_1,3);
            bitreader_refill(param_1,3);
            bitreader_peek(param_1,0xb);
            bitreader_refill(param_1,0xb);
            bitreader_refill(param_1,1);
            bitreader_peek(param_1,0xf);
            bitreader_refill(param_1,0xf);
            bitreader_refill(param_1,1);
          }
        }
        uVar12 = bitreader_peek(param_1,2);
        bitreader_refill(param_1,2);
        param_2[3] = uVar12;
        if ((uVar12 == 3) && (uVar11 != 1)) {
          bitreader_refill(param_1,4);
        }
        bitreader_refill(param_1,1);
        uVar12 = bitreader_peek(param_1,0x10);
        bitreader_refill(param_1,0x10);
        *param_2 = uVar12;
        if ((int)uVar12 < 1) {
          param_2[2] = 1;
        }
        else {
          uVar6 = uVar12 - 1;
          iVar5 = 0;
          if (uVar6 >> 0x10 != 0) {
            uVar6 = uVar6 >> 0x10;
            iVar5 = 0x10;
          }
          if ((uVar6 & 0xff00) != 0) {
            uVar6 = uVar6 >> 8;
            iVar5 = iVar5 + 8;
          }
          if ((uVar6 & 0xf0) != 0) {
            uVar6 = uVar6 >> 4;
            iVar5 = iVar5 + 4;
          }
          if ((uint)*(byte *)(DAT_0301f104 + uVar6) + iVar5 < 2) {
            uVar12 = 1;
          }
          else {
            uVar12 = uVar12 - 1;
            iVar5 = 0;
            if (uVar12 >> 0x10 != 0) {
              uVar12 = uVar12 >> 0x10;
              iVar5 = 0x10;
            }
            if ((uVar12 & 0xff00) != 0) {
              uVar12 = uVar12 >> 8;
              iVar5 = iVar5 + 8;
            }
            if ((uVar12 & 0xf0) != 0) {
              uVar12 = uVar12 >> 4;
              iVar5 = iVar5 + 4;
            }
            uVar12 = (uint)*(byte *)(DAT_0301f104 + uVar12) + iVar5;
          }
          param_2[2] = uVar12;
        }
        bitreader_refill(param_1,1);
        iVar5 = bitreader_peek(param_1,1);
        bitreader_refill(param_1,1);
        if (iVar5 != 0) {
          bitreader_refill(param_1,param_2[2]);
        }
        if (param_2[3] == 2) {
          if (uVar11 != 1) {
            cVar3 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            *(char *)(param_2 + 0x24) = cVar3;
            if (cVar3 != '\0') {
              bitreader_refill(param_1,4);
              bitreader_refill(param_1,5);
              bitreader_refill(param_1,5);
              bitreader_refill(param_1,5);
              bitreader_refill(param_1,5);
              return 0xffffffff;
            }
          }
          bitreader_refill(param_1,1);
        }
        else {
          if (param_2[3] == 0) {
            bitreader_refill(param_1,1);
            uVar6 = bitreader_peek(param_1,0xd);
            bitreader_refill(param_1,0xd);
            bitreader_refill(param_1,1);
            uVar13 = bitreader_peek(param_1,0xd);
            bitreader_refill(param_1,0xd);
            bitreader_refill(param_1,1);
            uVar12 = param_2[0x19];
            bVar14 = uVar12 == uVar6;
            if (bVar14) {
              uVar12 = param_2[0x1a];
            }
            if (!bVar14 || uVar12 != uVar13) {
              if (param_2[0x18] != 0) {
                return 0xffffffff;
              }
              param_2[0x19] = uVar6;
              param_2[0x1a] = uVar13;
              bVar2 = true;
            }
          }
          uVar12 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          param_2[0xb] = uVar12;
          if (uVar12 != 0) {
            *DAT_0301f108 = 1;
          }
          bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          uVar7 = 1;
          if (uVar11 != 1) {
            uVar7 = 2;
          }
          uVar6 = bitreader_peek(param_1,uVar7);
          uVar12 = bitreader_refill(param_1,uVar7);
          param_2[0x11] = uVar6;
          if (uVar6 == 1 || uVar6 == 2) {
            if (uVar6 != 2) {
              bitreader_peek(param_1,0xd);
              bitreader_refill(param_1,0xd);
              bitreader_refill(param_1,1);
              bitreader_peek(param_1,0xd);
              bitreader_refill(param_1,0xd);
              bitreader_refill(param_1,1);
              bitreader_peek(param_1,0xd);
              bitreader_refill(param_1,0xd);
              bitreader_refill(param_1,1);
              bitreader_peek(param_1,0xd);
              bitreader_refill(param_1,0xd);
              bitreader_refill(param_1,1);
            }
            uVar12 = bitreader_peek(param_1,6);
            bitreader_refill(param_1,6);
            param_2[0x12] = uVar12;
            uVar12 = bitreader_peek(param_1,2);
            bitreader_refill(param_1,2);
            param_2[0x13] = uVar12;
            uVar12 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            param_2[0x14] = uVar12;
            uVar12 = param_2[0x11];
            if (uVar12 != 2) {
              bitreader_peek(param_1,1);
              uVar12 = bitreader_refill(param_1,1);
            }
          }
          if (uVar11 != 1) {
            uVar12 = param_2[3];
          }
          if (uVar11 != 1 && uVar12 != 0) {
            bitreader_refill(param_1,1);
          }
          iVar5 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          if (iVar5 == 0) {
            param_2[5] = 5;
          }
          else {
            uVar12 = bitreader_peek(param_1,4);
            bitreader_refill(param_1,4);
            param_2[5] = uVar12;
            bitreader_refill(param_1,4);
          }
          if (param_2[3] == 3) {
            bitreader_refill(param_1,1);
            bitreader_refill(param_1,1);
            bitreader_refill(param_1,1);
          }
          uVar12 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          param_2[6] = uVar12;
          if (uVar12 != 0) {
            *DAT_0301f108 = 1;
          }
          if (uVar11 == 1) {
            param_2[8] = 0;
          }
          else {
            uVar12 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            param_2[8] = uVar12;
          }
          uVar12 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          param_2[10] = uVar12;
          if (uVar12 == 0) {
            *DAT_0301f108 = 1;
          }
          bitreader_refill(param_1,1);
          iVar5 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          if (iVar5 != 0) {
            bitreader_refill(param_1,1);
          }
          if (uVar11 == 1) {
            param_2[0x15] = 0;
            param_2[0x16] = 0;
          }
          else {
            uVar11 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            param_2[0x15] = uVar11;
            if (uVar11 != 0) {
              bitreader_refill(param_1,2);
              bitreader_refill(param_1,1);
            }
            uVar11 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            param_2[0x16] = uVar11;
          }
          cVar3 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          *(char *)(param_2 + 0x24) = cVar3;
          if (cVar3 != '\0') {
            bitreader_refill(param_1,1);
            bitreader_refill(param_1,4);
            bitreader_refill(param_1,1);
            bitreader_refill(param_1,5);
            bitreader_refill(param_1,5);
            bitreader_refill(param_1,5);
            bitreader_refill(param_1,5);
            bitreader_refill(param_1,1);
            if (param_2[3] != 1) {
              return 0xffffffff;
            }
            bitreader_refill(param_1,1);
            bitreader_refill(param_1,1);
            bitreader_refill(param_1,5);
            bitreader_refill(param_1,5);
            bitreader_refill(param_1,5);
            bitreader_refill(param_1,5);
            return 0xffffffff;
          }
        }
        if (bVar2) {
          uVar11 = 0xfffffffd;
        }
        else {
          uVar11 = 0xfffffffe;
        }
        return uVar11;
      }
      if (uVar6 == 0x1b3) {
        bitreader_refill(param_1,0x20);
        bitreader_peek(param_1,5);
        bitreader_refill(param_1,5);
        bitreader_peek(param_1,6);
        bitreader_refill(param_1,6);
        bitreader_refill(param_1,1);
        bitreader_peek(param_1,6);
        bitreader_refill(param_1,6);
        bitreader_refill(param_1,1);
        bitreader_refill(param_1,1);
      }
      else {
        if (uVar6 == 0x1b6) {
          bitreader_refill(param_1,0x20);
          uVar6 = bitreader_peek(param_1,2);
          bitreader_refill(param_1,2);
          iVar5 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          while (iVar5 != 0) {
            uVar11 = uVar11 + 1;
            iVar5 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
          }
          bitreader_refill(param_1,1);
          uVar13 = param_2[2];
          if (uVar13 != 0) {
            uVar12 = bitreader_peek(param_1,uVar13);
            bitreader_refill(param_1,uVar13);
          }
          if (uVar6 == 2) {
            uVar9 = param_2[0x2a] + uVar11;
            uVar13 = *param_2;
            lVar1 = (ulonglong)uVar9 * (ulonglong)uVar13;
            uVar10 = (uint)lVar1;
            uVar8 = uVar10 + uVar12;
            param_2[0x26] = uVar8;
            param_2[0x27] =
                 uVar9 * ((int)uVar13 >> 0x1f) +
                 (param_2[0x2b] + (uint)CARRY4(param_2[0x2a],uVar11)) * uVar13 +
                 (int)((ulonglong)lVar1 >> 0x20) +
                 ((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar10,uVar12);
            param_2[0x2f] = param_2[0x2e] - (param_2[0x2c] - uVar8);
          }
          else {
            uVar13 = param_2[0x28];
            param_2[0x2a] = uVar13;
            param_2[0x2b] = param_2[0x29];
            uVar8 = uVar13 + uVar11;
            uVar11 = param_2[0x29] + (uint)CARRY4(uVar13,uVar11);
            param_2[0x28] = uVar8;
            param_2[0x29] = uVar11;
            uVar9 = *param_2;
            uVar10 = (uint)((ulonglong)uVar8 * (ulonglong)uVar9);
            uVar13 = uVar10 + uVar12;
            uVar11 = uVar8 * ((int)uVar9 >> 0x1f) +
                     uVar11 * uVar9 + (int)((ulonglong)uVar8 * (ulonglong)uVar9 >> 0x20) +
                     ((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar10,uVar12);
            param_2[0x26] = uVar13;
            param_2[0x27] = uVar11;
            param_2[0x2e] = uVar13 - param_2[0x2c];
            param_2[0x2c] = uVar13;
            param_2[0x2d] = uVar11;
          }
          bitreader_refill(param_1,1);
          iVar5 = bitreader_peek(param_1,1);
          bitreader_refill(param_1,1);
          if (iVar5 == 0) {
            return 4;
          }
          if (param_2[0x15] != 0) {
            uVar11 = param_2[2] + 3;
            if (0xe < uVar11) {
              uVar11 = 0xf;
            }
            bitreader_peek(param_1,uVar11);
            bitreader_refill(param_1,uVar11);
            iVar5 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            if (iVar5 != 0) {
              uVar11 = param_2[2] + 3;
              if (0xe < uVar11) {
                uVar11 = 0xf;
              }
              bitreader_peek(param_1,uVar11);
              bitreader_refill(param_1,uVar11);
            }
            bitreader_refill(param_1,1);
          }
          uVar11 = param_2[3];
          if (uVar11 != 2) {
            if (uVar6 != 1) {
              if (uVar6 == 3) {
                uVar11 = param_2[0x11];
              }
              if (uVar6 != 3 || uVar11 != 2) goto LAB_0301f36a;
            }
            uVar7 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            *puStack_2c = uVar7;
          }
LAB_0301f36a:
          if (param_2[0x16] == 0) {
LAB_0301f38e:
            if (param_2[3] != 0) {
LAB_0301f392:
              if (param_2[0x11] != 1 || uVar6 != 0) {
                bitreader_peek(param_1,0xd);
                bitreader_refill(param_1,0xd);
                bitreader_refill(param_1,1);
                bitreader_peek(param_1,0xd);
                bitreader_refill(param_1,0xd);
                bitreader_refill(param_1,1);
                bitreader_peek(param_1,0xd);
                bitreader_refill(param_1,0xd);
                bitreader_refill(param_1,1);
                bitreader_peek(param_1,0xd);
                bitreader_refill(param_1,0xd);
                bitreader_refill(param_1,1);
              }
              bitreader_refill(param_1,1);
              iVar5 = bitreader_peek(param_1,1);
              bitreader_refill(param_1,1);
              if (iVar5 != 0) {
                bitreader_refill(param_1,8);
              }
              if (param_2[3] == 2) goto LAB_0301f49c;
            }
          }
          else {
            if (param_2[3] != 0) goto LAB_0301f392;
            if (uVar6 < 2) {
              bitreader_peek(param_1,1);
              bitreader_refill(param_1,1);
              goto LAB_0301f38e;
            }
          }
          if (param_2[10] == 0) {
            *_DAT_0301f56c = 1;
          }
          iVar5 = bitreader_peek(param_1,3);
          bitreader_refill(param_1,3);
          *param_7 = *(undefined4 *)(_DAT_0301f570 + iVar5 * 4);
          param_2[0xc] = 0;
          param_2[0xd] = 0;
          if (param_2[0xb] != 0) {
            uVar11 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            param_2[0xc] = uVar11;
            uVar11 = bitreader_peek(param_1,1);
            bitreader_refill(param_1,1);
            param_2[0xd] = uVar11;
          }
LAB_0301f49c:
          if ((param_2[0x11] == 1 || param_2[0x11] == 2) && (uVar6 == 3)) {
            *_DAT_0301f56c = 1;
          }
          uVar11 = param_2[5];
          iVar5 = bitreader_peek(param_1,uVar11);
          bitreader_refill(param_1,uVar11);
          *piStack_28 = iVar5;
          if (iVar5 == 0) {
            *piStack_28 = 1;
          }
          if (uVar6 != 0) {
            uVar7 = bitreader_peek(param_1,3);
            bitreader_refill(param_1,3);
            *param_5 = uVar7;
            if (uVar6 == 2) {
              uVar7 = bitreader_peek(param_1,3);
              bitreader_refill(param_1,3);
              *param_6 = uVar7;
            }
          }
          if (((char)param_2[0x24] == '\0') && (param_2[3] != 0 && uVar6 != 0)) {
            bitreader_refill(param_1,1);
          }
          return uVar6;
        }
        if (uVar6 == 0x1b2) {
          bitreader_refill(param_1,0x20);
          abStack_138[0] = bitreader_peek(param_1,8);
          iVar5 = 1;
          do {
            bVar4 = bitreader_peek(param_1,0x10);
            abStack_138[iVar5] = bVar4;
            if (bVar4 == 0) break;
            bitreader_refill(param_1,8);
            iVar5 = iVar5 + 1;
          } while (iVar5 < 0x100);
        }
        else {
          bitreader_peek(param_1,0x18);
          bitreader_refill(param_1,8);
        }
      }
    }
    iVar5 = *(int *)(param_1 + 0x18);
  } while( true );
}


