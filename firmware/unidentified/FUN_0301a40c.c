/**
 * FUN_0301a40c @ 0x0301a40c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0301a40c(void)

{
  char cVar1;
  byte *pbVar2;
  char *pcVar3;
  char *pcVar4;
  short *psVar5;
  undefined4 *puVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  undefined1 local_48 [2];
  byte bStack_46;
  
  iVar9 = FUN_0300298a();
  iVar16 = DAT_0301a4bc;
  iVar13 = DAT_0301a4b8;
  iVar12 = DAT_0301a4b4;
  pbVar2 = DAT_0301a488;
  iVar15 = iVar9;
  if ((iVar9 == DAT_0301a4b4 || iVar9 == DAT_0301a4b8) || iVar9 == DAT_0301a4bc) {
    if (*DAT_0301a488 == 0) {
      iVar12 = FUN_0300265a(0,0,0xf0,0x140,0);
      if (iVar12 != 0) {
        *pbVar2 = 8;
        FUN_03008e98(0x128);
      }
    }
    else {
      uVar10 = FUN_0300265a(200,0,0xf0,0x3c,0);
      if (uVar10 == 0) {
        iVar11 = FUN_0300265a(0,0x82,0x28,0xbe,0);
        if (iVar11 == 0) {
          iVar11 = FUN_0300265a(0,0x3c,0x28,0x78,0);
          if (iVar11 == 0) {
            iVar11 = FUN_0300265a(0,0xc3,0x28,0xff,0);
            if (iVar11 == 0) {
              iVar12 = FUN_0300265a(0x77,399,0x79,0x191,0);
              if (iVar12 != 0) {
                iVar15 = DAT_0301a828;
              }
            }
            else {
              iVar15 = DAT_0301a81c;
              if (((iVar9 != iVar12) && (iVar15 = DAT_0301a820, iVar9 != iVar13)) &&
                 (iVar15 = iVar9, iVar9 == iVar16)) {
                iVar15 = DAT_0301a824;
              }
            }
          }
          else {
            iVar15 = DAT_0301a810;
            if (((iVar9 != iVar12) && (iVar15 = DAT_0301a814, iVar9 != iVar13)) &&
               (iVar15 = iVar9, iVar9 == iVar16)) {
              iVar15 = DAT_0301a818;
            }
          }
        }
        else if (iVar9 != iVar16) {
          iVar15 = DAT_0301a80c;
        }
      }
      else {
        if (iVar9 != iVar16) {
          uVar10 = (uint)*pbVar2;
        }
        if (iVar9 != iVar16 && uVar10 != 0) {
          iVar15 = DAT_0301a4c0;
        }
      }
    }
  }
  puVar6 = DAT_0301a84c;
  psVar5 = DAT_0301a83c;
  iVar12 = DAT_0301a838;
  pcVar4 = DAT_0301a834;
  pcVar3 = DAT_0301a830;
  iVar13 = iVar15 - DAT_0301a82c;
  if (iVar15 != DAT_0301a82c) {
    if (iVar15 < DAT_0301a82c) {
      if (iVar15 == DAT_0301a840) goto LAB_0301a6ca;
      if (iVar15 < DAT_0301a840) {
        if (iVar15 == 0x20000002) {
          FUN_02ff7e7c(DAT_0301a85c,DAT_0301a858);
          FUN_030090c2(0,local_48);
          return 1;
        }
        if (iVar15 == 0x30000004) {
          *pbVar2 = 8;
          FUN_0301ab96(0x124,0);
          if (*pcVar4 == '\0') goto LAB_0301a6c4;
          goto LAB_0301a700;
        }
        if (iVar15 == 0x30000008) {
          *pbVar2 = 8;
          FUN_0301ab96(0x125,0);
          cVar1 = *pcVar4;
          goto joined_r0x0301a66c;
        }
        if (iVar15 == 0x30000010) goto LAB_0301a692;
      }
      else {
        iVar13 = (iVar15 - DAT_0301a840) + DAT_0301a844;
        if (iVar13 == 0) {
          *DAT_0301a848 = 0;
          *pbVar2 = 8;
          *puVar6 = 1;
          FUN_0301ab96(0x122);
          FUN_03008e98(0x128);
          return 0;
        }
        if (iVar13 == 4) {
          *DAT_0301a848 = 1;
          *pbVar2 = 8;
          *puVar6 = 1;
          *psVar5 = 0;
          *pcVar3 = '\0';
          FUN_0301ab96(0x122,0xffffffff);
          FUN_03008e98(0x128);
          return 0;
        }
        if (iVar13 == 0xc) {
LAB_0301a692:
          *pbVar2 = 8;
          if (*(byte *)(iVar12 + 0x12) < *(byte *)(iVar12 + 0x1e)) {
            *(byte *)(iVar12 + 0x12) = *(byte *)(iVar12 + 0x12) + 1;
            FUN_0301ab96(0x123);
          }
          cVar1 = *pcVar4;
          goto joined_r0x0301a6e8;
        }
      }
    }
    else {
      iVar16 = iVar13 - DAT_0301a850;
      if (iVar13 == DAT_0301a850) {
        *pbVar2 = 8;
        _local_48 = CONCAT12(bStack_46,1);
        FUN_03008e98(0x128);
        return 0;
      }
      if (iVar13 < DAT_0301a850) {
        if (iVar13 == 0x20) {
          *pbVar2 = 8;
          if (*psVar5 == 0) {
            FUN_03006134();
            func_0x03006b68();
            uVar14 = 0x120;
          }
          else {
            FUN_03006146();
            FUN_0300710a();
            *pcVar3 = '\0';
            uVar14 = 0x121;
          }
          FUN_0301ab96(uVar14,0);
          cVar1 = *pcVar4;
joined_r0x0301a66c:
          if (cVar1 != '\0') {
LAB_0301a700:
            uVar14 = 0x127;
            goto LAB_0301a68c;
          }
          goto LAB_0301a6c4;
        }
        if (iVar13 == 0x1e0 || iVar13 == 0xfe0) {
LAB_0301a602:
          FUN_02ff7e7c(DAT_0301a85c,DAT_0301a858);
          iVar13 = FUN_03008ef8(0x157);
          if (iVar13 == 0) {
            uVar7 = 2;
            uVar8 = *(undefined2 *)(iVar12 + 0x1b1);
          }
          else {
            uVar7 = 6;
            uVar8 = *DAT_0301a860;
          }
          _local_48 = CONCAT21(uVar8,uVar7);
          FUN_030090c2(9,local_48);
          return 1;
        }
        if (iVar13 + DAT_0301a854 == 0) {
          *pbVar2 = 8;
          _local_48 = (uint3)bStack_46 << 0x10;
          FUN_03008e98(0x128);
          return 0;
        }
      }
      else {
        if (iVar16 == 0xe000004 || iVar16 == 0xe000008) {
          *pbVar2 = 8;
          cVar1 = *pcVar3;
          goto joined_r0x0301a724;
        }
        if (iVar16 == 0xe000200) goto LAB_0301a602;
      }
    }
    if (*DAT_0301a83c != 1 && *DAT_0301a83c != 2) {
      return 0;
    }
    if (iVar15 == 0) {
      return 0;
    }
    *pbVar2 = 8;
    cVar1 = *pcVar3;
joined_r0x0301a724:
    if (cVar1 == '\x03') {
      return 0;
    }
    FUN_0301ab96(0x121,0);
    return 0;
  }
LAB_0301a6ca:
  *pbVar2 = 8;
  if (*(char *)(iVar12 + 0x12) != '\0') {
    *(char *)(iVar12 + 0x12) = *(char *)(iVar12 + 0x12) + -1;
    FUN_0301ab96(0x123);
  }
  cVar1 = *pcVar4;
joined_r0x0301a6e8:
  if (cVar1 != '\0') {
    uVar14 = 0x12e;
    goto LAB_0301a68c;
  }
LAB_0301a6c4:
  uVar14 = 0x128;
LAB_0301a68c:
  FUN_03008e98(uVar14);
  return 0;
}


