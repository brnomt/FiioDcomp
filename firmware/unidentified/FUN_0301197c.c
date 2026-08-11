/**
 * FUN_0301197c @ 0x0301197c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Type propagation algorithm not settling */

void FUN_0301197c(uint param_1)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  byte *unaff_r4;
  byte *unaff_r5;
  byte unaff_r6;
  byte unaff_r7;
  byte unaff_r8;
  byte *in_r12;
  bool bVar7;
  
  if (param_1 < 10) {
    bVar3 = unaff_r4[8];
    bVar4 = (byte)param_1;
    if (bVar3 == 0x37) {
      if (0xd < *unaff_r4) {
        return;
      }
      bVar3 = *unaff_r4 + 1;
      unaff_r4[8] = unaff_r8;
      *unaff_r4 = bVar3;
      in_r12[bVar3] = bVar4;
      in_r12[bVar3 + 1] = unaff_r6;
    }
    else if (bVar3 == 0) {
      bVar3 = *unaff_r4;
      if (0xd < bVar3) {
        return;
      }
      bVar7 = param_1 == 0 && bVar3 == 1;
      if (param_1 == 0 && bVar3 == 1) {
        bVar7 = in_r12[1] == 0;
      }
      if (bVar7) {
        return;
      }
      bVar3 = bVar3 + 1;
      *unaff_r4 = bVar3;
      in_r12[bVar3] = bVar4;
      pbVar1 = in_r12 + bVar3;
LAB_03011a16:
      pbVar1[1] = unaff_r6;
    }
    else if (bVar3 == 1) {
      if (0xd < unaff_r4[1]) {
        return;
      }
      bVar3 = unaff_r4[1] + 1;
      unaff_r4[1] = bVar3;
      unaff_r5[bVar3] = bVar4;
      unaff_r5[bVar3 + 1] = unaff_r6;
      unaff_r4[8] = unaff_r7;
    }
    else if (bVar3 == 2) {
      bVar3 = unaff_r4[1];
      if (0xd < bVar3) {
        return;
      }
      bVar7 = param_1 == 0 && bVar3 == 1;
      if (param_1 == 0 && bVar3 == 1) {
        bVar7 = unaff_r5[1] == 0;
      }
      if (bVar7) {
        return;
      }
      bVar3 = bVar3 + 1;
      unaff_r4[1] = bVar3;
      unaff_r5[bVar3] = bVar4;
      pbVar1 = unaff_r5 + bVar3;
      goto LAB_03011a16;
    }
LAB_03011ca0:
    FUN_03011192(1);
    goto LAB_03011d68;
  }
  if (param_1 == 0x13) {
    if (unaff_r4[8] == 0) {
      if (0xb < *unaff_r4) {
        return;
      }
      if (in_r12[1] == 0) {
        return;
      }
      uVar2 = (uint)(byte)(*unaff_r4 + 1);
      in_r12[uVar2] = unaff_r8;
      uVar2 = uVar2 + 1;
      uVar5 = uVar2 & 0xff;
      *unaff_r4 = (byte)uVar2;
      in_r12[uVar5] = unaff_r8;
      in_r12[uVar5 + 1] = unaff_r6;
      FUN_03011192(1);
    }
    else if (unaff_r4[8] == 2) {
      if (0xb < unaff_r4[1]) {
        return;
      }
      if (unaff_r5[1] == 0) {
        return;
      }
      uVar2 = (uint)(byte)(unaff_r4[1] + 1);
      unaff_r5[uVar2] = unaff_r8;
      uVar2 = uVar2 + 1;
      uVar5 = uVar2 & 0xff;
      unaff_r4[1] = (byte)uVar2;
      unaff_r5[uVar5] = unaff_r8;
      unaff_r5[uVar5 + 1] = unaff_r6;
      FUN_03011192(1);
    }
    goto LAB_03011d68;
  }
  if (param_1 == 0x12) {
    if (unaff_r4[8] == 0) {
      bVar3 = *unaff_r4;
      if (0xe < bVar3) {
        return;
      }
      if (unaff_r4[0xb] == 0) {
        unaff_r4[0xb] = 1;
        *unaff_r4 = bVar3 + 1;
        if (bVar3 == 0) {
          in_r12[1] = unaff_r8;
          *unaff_r4 = unaff_r7;
        }
        bVar3 = *unaff_r4;
        in_r12[bVar3] = 0x12;
        in_r12[bVar3 + 1] = unaff_r6;
        FUN_03011192(1);
      }
    }
    else if (unaff_r4[8] == 2) {
      bVar3 = unaff_r4[1];
      if (0xe < bVar3) {
        return;
      }
      if (unaff_r4[0xb] == 0) {
        unaff_r4[0xb] = 1;
        unaff_r4[1] = bVar3 + 1;
        if (bVar3 == 0) {
          unaff_r5[1] = unaff_r8;
          unaff_r4[1] = unaff_r7;
        }
        bVar3 = unaff_r4[1];
        unaff_r5[bVar3] = 0x12;
        unaff_r5[bVar3 + 1] = unaff_r6;
        FUN_03011192(1);
      }
    }
    goto LAB_03011d68;
  }
  if (param_1 == 0xd) {
    if (unaff_r4[8] == 0) {
      bVar3 = *unaff_r4;
      uVar2 = (uint)bVar3;
      if (10 < uVar2) {
        return;
      }
      bVar4 = in_r12[1];
      if (bVar4 == 0) {
        return;
      }
      if (in_r12[uVar2 + 1] != 0xff) goto LAB_03011d68;
      if (unaff_r4[0xb] == 0) {
        unaff_r4[0xb] = 1;
        iVar6 = DAT_03011d0c;
        if (uVar2 == 1) {
          *(undefined1 *)(DAT_03011d0c + 5) = *(undefined1 *)(DAT_03011d0c + 2);
          *(byte *)(iVar6 + 4) = bVar4;
          *(byte *)(iVar6 + 3) = unaff_r8;
          *(undefined1 *)(iVar6 + 2) = 0x12;
          in_r12[1] = unaff_r8;
        }
        else {
          if (uVar2 != 2) {
            if (2 < uVar2) {
              in_r12[uVar2 + 2] = 0xff;
              in_r12[uVar2 + 1] = in_r12[uVar2];
              in_r12[uVar2] = in_r12[uVar2 - 1];
              in_r12[uVar2 - 1] = 0x12;
              *unaff_r4 = bVar3 + 1;
            }
            goto LAB_03011ca0;
          }
          *(undefined1 *)(DAT_03011d0c + 5) = *(undefined1 *)(DAT_03011d0c + 3);
          *(byte *)(iVar6 + 4) = in_r12[2];
          *(byte *)(iVar6 + 3) = bVar4;
          in_r12[2] = 0x12;
          *(byte *)(iVar6 + 1) = unaff_r8;
        }
        *unaff_r4 = 4;
      }
      else {
        uVar5 = 0;
        do {
          iVar6 = uVar2 - uVar5;
          if (in_r12[iVar6 + 1] == 0x12) {
            in_r12[(uVar2 - uVar5) + 2] = unaff_r8;
            in_r12[iVar6 + 3] = unaff_r8;
            break;
          }
          uVar5 = uVar5 + 1 & 0xff;
          in_r12[iVar6 + 3] = in_r12[iVar6 + 1];
        } while (uVar5 <= uVar2 + 2);
        *unaff_r4 = (byte)(uVar2 + 2);
      }
    }
    else {
      if (unaff_r4[8] != 2) goto LAB_03011d68;
      uVar2 = (uint)unaff_r4[1];
      if (0xb < uVar2) {
        return;
      }
      bVar3 = unaff_r5[1];
      if (bVar3 == 0) {
        return;
      }
      if (unaff_r5[uVar2 + 1] != 0xff) goto LAB_03011d68;
      if (unaff_r4[0xb] == 0) {
        unaff_r4[0xb] = 1;
        iVar6 = DAT_03011d10;
        if (uVar2 == 1) {
          *(undefined1 *)(DAT_03011d10 + 5) = *(undefined1 *)(DAT_03011d10 + 2);
          *(byte *)(iVar6 + 4) = bVar3;
          *(byte *)(iVar6 + 3) = unaff_r8;
          *(undefined1 *)(iVar6 + 2) = 0x12;
          unaff_r5[1] = unaff_r8;
        }
        else {
          if (uVar2 != 2) {
            if (2 < uVar2) {
              unaff_r5[uVar2 + 2] = 0xff;
              unaff_r5[uVar2 + 1] = unaff_r5[uVar2];
              unaff_r5[uVar2] = unaff_r5[uVar2 - 1];
              unaff_r5[uVar2 - 1] = 0x12;
              *unaff_r4 = *unaff_r4 + 1;
            }
            goto LAB_03011ca0;
          }
          *(undefined1 *)(DAT_03011d10 + 5) = *(undefined1 *)(DAT_03011d10 + 3);
          *(byte *)(iVar6 + 4) = unaff_r5[2];
          *(byte *)(iVar6 + 3) = bVar3;
          unaff_r5[2] = 0x12;
          *(byte *)(iVar6 + 1) = unaff_r8;
        }
        unaff_r4[1] = 4;
      }
      else {
        uVar5 = 0;
        do {
          iVar6 = uVar2 - uVar5;
          if (unaff_r5[iVar6 + 1] == 0x12) {
            unaff_r5[(uVar2 - uVar5) + 2] = unaff_r8;
            unaff_r5[iVar6 + 3] = unaff_r8;
            break;
          }
          uVar5 = uVar5 + 1 & 0xff;
          unaff_r5[iVar6 + 3] = unaff_r5[iVar6 + 1];
        } while (uVar5 <= uVar2 + 2);
        unaff_r4[1] = (byte)(uVar2 + 2);
      }
    }
    goto LAB_03011ca0;
  }
  if (param_1 == 0xb) {
    FUN_030110cc();
    goto LAB_03011d68;
  }
  if (param_1 == 0xc) {
    if (unaff_r4[8] == 0) {
      if (*in_r12 == 0xc) {
        *in_r12 = unaff_r8;
      }
      else {
        *in_r12 = 0xc;
      }
    }
    else {
      if (unaff_r4[8] != 3) goto LAB_03011d68;
      if (*unaff_r5 == 0xc) {
        *unaff_r5 = unaff_r8;
      }
      else {
        *unaff_r5 = 0xc;
      }
    }
    goto LAB_03011ca0;
  }
  if (param_1 == 0xe) {
    bVar3 = unaff_r4[8];
    bVar4 = 0xe;
    if (bVar3 == 3 || bVar3 == 0) goto LAB_03011d14;
    if (bVar3 == 1) goto LAB_03011d1a;
joined_r0x03011d36:
    if (bVar3 == 2) {
      FUN_03011370();
    }
  }
  else {
    if (param_1 == 0xf) {
      bVar3 = unaff_r4[8];
      bVar4 = 0xf;
      if (bVar3 != 3 && bVar3 != 0) {
joined_r0x03011d32:
        if (bVar3 != 1) goto joined_r0x03011d36;
LAB_03011d1a:
        unaff_r4[10] = bVar4;
        goto LAB_03011d64;
      }
    }
    else if (param_1 == 0x10) {
      bVar3 = unaff_r4[8];
      bVar4 = 0x10;
      if (bVar3 != 3 && bVar3 != 0) goto joined_r0x03011d32;
    }
    else {
      if (param_1 != 0x11) {
        bVar7 = param_1 == 0x14;
        if (bVar7) {
          param_1 = (uint)unaff_r4[8];
        }
        if (bVar7 && param_1 == 2) {
          FUN_03011370();
        }
        goto LAB_03011d68;
      }
      bVar3 = unaff_r4[8];
      bVar4 = 0x11;
      if (bVar3 != 3 && bVar3 != 0) goto joined_r0x03011d32;
    }
LAB_03011d14:
    unaff_r4[8] = 1;
    unaff_r4[10] = bVar4;
  }
LAB_03011d64:
  unaff_r4[0xb] = unaff_r8;
LAB_03011d68:
  FUN_02ffff38(0x33);
  return;
}


