/**
 * FUN_0306eb64 @ 0x0306eb64
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0306eb64(uint param_1)

{
  longlong lVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  uint uVar12;
  uint uVar13;
  char local_928 [2308];
  
  iVar2 = DAT_0306ed14;
  pcVar11 = local_928;
  *(undefined4 *)(DAT_0306ed14 + 0x44) = _DAT_e000e100;
  _DAT_e000e180 = 0x60;
  *DAT_0306ed38 = 0;
  puVar3 = DAT_0306ed20;
  DAT_0306ed20[3] = 0;
  *puVar3 = 0;
  if (*(uint *)(iVar2 + 0x34) < param_1) {
    param_1 = *(uint *)(iVar2 + 0x34);
  }
  lVar1 = (ulonglong)param_1 * (ulonglong)*(uint *)(iVar2 + 0x2c);
  iVar8 = FUN_0306d274((int)lVar1,
                       param_1 * ((int)*(uint *)(iVar2 + 0x2c) >> 0x1f) +
                       (int)((ulonglong)lVar1 >> 0x20),8000,0);
  puVar5 = DAT_0306ed4c;
  puVar4 = DAT_0306ed48;
  if (puVar3[2] != puVar3[1]) {
    iVar8 = iVar8 + ((puVar3[1] - puVar3[2]) - *DAT_0306ed44);
  }
  (*(code *)*DAT_0306ed4c)(iVar8,0,*DAT_0306ed48);
  (*(code *)*DAT_0306ed50)(local_928,0x900,*puVar4);
  do {
    if ((*pcVar11 == -1) && (uVar13 = (uint)(byte)pcVar11[1], (~uVar13 & 0xe0) == 0)) {
      uVar12 = (uVar13 & 0x1f) >> 3;
      if (uVar12 == 0) {
        uVar12 = 3;
      }
      else {
        uVar12 = 4 - uVar12;
      }
      if (((((*DAT_0306ed3c & 0xf) == 4 - ((uVar13 & 7) >> 1) && uVar12 == *DAT_0306ed3c >> 4) &&
           (uVar13 = (uint)(byte)pcVar11[2], (pcVar11[2] & 0xf0U) != 0)) && ((~uVar13 & 0xf0) != 0))
         && (((~uVar13 & 0xc) != 0 &&
             (*(int *)(DAT_0306ed40 + (uVar13 & 0xc)) >> (uVar12 - 1 & 0xff) ==
              *(int *)(iVar2 + 0x28))))) {
        (*(code *)*puVar5)(iVar8,0,*puVar4);
        lVar1 = (ulonglong)param_1 * (ulonglong)*(uint *)(iVar2 + 0x28);
        uVar9 = FUN_0306d274((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),1000,0);
        piVar7 = DAT_0306ed58;
        piVar6 = DAT_0306ed54;
        *(undefined4 *)(iVar2 + 0x3c) = uVar9;
        FUN_0306d37e(*piVar6 + *piVar7 * 2,0x1200);
        FUN_0306d37e(piVar6[1] + *piVar7 * 2,0x1200);
        iVar10 = *piVar6 + *piVar7 * 2;
        *DAT_0306ed18 = iVar10;
        iVar8 = DAT_0306ed5c;
        *(int *)(iVar2 + 0xc) = iVar10;
        *(int *)(iVar8 + -0x20) = iVar8;
        *(int *)(iVar2 + 4) = iVar10;
        *(int *)(iVar2 + 8) = iVar10;
        *(int *)(iVar2 + 0x18) = iVar8;
        *(int *)(iVar2 + 0x1c) = iVar8 + 0x40;
        *(int *)(iVar8 + 0x6c) = iVar10;
        *(undefined4 *)(iVar8 + 0x14) = 0;
        *(undefined4 *)(iVar8 + 0x18) = 0;
        *(int *)(iVar8 + 0x70) = iVar10;
        (**(code **)(iVar8 + -0x18))(*(undefined4 *)(iVar8 + -0x1c));
        *(undefined2 *)(*(int *)(iVar2 + 0x18) + 0x3c) = 0;
        iVar8 = *(int *)(iVar2 + 0x1c);
        *(undefined4 *)(iVar8 + 0x34) = 0;
        *(undefined4 *)(iVar8 + 0x38) = 0;
        *(undefined4 *)(iVar8 + 0x3c) = 0;
        *(undefined4 *)(iVar8 + 0x40) = 0;
        *DAT_0306ed60 = 0;
        FUN_0306f378();
        _DAT_e000e280 = 0x60;
        *DAT_0306ed64 = 0;
        FUN_0306e3ac();
        _DAT_e000e100 = *(undefined4 *)(iVar2 + 0x44);
        return;
      }
    }
    pcVar11 = pcVar11 + 1;
    iVar8 = iVar8 + 1;
  } while( true );
}


