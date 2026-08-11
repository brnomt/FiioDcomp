/**
 * FUN_0308d546 @ 0x0308d546
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_0308d546(uint *param_1,uint param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  uint local_28;
  uint uStack_24;
  byte *local_20;
  
  psVar3 = DAT_0308d96c;
  local_20 = (byte *)0x0;
  local_28 = *param_1;
  uStack_24 = param_1[1];
  uVar5 = (local_28 + param_2) - 0x18;
  uVar6 = uStack_24 + CARRY4(local_28,param_2) + -1 + (uint)(0x17 < local_28 + param_2);
  iVar4 = 0;
  if (param_1[0x32] == 0) {
    param_1[0x32] = (uint)DAT_0308d96c;
    psVar3[0] = 0;
    psVar3[1] = 0;
    psVar3[2] = 0;
    psVar3[3] = 0;
    psVar3[4] = 0;
    psVar3[5] = 0;
    psVar3[6] = 0;
    psVar3[7] = 0;
    psVar3[8] = 0;
    psVar3[9] = 0;
    psVar3[10] = 0;
    psVar3[0xb] = 0;
    psVar3[0xc] = 0;
    psVar3[0xd] = 0;
    psVar3[0xe] = 0;
    psVar3[0xf] = 0;
    uVar7 = uStack_24 + (0xfffffff5 < local_28);
    if (uVar7 < uVar6 || uVar6 - uVar7 < (uint)(local_28 + 10 <= uVar5)) {
      iVar4 = wma_input_cache_read(param_1);
      if (iVar4 == 10) {
        bVar8 = 0xfffffff5 < local_28;
        local_28 = local_28 + 10;
        uStack_24 = uStack_24 + bVar8;
        *psVar3 = (ushort)*local_20 + (ushort)local_20[1] * 0x100;
        psVar3[1] = (ushort)local_20[2] + (ushort)local_20[3] * 0x100;
        psVar3[2] = (ushort)local_20[4] + (ushort)local_20[5] * 0x100;
        psVar3[3] = (ushort)local_20[6] + (ushort)local_20[7] * 0x100;
        pbVar1 = local_20 + 8;
        pbVar2 = local_20 + 9;
        local_20 = local_20 + 10;
        psVar3[4] = (ushort)*pbVar1 + (ushort)*pbVar2 * 0x100;
        *DAT_0308d970 = 0;
        iVar4 = GetSysReservedNextPage(param_1,&local_28,uVar5,uVar6,psVar3,psVar3 + 6);
        if ((((iVar4 == 0) &&
             (iVar4 = GetSysReservedNextPage(param_1,&local_28,uVar5,uVar6,psVar3 + 1,psVar3 + 8),
             iVar4 == 0)) &&
            (iVar4 = GetSysReservedNextPage(param_1,&local_28,uVar5,uVar6,psVar3 + 2,psVar3 + 10),
            iVar4 == 0)) &&
           (iVar4 = GetSysReservedNextPage(param_1,&local_28,uVar5,uVar6,psVar3 + 3,psVar3 + 0xc),
           iVar4 == 0)) {
          iVar4 = GetSysReservedNextPage(param_1,&local_28,uVar5,uVar6,psVar3 + 4,psVar3 + 0xe);
        }
      }
      else {
        iVar4 = 3;
      }
    }
    else {
      iVar4 = 6;
    }
  }
  *param_1 = uVar5;
  param_1[1] = uVar6;
  return iVar4;
}


