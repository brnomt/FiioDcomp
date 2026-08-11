/**
 * FUN_0308f364 @ 0x0308f364
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0308f364(ushort *param_1,uint *param_2,ushort *param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  uint unaff_lr;
  bool bVar6;
  bool bVar7;
  
  uVar4 = 0;
  if (param_1 == (ushort *)0x0 || param_2 == (uint *)0x0) {
    return DAT_0308f6b4;
  }
  uVar3 = (uint)*param_1;
  if ((uVar3 - 0x160 < 4) && ((uVar3 != 0x163 || (*(uint *)(param_1 + 2) == *param_2)))) {
    if (uVar3 < 0x162) {
      uVar2 = *(uint *)(param_1 + 2);
      bVar7 = 47999 < uVar2;
      bVar6 = uVar2 == 48000;
      if (uVar2 < 0xbb81) {
        bVar7 = 1 < param_1[1];
        bVar6 = param_1[1] == 2;
      }
      if (!bVar7 || bVar6) {
        bVar6 = param_1[7] == 0x10;
      }
      if (!bVar6) {
        return DAT_0308f6b8;
      }
    }
    else {
      if (0x20 < param_1[1]) {
        return DAT_0308f6b8;
      }
      if (uVar3 == 0x162 || uVar3 == 0x163) {
        return DAT_0308f6b8;
      }
    }
    uVar2 = *(uint *)(param_1 + 2);
    if (uVar2 != 0) {
      unaff_lr = (uint)param_1[1];
    }
    if (((uVar2 != 0 && unaff_lr != 0) && ((char)param_2[5] == '\0')) &&
       (uVar5 = param_2[4], uVar5 == 2 || uVar5 == 3)) {
      if ((param_2[3] == 0x10) && (uVar5 != 2)) {
        return DAT_0308f6b4;
      }
      uVar1 = param_1[7];
      if (((uVar1 == 0x10 || uVar1 == 0x14) || (uVar1 == 0x18 || uVar1 == 0x20)) &&
         (param_2[3] + 7 >> 3 <= uVar5)) {
        if ((*(uint *)(param_1 + 4) & 0x80000000) != 0) {
          return DAT_0308f6b4;
        }
        if (param_1[6] == 0) {
          return DAT_0308f6b4;
        }
        if ((param_2[1] == unaff_lr) && (param_2[2] == *(uint *)(param_1 + 8))) {
          if (param_3 != (ushort *)0x0) {
            if (2 < param_3[0xc]) {
              return DAT_0308f6b8;
            }
            uVar4 = *param_3;
          }
          uVar5 = *param_2;
          if ((uVar4 & 8) != 0) {
            uVar2 = uVar2 << 1;
          }
          if ((uVar4 & 2) != 0) {
            uVar2 = uVar2 >> 1;
          }
          if (uVar2 == uVar5) {
            return 0;
          }
          if (uVar3 != 0x163) {
            if (uVar5 < uVar2) {
              if (uVar2 <= uVar5 * 4) {
                return 0;
              }
            }
            else if (uVar5 <= uVar2 * 6) {
              return 0;
            }
          }
        }
      }
    }
  }
  return DAT_0308f6b8;
}


