/**
 * FUN_0300ae8a @ 0x0300ae8a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300ae8a(void)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 auStack_48 [18];
  
  iVar3 = FUN_02ff31f2();
  FUN_02ff9742(1);
  iVar4 = 0;
  if (iVar3 != 0x40000080) {
    iVar4 = iVar3 + -0x20000000;
  }
  if (iVar3 == 0x40000080 || iVar4 == 0x80) {
    iVar4 = FUN_02ff2ec2(0,0,0x3c,0x32,0);
    if (iVar4 == 0) {
      iVar4 = FUN_02ff2ec2(0x4a,0x4e,0xae,0xb2,0);
      if (iVar4 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = 0x40000040;
        FUN_02ff9700(0x42);
      }
    }
    else {
      iVar3 = 0x40001000;
    }
  }
  psVar2 = DAT_0300af2c;
  if (iVar3 != 0x40001000) {
    if (iVar3 < 0x40001001) {
      if (iVar3 == 0x20000002) {
        if (*DAT_0300af2c == 1) {
          DAT_0307a92c = 1;
        }
        if (*DAT_0300af2c == 2) {
          FUN_02ff9700(0x6c);
          FUN_03010d78(0x80,0);
        }
        FUN_02ff9700(0x76);
        return 0;
      }
      if (iVar3 != 0x20001000) {
        if (iVar3 == 0x40000040) {
          iVar4 = FUN_02ff9760(0x73);
          if (iVar4 != 0) {
            return 0;
          }
          DAT_0307a92c = 1;
          sVar1 = *psVar2;
          if (sVar1 == 0) {
            FUN_03010d78(0x7d,0);
            *psVar2 = 1;
            FUN_02ff9700(0x6a);
            uVar5 = 0x5b;
            goto LAB_0300afaa;
          }
          if (sVar1 == 1) {
            FUN_03010d78(0x7e,0);
            *psVar2 = 2;
            uVar5 = 0x6b;
            goto LAB_0300afaa;
          }
          if (sVar1 == 2) {
            FUN_03010d78(0x7f,0);
            *psVar2 = 1;
            uVar5 = 0x6a;
            goto LAB_0300afaa;
          }
        }
        else if (iVar3 != 0x40000200) {
          return 0;
        }
      }
    }
    else {
      if (iVar3 == 0x41000000) {
        auStack_48[0] = 0;
        FUN_02fe85fc(DAT_0300b030,DAT_0300b02c,auStack_48);
        return 0;
      }
      if (iVar3 == 0x42000000) {
        auStack_48[0] = 1;
        FUN_02fe85fc(DAT_0300b030,DAT_0300b02c,auStack_48);
        return 0;
      }
      if (iVar3 != 0x50000200) {
        return 0;
      }
    }
  }
  DAT_0307a92c = 1;
  if (*psVar2 == 1 || *psVar2 == 2) {
    DAT_0307a928 = 2;
  }
  else {
    FUN_02ff9700(0x79);
  }
  uVar5 = 0x6c;
LAB_0300afaa:
  FUN_02ff9700(uVar5);
  return 0;
}


