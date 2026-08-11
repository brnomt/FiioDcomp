/**
 * FUN_030afad8 @ 0x030afad8
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030afad8(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int local_18;
  
  local_18 = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  buffered_fseek(param_1,8,1);
  uVar2 = buffered_fread(&local_18,1,4,param_1);
  iVar3 = DAT_030aff94;
  iVar1 = DAT_030afb60;
  if (uVar2 < 4) {
    return 0xfffffffb;
  }
  puVar5 = (uint *)(DAT_030afb60 + 0x70);
  if (local_18 == DAT_030afb6c) {
    *(undefined4 *)(DAT_030afb60 + 0x24) = 0;
    uVar4 = *(uint *)(iVar1 + 0x1c);
    *(uint *)(param_2 + 0xa0) = uVar4;
    *(undefined1 *)(param_2 + 0xd5) = 1;
    uVar2 = *(uint *)(iVar1 + 0x20);
    if (uVar2 == 0) {
      uVar2 = *puVar5;
      iVar3 = 0;
      if (uVar2 == 0) {
        iVar3 = *(int *)(iVar1 + 0x74);
      }
      if (uVar2 == 0 && iVar3 == 0) goto LAB_030afbf6;
      *(uint *)(param_2 + 0xb0) = uVar2;
      *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(iVar1 + 0x74);
      iVar3 = ((uVar2 - uVar4 * (uVar2 / uVar4)) * 1000) / uVar4 + (uVar2 / uVar4) * 1000;
    }
    else {
      *(uint *)(param_2 + 0xa8) = uVar2;
      iVar3 = ((uVar2 - uVar4 * (uVar2 / uVar4)) * 1000) / uVar4 + (uVar2 / uVar4) * 1000;
    }
    *(int *)(param_2 + 0xc0) = iVar3;
  }
  else if (local_18 == DAT_030aff94) {
    if (*(int *)(DAT_030afb60 + 0x24) == -1) {
      *(undefined4 *)(param_2 + 0xa4) = *(undefined4 *)(DAT_030afb60 + 0x1c);
      if (*(int *)(iVar1 + 0x20) == 0) {
        uVar2 = *puVar5;
        if (uVar2 == 0) {
          iVar3 = *(int *)(iVar1 + 0x74);
        }
        if (uVar2 != 0 || iVar3 != 0) {
          *(uint *)(param_2 + 0xb8) = uVar2;
          *(undefined4 *)(param_2 + 0xbc) = *(undefined4 *)(iVar1 + 0x74);
        }
      }
      else {
        *(int *)(param_2 + 0xac) = *(int *)(iVar1 + 0x20);
      }
    }
    *(undefined4 *)(iVar1 + 0x24) = 1;
    *(undefined1 *)(param_2 + 0xd4) = 1;
  }
  else {
    *(undefined4 *)(DAT_030afb60 + 0x24) = 2;
  }
LAB_030afbf6:
  buffered_fseek(param_1,param_3 + -0x14,1);
  return 0;
}


