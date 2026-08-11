/**
 * FUN_03016c1a @ 0x03016c1a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03016c1a(int param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  ushort *puVar11;
  int iVar12;
  
  uVar6 = DAT_03016f94;
  iVar2 = DAT_03016f8c;
  uVar4 = *(int *)(DAT_03016f8c + 0x10) + 1;
  iVar12 = DAT_03016f90 + *(int *)(DAT_03016f8c + 0x10) * 0x14;
  puVar11 = (ushort *)(DAT_03016f90 + uVar4 * 0x14);
  *(uint *)(DAT_03016f8c + 0x10) = uVar4;
  *(uint *)(puVar11 + 8) =
       iVar2 + 0x46 + (uVar4 + (uint)((ulonglong)uVar6 * (ulonglong)uVar4 >> 0x21) * -3) * 0x3a;
  FUN_02ffefb6(*(undefined2 *)(*(int *)(iVar12 + 0x10) + (uint)*(ushort *)(iVar12 + 10) * 2 + 0x10))
  ;
  iVar9 = DAT_03016f7c;
  psVar10 = *(short **)(puVar11 + 8);
  puVar11[7] = psVar10[1];
  puVar11[6] = 0xff;
  pbVar3 = DAT_03016f98;
  if (param_1 == 0x12a) {
    if (*(char *)(iVar9 + 0x34b) == '\0') {
      puVar11[6] = 1;
    }
    else {
LAB_03016dac:
      puVar11[6] = 0;
    }
LAB_03016d7c:
    *(undefined2 *)(iVar2 + 4) = 0xff;
  }
  else if (param_1 < 299) {
    iVar8 = param_1 + -0x105;
    if (param_1 == 0x105) {
      puVar11[6] = (ushort)*(byte *)(iVar9 + 0x359);
      *(undefined2 *)(iVar2 + 4) = 0xff;
    }
    else if (param_1 < 0x106) {
      if (param_1 == 0xf3) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x1a1);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
      else if (param_1 < 0xf4) {
        if (param_1 == 0xe9) {
          puVar11[6] = (ushort)*(byte *)(iVar9 + 0x35e);
          *(undefined2 *)(iVar2 + 4) = 0xff;
        }
        else if (param_1 == 0xee) {
          if (*(char *)(iVar9 + 0x6f) == '\0') {
            uVar7 = *(byte *)(iVar9 + 0x6d) & 3;
          }
          else {
            uVar7 = 3;
          }
          puVar11[6] = uVar7;
          goto LAB_03016d7c;
        }
      }
      else if (param_1 == 0xf6) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x74);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
      else if (param_1 == 0xff) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x358);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
    }
    else if (iVar8 == 10) {
      puVar11[6] = (ushort)*(byte *)(iVar9 + 0x35c);
      *(undefined2 *)(iVar2 + 4) = 0xff;
    }
    else if (iVar8 < 0xb) {
      if (iVar8 == 3) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x34c);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
      else if (iVar8 == 7) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x35a);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
    }
    else {
      if (iVar8 == 0x23) {
        if (10 < *DAT_03016f98) goto LAB_03016dac;
        puVar11[6] = (ushort)*DAT_03016f98;
        *pbVar3 = 0;
        goto LAB_03016d7c;
      }
      if (iVar8 == 0x24) {
        *DAT_03016f98 = 0;
        *(undefined2 *)(iVar2 + 4) = 0;
      }
    }
  }
  else if (param_1 != 0x14c) {
    if (param_1 < 0x14d) {
      if (param_1 == 0x13f) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x1a);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
      else if (param_1 < 0x140) {
        if (param_1 == 0x130) {
          puVar11[6] = (ushort)*(byte *)(iVar9 + 0x18);
          *(undefined2 *)(iVar2 + 4) = 0xff;
        }
        else if (param_1 == 0x138) {
          puVar11[6] = (ushort)*(byte *)(iVar9 + 0x17);
          *(undefined2 *)(iVar2 + 4) = 0xff;
        }
      }
      else if (param_1 == 0x146) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x1b);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
    }
    else if (param_1 == 0x15d) {
      *(undefined2 *)(iVar2 + 4) = 0xff;
LAB_03016dd0:
      puVar11[6] = (ushort)*DAT_03016f9c;
    }
    else if (param_1 < 0x15e) {
      if (param_1 == 0x14e) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x356);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
      else if (param_1 == 0x157) {
        puVar11[6] = (ushort)*(byte *)(iVar9 + 0x34f);
        *(undefined2 *)(iVar2 + 4) = 0xff;
      }
    }
    else if ((param_1 != 0x19f) && (param_1 == 0x1aa)) goto LAB_03016dd0;
  }
  if (*psVar10 == 0xf6) {
    *(uint *)(iVar2 + 8) = (uint)*(byte *)(iVar9 + 0x74);
  }
  else if (*psVar10 == 0x138) {
    *(uint *)(iVar2 + 0xc) = (uint)*(byte *)(iVar9 + 0x17);
  }
  if (psVar10[7] == 0) {
    uVar5 = FUN_03018aa8(*(undefined2 *)
                          (*(int *)(iVar12 + 0x10) + (uint)*(ushort *)(iVar12 + 10) * 2 + 0x10));
    if (*(short *)(iVar2 + 4) == 0xff) {
      if (**(short **)(iVar12 + 0x10) == 0xf6) {
        *(undefined1 *)(iVar9 + 0x74) = *(undefined1 *)(iVar2 + 8);
        func_0x030037a8(0x102);
      }
      else if (**(short **)(iVar12 + 0x10) == 0x138) {
        *(undefined1 *)(iVar9 + 0x17) = *(undefined1 *)(iVar2 + 0xc);
        func_0x030009f8();
      }
      iVar9 = *(int *)(iVar2 + 0x10) + -1;
      *(int *)(iVar2 + 0x10) = iVar9;
      *(undefined2 *)(DAT_03016f90 + iVar9 * 0x14 + 0xc) = *(undefined2 *)(iVar2 + 6);
      func_0x030037a8(199);
      return uVar5;
    }
    iVar8 = func_0x030037c4(0xb8);
    if (iVar8 == 0) {
      if (**(short **)(iVar12 + 0x10) == 0xf6) {
        *(undefined1 *)(iVar9 + 0x74) = *(undefined1 *)(iVar2 + 8);
        func_0x030037a8(0x102);
      }
      else if (**(short **)(iVar12 + 0x10) == 0x138) {
        *(undefined1 *)(iVar9 + 0x17) = *(undefined1 *)(iVar2 + 0xc);
        func_0x030009f8();
      }
      if (*(int *)(iVar2 + 0x10) != 0) {
        *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -2;
        func_0x030037a8(199);
        return uVar5;
      }
      return 1;
    }
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
    func_0x030037a8(0xcb);
    return uVar5;
  }
  ui_post_redraw(0xb8);
  pbVar3 = DAT_03016fa0;
  if (puVar11[6] == 0xff) {
    puVar11[5] = 0;
    puVar11[1] = 0;
    puVar11[2] = 0;
    if (*(ushort *)(*(int *)(puVar11 + 8) + 0xe) < 7) {
      *puVar11 = *(ushort *)(*(int *)(puVar11 + 8) + 0xe);
      goto LAB_03016f68;
    }
  }
  else {
    if (param_1 == 0x15d || param_1 == 0x1aa) {
      bVar1 = *DAT_03016fa0;
      *(ushort *)(*(int *)(puVar11 + 8) + 0xe) = (ushort)bVar1;
      iVar9 = DAT_03016fa4;
      uVar6 = 0;
      if (bVar1 != 0) {
        do {
          *(undefined2 *)(*(int *)(puVar11 + 8) + uVar6 * 2 + 0x10) =
               *(undefined2 *)(iVar9 + uVar6 * 2);
          uVar6 = uVar6 + 1;
        } while (uVar6 < *pbVar3);
      }
    }
    uVar6 = (uint)puVar11[6];
    iVar9 = uVar6 + (uint)((ulonglong)DAT_03016f94 * (ulonglong)uVar6 >> 0x22) * -6;
    puVar11[2] = (ushort)iVar9;
    uVar6 = uVar6 - iVar9;
    uVar7 = (ushort)uVar6;
    puVar11[1] = uVar7;
    puVar11[5] = puVar11[6];
    if ((uint)*(ushort *)(*(int *)(puVar11 + 8) + 0xe) <= (uVar6 & 0xffff) + 6) {
      *puVar11 = *(ushort *)(*(int *)(puVar11 + 8) + 0xe) - uVar7;
      goto LAB_03016f68;
    }
  }
  *puVar11 = 6;
LAB_03016f68:
  func_0x030037a8(0xcc);
  func_0x030037a8(199);
  return 0;
}


