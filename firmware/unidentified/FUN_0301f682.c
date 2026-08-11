/**
 * FUN_0301f682 @ 0x0301f682
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


uint FUN_0301f682(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  uint local_28 [4];
  
  uVar1 = param_1[3];
  if ((int)uVar1 < 1) {
    uVar1 = (*param_1 >> (uVar1 & 0xff)) << (uVar1 & 0xff);
  }
  else {
    uVar1 = param_1[1] >> (0x20 - uVar1 & 0xff) | *param_1 << (uVar1 & 0xff);
  }
  if (uVar1 >> 0x19 == 3) {
    uVar7 = (uVar1 & 0x1ffffff) >> 0x17;
    if (2 < uVar7) {
      *param_3 = (uVar1 & 0x7fffff) >> 0x16;
      *param_2 = (uVar1 & 0x3fffff) >> 0x10;
      uVar7 = param_1[3];
      param_1[3] = uVar7 + 0x1e;
      if (0x1f < uVar7 + 0x1e) {
        *param_1 = param_1[1];
        if ((param_1[6] < 5) && (param_1[8] != 1)) {
          FUN_0301e7dc(param_1);
        }
        puVar3 = (uint *)param_1[4];
        param_1[4] = (uint)(puVar3 + 1);
        uVar7 = *puVar3;
        param_1[6] = param_1[6] - 4;
        param_1[1] = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                     uVar7 >> 0x18;
        param_1[3] = param_1[3] - 0x20;
      }
      return (int)(uVar1 << 0x11) >> 0x14;
    }
    local_28[0] = *DAT_0301f8ac;
    local_28[1] = DAT_0301f8ac[1];
    local_28[2] = DAT_0301f8ac[2];
    uVar2 = local_28[uVar7];
    uVar1 = (uVar1 << 7) << (uVar2 & 0xff);
    pbVar5 = (byte *)(DAT_0301f8a8 + (uVar1 >> 0x16) * 4);
    if (*pbVar5 == 0xff) {
      pbVar5 = (byte *)(DAT_0301f8a8 +
                       (((uVar1 & 0x3fffff) >> 0x14) + (int)*(short *)(pbVar5 + 2)) * 4);
    }
    uVar6 = (uint)pbVar5[3];
    if (uVar6 != 0) {
      *param_3 = (uint)pbVar5[1];
      uVar4 = (uint)pbVar5[2];
      *param_2 = uVar4;
      if (uVar7 < 2) {
        uVar6 = uVar6 + *(byte *)(uVar4 + DAT_0301f8b0 + *param_3 * 0x40);
      }
      else {
        *param_2 = uVar4 + *(byte *)(DAT_0301f8b4 + *param_3 * 0x40 + uVar6) + 1;
      }
      uVar7 = *pbVar5 + uVar2 + 8 + param_1[3];
      param_1[3] = uVar7;
      if (0x1f < uVar7) {
        *param_1 = param_1[1];
        if ((param_1[6] < 5) && (param_1[8] != 1)) {
          FUN_0301e7dc(param_1);
        }
        puVar3 = (uint *)param_1[4];
        param_1[4] = (uint)(puVar3 + 1);
        uVar7 = *puVar3;
        param_1[6] = param_1[6] - 4;
        param_1[1] = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                     uVar7 >> 0x18;
        param_1[3] = param_1[3] - 0x20;
      }
      if ((uVar1 >> (0x1f - *pbVar5 & 0xff) & 1) != 0) {
        uVar6 = -uVar6;
      }
      return uVar6;
    }
  }
  else {
    pbVar5 = (byte *)(DAT_0301f8a8 + (uVar1 >> 0x16) * 4);
    if (*pbVar5 == 0xff) {
      pbVar5 = (byte *)(DAT_0301f8a8 +
                       (((uVar1 & 0x3fffff) >> 0x14) + (int)*(short *)(pbVar5 + 2)) * 4);
    }
    uVar7 = (uint)pbVar5[3];
    if (uVar7 != 0) {
      *param_3 = (uint)pbVar5[1];
      *param_2 = (uint)pbVar5[2];
      uVar2 = *pbVar5 + 1 + param_1[3];
      param_1[3] = uVar2;
      if (0x1f < uVar2) {
        *param_1 = param_1[1];
        if ((param_1[6] < 5) && (param_1[8] != 1)) {
          FUN_0301e7dc(param_1);
        }
        puVar3 = (uint *)param_1[4];
        param_1[4] = (uint)(puVar3 + 1);
        uVar2 = *puVar3;
        param_1[6] = param_1[6] - 4;
        param_1[1] = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                     uVar2 >> 0x18;
        param_1[3] = param_1[3] - 0x20;
      }
      if ((uVar1 >> (0x1f - *pbVar5 & 0xff) & 1) != 0) {
        uVar7 = -uVar7;
      }
      return uVar7;
    }
  }
  *param_2 = 0x40;
  return 0;
}


