/**
 * FUN_030af182 @ 0x030af182
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_030af182(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint local_30;
  uint local_2c;
  uint local_28 [2];
  
  local_2c = 0;
  local_30 = 0;
  local_28[0] = 0;
  if ((param_1 != 0) && (param_2 == 0)) {
    return 0xffffffff;
  }
  buffered_fseek(param_1,4,1);
  uVar3 = buffered_fread(&local_2c,1,4,param_1);
  iVar1 = DAT_030af644;
  if (uVar3 < 4) {
    return 0xfffffffb;
  }
  local_2c = local_2c << 0x18 | (local_2c >> 8 & 0xff) << 0x10 | (local_2c >> 0x10 & 0xff) << 8 |
             local_2c >> 0x18;
  if (*(int *)(DAT_030af644 + 0x24) == 0) {
    *(uint *)(param_2 + 0x88) = local_2c;
  }
  else if (*(int *)(DAT_030af644 + 0x24) == 1) {
    *(uint *)(param_2 + 0x84) = local_2c;
  }
  uVar3 = buffered_fread(&local_30,1,4,param_1);
  piVar2 = DAT_030af648;
  if (3 < uVar3) {
    local_30 = local_30 << 0x18 | (local_30 >> 8 & 0xff) << 0x10 | (local_30 >> 0x10 & 0xff) << 8 |
               local_30 >> 0x18;
    uVar3 = local_30;
    if (*(int *)(iVar1 + 0x24) == 0) {
      for (; uVar3 != 0; uVar3 = uVar3 - 1) {
        uVar4 = buffered_fread(local_28,1,4,param_1);
        if (uVar4 < 4) {
          return 0xfffffffb;
        }
        local_28[0] = local_28[0] << 0x18 | (local_28[0] >> 8 & 0xff) << 0x10 |
                      (local_28[0] >> 0x10 & 0xff) << 8 | local_28[0] >> 0x18;
        *piVar2 = local_28[0] + *piVar2;
      }
      hifi_debug_printf_ovl(s_vidiosamplesum____d_030af64c,*piVar2);
      buffered_fseek(param_1,local_30 * -4,1);
    }
    puVar6 = DAT_030af660;
    if (*(int *)(iVar1 + 0x24) == 0) {
      *(uint *)(param_2 + 0x80) = local_30;
      if (*(int *)(param_2 + 0x88) != 0) {
        return 0;
      }
      iVar5 = (*(code *)*puVar6)(*(undefined4 *)(param_1 + 0x204));
      puVar6 = *(undefined4 **)(iVar1 + 0x28);
      iVar5 = iVar5 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200));
    }
    else {
      if (*(int *)(iVar1 + 0x24) != 1) {
        buffered_fseek(param_1,param_3 + -0x14,1);
        return 0;
      }
      *(uint *)(param_2 + 0x7c) = local_30;
      if (*(int *)(param_2 + 0x84) != 0) {
        return 0;
      }
      iVar5 = (*(code *)*puVar6)(*(undefined4 *)(param_1 + 0x204));
      puVar6 = *(undefined4 **)(iVar1 + 0x2c);
      iVar5 = iVar5 - ((uint)*(ushort *)(param_1 + 0x202) - (uint)*(ushort *)(param_1 + 0x200));
    }
    if (puVar6 != (undefined4 *)0x0) {
      puVar6[1] = iVar5;
      buffered_fseek(*puVar6,iVar5,0);
      puVar6[2] = 0;
    }
    buffered_fseek(param_1,local_30 << 2,1);
    return 0;
  }
  return 0xfffffffb;
}


