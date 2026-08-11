/**
 * FUN_0301575e @ 0x0301575e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301575e(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  ushort *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  ushort uVar8;
  short sVar9;
  ushort uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  undefined4 uVar18;
  short sVar19;
  short sVar20;
  int iVar21;
  ushort *puVar22;
  bool bVar23;
  short local_60;
  short local_58;
  short local_56;
  undefined4 local_54;
  short local_50;
  short local_4e;
  short local_4c;
  short local_4a;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  
  puVar22 = DAT_030159bc;
  local_34 = (uint)*DAT_030159bc;
  local_38 = (uint)DAT_030159bc[1];
  local_40 = FUN_02ffef2c(1);
  local_3c = FUN_02ffef08(2);
  *puVar22 = *DAT_030159c0;
  puVar22[1] = *DAT_030159c4;
  iVar11 = func_0x030037c4(0x32);
  if (iVar11 != 0) {
    func_0x030037a8(199);
  }
  puVar22 = (ushort *)(DAT_030159cc + *(int *)(DAT_030159c8 + 0x10) * 0x14);
  iVar11 = ui_refresh_and_redraw(0x26);
  if (((iVar11 != 0) || (iVar11 = func_0x030037c4(199), iVar11 != 0)) ||
     (iVar11 = func_0x030037c4(0x2f), iVar11 != 0)) {
    uVar12 = *(uint *)(DAT_030159c8 + 0x14);
    if (*(uint *)(DAT_030159c8 + 0x10) < 2) {
      bVar23 = uVar12 == 9;
      if (bVar23) {
        uVar12 = (uint)*(ushort *)(DAT_030159c8 + 2);
      }
      if (bVar23 && uVar12 == 0xfe) {
        FUN_02fff7da(0x7a);
        FUN_030155ae();
      }
      else {
        FUN_02fff7da(0x7a);
      }
    }
    else {
      if (uVar12 == 6) {
        if (*(short *)(DAT_030159c8 + 2) != 0xfe) goto LAB_0301580e;
LAB_03015880:
        FUN_03015318(1);
      }
      else {
        if (uVar12 == 7) {
          if (*(short *)(DAT_030159c8 + 2) == 0xfe) goto LAB_03015880;
LAB_0301580e:
          uVar18 = 0;
        }
        else {
          bVar23 = uVar12 == 8;
          if (bVar23) {
            uVar12 = (uint)*(ushort *)(DAT_030159c8 + 2);
          }
          if (!bVar23 || uVar12 != 0xfe) goto LAB_0301580e;
          uVar18 = 1;
        }
        FUN_03015318(uVar18);
      }
      FUN_02fff812(0x7a,0,0,0,0x14);
    }
    func_0x030037a8(0xcd);
    func_0x030037a8(0xcb);
    func_0x030037a8(0xcc);
    func_0x030037a8(0x1a9);
  }
  iVar13 = func_0x030037c4(0xcd);
  iVar11 = DAT_030159c8;
  puVar4 = DAT_030159bc;
  if (iVar13 != 0) {
    *DAT_030159bc = *DAT_030159d0;
    if ((*(uint *)(iVar11 + 0x10) < 2) || (iVar13 = ui_refresh_and_redraw(0x1dc), iVar13 != 0)) {
      if (*(short *)(iVar11 + 2) == 0xfe) {
        FUN_02ffefd8(0,3,0x140,0x10,2,1);
      }
      else {
        FUN_02ffefd8(0,3,0x140,0x10,2,0x128);
      }
    }
    else {
      FUN_02ffefd8(0,3,0x140,0x10,2,**(undefined2 **)(puVar22 + 8));
    }
    *puVar4 = *DAT_030159c0;
  }
  if ((*(char *)(DAT_030159b4 + 0x357) == 'U') || (*(uint *)(DAT_030159c8 + 0x10) < 2)) {
    iVar13 = 0;
    iVar11 = 0x87;
    local_60 = 0x85;
  }
  else {
    iVar13 = 0x85;
    iVar11 = 0x8a;
    local_60 = 0xb7;
  }
  iVar14 = func_0x030037c4(0xcb);
  sVar1 = (short)iVar13;
  if (iVar14 != 0) {
    FUN_02fff9c8(0x7a,sVar1,0x17,sVar1,0x17,local_60,0x93);
    iVar15 = ui_refresh_and_redraw(0x11a);
    iVar14 = DAT_030159c8;
    if (iVar15 == 0) {
LAB_0301592e:
      if (*(short *)(DAT_030159c8 + 2) == 0xfb) goto LAB_03015a22;
      ui_post_redraw(0xae);
      ui_post_redraw(0xaf);
    }
    else {
      if (*(short *)(DAT_030159c8 + 2) != 0xfb) {
        if (*(short *)(DAT_030159c8 + 2) == 0xfe) {
          if (*(uint *)(DAT_030159c8 + 0x14) < 5) {
            uVar18 = 3;
          }
          else {
            *puVar22 = 4;
            if (*(int *)(iVar14 + 0x14) == 6) {
              uVar18 = 4;
            }
            else {
              uVar18 = 2;
            }
          }
          goto LAB_03015a5c;
        }
        ui_post_redraw(0x11a);
        goto LAB_0301592e;
      }
      uVar18 = 0;
      if (puVar22[2] == 0) {
LAB_03015a5c:
        FUN_03014e98(uVar18);
        goto LAB_0301592e;
      }
LAB_03015a22:
      if (*(uint *)(DAT_03015de0 + 0x10) < 2) {
        if (puVar22[1] == 6) {
          if (puVar22[2] == 0) {
            FUN_03014c1a(0x85,0);
          }
          else {
            ui_post_redraw(0xae);
          }
          if (puVar22[2] != 1) {
            ui_post_redraw(0xaf);
            uVar18 = 0xac;
            goto LAB_03015a7a;
          }
          FUN_03014af2(0x85,0);
        }
        else {
          ui_post_redraw(0xae);
          ui_post_redraw(0xac);
          ui_post_redraw(0xaf);
        }
      }
      else {
        ui_post_redraw(0xae);
        ui_post_redraw(0xac);
        uVar18 = 0xaf;
LAB_03015a7a:
        ui_post_redraw(uVar18);
      }
    }
    uVar12 = 0;
    if (*puVar22 != 0) {
      local_2c = iVar11 - 1;
      iVar14 = iVar11 + 1;
      local_48 = iVar13 + 0x1c;
      sVar2 = (short)local_48;
      local_30 = (int)(short)(local_60 + -0x20 + sVar2);
      sVar20 = sVar1 + 5;
      sVar3 = sVar1 + 0xb;
      do {
        uVar8 = puVar22[2];
        if (*puVar22 <= uVar8) {
          uVar8 = 0;
          puVar22[2] = 0;
        }
        sVar9 = (short)uVar12;
        if ((uVar8 == uVar12) && (iVar15 = ui_refresh_and_redraw(0x1dc), iVar15 == 0)) {
          if (uVar12 == 0) {
            FUN_02fffc76(local_2c & 0xffff,sVar1 + 4,0x17);
          }
          else {
            if (uVar12 == 5) {
              iVar21 = 0x8f;
              iVar15 = iVar14;
            }
            else {
              iVar21 = (int)(short)(sVar9 * 0x18 + 0x17);
              iVar15 = iVar11;
            }
            FUN_02fffc76(iVar15,sVar1 + 4,iVar21);
          }
          *DAT_03015de8 = *DAT_03015de4;
        }
        else {
          *DAT_030159bc = *DAT_030159c0;
        }
        if ((puVar22[6] == 0xff) || (*DAT_030159d4 == '\x04')) {
          sVar19 = sVar1 + 9;
          if (*(short *)(DAT_03015de0 + 2) == 0xfe) {
            if (*(uint *)(DAT_03015de0 + 0x10) < 2) {
              iVar15 = (int)(short)(sVar9 * 0x18 + 0x19);
              sVar9 = *(short *)(DAT_03015dec + (puVar22[1] + uVar12) * 4);
              if (puVar22[2] != uVar12) {
                sVar9 = sVar9 + 1;
              }
              sVar19 = 5;
              goto LAB_03015b34;
            }
            if (puVar22[2] == uVar12) {
              iVar15 = ui_refresh_and_redraw(0x1dc);
              goto joined_r0x03015b30;
            }
          }
          else if (puVar22[2] == uVar12) {
            iVar15 = ui_refresh_and_redraw(0x1dc);
joined_r0x03015b30:
            if (iVar15 == 0) {
              iVar15 = (int)(short)(sVar9 * 0x18 + 0x1c);
              sVar9 = 0xf4;
              goto LAB_03015b34;
            }
          }
          iVar15 = (int)(short)(sVar9 * 0x18 + 0x1c);
          sVar9 = 0xf5;
        }
        else {
          sVar19 = sVar20;
          if ((uint)puVar22[6] == puVar22[1] + uVar12) {
            if (*(char *)(DAT_03015ddc + 0x357) == 'U') {
              if (puVar22[2] == uVar12) {
                iVar15 = ui_refresh_and_redraw(0x1dc);
joined_r0x03015bf6:
                if (iVar15 == 0) {
                  iVar15 = (int)(short)(sVar9 * 0x18 + 0x1c);
                  sVar9 = 0x7c;
                  sVar19 = sVar3;
                  goto LAB_03015b34;
                }
              }
            }
            else {
              if (*(uint *)(DAT_03015de0 + 0x10) < 2) {
                if ((puVar22[2] == uVar12) && (iVar15 = ui_refresh_and_redraw(0x1dc), iVar15 == 0))
                {
                  if (5 < puVar22[1]) goto LAB_03015cac;
LAB_03015c98:
                  iVar15 = (int)(short)(sVar9 * 0x18 + 0x18);
                  sVar9 = *(short *)(DAT_03015df4 + uVar12 * 4);
                }
                else {
                  if (5 < puVar22[1]) goto LAB_03015cc2;
LAB_03015c56:
                  iVar15 = (int)(short)(sVar9 * 0x18 + 0x18);
                  sVar9 = *(short *)(DAT_03015df4 + uVar12 * 4) + 1;
                }
                goto LAB_03015b34;
              }
              if (puVar22[2] == uVar12) {
                iVar15 = ui_refresh_and_redraw(0x1dc);
                goto joined_r0x03015bf6;
              }
            }
            iVar15 = (int)(short)(sVar9 * 0x18 + 0x1c);
            sVar9 = 0x7d;
            sVar19 = sVar3;
          }
          else {
            if (*(char *)(DAT_03015ddc + 0x357) == 'U') {
              if (puVar22[2] == uVar12) {
                iVar15 = ui_refresh_and_redraw(0x1dc);
joined_r0x03015c80:
                if (iVar15 == 0) {
                  iVar15 = (int)(short)(sVar9 * 0x18 + 0x1c);
                  sVar9 = 0x83;
                  sVar19 = sVar3;
                  goto LAB_03015b34;
                }
              }
            }
            else {
              if (*(uint *)(DAT_03015de0 + 0x10) < 2) {
                if ((puVar22[2] == uVar12) && (iVar15 = ui_refresh_and_redraw(0x1dc), iVar15 == 0))
                {
                  if (puVar22[1] < 6) goto LAB_03015c98;
LAB_03015cac:
                  iVar15 = (int)(short)(sVar9 * 0x18 + 0x18);
                  sVar9 = *(short *)(DAT_03015df4 + uVar12 * 4 + 0x18);
                }
                else {
                  if (puVar22[1] < 6) goto LAB_03015c56;
LAB_03015cc2:
                  iVar15 = (int)(short)(sVar9 * 0x18 + 0x18);
                  sVar9 = *(short *)(DAT_03015df4 + uVar12 * 4 + 0x18) + 1;
                }
                goto LAB_03015b34;
              }
              if (puVar22[2] == uVar12) {
                iVar15 = ui_refresh_and_redraw(0x1dc);
                goto joined_r0x03015c80;
              }
            }
            iVar15 = (int)(short)(sVar9 * 0x18 + 0x1c);
            sVar9 = 0x84;
            sVar19 = sVar3;
          }
        }
LAB_03015b34:
        FUN_02fffc76(sVar9,sVar19,iVar15);
        local_54 = uVar12 * 0x18 + 0x1c;
        local_4e = (short)local_54;
        local_4c = (short)local_30;
        local_4a = local_4e + 0xf;
        local_50 = sVar2;
        if ((puVar22[2] == uVar12) && (iVar15 = ui_refresh_and_redraw(0x1dc), iVar15 == 0)) {
          FUN_02ffee7e(*(undefined2 *)
                        (*(int *)(puVar22 + 8) + ((uint)puVar22[2] + (uint)puVar22[1]) * 2 + 0x10),
                       DAT_03015df8,0x50);
          *DAT_03015de8 = *DAT_03015de4;
          uVar16 = FUN_02ffe06a(DAT_03015df8);
          local_44 = (int)local_4c;
          uVar17 = (uint)local_50;
          if (uVar16 < local_44 - uVar17) {
            ui_post_redraw(0x154);
            FUN_02ffefd8(local_48,local_54 & 0xffff,local_4c - local_50,0x10,0,
                         *(undefined2 *)(*(int *)(puVar22 + 8) + (puVar22[1] + uVar12) * 2 + 0x10));
          }
          else {
            if (*(uint *)(DAT_03015de0 + 0x10) < 2) {
              local_58 = local_50;
              local_56 = local_4e;
              local_54 = CONCAT22(local_4e + 0xf,local_4c);
              FUN_02ffec6c(&local_58,CONCAT22(local_4e,local_50),0x100000,uVar17 & 0xffff0000 | 0x8d
                           ,DAT_03015df8,0x1e);
            }
            else {
              local_58 = local_50;
              local_56 = local_4e;
              local_54 = CONCAT22(local_4e + 0xf,local_4c);
              FUN_02ffec6c(&local_58,CONCAT22(local_4e,local_50),0x100000,uVar17 & 0xffff0000 | 0x8c
                           ,DAT_03015df8,0x1e);
            }
            FUN_02ffe3dc(&local_50,&local_50,DAT_030161f8,0);
            func_0x030037a8(0x154);
          }
        }
        else {
          *DAT_03015de8 = *DAT_03015df0;
          FUN_02ffefd8(local_48,local_54 & 0xffff,local_4c - local_50,0x10,0,
                       *(undefined2 *)(*(int *)(puVar22 + 8) + (puVar22[1] + uVar12) * 2 + 0x10));
        }
        uVar12 = uVar12 + 1 & 0xffff;
      } while (uVar12 < *puVar22);
    }
    iVar14 = DAT_03015de0;
    if (*(int *)(DAT_03015de0 + 0x14) == 7) {
      if ((*(short *)(DAT_03015de0 + 2) == 0xfe) && (1 < *(uint *)(DAT_03015de0 + 0x10))) {
        FUN_02fffc76(0xdb,0x94,0x49);
        goto LAB_03015e60;
      }
    }
    else {
LAB_03015e60:
      uVar12 = *(uint *)(iVar14 + 0x14);
      bVar23 = uVar12 == 6;
      if (bVar23) {
        uVar12 = (uint)*(ushort *)(iVar14 + 2);
      }
      if ((bVar23 && uVar12 == 0xfe) && (1 < *(uint *)(iVar14 + 0x10))) {
        FUN_02fffc76(0x10f,0x8a,0x61);
      }
    }
    FUN_02fff2ce(1);
    func_0x030037a8(0xcc);
  }
  iVar14 = func_0x030037c4(0xce);
  if (iVar14 == 0) goto LAB_030166e0;
  iVar13 = iVar13 + 0x1c;
  sVar2 = (short)iVar13;
  sVar3 = sVar2 + local_60 + -0x20;
  local_50 = sVar2;
  local_4c = sVar3;
  iVar14 = ui_refresh_and_redraw(0x1dc);
  if (iVar14 != 0) {
    *DAT_03016200 = *DAT_030161fc;
    FUN_02fff812(0x7a,0,0,0,0x14);
    FUN_02fff2ce(1);
    if (*(short *)(DAT_03016204 + 2) == 0xfe) {
      FUN_02ffefd8(0,3,0x140,0x10,2,1);
    }
    else {
      FUN_02ffefd8(0,3,0x140,0x10,2,0x128);
    }
  }
  uVar8 = *puVar22;
  if (uVar8 <= puVar22[3]) {
    puVar22[3] = 1;
    puVar22[2] = 0;
  }
  uVar10 = puVar22[2];
  if (uVar10 < uVar8) {
    if (puVar22[3] == uVar10) {
      if (puVar22[3] == 0) {
        uVar10 = uVar10 + 1;
        goto LAB_03015f14;
      }
      puVar22[3] = 0;
    }
  }
  else {
    puVar22[2] = 0;
    uVar10 = 1;
LAB_03015f14:
    puVar22[3] = uVar10;
  }
  if (uVar8 == 1) {
    puVar22[3] = 0;
    puVar22[2] = 0;
  }
  if ((puVar22[6] == 0xff) || (*DAT_03016208 == '\x04')) {
    iVar14 = (int)(short)(puVar22[3] * 0x18 + 0x17);
    local_50 = sVar2;
    local_4c = sVar3;
    FUN_02fff9c8(0x7a,sVar1,iVar14,sVar1,iVar14,local_60,0x19);
    if (*(short *)(DAT_03016204 + 2) != 0xfe) {
      sVar20 = sVar1 + 9;
      FUN_02fffc76(0xf5,sVar20,(int)(short)(puVar22[3] * 0x18 + 0x1c));
      iVar14 = ui_refresh_and_redraw(0x1dc);
      if (iVar14 == 0) {
        uVar8 = puVar22[2];
        if (uVar8 == 0) {
          FUN_02fffc76(iVar11 - 1U & 0xffff,sVar1 + 4,0x17);
        }
        else {
          if (uVar8 == 5) {
            iVar14 = 0x8f;
            iVar11 = iVar11 + 1;
          }
          else {
            iVar14 = (int)(short)(uVar8 * 0x18 + 0x17);
          }
          FUN_02fffc76(iVar11,sVar1 + 4,iVar14);
        }
        uVar8 = puVar22[2];
LAB_03016258:
        sVar20 = sVar1 + 9;
        iVar11 = (int)(short)(uVar8 * 0x18 + 0x1c);
        sVar9 = 0xf4;
      }
      else {
        iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x17);
        FUN_02fff9c8(0x7a,sVar1,iVar11,sVar1,iVar11,local_60,0x19);
        iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x1c);
        sVar9 = 0xf5;
      }
      goto LAB_0301617a;
    }
    uVar8 = puVar22[2];
    if (uVar8 == 0) {
      FUN_02fffc76(iVar11 - 1U & 0xffff,sVar1 + 4,0x17);
    }
    else {
      if (uVar8 == 5) {
        iVar14 = 0x8f;
        iVar11 = iVar11 + 1;
      }
      else {
        iVar14 = (int)(short)(uVar8 * 0x18 + 0x17);
      }
      FUN_02fffc76(iVar11,sVar1 + 4,iVar14);
    }
    iVar11 = DAT_03016214;
    if (*(uint *)(DAT_03016204 + 0x10) < 2) {
      FUN_02fffc76(*(undefined2 *)(DAT_03016214 + ((uint)puVar22[1] + (uint)puVar22[2]) * 4),5,
                   (int)(short)(puVar22[2] * 0x18 + 0x19));
      sVar9 = *(short *)(iVar11 + ((uint)puVar22[1] + (uint)puVar22[3]) * 4) + 1;
      iVar11 = (int)(short)(puVar22[3] * 0x18 + 0x19);
      sVar20 = 5;
      goto LAB_0301617a;
    }
    FUN_02fffc76(0xf5,sVar1 + 9,(int)(short)(puVar22[3] * 0x18 + 0x1c));
    iVar11 = ui_refresh_and_redraw(0x1dc);
    if (iVar11 == 0) {
      uVar8 = puVar22[2];
      goto LAB_03016258;
    }
    iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x17);
    FUN_02fff9c8(0x7a,sVar1,iVar11,sVar1,iVar11,local_60,0x19);
    FUN_02fffc76(0xf5,sVar1 + 9,(int)(short)(puVar22[2] * 0x18 + 0x1c));
  }
  else {
    iVar14 = (int)(short)(puVar22[3] * 0x18 + 0x17);
    FUN_02fff9c8(0x7a,sVar1,iVar14,sVar1,iVar14,local_60,0x19);
    if ((uint)puVar22[1] + (uint)puVar22[2] == (uint)puVar22[6]) {
      iVar14 = ui_refresh_and_redraw(0x1dc);
      if (iVar14 == 0) {
        uVar8 = puVar22[2];
        if (uVar8 == 0) {
          FUN_02fffc76(iVar11 - 1U & 0xffff,sVar1 + 4,0x17);
        }
        else {
          if (uVar8 == 5) {
            iVar14 = 0x8f;
            iVar11 = iVar11 + 1;
          }
          else {
            iVar14 = (int)(short)(uVar8 * 0x18 + 0x17);
          }
          FUN_02fffc76(iVar11,sVar1 + 4,iVar14);
        }
        if ((*(char *)(DAT_0301668c + 0x357) == 'U') || (1 < *(uint *)(DAT_03016690 + 0x10))) {
          sVar20 = sVar1 + 0xb;
          FUN_02fffc76(0x84,sVar20,(int)(short)(puVar22[3] * 0x18 + 0x1c));
          iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x1c);
          sVar9 = 0x7c;
        }
        else {
          uVar8 = puVar22[2];
          iVar11 = (int)(short)(uVar8 * 0x18 + 0x18);
          if (puVar22[1] < 6) {
            FUN_02fffc76(*(undefined2 *)(DAT_03016688 + (uint)uVar8 * 4),sVar1 + 5,iVar11);
          }
          else {
            FUN_02fffc76(*(undefined2 *)(DAT_03016688 + (uint)uVar8 * 4 + 0x18),sVar1 + 5,iVar11);
          }
          uVar8 = puVar22[3];
          iVar11 = (int)(short)(uVar8 * 0x18 + 0x18);
          if (puVar22[1] < 6) {
            sVar9 = *(short *)(DAT_03016688 + (uint)uVar8 * 4) + 1;
            sVar20 = sVar1 + 5;
          }
          else {
            sVar9 = *(short *)(DAT_03016688 + (uint)uVar8 * 4 + 0x18) + 1;
            sVar20 = sVar1 + 5;
          }
        }
      }
      else {
        iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x17);
        FUN_02fff9c8(0x7a,sVar1,iVar11,sVar1,iVar11,local_60,0x19);
        if ((*(char *)(DAT_0301620c + 0x357) != 'U') && (*(uint *)(DAT_03016204 + 0x10) < 2)) {
          uVar8 = puVar22[3];
          iVar11 = (int)(short)(uVar8 * 0x18 + 0x18);
          if (puVar22[1] < 6) {
            FUN_02fffc76(*(short *)(DAT_03016210 + (uint)uVar8 * 4) + 1,sVar1 + 5,iVar11);
          }
          else {
            FUN_02fffc76(*(short *)(DAT_03016210 + (uint)uVar8 * 4 + 0x18) + 1,sVar1 + 5,iVar11);
          }
          uVar8 = puVar22[1];
          goto joined_r0x03016494;
        }
        sVar20 = sVar1 + 0xb;
        FUN_02fffc76(0x84,sVar20,(int)(short)(puVar22[3] * 0x18 + 0x1c));
        iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x1c);
        sVar9 = 0x7d;
      }
    }
    else {
      if ((uint)puVar22[1] + (uint)puVar22[3] == (uint)puVar22[6]) {
        iVar14 = ui_refresh_and_redraw(0x1dc);
        if (iVar14 == 0) {
          uVar8 = puVar22[2];
          if (uVar8 == 0) {
            FUN_02fffc76(iVar11 - 1U & 0xffff,sVar1 + 4,0x17);
          }
          else {
            if (uVar8 == 5) {
              iVar14 = 0x8f;
              iVar11 = iVar11 + 1;
            }
            else {
              iVar14 = (int)(short)(uVar8 * 0x18 + 0x17);
            }
            FUN_02fffc76(iVar11,sVar1 + 4,iVar14);
          }
        }
        else {
          iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x17);
          FUN_02fff9c8(0x7a,sVar1,iVar11,sVar1,iVar11,local_60,0x19);
        }
        if (*(char *)(DAT_0301668c + 0x357) != 'U') {
          if (*(uint *)(DAT_03016690 + 0x10) < 2) {
            uVar8 = puVar22[3];
            iVar11 = (int)(short)(uVar8 * 0x18 + 0x18);
            if (puVar22[1] < 6) {
              FUN_02fffc76(*(short *)(DAT_03016688 + (uint)uVar8 * 4) + 1,sVar1 + 5,iVar11);
            }
            else {
              FUN_02fffc76(*(short *)(DAT_03016688 + (uint)uVar8 * 4 + 0x18) + 1,sVar1 + 5,iVar11);
            }
            uVar8 = puVar22[1];
joined_r0x03016494:
            if (uVar8 < 6) {
              iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x18);
              sVar9 = *(short *)(DAT_03016688 + (uint)puVar22[2] * 4);
              sVar20 = sVar1 + 5;
            }
            else {
              iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x18);
              sVar20 = sVar1 + 5;
              sVar9 = *(short *)(DAT_03016688 + (uint)puVar22[2] * 4 + 0x18);
            }
          }
          else {
            FUN_02fffc76(0x7d,sVar1 + 0xb,(int)(short)(puVar22[3] * 0x18 + 0x1c));
            iVar11 = ui_refresh_and_redraw(0x1dc);
            if (iVar11 == 0) goto LAB_030164d8;
LAB_030165ea:
            sVar20 = sVar1 + 0xb;
            iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x1c);
            sVar9 = 0x84;
          }
          goto LAB_0301617a;
        }
        uVar8 = puVar22[3];
        uVar18 = 0x7d;
LAB_030165a0:
        FUN_02fffc76(uVar18,sVar1 + 0xb,(int)(short)(uVar8 * 0x18 + 0x1c));
      }
      else {
        iVar14 = ui_refresh_and_redraw(0x1dc);
        if (iVar14 == 0) {
          uVar8 = puVar22[2];
          if (uVar8 == 0) {
            FUN_02fffc76(iVar11 - 1U & 0xffff,sVar1 + 4,0x17);
          }
          else {
            if (uVar8 == 5) {
              iVar14 = 0x8f;
              iVar11 = iVar11 + 1;
            }
            else {
              iVar14 = (int)(short)(uVar8 * 0x18 + 0x17);
            }
            FUN_02fffc76(iVar11,sVar1 + 4,iVar14);
          }
        }
        else {
          iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x17);
          FUN_02fff9c8(0x7a,sVar1,iVar11,sVar1,iVar11,local_60,0x19);
        }
        if (*(char *)(DAT_0301668c + 0x357) == 'U') {
          uVar8 = puVar22[3];
          uVar18 = 0x84;
          goto LAB_030165a0;
        }
        if (*(uint *)(DAT_03016690 + 0x10) < 2) {
          uVar8 = puVar22[3];
          iVar11 = (int)(short)(uVar8 * 0x18 + 0x18);
          if (puVar22[1] < 6) {
            FUN_02fffc76(*(short *)(DAT_03016688 + (uint)uVar8 * 4) + 1,sVar1 + 5,iVar11);
          }
          else {
            FUN_02fffc76(*(short *)(DAT_03016688 + (uint)uVar8 * 4 + 0x18) + 1,sVar1 + 5,iVar11);
          }
          uVar8 = puVar22[1];
          goto joined_r0x03016494;
        }
        FUN_02fffc76(0x84,sVar1 + 0xb,(int)(short)(puVar22[3] * 0x18 + 0x1c));
        iVar11 = ui_refresh_and_redraw(0x1dc);
        if (iVar11 != 0) goto LAB_030165ea;
      }
LAB_030164d8:
      sVar20 = sVar1 + 0xb;
      iVar11 = (int)(short)(puVar22[2] * 0x18 + 0x1c);
      sVar9 = 0x83;
    }
LAB_0301617a:
    FUN_02fffc76(sVar9,sVar20,iVar11);
  }
  puVar6 = DAT_03016218;
  puVar5 = DAT_03016200;
  *DAT_03016200 = *DAT_03016218;
  FUN_02ffefd8(iVar13,(uint)puVar22[3] * 0x18 + 0x1c & 0xffff,local_4c - local_50,0x10,0,
               *(undefined2 *)
                (*(int *)(puVar22 + 8) + ((uint)puVar22[1] + (uint)puVar22[3]) * 2 + 0x10));
  iVar11 = ui_refresh_and_redraw(0x1dc);
  puVar7 = DAT_03016694;
  if (iVar11 == 0) {
    *puVar5 = *DAT_03016694;
    FUN_02ffee7e(*(undefined2 *)
                  (*(int *)(puVar22 + 8) + ((uint)puVar22[1] + (uint)puVar22[2]) * 2 + 0x10),
                 DAT_03016698,0x50);
    local_4e = puVar22[2] * 0x18 + 0x1c;
    local_4a = puVar22[2] * 0x18 + 0x2b;
    local_50 = sVar2;
    local_4c = sVar3;
    uVar12 = FUN_02ffe06a(DAT_03016698);
    if (uVar12 < (uint)((int)local_4c - (int)local_50)) {
      ui_post_redraw(0x154);
      *puVar5 = *puVar7;
      FUN_02ffefd8(iVar13,(uint)puVar22[2] * 0x18 + 0x1c & 0xffff,local_4c - local_50,0x10,0,
                   *(undefined2 *)
                    (*(int *)(puVar22 + 8) + ((uint)puVar22[1] + (uint)puVar22[2]) * 2 + 0x10));
    }
    else {
      if (*(uint *)(DAT_03016690 + 0x10) < 2) {
        FUN_03014aa0(&local_50,0x8d,DAT_03016698,0x1e);
      }
      else {
        FUN_03014aa0(&local_50,0x8c,DAT_03016698,0x1e);
      }
      FUN_02ffe3dc(&local_50,&local_50,DAT_03016698,0);
      func_0x030037a8(0x154);
    }
  }
  else {
    *puVar5 = *puVar6;
    FUN_02ffefd8(iVar13,(uint)puVar22[2] * 0x18 + 0x1c & 0xffff,local_4c - local_50,0x10,0,
                 *(undefined2 *)
                  (*(int *)(puVar22 + 8) + ((uint)puVar22[1] + (uint)puVar22[2]) * 2 + 0x10));
  }
  *puVar5 = *puVar6;
LAB_030166e0:
  iVar11 = ui_refresh_and_redraw(0x154);
  if ((iVar11 != 0) && (iVar11 = ui_refresh_and_redraw(0x1dc), puVar5 = DAT_03016af4, iVar11 == 0))
  {
    *DAT_03016af4 = *DAT_03016af0;
    puVar5[1] = 0xbdf7;
    FUN_02ffeb44(DAT_03016af8);
    func_0x030037a8(0x3e);
  }
  FUN_02ffef2c(local_40);
  puVar5 = DAT_03016af4;
  DAT_03016af4[1] = (short)local_38;
  *puVar5 = (short)local_34;
  FUN_02ffef08(local_3c);
  return;
}


