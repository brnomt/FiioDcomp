/**
 * FUN_030a41be @ 0x030a41be
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030a41be(int param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_b8 [32];
  undefined1 auStack_98 [32];
  undefined1 auStack_78 [32];
  undefined1 auStack_58 [32];
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  int iStack_30;
  uint local_2c;
  uint uStack_28;
  
  puVar2 = DAT_030a453c;
  puVar1 = DAT_030a4534;
  uVar7 = 4;
  iStack_30 = param_1;
  local_2c = param_2;
  uStack_28 = param_3;
  if (4 < param_2) {
    do {
      (*(code *)*DAT_030a4538)(*(undefined4 *)(param_1 + 0x8214),0,*puVar1);
      iVar3 = (*(code *)*puVar2)(param_1 + 8,8,*puVar1);
      if (iVar3 != 8) {
        return 0;
      }
      local_38 = *(undefined1 *)(param_1 + 8);
      local_37 = *(undefined1 *)(param_1 + 9);
      local_36 = *(undefined1 *)(param_1 + 10);
      local_35 = *(undefined1 *)(param_1 + 0xb);
      uVar6 = (uint)*(byte *)(param_1 + 0xc) | *(int *)(param_1 + 0xd) << 8;
      *(int *)(param_1 + 0x8214) = *(int *)(param_1 + 0x8214) + 8;
      if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
        uVar6 = uVar6 + 1;
      }
      uVar7 = uVar7 + uVar6 + 8;
      uVar5 = param_3;
      if (uVar6 <= param_3) {
        uVar5 = uVar6;
      }
      iVar3 = FUN_0309f6e8(DAT_030a4544,&local_38,4);
      if (iVar3 == 0) {
        uVar4 = (*(code *)*puVar2)(auStack_b8,uVar5,*puVar1);
joined_r0x030a429c:
        if (uVar4 != uVar5) {
          return 0;
        }
      }
      else {
        iVar3 = FUN_0309f6e8(DAT_030a4548,&local_38,4);
        if (iVar3 == 0) {
          uVar4 = (*(code *)*puVar2)(auStack_98,uVar5,*puVar1);
          goto joined_r0x030a429c;
        }
        iVar3 = FUN_0309f6e8(DAT_030a454c,&local_38,4);
        if (iVar3 == 0) {
          uVar4 = (*(code *)*puVar2)(auStack_78,uVar5,*puVar1);
          goto joined_r0x030a429c;
        }
        iVar3 = FUN_0309f6e8(DAT_030a4550,&local_38,4);
        if (iVar3 == 0) {
          uVar4 = (*(code *)*puVar2)(auStack_58,uVar5,*puVar1);
          goto joined_r0x030a429c;
        }
      }
      *(uint *)(param_1 + 0x8214) = *(int *)(param_1 + 0x8214) + uVar6;
    } while (uVar7 < local_2c);
  }
  return 1;
}


