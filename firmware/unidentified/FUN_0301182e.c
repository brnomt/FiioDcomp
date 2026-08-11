/**
 * FUN_0301182e @ 0x0301182e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

bool FUN_0301182e(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  undefined2 auStack_48 [18];
  
  uVar10 = 0;
  iVar4 = FUN_02ff9a2a();
  iVar2 = DAT_030118f4;
  iVar5 = 0;
  if (iVar4 != 0x40000080) {
    iVar5 = iVar4 + -0x50000000;
  }
  if ((iVar4 == 0x40000080 || iVar5 == 0x80) || iVar4 == DAT_030118f4) {
    iVar5 = FUN_02ff96fa(0,0,0x46,0x22,0);
    if (iVar5 == 0) {
      iVar5 = FUN_02ff96fa(0x77,399,0x79,0x191,0);
      if (iVar5 == 0) {
        if (iVar4 != iVar2) {
          do {
            uVar9 = 0;
            do {
              iVar6 = FUN_02ff96fa(uVar10 * 0x3b + 4,uVar9 * 0x36 + 0x34,uVar10 * 0x3b + 0x3f,
                                   uVar9 * 0x36 + 0x6a,0);
              iVar2 = DAT_03011900;
              iVar5 = DAT_030118dc;
              if (iVar6 != 0) {
                *(char *)(DAT_030118dc + 6) = (char)uVar10;
                *(char *)(iVar5 + 7) = (char)uVar9;
                uVar10 = 9;
                FUN_02ffff38(0x1c3);
                iVar4 = iVar2;
                break;
              }
              uVar9 = uVar9 + 1 & 0xff;
            } while (uVar9 < 5);
            uVar10 = uVar10 + 1 & 0xff;
          } while (uVar10 < 4);
        }
      }
      else if (iVar4 != iVar2) {
        iVar4 = DAT_030118fc;
      }
    }
    else if (iVar4 != iVar2) {
      iVar4 = DAT_030118f8;
    }
  }
  pbVar3 = DAT_03011d08;
  if (iVar4 == DAT_03011d00) {
LAB_03011d70:
    bVar13 = *(char *)(DAT_0301205c + 8) == '7';
    if (bVar13) {
      auStack_48[0] = 7;
      FUN_03000162(10,auStack_48);
      uVar7 = 0x32;
    }
    else {
      FUN_030110cc();
      uVar7 = 0x33;
    }
    FUN_02ffff38(uVar7);
    return bVar13;
  }
  if (DAT_03011d00 <= iVar4) {
    if (iVar4 - DAT_03011d00 != 0xe00 && iVar4 - DAT_03011d00 != 0x10000000) {
      return false;
    }
    goto LAB_03011d70;
  }
  if (iVar4 + -0x20001000 == 0) {
    auStack_48[0] = 7;
    FUN_03000162(10,auStack_48);
    return true;
  }
  iVar5 = iVar4 + -0x20001000 + DAT_03011d04;
  if (iVar5 == 0) {
    if (DAT_03011d08[8] != 2) {
      return false;
    }
    FUN_03011370();
    return false;
  }
  if (iVar5 != 0x3e) {
    return false;
  }
  pbVar12 = DAT_03011d08 + 0x65;
  bVar1 = DAT_03011d08[(byte)(DAT_03011d08[6] + DAT_03011d08[7] * '\x04') + 0x50];
  pbVar11 = DAT_03011d08 + 0x7b;
  if (bVar1 < 10) {
    bVar8 = DAT_03011d08[8];
    if (bVar8 == 0x37) {
      if (0xd < *DAT_03011d08) {
        return false;
      }
      bVar8 = *DAT_03011d08 + 1;
      DAT_03011d08[8] = 0;
      *pbVar3 = bVar8;
      pbVar12[bVar8] = bVar1;
      pbVar12[bVar8 + 1] = 0xff;
    }
    else if (bVar8 == 0) {
      bVar8 = *DAT_03011d08;
      if (0xd < bVar8) {
        return false;
      }
      bVar13 = bVar1 == 0 && bVar8 == 1;
      if (bVar1 == 0 && bVar8 == 1) {
        bVar13 = DAT_03011d08[0x66] == 0;
      }
      if (bVar13) {
        return false;
      }
      bVar8 = bVar8 + 1;
      *DAT_03011d08 = bVar8;
      pbVar12[bVar8] = bVar1;
      pbVar11 = pbVar12 + bVar8;
LAB_03011a16:
      pbVar11[1] = 0xff;
    }
    else if (bVar8 == 1) {
      if (0xd < DAT_03011d08[1]) {
        return false;
      }
      bVar8 = DAT_03011d08[1] + 1;
      DAT_03011d08[1] = bVar8;
      pbVar11[bVar8] = bVar1;
      pbVar11[bVar8 + 1] = 0xff;
      pbVar3[8] = 2;
    }
    else if (bVar8 == 2) {
      bVar8 = DAT_03011d08[1];
      if (0xd < bVar8) {
        return false;
      }
      bVar13 = bVar1 == 0 && bVar8 == 1;
      if (bVar1 == 0 && bVar8 == 1) {
        bVar13 = DAT_03011d08[0x7c] == 0;
      }
      if (bVar13) {
        return false;
      }
      bVar8 = bVar8 + 1;
      DAT_03011d08[1] = bVar8;
      pbVar11[bVar8] = bVar1;
      pbVar11 = pbVar11 + bVar8;
      goto LAB_03011a16;
    }
LAB_03011ca0:
    FUN_03011192(1);
    goto LAB_03011d68;
  }
  if (bVar1 == 0x13) {
    if (DAT_03011d08[8] == 0) {
      if (0xb < *DAT_03011d08) {
        return false;
      }
      if (DAT_03011d08[0x66] == 0) {
        return false;
      }
      uVar10 = (uint)(byte)(*DAT_03011d08 + 1);
      pbVar12[uVar10] = 0;
      uVar10 = uVar10 + 1;
      uVar9 = uVar10 & 0xff;
      *pbVar3 = (byte)uVar10;
      pbVar12[uVar9] = 0;
      pbVar12[uVar9 + 1] = 0xff;
      FUN_03011192(1);
    }
    else if (DAT_03011d08[8] == 2) {
      if (0xb < DAT_03011d08[1]) {
        return false;
      }
      if (DAT_03011d08[0x7c] == 0) {
        return false;
      }
      uVar10 = (uint)(byte)(DAT_03011d08[1] + 1);
      pbVar11[uVar10] = 0;
      uVar10 = uVar10 + 1;
      uVar9 = uVar10 & 0xff;
      pbVar3[1] = (byte)uVar10;
      pbVar11[uVar9] = 0;
      pbVar11[uVar9 + 1] = 0xff;
      FUN_03011192(1);
    }
    goto LAB_03011d68;
  }
  if (bVar1 == 0x12) {
    if (DAT_03011d08[8] == 0) {
      bVar1 = *DAT_03011d08;
      if (0xe < bVar1) {
        return false;
      }
      if (DAT_03011d08[0xb] == 0) {
        DAT_03011d08[0xb] = 1;
        *pbVar3 = bVar1 + 1;
        if (bVar1 == 0) {
          pbVar3[0x66] = 0;
          *pbVar3 = 2;
        }
        bVar1 = *pbVar3;
        pbVar12[bVar1] = 0x12;
        pbVar12[bVar1 + 1] = 0xff;
        FUN_03011192(1);
      }
    }
    else if (DAT_03011d08[8] == 2) {
      bVar1 = DAT_03011d08[1];
      if (0xe < bVar1) {
        return false;
      }
      if (DAT_03011d08[0xb] == 0) {
        DAT_03011d08[0xb] = 1;
        pbVar3[1] = bVar1 + 1;
        if (bVar1 == 0) {
          pbVar3[0x7c] = 0;
          pbVar3[1] = 2;
        }
        bVar1 = pbVar3[1];
        pbVar11[bVar1] = 0x12;
        pbVar11[bVar1 + 1] = 0xff;
        FUN_03011192(1);
      }
    }
    goto LAB_03011d68;
  }
  if (bVar1 == 0xd) {
    if (DAT_03011d08[8] == 0) {
      bVar1 = *DAT_03011d08;
      uVar10 = (uint)bVar1;
      if (10 < uVar10) {
        return false;
      }
      bVar8 = DAT_03011d08[0x66];
      if (bVar8 == 0) {
        return false;
      }
      if (pbVar12[uVar10 + 1] != 0xff) goto LAB_03011d68;
      if (DAT_03011d08[0xb] == 0) {
        DAT_03011d08[0xb] = 1;
        iVar5 = DAT_03011d0c;
        if (uVar10 == 1) {
          *(undefined1 *)(DAT_03011d0c + 5) = *(undefined1 *)(DAT_03011d0c + 2);
          *(byte *)(iVar5 + 4) = bVar8;
          *(undefined1 *)(iVar5 + 3) = 0;
          *(undefined1 *)(iVar5 + 2) = 0x12;
          pbVar3[0x66] = 0;
        }
        else {
          if (uVar10 != 2) {
            if (2 < uVar10) {
              pbVar12[uVar10 + 2] = 0xff;
              pbVar12[uVar10 + 1] = pbVar12[uVar10];
              pbVar12[uVar10] = pbVar12[uVar10 - 1];
              pbVar12[uVar10 - 1] = 0x12;
              *pbVar3 = bVar1 + 1;
            }
            goto LAB_03011ca0;
          }
          *(undefined1 *)(DAT_03011d0c + 5) = *(undefined1 *)(DAT_03011d0c + 3);
          *(byte *)(iVar5 + 4) = pbVar3[0x67];
          *(byte *)(iVar5 + 3) = bVar8;
          pbVar3[0x67] = 0x12;
          *(undefined1 *)(iVar5 + 1) = 0;
        }
        *pbVar3 = 4;
      }
      else {
        uVar9 = 0;
        do {
          iVar5 = uVar10 - uVar9;
          if (pbVar12[iVar5 + 1] == 0x12) {
            pbVar12[(uVar10 - uVar9) + 2] = 0;
            pbVar12[iVar5 + 3] = 0;
            break;
          }
          uVar9 = uVar9 + 1 & 0xff;
          pbVar12[iVar5 + 3] = pbVar12[iVar5 + 1];
        } while (uVar9 <= uVar10 + 2);
        *pbVar3 = (byte)(uVar10 + 2);
      }
    }
    else {
      if (DAT_03011d08[8] != 2) goto LAB_03011d68;
      uVar10 = (uint)DAT_03011d08[1];
      if (0xb < uVar10) {
        return false;
      }
      bVar1 = DAT_03011d08[0x7c];
      if (bVar1 == 0) {
        return false;
      }
      if (pbVar11[uVar10 + 1] != 0xff) goto LAB_03011d68;
      if (DAT_03011d08[0xb] == 0) {
        DAT_03011d08[0xb] = 1;
        iVar5 = DAT_03011d10;
        if (uVar10 == 1) {
          *(undefined1 *)(DAT_03011d10 + 5) = *(undefined1 *)(DAT_03011d10 + 2);
          *(byte *)(iVar5 + 4) = bVar1;
          *(undefined1 *)(iVar5 + 3) = 0;
          *(undefined1 *)(iVar5 + 2) = 0x12;
          pbVar3[0x7c] = 0;
        }
        else {
          if (uVar10 != 2) {
            if (2 < uVar10) {
              pbVar11[uVar10 + 2] = 0xff;
              pbVar11[uVar10 + 1] = pbVar11[uVar10];
              pbVar11[uVar10] = pbVar11[uVar10 - 1];
              pbVar11[uVar10 - 1] = 0x12;
              *pbVar3 = *pbVar3 + 1;
            }
            goto LAB_03011ca0;
          }
          *(undefined1 *)(DAT_03011d10 + 5) = *(undefined1 *)(DAT_03011d10 + 3);
          *(byte *)(iVar5 + 4) = pbVar3[0x7d];
          *(byte *)(iVar5 + 3) = bVar1;
          pbVar3[0x7d] = 0x12;
          *(undefined1 *)(iVar5 + 1) = 0;
        }
        pbVar3[1] = 4;
      }
      else {
        uVar9 = 0;
        do {
          iVar5 = uVar10 - uVar9;
          if (pbVar11[iVar5 + 1] == 0x12) {
            pbVar11[(uVar10 - uVar9) + 2] = 0;
            pbVar11[iVar5 + 3] = 0;
            break;
          }
          uVar9 = uVar9 + 1 & 0xff;
          pbVar11[iVar5 + 3] = pbVar11[iVar5 + 1];
        } while (uVar9 <= uVar10 + 2);
        pbVar3[1] = (byte)(uVar10 + 2);
      }
    }
    goto LAB_03011ca0;
  }
  if (bVar1 == 0xb) {
    FUN_030110cc();
    goto LAB_03011d68;
  }
  if (bVar1 == 0xc) {
    if (DAT_03011d08[8] == 0) {
      if (*pbVar12 == 0xc) {
        *pbVar12 = 0;
      }
      else {
        *pbVar12 = 0xc;
      }
    }
    else {
      if (DAT_03011d08[8] != 3) goto LAB_03011d68;
      if (*pbVar11 == 0xc) {
        *pbVar11 = 0;
      }
      else {
        *pbVar11 = 0xc;
      }
    }
    goto LAB_03011ca0;
  }
  if (bVar1 == 0xe) {
    bVar1 = DAT_03011d08[8];
    bVar8 = 0xe;
    if (bVar1 == 3 || bVar1 == 0) goto LAB_03011d14;
    if (bVar1 == 1) goto LAB_03011d1a;
joined_r0x03011d36:
    if (bVar1 == 2) {
      FUN_03011370();
    }
  }
  else {
    if (bVar1 == 0xf) {
      bVar1 = DAT_03011d08[8];
      bVar8 = 0xf;
      if (bVar1 != 3 && bVar1 != 0) {
joined_r0x03011d32:
        if (bVar1 != 1) goto joined_r0x03011d36;
LAB_03011d1a:
        DAT_03011d08[10] = bVar8;
        goto LAB_03011d64;
      }
    }
    else if (bVar1 == 0x10) {
      bVar1 = DAT_03011d08[8];
      bVar8 = 0x10;
      if (bVar1 != 3 && bVar1 != 0) goto joined_r0x03011d32;
    }
    else {
      if (bVar1 != 0x11) {
        bVar13 = bVar1 == 0x14;
        if (bVar13) {
          bVar1 = DAT_03011d08[8];
        }
        if (bVar13 && bVar1 == 2) {
          FUN_03011370();
        }
        goto LAB_03011d68;
      }
      bVar1 = DAT_03011d08[8];
      bVar8 = 0x11;
      if (bVar1 != 3 && bVar1 != 0) goto joined_r0x03011d32;
    }
LAB_03011d14:
    DAT_03011d08[8] = 1;
    pbVar3[10] = bVar8;
  }
LAB_03011d64:
  pbVar3[0xb] = 0;
LAB_03011d68:
  FUN_02ffff38(0x33);
  return false;
}


