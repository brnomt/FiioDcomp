/**
 * FUN_0308e278 @ 0x0308e278
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308e278(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  short sVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar7 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  FUN_03083faa(param_1 + 0xac,param_3,param_2);
  FUN_03083f5c(param_1 + 0xac,0x18,&local_40);
  FUN_0308fd1e(param_1 + 0x1b0,&local_30);
  *(undefined4 *)(param_1 + 0x230) = local_40;
  *(undefined4 *)(param_1 + 0x234) = local_3c;
  *(undefined4 *)(param_1 + 0x238) = local_38;
  *(undefined4 *)(param_1 + 0x23c) = local_34;
  do {
    local_40 = *(undefined4 *)(param_1 + 0x230);
    local_3c = *(undefined4 *)(param_1 + 0x234);
    uVar8 = *(undefined4 *)(param_1 + 0x238);
    uVar9 = *(undefined4 *)(param_1 + 0x23c);
    pbVar2 = (byte *)((int)param_4 + uVar7);
    local_38._0_1_ = (byte)uVar8;
    pbVar5 = (byte *)((int)&local_50 + uVar7);
    local_38._0_1_ = (byte)local_38 ^ *pbVar2;
    local_38._1_1_ = (byte)((uint)uVar8 >> 8);
    local_38._1_1_ = local_38._1_1_ ^ pbVar2[1];
    local_38._2_1_ = (byte)((uint)uVar8 >> 0x10);
    local_38._2_1_ = local_38._2_1_ ^ pbVar2[2];
    local_38._3_1_ = (byte)((uint)uVar8 >> 0x18);
    local_38 = CONCAT13(local_38._3_1_ ^ pbVar2[3],CONCAT12(local_38._2_1_,(undefined2)local_38));
    local_34._0_1_ = (byte)uVar9;
    local_34._0_1_ = (byte)local_34 ^ pbVar2[4];
    local_34._1_1_ = (byte)((uint)uVar9 >> 8);
    local_34._1_1_ = local_34._1_1_ ^ pbVar2[5];
    local_34._2_1_ = (byte)((uint)uVar9 >> 0x10);
    local_34._2_1_ = local_34._2_1_ ^ pbVar2[6];
    local_34._3_1_ = (byte)((uint)uVar9 >> 0x18);
    local_34 = CONCAT13(local_34._3_1_ ^ pbVar2[7],CONCAT12(local_34._2_1_,(undefined2)local_34));
    FUN_030840d6(pbVar5,&local_38,param_1 + 0x1b0,0);
    *pbVar5 = (byte)local_40 ^ *pbVar5;
    *(byte *)((int)&local_50 + uVar7 + 1) = *(byte *)((int)&local_50 + uVar7 + 1) ^ local_40._1_1_;
    *(byte *)((int)&local_50 + uVar7 + 2) = *(byte *)((int)&local_50 + uVar7 + 2) ^ local_40._2_1_;
    *(byte *)((int)&local_50 + uVar7 + 3) = *(byte *)((int)&local_50 + uVar7 + 3) ^ local_40._3_1_;
    *(byte *)((int)&local_4c + uVar7) = *(byte *)((int)&local_4c + uVar7) ^ (byte)local_3c;
    *(byte *)((int)&local_4c + uVar7 + 1) = *(byte *)((int)&local_4c + uVar7 + 1) ^ local_3c._1_1_;
    *(byte *)((int)&local_4c + uVar7 + 2) = *(byte *)((int)&local_4c + uVar7 + 2) ^ local_3c._2_1_;
    *(byte *)((int)&local_4c + uVar7 + 3) = *(byte *)((int)&local_4c + uVar7 + 3) ^ local_3c._3_1_;
    uVar7 = uVar7 + 8 & 0xffff;
  } while (uVar7 < 0x10);
  uVar7 = local_50 & 0xff;
  iVar3 = (int)&local_50 + 1;
  if (uVar7 < 0x11) {
    uVar4 = 0xf - uVar7 & 0xffff;
    if (uVar4 <= uVar7) {
      uVar7 = uVar4;
    }
    uVar4 = (uint)(short)uVar7;
    pbVar2 = (byte *)((local_50 & 0xff) + iVar3);
    if (0 < (int)uVar4) {
      pbVar5 = (byte *)((int)&local_50 + (local_50 & 0xff));
      if ((uVar4 & 1) != 0) {
        *pbVar2 = ~*pbVar2;
        pbVar5 = pbVar2;
      }
      for (iVar6 = (int)uVar4 >> 1; iVar6 != 0; iVar6 = iVar6 + -1) {
        pbVar5[1] = ~pbVar5[1];
        pbVar2 = pbVar5 + 2;
        pbVar5 = pbVar5 + 2;
        *pbVar5 = ~*pbVar2;
      }
    }
    sVar1 = wma_memcmp(iVar3,(local_50 & 0xff) + iVar3,uVar7);
    if (sVar1 == 0) {
      *param_4 = local_50;
      param_4[1] = local_4c;
      param_4[2] = local_48;
      param_4[3] = local_44;
      return 0;
    }
  }
  return 9;
}


