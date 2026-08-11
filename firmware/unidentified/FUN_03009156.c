/**
 * FUN_03009156 @ 0x03009156
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03009156(undefined4 param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  undefined4 uVar5;
  ushort uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  
  puVar3 = DAT_03009498;
  uVar1 = *DAT_03009498;
  uVar2 = DAT_03009498[1];
  uVar7 = FUN_02ff2b38(1);
  uVar8 = FUN_02ff2b14(2);
  *puVar3 = 0xffff;
  puVar3[1] = 0xffff;
  iVar9 = FUN_02ff73d0(0x96);
  puVar4 = DAT_0300949c;
  if (iVar9 == 1) {
    iVar9 = FUN_02ff73d0(0xce);
    if (iVar9 == 0) {
      FUN_02ff407e(0,0x41,0xf0,0x115);
      FUN_02ff2be4(0,3,0x140,0x10,0,9);
      uVar5 = DAT_030094a4;
      if (-1 < param_2) {
        FUN_02ff3130(0,param_2 + 0x41U & 0xffff,0x140,1,0x10,DAT_030094a4);
      }
      FUN_02ff3130(0,param_2 + 0x6bU & 0xffff,0x140,1,0x10,uVar5);
      FUN_02ff3130(0,param_2 + 0x95U & 0xffff,0x140,1,0x10,uVar5);
      FUN_02ff3130(0,param_2 + 0xbfU & 0xffff,0x140,1,0x10,uVar5);
      FUN_02ff3130(0,param_2 + 0xe9U & 0xffff,0x140,1,0x10,uVar5);
      FUN_02ff3130(0,param_2 + 0x113U & 0xffff,0x140,1,0x10,uVar5);
      if (1 < *puVar4) {
        *puVar4 = 2;
      }
      uVar10 = 0;
      do {
        uVar6 = *puVar4;
        if (uVar10 == uVar6) {
          iVar9 = FUN_02ff73d0(0xce);
          if (iVar9 == 0) {
            *puVar3 = 0xffff;
          }
          else {
            *puVar3 = 0xf800;
          }
          FUN_02ff2be4(0x1c,param_2 + uVar10 * 0x18 + 0x1c & 0xffff,100,0x10,0,
                       *puVar4 + uVar10 + 0x1c & 0xffff);
        }
        else {
          *puVar3 = 0xffff;
          FUN_02ff2be4(0x1c,param_2 + uVar10 * 0x18 + 0x1c & 0xffff,100,0x10,0,
                       uVar6 + uVar10 + 0x1c & 0xffff);
        }
        uVar10 = uVar10 + 1 & 0xffff;
      } while (uVar10 < 5);
    }
    else {
      FUN_02ff73d0(0xce);
      *puVar3 = 0xf800;
      FUN_02ff2be4(0x1c,param_2 + ((uint)*puVar4 - (uint)*DAT_030094a0) * 0x18 + 0x1c & 0xffff,100,
                   0x10,0,*puVar4 + 0x1c & 0xffff);
    }
    if (param_3 != 0) {
      if (param_3 == 2) {
        if ((int)(short)((short)param_2 + 0x8f) - 0x17U < 0xfd) {
          *puVar3 = 0xffff;
          FUN_02ff2be4(0x1c,param_2 + 0x94U & 0xffff,100,0x10,0,*puVar4 + 0x21);
        }
      }
      else if ((param_3 == 1) && ((int)(short)((short)param_2 + -1) - 0x17U < 0xfd)) {
        *puVar3 = 0xffff;
        if (*puVar4 != 0) {
          FUN_02ff2be4(0x1c,param_2 + 4U & 0xffff,100,0x10,0,*puVar4 + 0x1b);
        }
      }
    }
    FUN_02ff341e(0x7a,0,0,0x1e,0x23);
    FUN_02ff341e(0x7a,0,0,0x114,0x29);
    *puVar3 = *DAT_030094a8;
    FUN_02ff2be4(0,3,0x140,0x10,0,9);
    *puVar3 = 0xffff;
    FUN_02ff73b4(0x9b);
  }
  iVar9 = FUN_02ff73d0(0x9b);
  if (iVar9 != 0) {
    uVar6 = *puVar4 + 1;
    if (6 < uVar6) {
      uVar6 = 7;
    }
    FUN_02ff2d04(uVar6);
  }
  FUN_02ff2b38(uVar7);
  puVar3[1] = uVar2;
  *puVar3 = uVar1;
  FUN_02ff2b14(uVar8);
  return;
}


