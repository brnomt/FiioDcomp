/**
 * FUN_0300490a @ 0x0300490a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300490a(void)

{
  char cVar1;
  bool bVar2;
  ushort *puVar3;
  char *pcVar4;
  ushort uVar5;
  int iVar6;
  uint unaff_r4;
  uint unaff_r5;
  ushort uVar7;
  uint uVar8;
  bool bVar9;
  uint local_2c [2];
  
  uVar7 = 0;
  bVar2 = true;
  FUN_0301309e(local_2c);
  pcVar4 = DAT_03004b04;
  iVar6 = DAT_03004aec;
  uVar8 = local_2c[0] / 1000;
  if (*DAT_03004b04 < '\0') {
    *DAT_03004b00 = *(undefined1 *)(DAT_03004aec + 0x5c);
    iVar6 = FUN_02fe373e(iVar6 + 0x14,*(undefined4 *)(iVar6 + 0x34),*(int *)(iVar6 + 0x38) + -1,3,
                         &DAT_03004b08);
    *pcVar4 = (char)iVar6;
    if (iVar6 != -1) {
      func_0x02fdfcac(DAT_03004b0c,0x800);
      func_0x02fdfcac(DAT_03004b10,0x1000);
      func_0x02fdfcac(DAT_03004b14,0x1000);
      puVar3 = DAT_03004b18;
      puVar3[8] = 0xffff;
      puVar3[9] = 0xffff;
      *puVar3 = 0;
      puVar3[2] = 0;
      uVar5 = FUN_02fe3d26(puVar3 + 0x96,0x800,iVar6);
      puVar3[1] = uVar5;
      if (uVar5 < 0x800) {
        *puVar3 = *puVar3 | 1;
      }
      pcVar4 = DAT_03004b0c;
      cVar1 = *DAT_03004b0c;
      bVar9 = cVar1 == -0x11;
      if (bVar9) {
        cVar1 = DAT_03004b0c[1];
      }
      if ((bVar9 && cVar1 == -0x45) && (DAT_03004b0c[2] == -0x41)) {
        puVar3[3] = 1;
      }
      else {
        uVar5 = func_0x02fdeeca(DAT_03004b0c);
        puVar3[3] = uVar5;
        cVar1 = *pcVar4;
        if (cVar1 == -1) {
          if (pcVar4[1] == -2) {
            uVar7 = 1;
          }
        }
        else {
          bVar9 = cVar1 == -2;
          if (bVar9) {
            cVar1 = pcVar4[1];
          }
          if (bVar9 && cVar1 == -1) {
            uVar7 = 2;
          }
        }
      }
      if (*DAT_03004b1c == 3) {
        puVar3[8] = 0;
        puVar3[9] = 0;
      }
      else {
        do {
          iVar6 = FUN_03004612(local_2c);
          if (local_2c[0] == 0xffffffff) {
LAB_03004a2e:
            bVar9 = uVar8 <= local_2c[0];
            if (local_2c[0] <= uVar8) {
              bVar9 = local_2c[0] <= unaff_r5;
            }
            if (!bVar9) {
              unaff_r5 = local_2c[0];
            }
          }
          else {
            if (uVar8 < local_2c[0]) {
              if (local_2c[0] < unaff_r4) {
                unaff_r4 = local_2c[0];
              }
              if (bVar2) {
                bVar2 = false;
                unaff_r4 = local_2c[0];
              }
            }
            if (local_2c[0] != 0) goto LAB_03004a2e;
          }
        } while (iVar6 != -1);
        *(uint *)(puVar3 + 6) = unaff_r5;
        *(uint *)(puVar3 + 8) = unaff_r4;
      }
      pcVar4 = DAT_03004b04;
      if (*(int *)(puVar3 + 8) != -1) {
        FUN_02fe421e(0,0,(int)*DAT_03004b04);
        *puVar3 = *puVar3 & 0xfffe;
        puVar3[2] = 0;
        uVar5 = FUN_02fe3d26(DAT_03004b0c,0x800,(int)*pcVar4);
        puVar3[1] = uVar5;
        if (uVar5 < 0x800) {
          *puVar3 = *puVar3 | 1;
        }
        puVar3[4] = uVar7;
        FUN_03004456(*(undefined4 *)(puVar3 + 6));
        if (puVar3[3] == 0) {
          FUN_02fed304(DAT_03004b10 + -0x1000,DAT_03004b10,0x400);
        }
        else {
          FUN_02fed118(DAT_03004b10 + -0x1000,DAT_03004b10,0x400,3);
        }
        FUN_02ff2de4(0x4f);
      }
      pcVar4 = DAT_03004b04;
      if (uVar7 != 0) {
        *puVar3 = 0;
        puVar3[2] = 0;
        FUN_02fe3c0c((int)*pcVar4);
        *pcVar4 = -1;
      }
      return 0;
    }
  }
  return 1;
}


