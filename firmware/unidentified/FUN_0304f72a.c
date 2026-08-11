/**
 * FUN_0304f72a @ 0x0304f72a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0304f72a(undefined4 *param_1,byte *param_2,byte *param_3,int *param_4)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_d0 [64];
  undefined1 auStack_90 [4];
  undefined4 uStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  undefined4 auStack_78 [2];
  undefined4 local_70;
  byte *pbStack_6c;
  undefined4 local_68;
  undefined1 *puStack_64;
  undefined4 *puStack_60;
  int *piStack_5c;
  int *piStack_58;
  int *piStack_54;
  int *piStack_50;
  undefined4 *puStack_4c;
  byte *pbStack_48;
  undefined4 uStack_44;
  undefined1 auStack_40 [4];
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  int local_30;
  int local_2c;
  
  if (param_1 != (undefined4 *)0x0 && param_2 != (byte *)0x0) {
    FUN_0301a35c(auStack_d0,0x60);
    FUN_0304ec42(*param_1,0);
    FUN_0304ee3a(*param_1,0);
    piVar1 = (int *)param_1[1];
    local_2c = 0;
    if (piVar1 == (int *)0x0) {
      local_30 = -1;
    }
    else {
      local_30 = piVar1[2];
      if (*piVar1 == local_30) {
        local_2c = 1;
      }
      else if (piVar1[1] == local_30) {
        local_2c = 2;
      }
    }
    if (local_2c == 1) {
      iVar6 = 1;
      FUN_0304fdf2(local_30);
    }
    else if (local_2c == 2) {
      iVar6 = 2;
    }
    else if (local_2c == 3) {
      iVar6 = 3;
    }
    else {
      iVar6 = 0;
    }
    pbStack_6c = (byte *)0x7fffffff;
    if (param_1[1] != 0) {
      local_70 = 0;
      local_68 = 0;
      pbStack_6c = param_2;
      pbStack_6c = (byte *)FUN_0304fe5c(*(undefined4 *)(param_1[1] + 8),*param_1,&local_70);
    }
    if (pbStack_6c == (byte *)0x7fffffff) {
      return 3;
    }
    pbVar2 = param_3;
    if (param_3 != (byte *)0x0) {
      while( true ) {
        uVar7 = (uint)*param_2;
        uVar5 = (uint)*pbVar2;
        if (uVar7 - 0x41 < 0x1a) {
          uVar7 = uVar7 + 0x20 & 0xff;
        }
        if (uVar5 - 0x41 < 0x1a) {
          uVar5 = uVar5 + 0x20 & 0xff;
        }
        if (uVar7 == 0xd || uVar7 == 10) {
          uVar7 = 0;
        }
        if (uVar5 == 0xd || uVar5 == 10) {
          uVar7 = 0;
        }
        if ((uVar7 != uVar5) || (uVar7 == 0)) break;
        param_2 = param_2 + 1;
        pbVar2 = pbVar2 + 1;
      }
    }
    if (iVar6 == 1) {
      puStack_64 = auStack_90;
      puStack_60 = &uStack_8c;
      piStack_5c = &iStack_88;
      piStack_58 = &iStack_84;
      piStack_54 = &iStack_80;
      piStack_50 = &iStack_7c;
      puStack_4c = auStack_78;
      uStack_44 = 0x40;
      local_70 = 1;
      pbStack_48 = param_3;
      iVar6 = dict_build_frame_index(local_30,*param_1,&local_70);
      if (iVar6 == 0) {
        FUN_03033618(s_no_match_0304f8e4);
        return 3;
      }
      iVar3 = FUN_0304fe12(local_30);
      auStack_40[0] = 3;
      uStack_38 = iVar3 << 8 | 1;
      uStack_3c = 4;
      uStack_34 = auStack_78[0];
      FUN_0304f550(*param_1,auStack_40);
      FUN_0304ec42(*param_1,uStack_8c);
      FUN_0304ee3a(*param_1,iStack_80 + iStack_7c + iStack_88 + iStack_84);
      *param_4 = iStack_88 + iStack_84 + iStack_80 + iStack_7c;
      if (iVar6 == 1) {
        uVar4 = 4;
      }
      else {
        uVar4 = 0;
      }
      return uVar4;
    }
  }
  return 1;
}


