/**
 * FUN_03014e98 @ 0x03014e98
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03014e98(int param_1)

{
  ushort *puVar1;
  undefined2 *puVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint local_60;
  undefined4 local_5c;
  undefined1 auStack_58 [16];
  undefined1 auStack_48 [16];
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  
  puVar1 = DAT_03014ef0;
  local_2c = (uint)*DAT_03014ef0;
  local_38 = (uint)DAT_03014ef0[1];
  local_34 = FUN_02ffef2c(1);
  local_30 = FUN_02ffef08(2);
  *puVar1 = *DAT_03014ef4;
  puVar1[1] = *DAT_03014ef8;
  FUN_02fff4de(0x8c,auStack_58);
  FUN_02fff4de(0x9e,auStack_48);
  if (param_1 == 3) {
LAB_03015148:
    local_60 = 2;
  }
  else {
    if (param_1 != 0) {
      if (param_1 == 2) goto LAB_03015148;
      if (param_1 != 4) goto LAB_0301511a;
    }
    local_60 = 3;
  }
LAB_0301511a:
  uVar6 = 0;
  local_5c = 0x8e;
  do {
    if (local_60 <= uVar6) break;
    sVar3 = (short)uVar6;
    uVar4 = 0x90;
    if (param_1 == 3) {
      if (*(byte *)(DAT_03015560 + 0x35e) == uVar6) {
LAB_03015210:
        iVar5 = (int)(short)(sVar3 * 0x18 + 0x1c);
        sVar3 = 0x7d;
        goto LAB_03015190;
      }
      FUN_02fffc76(0x84,0x90,(int)(short)(sVar3 * 0x18 + 0x1c));
    }
    else {
      if (param_1 == 0) {
        iVar5 = (int)(short)(sVar3 * 0x18 + 0x1c);
        sVar3 = *(short *)(DAT_03015564 + uVar6 * 4) + 1;
        uVar4 = local_5c;
      }
      else {
        if (param_1 != 2 && param_1 != 4) goto LAB_030151a6;
        iVar5 = *(int *)(DAT_03015568 + 0x14);
        if (iVar5 == 6) {
          if (*(byte *)(DAT_03015560 + 0x34c) == uVar6) {
            uVar4 = 0x7d;
          }
          else {
            uVar4 = 0x84;
          }
          FUN_02fffc76(uVar4,0x90,(int)(short)(sVar3 * 0x18 + 0x1c));
          iVar5 = 0x61;
          sVar3 = 0x10f;
          uVar4 = 0x8a;
        }
        else if (iVar5 == 7) {
          if (*(byte *)(DAT_03015560 + 0x35a) == uVar6) {
            uVar4 = 0x7d;
          }
          else {
            uVar4 = 0x84;
          }
          FUN_02fffc76(uVar4,0x90,(int)(short)(sVar3 * 0x18 + 0x1c));
          iVar5 = 0x49;
          sVar3 = 0xdb;
          uVar4 = 0x94;
        }
        else {
          if (iVar5 != 8) goto LAB_030151a6;
          if (*(byte *)(DAT_03015560 + 0x35c) == uVar6) goto LAB_03015210;
          iVar5 = (int)(short)(sVar3 * 0x18 + 0x1c);
          sVar3 = 0x84;
        }
      }
LAB_03015190:
      FUN_02fffc76(sVar3,uVar4,iVar5);
    }
LAB_030151a6:
    *DAT_03015570 = *DAT_0301556c;
    if (param_1 == 3) {
      FUN_02ffefd8(0xa1,uVar6 * 0x18 + 0x1c & 0xffff,0x121,0x10,0,
                   *(undefined2 *)(DAT_03015574 + uVar6 * 4 + 2));
    }
    else if (param_1 == 0) {
      FUN_02ffefd8(0xa1,uVar6 * 0x18 + 0x1c & 0xffff,0x121,0x10,0,
                   *(undefined2 *)(DAT_03015564 + uVar6 * 4 + 2));
    }
    else if (param_1 == 2 || param_1 == 4) {
      iVar5 = *(int *)(DAT_03015568 + 0x14);
      if (iVar5 == 6) {
        FUN_02ffefd8(0xa1,uVar6 * 0x18 + 0x1c & 0xffff,0x121,0x10,0,
                     *(undefined2 *)(DAT_03015578 + uVar6 * 4 + 2));
      }
      else if (iVar5 == 7) {
        FUN_02ffefd8(0xa1,uVar6 * 0x18 + 0x1c & 0xffff,0x121,0x10,0,
                     *(undefined2 *)(DAT_0301557c + uVar6 * 4 + 2));
      }
      else if (iVar5 == 8) {
        FUN_02ffefd8(0xa1,uVar6 * 0x18 + 0x1c & 0xffff,0x121,0x10,0,
                     *(undefined2 *)(DAT_03015580 + uVar6 * 4 + 2));
      }
    }
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 6);
  FUN_02ffef2c(local_34);
  puVar2 = DAT_03015570;
  DAT_03015570[1] = (short)local_38;
  *puVar2 = (short)local_2c;
  FUN_02ffef08(local_30);
  return;
}


