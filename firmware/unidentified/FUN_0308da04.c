/**
 * FUN_0308da04 @ 0x0308da04
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

int FUN_0308da04(uint *param_1,int param_2,undefined4 param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  short sVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  bool bVar15;
  int aiStack_78 [7];
  byte *local_5c;
  int iStack_58;
  short sStack_54;
  short sStack_52;
  byte bStack_50;
  byte bStack_4f;
  byte bStack_4e;
  byte bStack_4d;
  byte bStack_4c;
  byte bStack_4b;
  byte bStack_4a;
  byte bStack_49;
  undefined1 auStack_48 [16];
  undefined4 auStack_38 [2];
  uint *puStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  
  iVar11 = 0;
  sVar8 = 0;
  local_5c = (byte *)0x0;
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  uVar13 = param_2 - 0x18;
  if (((0x11 < uVar13) &&
      (puStack_30 = param_1, iStack_2c = param_2, uStack_28 = param_3,
      iVar9 = wma_input_cache_read(param_1,param_2,*param_1,param_1[1]), iVar9 == 0x12)) &&
     (local_5c != (byte *)0x0)) {
    iStack_58 = (uint)*local_5c + (uint)local_5c[3] * 0x1000000 +
                (uint)local_5c[2] * 0x10000 + (uint)local_5c[1] * 0x100;
    sStack_54 = (ushort)local_5c[4] + (ushort)local_5c[5] * 0x100;
    sStack_52 = (ushort)local_5c[6] + (ushort)local_5c[7] * 0x100;
    bStack_50 = local_5c[8];
    bStack_4f = local_5c[9];
    bStack_4e = local_5c[10];
    bStack_4d = local_5c[0xb];
    bStack_4c = local_5c[0xc];
    bStack_4b = local_5c[0xd];
    bStack_4a = local_5c[0xe];
    bStack_49 = local_5c[0xf];
    local_5c = local_5c + 0x10;
    iVar9 = wma_memcmp(*DAT_0308dd94,&iStack_58,0x10);
    if (iVar9 == 0) {
      sVar5 = *(short *)local_5c;
      local_5c = local_5c + 2;
      if (sVar5 == 6) {
        if (((0x15 < uVar13) &&
            (iVar9 = wma_input_cache_read
                               (param_1,param_1[1],*param_1 + 0x12,
                                param_1[1] + (uint)(0xffffffed < *param_1)), puVar7 = DAT_0308dd9c,
            puVar6 = DAT_0308dd98, iVar9 == 4)) && (local_5c != (byte *)0x0)) {
          bVar4 = *local_5c;
          pbVar1 = local_5c + 3;
          pbVar2 = local_5c + 1;
          pbVar3 = local_5c + 2;
          local_5c = local_5c + 4;
          uVar12 = 0x16;
          uVar10 = (uint)bVar4 + (uint)*pbVar1 * 0x1000000 +
                   (uint)*pbVar3 * 0x10000 + (uint)*pbVar2 * 0x100;
          bVar14 = uVar10 == 0x18;
          if (0x17 < uVar10) {
            bVar14 = uVar13 == 0x16;
          }
          if ((0x17 < uVar10 && 0x15 < uVar13) && !bVar14) {
            do {
              iVar11 = FUN_0308ca7c(param_1,auStack_48,aiStack_78,uVar12);
              if (iVar11 != 0) {
                return iVar11;
              }
              iVar11 = wma_memcmp(*puVar6,auStack_48,0x10);
              if (iVar11 == 0) {
                sVar8 = sVar8 + 1;
                bVar15 = uVar13 <= aiStack_78[0] + uVar12;
                bVar14 = aiStack_78[0] + uVar12 == uVar13;
                if (!bVar15 || bVar14) {
                  bVar15 = sVar8 != 0;
                  bVar14 = sVar8 == 1;
                }
                if (bVar15 && !bVar14) {
                  iVar11 = 3;
                  break;
                }
                auStack_38[0] = 0;
                wma_input_cache_read
                          (param_1,auStack_38,*param_1 + uVar12 + 0x18,
                           (uint)(0xffffffe7 < uVar12) + param_1[1] +
                           (uint)CARRY4(*param_1,uVar12 + 0x18));
                uVar12 = uVar12 + aiStack_78[0];
              }
              else {
                iVar11 = wma_memcmp(*puVar7,auStack_48,0x10);
                if (iVar11 == 0) {
                  if (param_1[0xb] == 0 &&
                      (uint)(aiStack_78[0] + (uVar12 - 0x18) <= param_1[10]) <= param_1[0xb]) {
                    return 1;
                  }
                  iVar11 = FUN_0308d814(param_1,aiStack_78[0],uStack_28,uVar12);
                  uVar12 = uVar12 + aiStack_78[0];
                  if (iVar11 != 0) {
                    return iVar11;
                  }
                }
                else {
                  uVar12 = uVar12 + aiStack_78[0];
                }
              }
              iVar11 = 0;
            } while (uVar12 < uVar13);
          }
          uVar10 = *param_1;
          *param_1 = uVar10 + uVar13;
          param_1[1] = param_1[1] + (uint)CARRY4(uVar10,uVar13);
          return iVar11;
        }
      }
      else {
        uVar10 = *param_1;
        *param_1 = uVar10 + uVar13;
        param_1[1] = param_1[1] + (uint)CARRY4(uVar10,uVar13);
      }
    }
    else {
      uVar10 = *param_1;
      *param_1 = uVar10 + uVar13;
      param_1[1] = param_1[1] + (uint)CARRY4(uVar10,uVar13);
    }
  }
  return 3;
}


