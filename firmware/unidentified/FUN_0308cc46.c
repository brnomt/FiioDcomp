/**
 * FUN_0308cc46 @ 0x0308cc46
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0308cc46(uint *param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  byte bVar20;
  byte bVar21;
  byte bVar22;
  byte bVar23;
  byte bVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  undefined8 uVar32;
  int local_28;
  
  local_28 = 0;
  if (param_1 == (uint *)0x0) {
    return 2;
  }
  uVar29 = param_2 - 0x18;
  if ((0x4f < uVar29) &&
     (iVar27 = wma_input_cache_read(param_1,&local_28,*param_1,param_1[1]), iVar27 == 0x50)) {
    pbVar1 = (byte *)(local_28 + 0x25);
    uVar28 = (uint)*(byte *)(local_28 + 0x20) + (uint)*(byte *)(local_28 + 0x23) * 0x1000000 +
             (uint)*(byte *)(local_28 + 0x22) * 0x10000 + (uint)*(byte *)(local_28 + 0x21) * 0x100;
    pbVar10 = (byte *)(local_28 + 0x24);
    pbVar11 = (byte *)(local_28 + 0x27);
    pbVar12 = (byte *)(local_28 + 0x26);
    bVar23 = *(byte *)(local_28 + 0x28);
    bVar13 = *(byte *)(local_28 + 0x2b);
    bVar14 = *(byte *)(local_28 + 0x29);
    bVar15 = *(byte *)(local_28 + 0x2a);
    bVar16 = *(byte *)(local_28 + 0x34);
    bVar17 = *(byte *)(local_28 + 0x37);
    bVar19 = *(byte *)(local_28 + 0x35);
    bVar18 = *(byte *)(local_28 + 0x36);
    uVar30 = (uint)*(byte *)(local_28 + 0x38) + (uint)*(byte *)(local_28 + 0x3b) * 0x1000000 +
             (uint)*(byte *)(local_28 + 0x3a) * 0x10000 + (uint)*(byte *)(local_28 + 0x39) * 0x100;
    bVar24 = *(byte *)(local_28 + 0x40);
    bVar20 = *(byte *)(local_28 + 0x43);
    bVar21 = *(byte *)(local_28 + 0x41);
    bVar22 = *(byte *)(local_28 + 0x42);
    pbVar8 = (byte *)(local_28 + 0x44);
    pbVar2 = (byte *)(local_28 + 0x47);
    pbVar3 = (byte *)(local_28 + 0x45);
    pbVar4 = (byte *)(local_28 + 0x46);
    pbVar9 = (byte *)(local_28 + 0x48);
    pbVar5 = (byte *)(local_28 + 0x4b);
    pbVar6 = (byte *)(local_28 + 0x49);
    pbVar7 = (byte *)(local_28 + 0x4a);
    local_28 = local_28 + 0x50;
    uVar31 = (uint)*pbVar9 + (uint)*pbVar5 * 0x1000000 +
             (uint)*pbVar7 * 0x10000 + (uint)*pbVar6 * 0x100;
    if (((uint)*pbVar8 + (uint)*pbVar2 * 0x1000000 + (uint)*pbVar4 * 0x10000 + (uint)*pbVar3 * 0x100
         == uVar31) &&
       (uVar28 != 0 ||
        (uint)*pbVar10 + (uint)*pbVar11 * 0x1000000 +
        (uint)*pbVar12 * 0x10000 + (uint)*pbVar1 * 0x100 != 0)) {
      param_1[5] = uVar31;
      param_1[7] = uVar28;
      uVar26 = DAT_0308d32c;
      uVar25 = DAT_0308d328;
      FUN_03082c0c((uint)bVar16 + (uint)bVar17 * 0x1000000 +
                   (uint)bVar18 * 0x10000 + (uint)bVar19 * 0x100);
      uVar32 = FUN_03082cc4();
      FUN_03082a0a((int)uVar32,(int)((ulonglong)uVar32 >> 0x20),uVar25,uVar26);
      iVar27 = FUN_03082c92();
      param_1[0xe] = (uint)bVar24 + (uint)bVar20 * 0x1000000 +
                     (uint)bVar22 * 0x10000 + (uint)bVar21 * 0x100;
      param_1[8] = iVar27 + ((uint)bVar15 * 0x10000 + (uint)bVar14 * 0x100 +
                             (uint)bVar23 + (uint)bVar13 * 0x1000000 + uVar30 * -10000) / 10000;
      param_1[9] = uVar30;
      uVar28 = *param_1;
      *param_1 = uVar28 + uVar29;
      param_1[1] = param_1[1] + (uint)CARRY4(uVar28,uVar29);
      return 0;
    }
    return 1;
  }
  return 3;
}


