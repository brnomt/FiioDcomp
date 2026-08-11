/**
 * FUN_030c415a @ 0x030c415a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030c415a(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint local_30;
  int local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  
  iVar5 = *(int *)(param_1 + 0x1c);
  iVar4 = 0;
  piVar6 = (int *)*param_2;
  iVar3 = *(int *)(iVar5 + 8);
  memset_byte(&local_30,0,0x18);
  local_1c = 0;
  local_2c = *piVar6 + piVar6[1];
  local_28 = piVar6[2];
  local_24 = piVar6;
  uVar1 = local_30;
  iVar2 = local_28 - ((int)local_30 >> 3);
  do {
    local_30 = uVar1;
    if (0 < iVar2) {
LAB_030c41e0:
      local_20 = piVar6;
      iVar2 = sbuf_read_bits(&local_30,1);
      if (iVar2 != 0) {
        return 0xffffff79;
      }
      for (; 1 < iVar3; iVar3 = iVar3 >> 1) {
        iVar4 = iVar4 + 1;
      }
      iVar4 = sbuf_read_bits(&local_30,iVar4);
      if (iVar4 == -1) {
        return 0xffffff78;
      }
      return *(undefined4 *)(iVar5 + (uint)*(byte *)(*(int *)(iVar5 + 0x1c) + iVar4 * 2) * 4);
    }
    local_30 = uVar1 & 7;
    local_28 = local_28 - ((int)uVar1 >> 3);
    if (local_24[3] == 0) {
      if (local_28 * 8 < (int)local_30) {
        local_28 = -1;
      }
      goto LAB_030c41e0;
    }
    local_1c = local_1c + local_24[2];
    local_24 = (int *)local_24[3];
    if (0 < local_24[2] + local_28) {
      local_2c = (*local_24 + local_24[1]) - local_28;
    }
    local_28 = local_24[2] + local_28;
    uVar1 = local_30;
    iVar2 = local_28;
  } while( true );
}


