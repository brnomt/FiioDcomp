/**
 * FUN_0301ea36 @ 0x0301ea36
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0301ea36(void)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int unaff_r4;
  uint *unaff_r5;
  uint unaff_r7;
  uint unaff_r8;
  uint unaff_r9;
  int unaff_r10;
  bool bVar11;
  undefined1 in_stack_00000000;
  undefined4 *in_stack_0000010c;
  uint *in_stack_00000110;
  undefined4 *in_stack_00000138;
  undefined4 *in_stack_0000013c;
  undefined4 *in_stack_00000140;
  
  do {
    iVar4 = bitreader_peek();
    bitreader_refill();
    if (iVar4 != 0) {
      bitreader_refill();
      bitreader_refill();
      bitreader_refill();
    }
LAB_0301f198:
    while( true ) {
      if (*(int *)(unaff_r4 + 0x18) == 0) {
        return 0xffffffff;
      }
      if ((*(byte *)(unaff_r4 + 0xc) & 7) != 0) {
        bitreader_refill();
      }
      uVar3 = bitreader_peek();
      if (uVar3 != 0x1b0) break;
      bitreader_refill();
      bitreader_peek();
      bitreader_refill();
    }
    if (uVar3 == 0x1b1) {
LAB_0301eaf4:
      bitreader_refill();
      goto LAB_0301f198;
    }
    if (uVar3 != 0x1b5) {
      if ((uVar3 & 0xffffffe0) == 0x100) goto LAB_0301eaf4;
      if ((uVar3 & 0xfffffff0) == 0x120) {
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
        iVar4 = bitreader_peek();
        bitreader_refill();
        if (iVar4 == 0) {
          uVar3 = unaff_r5[4];
        }
        else {
          uVar3 = bitreader_peek();
          bitreader_refill();
          bitreader_refill();
        }
        uVar7 = bitreader_peek();
        bitreader_refill();
        unaff_r5[0xe] = uVar7;
        if (uVar7 == 0xf) {
          uVar7 = bitreader_peek();
          bitreader_refill();
          unaff_r5[0xf] = uVar7;
          uVar7 = bitreader_peek();
          bitreader_refill();
          unaff_r5[0x10] = uVar7;
        }
        iVar4 = bitreader_peek();
        bitreader_refill();
        if (iVar4 == 0) {
          unaff_r5[0x30] = unaff_r5[0x31];
        }
        else {
          bitreader_refill();
          uVar7 = bitreader_peek();
          bitreader_refill();
          unaff_r5[0x30] = uVar7;
          iVar4 = bitreader_peek();
          bitreader_refill();
          if (iVar4 != 0) {
            bitreader_peek();
            bitreader_refill();
            bitreader_refill();
            bitreader_peek();
            bitreader_refill();
            bitreader_refill();
            bitreader_peek();
            bitreader_refill();
            bitreader_refill();
            bitreader_peek();
            bitreader_refill();
            bitreader_peek();
            bitreader_refill();
            bitreader_refill();
            bitreader_peek();
            bitreader_refill();
            bitreader_refill();
          }
        }
        uVar7 = bitreader_peek();
        bitreader_refill();
        unaff_r5[3] = uVar7;
        if ((uVar7 == 3) && (uVar3 != 1)) {
          bitreader_refill();
        }
        bitreader_refill();
        uVar7 = bitreader_peek();
        bitreader_refill();
        *unaff_r5 = uVar7;
        if ((int)uVar7 < 1) {
          unaff_r5[2] = unaff_r7;
        }
        else {
          uVar5 = uVar7 - 1;
          iVar4 = 0;
          if (uVar5 >> 0x10 != 0) {
            uVar5 = uVar5 >> 0x10;
            iVar4 = 0x10;
          }
          if ((uVar5 & 0xff00) != 0) {
            uVar5 = uVar5 >> 8;
            iVar4 = iVar4 + 8;
          }
          if ((uVar5 & 0xf0) != 0) {
            uVar5 = uVar5 >> 4;
            iVar4 = iVar4 + 4;
          }
          if ((uint)*(byte *)(DAT_0301f104 + uVar5) + iVar4 < 2) {
            uVar7 = 1;
          }
          else {
            uVar7 = uVar7 - 1;
            iVar4 = 0;
            if (uVar7 >> 0x10 != 0) {
              uVar7 = uVar7 >> 0x10;
              iVar4 = 0x10;
            }
            if ((uVar7 & 0xff00) != 0) {
              uVar7 = uVar7 >> 8;
              iVar4 = iVar4 + 8;
            }
            if ((uVar7 & 0xf0) != 0) {
              uVar7 = uVar7 >> 4;
              iVar4 = iVar4 + 4;
            }
            uVar7 = (uint)*(byte *)(DAT_0301f104 + uVar7) + iVar4;
          }
          unaff_r5[2] = uVar7;
        }
        bitreader_refill();
        iVar4 = bitreader_peek();
        bitreader_refill();
        if (iVar4 != 0) {
          bitreader_refill();
        }
        if (unaff_r5[3] == 2) {
          if (uVar3 != 1) {
            cVar2 = bitreader_peek();
            bitreader_refill();
            *(char *)(unaff_r5 + 0x24) = cVar2;
            if (cVar2 != '\0') {
              bitreader_refill();
              bitreader_refill();
              bitreader_refill();
              bitreader_refill();
              bitreader_refill();
              return 0xffffffff;
            }
          }
          bitreader_refill();
        }
        else {
          if (unaff_r5[3] == 0) {
            bitreader_refill();
            uVar5 = bitreader_peek();
            bitreader_refill();
            bitreader_refill();
            uVar8 = bitreader_peek();
            bitreader_refill();
            bitreader_refill();
            uVar7 = unaff_r5[0x19];
            bVar11 = uVar7 == uVar5;
            if (bVar11) {
              uVar7 = unaff_r5[0x1a];
            }
            if (!bVar11 || uVar7 != uVar8) {
              if (unaff_r5[0x18] != 0) {
                return 0xffffffff;
              }
              unaff_r10 = 1;
              unaff_r5[0x19] = uVar5;
              unaff_r5[0x1a] = uVar8;
            }
          }
          uVar7 = bitreader_peek();
          bitreader_refill();
          unaff_r5[0xb] = uVar7;
          if (uVar7 != 0) {
            *DAT_0301f108 = unaff_r7;
          }
          bitreader_peek();
          bitreader_refill();
          uVar5 = bitreader_peek();
          uVar7 = bitreader_refill();
          unaff_r5[0x11] = uVar5;
          if (uVar5 == 1 || uVar5 == 2) {
            if (uVar5 != 2) {
              bitreader_peek();
              bitreader_refill();
              bitreader_refill();
              bitreader_peek();
              bitreader_refill();
              bitreader_refill();
              bitreader_peek();
              bitreader_refill();
              bitreader_refill();
              bitreader_peek();
              bitreader_refill();
              bitreader_refill();
            }
            uVar7 = bitreader_peek();
            bitreader_refill();
            unaff_r5[0x12] = uVar7;
            uVar7 = bitreader_peek();
            bitreader_refill();
            unaff_r5[0x13] = uVar7;
            uVar7 = bitreader_peek();
            bitreader_refill();
            unaff_r5[0x14] = uVar7;
            uVar7 = unaff_r5[0x11];
            if (uVar7 != 2) {
              bitreader_peek();
              uVar7 = bitreader_refill();
            }
          }
          if (uVar3 != 1) {
            uVar7 = unaff_r5[3];
          }
          if (uVar3 != 1 && uVar7 != 0) {
            bitreader_refill();
          }
          iVar4 = bitreader_peek();
          bitreader_refill();
          if (iVar4 == 0) {
            unaff_r5[5] = 5;
          }
          else {
            uVar7 = bitreader_peek();
            bitreader_refill();
            unaff_r5[5] = uVar7;
            bitreader_refill();
          }
          if (unaff_r5[3] == 3) {
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
          }
          uVar7 = bitreader_peek();
          bitreader_refill();
          unaff_r5[6] = uVar7;
          if (uVar7 != 0) {
            *DAT_0301f108 = unaff_r7;
          }
          if (uVar3 == 1) {
            unaff_r5[8] = 0;
          }
          else {
            uVar7 = bitreader_peek();
            bitreader_refill();
            unaff_r5[8] = uVar7;
          }
          uVar7 = bitreader_peek();
          bitreader_refill();
          unaff_r5[10] = uVar7;
          if (uVar7 == 0) {
            *DAT_0301f108 = unaff_r7;
          }
          bitreader_refill();
          iVar4 = bitreader_peek();
          bitreader_refill();
          if (iVar4 != 0) {
            bitreader_refill();
          }
          if (uVar3 == 1) {
            unaff_r5[0x15] = 0;
            unaff_r5[0x16] = 0;
          }
          else {
            uVar3 = bitreader_peek();
            bitreader_refill();
            unaff_r5[0x15] = uVar3;
            if (uVar3 != 0) {
              bitreader_refill();
              bitreader_refill();
            }
            uVar3 = bitreader_peek();
            bitreader_refill();
            unaff_r5[0x16] = uVar3;
          }
          cVar2 = bitreader_peek();
          bitreader_refill();
          *(char *)(unaff_r5 + 0x24) = cVar2;
          if (cVar2 != '\0') {
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            if (unaff_r5[3] != 1) {
              return 0xffffffff;
            }
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            bitreader_refill();
            return 0xffffffff;
          }
        }
        if (unaff_r10 == 0) {
          uVar3 = 0xfffffffe;
        }
        else {
          uVar3 = 0xfffffffd;
        }
        return uVar3;
      }
      if (uVar3 == 0x1b3) {
        bitreader_refill();
        bitreader_peek();
        bitreader_refill();
        bitreader_peek();
        bitreader_refill();
        bitreader_refill();
        bitreader_peek();
        bitreader_refill();
        bitreader_refill();
        bitreader_refill();
      }
      else {
        if (uVar3 == 0x1b6) {
          bitreader_refill();
          uVar3 = bitreader_peek();
          bitreader_refill();
          iVar4 = bitreader_peek();
          bitreader_refill();
          while (iVar4 != 0) {
            unaff_r8 = unaff_r8 + 1;
            iVar4 = bitreader_peek();
            bitreader_refill();
          }
          bitreader_refill();
          if (unaff_r5[2] != 0) {
            unaff_r9 = bitreader_peek();
            bitreader_refill();
          }
          if (uVar3 == 2) {
            uVar8 = unaff_r5[0x2a] + unaff_r8;
            uVar7 = *unaff_r5;
            lVar1 = (ulonglong)uVar8 * (ulonglong)uVar7;
            uVar9 = (uint)lVar1;
            uVar5 = uVar9 + unaff_r9;
            unaff_r5[0x26] = uVar5;
            unaff_r5[0x27] =
                 uVar8 * ((int)uVar7 >> 0x1f) +
                 (unaff_r5[0x2b] + (uint)CARRY4(unaff_r5[0x2a],unaff_r8)) * uVar7 +
                 (int)((ulonglong)lVar1 >> 0x20) +
                 ((int)unaff_r9 >> 0x1f) + (uint)CARRY4(uVar9,unaff_r9);
            unaff_r5[0x2f] = unaff_r5[0x2e] - (unaff_r5[0x2c] - uVar5);
          }
          else {
            uVar7 = unaff_r5[0x28];
            unaff_r5[0x2a] = uVar7;
            unaff_r5[0x2b] = unaff_r5[0x29];
            uVar8 = uVar7 + unaff_r8;
            uVar7 = unaff_r5[0x29] + (uint)CARRY4(uVar7,unaff_r8);
            unaff_r5[0x28] = uVar8;
            unaff_r5[0x29] = uVar7;
            uVar9 = *unaff_r5;
            uVar10 = (uint)((ulonglong)uVar8 * (ulonglong)uVar9);
            uVar5 = uVar10 + unaff_r9;
            uVar7 = uVar8 * ((int)uVar9 >> 0x1f) +
                    uVar7 * uVar9 + (int)((ulonglong)uVar8 * (ulonglong)uVar9 >> 0x20) +
                    ((int)unaff_r9 >> 0x1f) + (uint)CARRY4(uVar10,unaff_r9);
            unaff_r5[0x26] = uVar5;
            unaff_r5[0x27] = uVar7;
            unaff_r5[0x2e] = uVar5 - unaff_r5[0x2c];
            unaff_r5[0x2c] = uVar5;
            unaff_r5[0x2d] = uVar7;
          }
          bitreader_refill();
          iVar4 = bitreader_peek();
          bitreader_refill();
          if (iVar4 == 0) {
            return 4;
          }
          if (unaff_r5[0x15] != 0) {
            bitreader_peek();
            bitreader_refill();
            iVar4 = bitreader_peek();
            bitreader_refill();
            if (iVar4 != 0) {
              bitreader_peek();
              bitreader_refill();
            }
            bitreader_refill();
          }
          uVar7 = unaff_r5[3];
          if (uVar7 != 2) {
            if (uVar3 != 1) {
              if (uVar3 == 3) {
                uVar7 = unaff_r5[0x11];
              }
              if (uVar3 != 3 || uVar7 != 2) goto LAB_0301f36a;
            }
            uVar6 = bitreader_peek();
            bitreader_refill();
            *in_stack_0000010c = uVar6;
          }
LAB_0301f36a:
          if (unaff_r5[0x16] == 0) {
LAB_0301f38e:
            if (unaff_r5[3] != 0) {
LAB_0301f392:
              if (unaff_r5[0x11] != 1 || uVar3 != 0) {
                bitreader_peek();
                bitreader_refill();
                bitreader_refill();
                bitreader_peek();
                bitreader_refill();
                bitreader_refill();
                bitreader_peek();
                bitreader_refill();
                bitreader_refill();
                bitreader_peek();
                bitreader_refill();
                bitreader_refill();
              }
              bitreader_refill();
              iVar4 = bitreader_peek();
              bitreader_refill();
              if (iVar4 != 0) {
                bitreader_refill();
              }
              if (unaff_r5[3] == 2) goto LAB_0301f49c;
            }
          }
          else {
            if (unaff_r5[3] != 0) goto LAB_0301f392;
            if (uVar3 < 2) {
              bitreader_peek();
              bitreader_refill();
              goto LAB_0301f38e;
            }
          }
          if (unaff_r5[10] == 0) {
            *_DAT_0301f56c = unaff_r7;
          }
          iVar4 = bitreader_peek();
          bitreader_refill();
          *in_stack_00000140 = *(undefined4 *)(_DAT_0301f570 + iVar4 * 4);
          unaff_r5[0xc] = 0;
          unaff_r5[0xd] = 0;
          if (unaff_r5[0xb] != 0) {
            uVar7 = bitreader_peek();
            bitreader_refill();
            unaff_r5[0xc] = uVar7;
            uVar7 = bitreader_peek();
            bitreader_refill();
            unaff_r5[0xd] = uVar7;
          }
LAB_0301f49c:
          if ((unaff_r5[0x11] == 1 || unaff_r5[0x11] == 2) && (uVar3 == 3)) {
            *_DAT_0301f56c = unaff_r7;
          }
          uVar7 = bitreader_peek();
          bitreader_refill();
          *in_stack_00000110 = uVar7;
          if (uVar7 == 0) {
            *in_stack_00000110 = unaff_r7;
          }
          if (uVar3 != 0) {
            uVar6 = bitreader_peek();
            bitreader_refill();
            *in_stack_00000138 = uVar6;
            if (uVar3 == 2) {
              uVar6 = bitreader_peek();
              bitreader_refill();
              *in_stack_0000013c = uVar6;
            }
          }
          if (((char)unaff_r5[0x24] == '\0') && (unaff_r5[3] != 0 && uVar3 != 0)) {
            bitreader_refill();
          }
          return uVar3;
        }
        if (uVar3 == 0x1b2) {
          bitreader_refill();
          in_stack_00000000 = bitreader_peek();
          iVar4 = 1;
          do {
            cVar2 = bitreader_peek();
            (&stack0x00000000)[iVar4] = cVar2;
            if (cVar2 == '\0') break;
            bitreader_refill();
            iVar4 = iVar4 + 1;
          } while (iVar4 < 0x100);
        }
        else {
          bitreader_peek();
          bitreader_refill();
        }
      }
      goto LAB_0301f198;
    }
    bitreader_refill();
    iVar4 = bitreader_peek();
    bitreader_refill();
    if (iVar4 == 0) {
      unaff_r5[4] = unaff_r7;
    }
    else {
      uVar3 = bitreader_peek();
      bitreader_refill();
      unaff_r5[4] = uVar3;
      bitreader_refill();
    }
    iVar4 = bitreader_peek();
    if (iVar4 != 1) {
      return 0xffffffff;
    }
    bitreader_refill();
    iVar4 = bitreader_peek();
    bitreader_refill();
    if (iVar4 == 0) goto LAB_0301f198;
    bitreader_refill();
    bitreader_refill();
  } while( true );
}


