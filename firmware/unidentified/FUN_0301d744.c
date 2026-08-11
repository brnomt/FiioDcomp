/**
 * FUN_0301d744 @ 0x0301d744
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 FUN_0301d744(undefined4 param_1,ushort *param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint extraout_r1;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  byte local_b0;
  byte bStack_af;
  char cStack_ae;
  char cStack_ad;
  char local_ac;
  char local_ab;
  char local_aa;
  char local_a9;
  int local_a8;
  uint local_a4;
  int local_9c;
  int local_98;
  uint local_90;
  uint local_84;
  int iStack_80;
  uint local_78;
  int local_70;
  int local_6c;
  undefined4 local_30;
  int local_2c;
  
  iVar8 = 0;
  *param_2 = 0;
  local_30 = param_1;
  bVar2 = ape_rom_read_thunk(&local_b0,0x58,param_1);
  iVar6 = 0x58;
  if (bVar2 < 0x58) {
    return 0xfffffffe;
  }
  if ((((CONCAT13(cStack_ad,CONCAT12(cStack_ae,CONCAT11(bStack_af,local_b0))) == DAT_0301db20) &&
       (local_a8 == DAT_0301db24)) && (local_a4 == _DAT_0301db28)) &&
     ((local_9c == 0x6c726468 && (local_98 == 0x68697661)))) {
    DAT_03025b7d = 1;
    DAT_03025b7f = local_78 != 1;
    bVar11 = local_70 == 0x140;
    if (bVar11) {
      local_70 = local_6c;
    }
    if ((bVar11 && local_70 == 0xf0) && (9999 < local_90)) {
      DAT_03025b5c = local_90;
      if ((local_84 & 0x10) == 0) {
        DAT_03025b7d = 1;
        return 0xfffffffe;
      }
      local_2c = 1;
      uVar9 = 0;
      if (local_78 != 0) {
        do {
          ape_rom_read_thunk(&local_b0,8,local_30);
          iVar7 = CONCAT31(CONCAT12(local_a9,CONCAT11(local_aa,local_ab)),local_ac);
          ape_rom_read_thunk(&local_b0,8,local_30);
          if (((uint)local_b0 |
              CONCAT13(local_ac,CONCAT12(cStack_ad,CONCAT11(cStack_ae,bStack_af))) << 8) !=
              0x6c727473) {
            return 0xffffffff;
          }
          if (CONCAT31(CONCAT12(local_a9,CONCAT11(local_aa,local_ab)),local_ac) != 0x68727473) {
            return 0xffffffff;
          }
          ape_rom_read_thunk(&local_b0,4,local_30);
          uVar4 = (uint)local_b0;
          iVar10 = CONCAT13(local_ac,CONCAT12(cStack_ad,CONCAT11(cStack_ae,bStack_af)));
          ape_rom_read_thunk(&local_b0,8,local_30);
          uVar5 = (uint)local_b0;
          iVar6 = iVar6 + 0x1c;
          iVar7 = iVar7 + -0x14;
          iVar10 = (uVar4 | iVar10 << 8) - 8;
          uVar4 = extraout_r1;
          if (uVar5 == 0x76) {
            uVar4 = (uint)bStack_af;
          }
          if (uVar5 != 0x76 || uVar4 != 0x69) {
LAB_0301d87c:
            if ((uVar5 | CONCAT13(local_ac,CONCAT12(cStack_ad,CONCAT11(cStack_ae,bStack_af))) << 8)
                != 0x73647561) {
              return 0xffffffff;
            }
            ape_rom_seek_thunk(iVar10,1,local_30);
            ape_rom_read_thunk(&local_b0,8,local_30);
            bVar2 = local_b0;
            if (local_b0 == 0x73) {
              bVar2 = bStack_af;
            }
            if (local_b0 != 0x73 || bVar2 != 0x74) {
              return 0xffffffff;
            }
            cVar1 = cStack_ae;
            if (cStack_ae == 'r') {
              cVar1 = cStack_ad;
            }
            if (cStack_ae != 'r' || cVar1 != 'f') {
              return 0xffffffff;
            }
            ape_rom_read_thunk(&local_b0,8,local_30);
            iVar6 = iVar6 + iVar10 + 0x10;
            iVar7 = (iVar7 - iVar10) + -0x10;
            if (CONCAT11(bStack_af,local_b0) != 0x50) {
              return 0xffffffff;
            }
            *(uint *)(param_2 + 10) =
                 CONCAT31(CONCAT12(local_a9,CONCAT11(local_aa,local_ab)),local_ac);
            uVar3 = *param_2 | 1;
          }
          else {
            cVar1 = cStack_ae;
            if (cStack_ae == 'd') {
              cVar1 = cStack_ad;
            }
            if (cStack_ae != 'd' || cVar1 != 's') goto LAB_0301d87c;
            cVar1 = local_ac;
            if (local_ac == 'X') {
              cVar1 = local_ab;
            }
            if (local_ac != 'X' || cVar1 != 'V') {
              return 0xffffffff;
            }
            cVar1 = local_aa;
            if (local_aa == 'I') {
              cVar1 = local_a9;
            }
            if (local_aa != 'I' || cVar1 != 'D') {
              return 0xffffffff;
            }
            uVar3 = *param_2 | 2;
          }
          *param_2 = uVar3;
          ape_rom_seek_thunk(iVar7,1,local_30);
          iVar6 = iVar7 + iVar6;
          while( true ) {
            bVar2 = ape_rom_read_thunk(&local_b0,8,local_30);
            if (bVar2 < 8) {
              return 0xffffffff;
            }
            if (((uint)local_b0 |
                CONCAT13(local_ac,CONCAT12(cStack_ad,CONCAT11(cStack_ae,bStack_af))) << 8) !=
                0x4a554e4b) break;
            iVar7 = CONCAT31(CONCAT12(local_a9,CONCAT11(local_aa,local_ab)),local_ac);
            ape_rom_seek_thunk(iVar7,1,local_30);
            iVar6 = iVar6 + iVar7 + 8;
          }
          ape_rom_seek_thunk(0xfffffff8,1,local_30);
          uVar9 = uVar9 + 1;
        } while (uVar9 < local_78);
      }
      ape_rom_read_thunk(&local_b0,8,local_30);
      iVar7 = FUN_0301d6a2(local_30);
      uVar9 = _DAT_0301db28;
      do {
        iVar10 = iVar6 + 8;
        if (iVar7 != 0) {
LAB_0301d9fc:
          iVar6 = FUN_0301d6a2(local_30);
          if (iVar6 == 0) {
            if ((*param_2 & 3) == 0) {
              return 0xfffffff8;
            }
            *(int *)(param_2 + 6) = iVar10 + -8;
            if (local_2c != 1) {
              param_2[8] = 0;
              param_2[9] = 0;
              return 0xfffffffe;
            }
            *(int *)(param_2 + 8) = iVar8 + 8;
            ape_rom_seek_thunk(iVar8 + 4,0,DAT_03025fdc);
            ape_rom_read_thunk(&local_b0,4,DAT_03025fdc);
            DAT_03025b60 = (CONCAT31(CONCAT12(cStack_ad,CONCAT11(cStack_ae,bStack_af)),local_b0) >>
                           4) - iStack_80;
            DAT_03025b68 = iStack_80;
            if (iStack_80 != 0) {
              DAT_03025b70 = (uint)(DAT_03025b60 == 0);
              ape_rom_seek_thunk(*(undefined4 *)(param_2 + 8),0,DAT_03026400);
              DAT_03025b6c = 0;
              DAT_03025b64 = 0;
              uRam03025ff0 = 4;
              uRam03025ff4 = 0;
              uRam03026414 = 4;
              uRam03026418 = 0;
              *(int *)(param_2 + 4) = iStack_80;
              *(uint *)(param_2 + 2) = local_90;
              return 0;
            }
          }
          return 0xfffffffd;
        }
        iVar7 = CONCAT31(CONCAT12(local_a9,CONCAT11(local_aa,local_ab)),local_ac);
        if (((uint)local_b0 |
            CONCAT13(local_ac,CONCAT12(cStack_ad,CONCAT11(cStack_ae,bStack_af))) << 8) == uVar9) {
          ape_rom_read_thunk(&local_b0,8,local_30);
          iVar10 = iVar6 + 0x10;
          iVar7 = iVar7 + -8;
          if (((uint)local_b0 |
              CONCAT13(local_ac,CONCAT12(cStack_ad,CONCAT11(cStack_ae,bStack_af))) << 8) ==
              0x69766f6d) {
            iVar8 = iVar7 + iVar10;
            goto LAB_0301d9fc;
          }
        }
        ape_rom_seek_thunk(iVar7,1,local_30);
        ape_rom_read_thunk(&local_b0,8,local_30);
        iVar6 = iVar10 + iVar7;
        iVar7 = FUN_0301d6a2(local_30);
      } while( true );
    }
  }
  return 0xffffffff;
}


