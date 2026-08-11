/**
 * FUN_03012a44 @ 0x03012a44
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03012a44(void)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  int *piVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  uint extraout_r3;
  int iVar13;
  short sVar14;
  uint uVar15;
  undefined4 unaff_r7;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  undefined4 uVar19;
  uint local_88;
  undefined4 local_84;
  int local_80;
  uint local_7c;
  undefined4 local_78;
  short local_74;
  short local_72;
  ushort local_70 [3];
  short local_6a;
  undefined1 auStack_60 [4];
  short local_5c;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  
  puVar5 = DAT_03012e48;
  iVar13 = *DAT_03012e44;
  uVar15 = (uint)*(ushort *)((int)DAT_03012e44 + (uint)*(ushort *)(DAT_03012e44 + 0x73) * 2 + 0x1ce)
  ;
  local_3c = (uint)*DAT_03012e48;
  local_40 = (uint)DAT_03012e48[1];
  local_48 = FUN_02ffc718(1);
  local_44 = FUN_02ffc6f4(2);
  *puVar5 = *DAT_03012e4c;
  puVar5[1] = *DAT_03012e50;
  if (*(short *)(DAT_03012e54 + 0xc) == 0) {
    sVar14 = 0x85;
    local_7c = 0xbd;
    local_80 = 0x8a;
  }
  else {
    sVar14 = 0;
    local_7c = 0x85;
    local_80 = 0x87;
  }
  iVar7 = MediaLib_GetTotalFiles_d(0x26);
  if (((iVar7 != 0) || (iVar7 = MediaLib_GetTotalFiles_b(0x14d), iVar7 != 0)) ||
     (iVar7 = MediaLib_GetTotalFiles_b(0x2f), iVar7 != 0)) {
    FUN_02ffcfc6(0x7a);
    puVar5 = DAT_03012e48;
    *DAT_03012e48 = *DAT_03012e58;
    if (*(short *)(DAT_03012e54 + 0xc) == 0) {
      if (*(char *)(DAT_03012e5c + 0xe) == '\x02') {
        unaff_r7 = 0x50;
      }
      else if (*(char *)(DAT_03012e5c + 0xe) == '\x04') {
        unaff_r7 = 0x52;
      }
    }
    else {
      unaff_r7 = 3;
    }
    FUN_02ffc7c4(0,3,0x140,0x10,2,unaff_r7);
    *puVar5 = 0xffff;
    MediaLib_GetTotalFiles(0x14f);
    MediaLib_GetTotalFiles(0x1a9);
    MediaLib_GetTotalFiles_c(0x154);
    FUN_02ffcaba(1);
  }
  FUN_02ffcaba(0);
  iVar7 = MediaLib_GetTotalFiles_b(0x150);
  if (iVar7 != 0) {
    MediaLib_GetTotalFiles(0x3e);
    MediaLib_GetTotalFiles_c(0x154);
    FUN_02ffccca(0x6e,auStack_60);
    FUN_02ffccca(0x8c,local_70);
    if (*(short *)(DAT_03012e54 + 0xc) != 0) {
      uVar15 = 0;
    }
    local_28 = uVar15 + 6;
    if (uVar15 < local_28) {
      local_2c = (int)(short)((short)local_7c + 1);
      local_30 = (int)(short)(sVar14 + 0x1c);
      local_34 = local_80 - 1;
      local_38 = local_80 + 1;
      local_4c = (int)(short)((1 - (short)uVar15) * 0x18 + 0x18);
      local_50 = (int)sVar14;
      uVar16 = uVar15;
      do {
        uVar17 = uVar16 - uVar15;
        if (uVar17 == *(ushort *)(DAT_03012e44 + 0x7c) ||
            uVar17 == *(ushort *)((int)DAT_03012e44 + 0x1ee)) {
          sVar3 = (short)uVar17;
          sVar2 = sVar3 * 0x18 + 0x17;
          iVar7 = (int)sVar2;
          local_88 = 0x19;
          FUN_02ffd1b4(0x7a,local_50,iVar7,local_50,iVar7,local_2c);
          piVar4 = DAT_03012e44;
          local_74 = (short)local_30 + local_70[0];
          local_78 = CONCAT22(sVar2,(short)local_30);
          local_72 = sVar3 * 0x18 + 0x2f;
          uVar8 = (uint)*(ushort *)((int)DAT_03012e44 + 0x1ee);
          if (uVar17 == uVar8) {
            if (uVar8 == 0) {
              FUN_02ffd462(local_34 & 0xffff,sVar14 + 4,iVar7);
            }
            else {
              iVar9 = local_38;
              if (uVar8 != 5) {
                iVar9 = local_80;
              }
              FUN_02ffd462(iVar9,sVar14 + 4,iVar7);
            }
          }
          uVar8 = (uint)*(byte *)(iVar13 + 0x4e);
          bVar18 = uVar8 == 5;
          if (5 < uVar8) {
            uVar8 = 5;
          }
          if (bVar18) {
            uVar8 = 1;
          }
          uVar11 = (uint)*(ushort *)((int)piVar4 + 0x1ee);
          if (uVar17 == uVar11) {
            if (*(short *)(DAT_03012e54 + 0xc) == 0) {
              iVar9 = uVar8 + 0x74;
              iVar12 = (int)(short)(local_5c + sVar14);
              iVar7 = (int)(short)(sVar3 * 0x18 + 0x1c + local_6a);
            }
            else {
              iVar7 = (int)(short)(sVar3 * 0x18 + 0x18);
              iVar12 = 5;
              if (uVar11 == 1) {
                iVar9 = 0x130;
              }
              else {
                iVar9 = 0x12e;
              }
            }
          }
          else if (*(short *)(DAT_03012e54 + 0xc) == 0) {
            iVar7 = (int)(short)(sVar3 * 0x18 + 0x1c + local_6a);
            iVar9 = uVar8 + 0x6e;
            iVar12 = (int)(short)(local_5c + sVar14);
          }
          else if (uVar16 == 1) {
            iVar12 = 5;
            iVar9 = 0x12f;
            iVar7 = local_4c;
          }
          else {
            iVar12 = 5;
            iVar9 = 0x12d;
            iVar7 = (int)(short)(sVar3 * 0x18 + 0x18);
          }
          FUN_02ffd462(iVar9,iVar12,iVar7);
          if (uVar17 == *(ushort *)((int)piVar4 + 0x1ee)) {
            uVar17 = FUN_02ffb856(iVar13 + 0x70);
            *DAT_03012e48 = *DAT_03012e58;
            if (local_70[0] < uVar17) {
              *(int *)(DAT_03012e54 + 0x10) = iVar13 + 0x70;
              DAT_03012e48[1] = 0xbdf7;
              local_88 = CONCAT22(local_78._2_2_ + 5,(short)local_78);
              local_84 = CONCAT22(local_78._2_2_ + 0x14,local_74);
              FUN_02ffc458(&local_88,local_78,0x100005,extraout_r3 & 0xffff0000 | 0x8c,iVar13 + 0x70
                           ,0x1e);
              DAT_03012e48[1] = *DAT_03012e50;
              MediaLib_GetTotalFiles(0x154);
            }
            else {
              MediaLib_GetTotalFiles_c(0x154);
            }
          }
          else {
            *DAT_03012e48 = *DAT_03012e4c;
          }
          local_72 = local_78._2_2_;
          local_78 = CONCAT22(local_78._2_2_ + 5,(undefined2)local_78);
          local_72 = local_72 + 0x14;
          uVar10 = FUN_02ffc718(1);
          FUN_02ffbbc8(&local_78,&local_78,iVar13 + 0x70,0);
          FUN_02ffc718(uVar10);
        }
        uVar16 = uVar16 + 1 & 0xffff;
        iVar13 = *(int *)(iVar13 + 4);
      } while ((int)uVar16 < (int)local_28);
    }
    MediaLib_GetTotalFiles(0x153);
  }
  iVar7 = MediaLib_GetTotalFiles_b(0x14f);
  if (iVar7 != 0) {
    FUN_02ffccca(0x8c,local_70);
    FUN_02ffccca(0x6e,auStack_60);
    FUN_02ffcffe(0x7a,0,0,0x17,0x93);
    iVar7 = DAT_03012e54;
    if (*(short *)(DAT_03012e54 + 0xc) == 0) {
      if (*DAT_03012e60 == '\0') {
        FUN_02ffd462(0x12d,5,0x18);
        FUN_02ffd462(0x12f,5,0x30);
        iVar9 = DAT_03012e5c;
        if (*(char *)(DAT_03012e5c + 0xe) == '\x04') {
          *DAT_0301326c = *DAT_03013270;
        }
        else {
          FUN_02ffd462(0x86,4,0x17);
          FUN_02ffd462(0x12e,4,0x18);
          *DAT_0301326c = *DAT_03013268;
        }
        FUN_02ffc7c4(0x1c,0x1c,0x82,0x10,0,0x50);
        if (*(char *)(iVar9 + 0xe) == '\x04') {
          FUN_02ffd462(0x87,4,0x2f);
          FUN_02ffd462(0x130,5,0x30);
          *DAT_0301326c = *DAT_03013268;
        }
        else {
          *DAT_0301326c = *DAT_03013270;
        }
        uVar19 = 0x52;
        uVar10 = 0x34;
      }
      else {
        FUN_02ffd462(0x86,4,0x17);
        FUN_02ffd462(0x12e,4,0x18);
        *DAT_03012e48 = *DAT_03012e58;
        uVar19 = 0x50;
        uVar10 = 0x1c;
      }
      FUN_02ffc7c4(0x1c,uVar10,0x82,0x10,0,uVar19);
    }
    local_88 = 0x93;
    FUN_02ffd1b4(0x7a,sVar14,0x17,sVar14,0x17,(int)(short)local_7c);
    MediaLib_GetTotalFiles_c(0x154);
    uVar1 = *(ushort *)(DAT_03013274 + (uint)*(ushort *)(DAT_03013274 + 0x1cc) * 0x38 + 0xc);
    if (*(short *)(iVar7 + 0xc) != 0) {
      uVar1 = *(ushort *)(DAT_03013274 + 8);
      uVar15 = 0;
    }
    local_88 = (uint)uVar1;
    local_30 = (int)(short)(sVar14 + 0x1c);
    local_7c = local_80 - 1;
    local_84 = local_80 + 1;
    local_34 = (uint)(short)((1 - (short)uVar15) * 0x18 + 0x18);
    local_38 = uVar15 + 6;
    for (uVar16 = uVar15; ((int)uVar16 < local_38 && (uVar16 < local_88));
        uVar16 = uVar16 + 1 & 0xffff) {
      uVar17 = uVar16 - uVar15;
      sVar2 = (short)uVar17;
      local_78 = CONCAT22(sVar2 * 0x18 + 0x17,(short)local_30);
      local_74 = (short)local_30 + local_70[0];
      local_72 = sVar2 * 0x18 + 0x2f;
      if ((uVar17 == *(ushort *)(DAT_03013274 + 0x1ee)) &&
         (iVar7 = MediaLib_GetTotalFiles_d(0x1dc), iVar7 == 0)) {
        if (*(short *)(DAT_03013274 + 0x1ee) == 0) {
          FUN_02ffd462(local_7c & 0xffff,sVar14 + 4,(int)local_78._2_2_);
        }
        else {
          iVar7 = local_84;
          if (*(short *)(DAT_03013274 + 0x1ee) != 5) {
            iVar7 = local_80;
          }
          FUN_02ffd462(iVar7,sVar14 + 4,(int)local_78._2_2_);
        }
        uVar8 = FUN_02ffb856(iVar13 + 0x70);
        if (local_70[0] < uVar8) {
          *(int *)(DAT_03013278 + 0x10) = iVar13 + 0x70;
          puVar6 = DAT_0301326c;
          *DAT_0301326c = *DAT_03013268;
          puVar6[1] = 0xbdf7;
          local_50 = CONCAT22(local_78._2_2_ + 5,(short)local_78);
          local_4c = CONCAT22(local_78._2_2_ + 0x14,local_74);
          FUN_02ffc458(&local_50,local_78,0x100005,0x8c,iVar13 + 0x70,0x1e);
          DAT_0301326c[1] = *DAT_0301327c;
          MediaLib_GetTotalFiles(0x154);
        }
        else {
          *DAT_0301326c = *DAT_03013268;
          MediaLib_GetTotalFiles_c(0x154);
        }
      }
      else {
        *DAT_0301326c = *DAT_03013270;
      }
      iVar7 = DAT_03013274;
      uVar8 = (uint)*(byte *)(iVar13 + 0x4e);
      bVar18 = uVar8 == 5;
      if (5 < uVar8) {
        uVar8 = 5;
      }
      if (bVar18) {
        uVar8 = 1;
      }
      if ((uVar17 == *(ushort *)(DAT_03013274 + 0x1ee)) &&
         (iVar9 = MediaLib_GetTotalFiles_d(0x1dc), iVar9 == 0)) {
        if (*(short *)(DAT_03013278 + 0xc) == 0) {
          uVar17 = (uint)(short)(sVar2 * 0x18 + 0x1c + local_6a);
          iVar9 = (int)(short)(local_5c + sVar14);
          iVar7 = uVar8 + 0x74;
        }
        else {
          iVar9 = 5;
          uVar17 = (uint)(short)(sVar2 * 0x18 + 0x18);
          if (*(short *)(iVar7 + 0x1ee) == 1) {
            iVar7 = 0x130;
          }
          else {
            iVar7 = 0x12e;
          }
        }
      }
      else if (*(short *)(DAT_03013278 + 0xc) == 0) {
        uVar17 = (uint)(short)(sVar2 * 0x18 + 0x1c + local_6a);
        iVar9 = (int)(short)(local_5c + sVar14);
        iVar7 = uVar8 + 0x6e;
      }
      else if (uVar16 == 1) {
        iVar9 = 5;
        iVar7 = 0x12f;
        uVar17 = local_34;
      }
      else {
        iVar9 = 5;
        iVar7 = 0x12d;
        uVar17 = (int)(short)(sVar2 * 0x18 + 0x18);
      }
      FUN_02ffd462(iVar7,iVar9,uVar17);
      local_72 = local_78._2_2_;
      local_78 = CONCAT22(local_78._2_2_ + 5,(undefined2)local_78);
      local_72 = local_72 + 0x14;
      uVar10 = FUN_02ffc718(1);
      FUN_02ffbbc8(&local_78,&local_78,iVar13 + 0x70,0);
      FUN_02ffc718(uVar10);
      iVar13 = *(int *)(iVar13 + 4);
    }
    MediaLib_GetTotalFiles(0x153);
  }
  MediaLib_GetTotalFiles_b(0x21);
  iVar13 = MediaLib_GetTotalFiles_d(0x154);
  if ((iVar13 != 0) &&
     (iVar13 = MediaLib_GetTotalFiles_d(0x1dc), puVar6 = DAT_0301326c, iVar13 == 0)) {
    *DAT_0301326c = *DAT_03013268;
    puVar6[1] = 0xbdf7;
    FUN_02ffc330(*(undefined4 *)(DAT_03013278 + 0x10));
    MediaLib_GetTotalFiles(0x3e);
  }
  FUN_02ffc718(local_48);
  puVar6 = DAT_0301326c;
  DAT_0301326c[1] = (short)local_40;
  *puVar6 = (short)local_3c;
  FUN_02ffc6f4(local_44);
  return;
}


