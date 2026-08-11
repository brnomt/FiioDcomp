/**
 * FUN_030b056e @ 0x030b056e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_030b056e(int param_1,int param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  int *local_48;
  undefined4 *puStack_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c [2];
  
  puVar8 = DAT_030b0810;
  pcVar3 = DAT_030b080c;
  uVar11 = *param_4;
  if (*DAT_030b080c != '\x04' && *DAT_030b080c != '\x03') goto joined_r0x030b063e;
  uVar14 = *(uint *)(param_2 + 200);
  sVar5 = *(short *)(param_2 + 0xc4);
  if ((uVar14 < 0xbb81) && (sVar5 == 1 || sVar5 == 2)) {
    iVar10 = *(int *)(param_2 + 0x38) + 7;
    *DAT_030b0810 = 0xff;
    puVar8[1] = 0xf1;
    if (uVar14 == 0x5622) {
      cVar4 = '\a';
    }
    else if ((int)uVar14 < 0x5623) {
      if (uVar14 == 8000) {
        cVar4 = '\v';
      }
      else if (uVar14 == 0x2b11) {
        cVar4 = '\n';
      }
      else if (uVar14 == 12000) {
        cVar4 = '\t';
      }
      else {
        if (uVar14 != 16000) goto LAB_030b062c;
        cVar4 = '\b';
      }
    }
    else if (uVar14 == 24000) {
      cVar4 = '\x06';
    }
    else if (uVar14 == 32000) {
      cVar4 = '\x05';
    }
    else if (uVar14 == 0xac44) {
      cVar4 = '\x04';
    }
    else {
      if (uVar14 != 48000) goto LAB_030b062c;
      cVar4 = '\x03';
    }
    puVar8[2] = cVar4 << 2 | 0x40;
    if (sVar5 == 2) {
      puVar8[3] = 0x80;
    }
    else {
      puVar8[3] = 0x40;
    }
    puVar8[4] = (char)((uint)(iVar10 * 0x200000) >> 0x18);
    puVar8[5] = (char)iVar10 * ' ' | 0x1f;
    puVar8[6] = 0xfc;
  }
LAB_030b062c:
  pcVar3[2] = '\x01';
  pcVar3[3] = '\0';
  *pcVar3 = '\x02';
  *(undefined4 *)(param_2 + 0x30) = 0;
joined_r0x030b063e:
  do {
    if (uVar11 == 0) goto LAB_030b079e;
    uVar14 = *(int *)(param_2 + 0x38) - *(int *)(param_2 + 0x30);
    if (uVar14 != 0) {
      iVar10 = (int)*(short *)(pcVar3 + 2);
      if (iVar10 < 8) {
        uVar13 = 8 - iVar10;
        if (uVar11 <= uVar13) {
          if (uVar11 != 0) {
            puVar8 = DAT_030b0810 + *(short *)(pcVar3 + 2) + -2;
            puVar9 = (undefined1 *)((*param_4 - uVar11) + param_3);
            puVar7 = puVar9 + -1;
            if ((uVar11 & 1) != 0) {
              puVar8 = DAT_030b0810 + *(short *)(pcVar3 + 2) + -1;
              *puVar9 = *puVar8;
              puVar7 = puVar9;
            }
            for (uVar14 = uVar11 >> 1; uVar14 != 0; uVar14 = uVar14 - 1) {
              puVar7[1] = puVar8[1];
              puVar8 = puVar8 + 2;
              puVar7 = puVar7 + 2;
              *puVar7 = *puVar8;
            }
          }
          sVar5 = *(short *)(pcVar3 + 2) + (short)uVar11;
          goto LAB_030b0a30;
        }
        if (0 < (int)uVar13) {
          puVar8 = DAT_030b0810 + iVar10 + -2;
          iVar6 = ((iVar10 + (*param_4 - uVar11)) - (int)(short)(*(short *)(pcVar3 + 2) + -1)) +
                  param_3;
          puVar7 = (undefined1 *)(iVar6 + -2);
          if ((uVar13 & 1) != 0) {
            puVar8 = DAT_030b0810 + iVar10 + -1;
            puVar7 = (undefined1 *)(iVar6 + -1);
            *puVar7 = *puVar8;
          }
          for (iVar10 = (int)uVar13 >> 1; iVar10 != 0; iVar10 = iVar10 + -1) {
            puVar7[1] = puVar8[1];
            puVar8 = puVar8 + 2;
            puVar7 = puVar7 + 2;
            *puVar7 = *puVar8;
          }
        }
        uVar11 = uVar11 - uVar13;
        pcVar3[2] = '\b';
        pcVar3[3] = '\0';
      }
      puVar12 = DAT_030b0814;
      iVar10 = (*(code *)*DAT_030b0814)(*(undefined4 *)(param_1 + 0x204));
      if (iVar10 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200)) !=
          *(int *)(param_2 + 0x34) + *(int *)(param_2 + 0x30)) {
        iVar10 = (*(code *)*puVar12)(*(undefined4 *)(param_1 + 0x204));
        buffered_fseek(param_1,(*(int *)(param_2 + 0x30) + *(int *)(param_2 + 0x34)) -
                               (iVar10 - ((uint)*(ushort *)(param_1 + 0x202) -
                                         (uint)*(ushort *)(param_1 + 0x200))),1);
      }
      iVar10 = (*param_4 + param_3) - uVar11;
      if (uVar11 <= uVar14) {
        uVar14 = buffered_fread(iVar10,1,uVar11,param_1);
        if (uVar14 < uVar11) {
          return 0xfffffffb;
        }
        *(uint *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + uVar11;
        goto LAB_030b079e;
      }
      uVar13 = buffered_fread(iVar10,1,uVar14,param_1);
      if (uVar13 < uVar14) {
        return 0xfffffffb;
      }
      uVar11 = uVar11 - uVar14;
      *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_2 + 0x38);
      goto joined_r0x030b063e;
    }
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c[0] = 0;
    if (*(uint *)(param_2 + 0x7c) <= *(uint *)(param_2 + 0x68)) {
      if (*param_4 == uVar11) {
        uVar11 = 0xfffffffe;
      }
      else {
        uVar11 = *param_4 - uVar11;
      }
      return uVar11;
    }
    *(uint *)(param_2 + 0x68) = *(uint *)(param_2 + 0x68) + 1;
    *(undefined4 *)(param_2 + 0x30) = 0;
    local_48 = &local_3c;
    FUN_030b033e(param_1,param_2,*(undefined4 *)(param_2 + 0x68),&local_40);
    iVar10 = local_40;
    puVar12 = *(undefined4 **)(pcVar3 + 0x3c);
    buffered_fseek(*puVar12,(local_40 - puVar12[2]) * 4 + -4,1);
    puVar12[2] = iVar10;
    buffered_fread(&local_48,1,4,*puVar12);
    puStack_44 = &local_30;
    uVar14 = (uint)local_48 >> 8;
    uVar13 = (uint)local_48 >> 0x10;
    uVar1 = (uint)local_48 >> 0x18;
    uVar2 = (int)local_48 << 0x18;
    local_48 = &local_34;
    FUN_030b03f0(param_1,param_2,&local_40,&local_38);
    local_2c[0] = local_34 + local_3c + -2;
    iVar10 = FUN_030b0272(param_1,param_2,&local_34,local_2c);
    *(uint *)(param_2 + 0x34) =
         (uVar2 | (uVar14 & 0xff) << 0x10 | (uVar13 & 0xff) << 8 | uVar1) + iVar10;
    iVar10 = *(int *)(param_2 + 0x68);
    if (param_2 == 0) {
      uVar14 = 0xffffffff;
    }
    else {
      uVar14 = *(uint *)(param_2 + 0x84);
      if (uVar14 == 0) {
        puVar12 = *(undefined4 **)(pcVar3 + 0x2c);
        buffered_fseek(*puVar12,(iVar10 - puVar12[2]) * 4 + -4,1);
        puVar12[2] = iVar10;
        buffered_fread(&local_48,1,4,*puVar12);
        uVar14 = (int)local_48 << 0x18 | ((uint)local_48 >> 8 & 0xff) << 0x10 |
                 ((uint)local_48 >> 0x10 & 0xff) << 8 | (uint)local_48 >> 0x18;
      }
    }
    *(uint *)(param_2 + 0x38) = uVar14;
    puVar8 = DAT_030b0c98;
    uVar13 = *(uint *)(param_2 + 200);
    sVar5 = *(short *)(param_2 + 0xc4);
    if ((uVar13 < 0xbb81) && (sVar5 == 1 || sVar5 == 2)) {
      *DAT_030b0c98 = 0xff;
      puVar8[1] = 0xf1;
      if (uVar13 == 0x5622) {
        cVar4 = '\a';
      }
      else if ((int)uVar13 < 0x5623) {
        if (uVar13 == 8000) {
          cVar4 = '\v';
        }
        else if (uVar13 == 0x2b11) {
          cVar4 = '\n';
        }
        else if (uVar13 == 12000) {
          cVar4 = '\t';
        }
        else {
          if (uVar13 != 16000) goto LAB_030b0938;
          cVar4 = '\b';
        }
      }
      else if (uVar13 == 24000) {
        cVar4 = '\x06';
      }
      else if (uVar13 == 32000) {
        cVar4 = '\x05';
      }
      else if (uVar13 == 0xac44) {
        cVar4 = '\x04';
      }
      else {
        if (uVar13 != 48000) goto LAB_030b0938;
        cVar4 = '\x03';
      }
      puVar8[2] = cVar4 << 2 | 0x40;
      if (sVar5 == 2) {
        puVar8[3] = 0x80;
      }
      else {
        puVar8[3] = 0x40;
      }
      puVar8[4] = (char)((uVar14 + 7) * 0x200000 >> 0x18);
      puVar8[5] = (char)(uVar14 + 7) * ' ' | 0x1f;
      puVar8[6] = 0xfc;
    }
LAB_030b0938:
    puVar8 = DAT_030b0c98;
    if (uVar11 < 8) {
      if (uVar11 != 0) {
        puVar9 = (undefined1 *)((*param_4 - uVar11) + param_3);
        puVar8 = DAT_030b0ca0;
        puVar7 = puVar9 + -1;
        if ((uVar11 & 1) != 0) {
          puVar8 = DAT_030b0ca0 + 1;
          *puVar9 = *puVar8;
          puVar7 = puVar9;
        }
        for (uVar14 = uVar11 >> 1; uVar14 != 0; uVar14 = uVar14 - 1) {
          puVar7[1] = puVar8[1];
          puVar8 = puVar8 + 2;
          puVar7 = puVar7 + 2;
          *puVar7 = *puVar8;
        }
      }
      sVar5 = (short)uVar11 + 1;
LAB_030b0a30:
      *(short *)(pcVar3 + 2) = sVar5;
LAB_030b079e:
      return *param_4;
    }
    puVar7 = (undefined1 *)((*param_4 - uVar11) + param_3);
    *puVar7 = *DAT_030b0c98;
    iVar10 = 3;
    do {
      puVar7[1] = puVar8[1];
      puVar8 = puVar8 + 2;
      puVar7 = puVar7 + 2;
      *puVar7 = *puVar8;
      puVar12 = DAT_030b0c9c;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    uVar11 = uVar11 - 7;
    pcVar3[2] = '\b';
    pcVar3[3] = '\0';
    iVar10 = (*(code *)*puVar12)(*(undefined4 *)(param_1 + 0x204));
    if (iVar10 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200)) !=
        *(int *)(param_2 + 0x34) + *(int *)(param_2 + 0x30)) {
      iVar10 = (*(code *)*puVar12)(*(undefined4 *)(param_1 + 0x204));
      buffered_fseek(param_1,(*(int *)(param_2 + 0x34) + *(int *)(param_2 + 0x30)) -
                             (iVar10 - ((uint)*(ushort *)(param_1 + 0x202) -
                                       (uint)*(ushort *)(param_1 + 0x200))),1);
    }
    iVar10 = (*param_4 + param_3) - uVar11;
    if (uVar11 <= *(uint *)(param_2 + 0x38)) {
      uVar14 = buffered_fread(iVar10,1,uVar11,param_1);
      if (uVar14 < uVar11) {
        return 0xfffffffb;
      }
      *(uint *)(param_2 + 0x30) = uVar11;
      goto LAB_030b079e;
    }
    uVar14 = buffered_fread(iVar10,1,*(uint *)(param_2 + 0x38),param_1);
    uVar13 = *(uint *)(param_2 + 0x38);
    if (uVar14 < uVar13) {
      return 0xfffffffb;
    }
    uVar11 = uVar11 - uVar13;
    *(uint *)(param_2 + 0x30) = uVar13;
  } while( true );
}


