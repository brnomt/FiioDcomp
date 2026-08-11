/**
 * FUN_030a45fe @ 0x030a45fe
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030a45fe(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  
  puVar2 = DAT_030a49fc;
  iVar7 = 0;
  uVar3 = (*(code *)*DAT_030a4a00)(param_1 + 8,0x1000,*DAT_030a49fc);
  *(undefined4 *)(param_1 + 0x8218) = uVar3;
  iVar4 = 1;
  do {
    iVar5 = param_1 + iVar7;
    iVar7 = iVar7 + 1;
    pcVar6 = (char *)(iVar5 + 8);
    cVar1 = *pcVar6;
    if (cVar1 == -1) {
      cVar1 = *(char *)(iVar5 + 9);
      bVar8 = cVar1 == '\x1f';
      if (bVar8) {
        cVar1 = *(char *)(iVar5 + 10);
      }
      bVar9 = bVar8 && cVar1 == '\0';
      if (bVar8 && cVar1 == '\0') {
        bVar9 = *(char *)(iVar5 + 0xb) == -0x18;
      }
      if (bVar9) {
        bVar8 = (~*(byte *)(iVar5 + 0xc) & 0xf0) == 0;
        if (bVar8) {
          pcVar6 = (char *)(uint)*(byte *)(iVar5 + 0xd);
        }
        if (bVar8 && pcVar6 == &DAT_00000007) {
          return 1;
        }
      }
    }
    else if (cVar1 == '\x1f') {
      cVar1 = *(char *)(iVar5 + 9);
      bVar8 = cVar1 == -1;
      if (bVar8) {
        cVar1 = *(char *)(iVar5 + 10);
      }
      if (bVar8 && cVar1 == -0x18) {
        cVar1 = *(char *)(iVar5 + 0xb);
        bVar8 = cVar1 == '\0';
        if (bVar8) {
          cVar1 = *(char *)(iVar5 + 0xc);
        }
        if ((bVar8 && cVar1 == '\a') && ((~*(byte *)(iVar5 + 0xd) & 0xf0) == 0)) {
          return 1;
        }
      }
    }
    else if (cVar1 == -2) {
      cVar1 = *(char *)(iVar5 + 9);
      bVar8 = cVar1 == '\x7f';
      if (bVar8) {
        cVar1 = *(char *)(iVar5 + 10);
      }
      bVar9 = bVar8 && cVar1 == '\x01';
      if (bVar8 && cVar1 == '\x01') {
        bVar9 = *(char *)(iVar5 + 0xb) == -0x80;
      }
      if (bVar9) {
        return 1;
      }
    }
    else {
      bVar8 = cVar1 == '\x7f';
      if (bVar8) {
        cVar1 = *(char *)(iVar5 + 9);
      }
      if (bVar8 && cVar1 == -2) {
        bVar8 = *(char *)(iVar5 + 10) == -0x80;
        if (bVar8) {
          pcVar6 = (char *)(uint)*(byte *)(iVar5 + 0xb);
        }
        if (bVar8 && pcVar6 == (char *)0x1) {
          return 1;
        }
      }
    }
    iVar4 = iVar4 + 1;
    if (0xffa < iVar4) {
      (*(code *)*DAT_030a4a04)(*(undefined4 *)(param_1 + 0x821c),0,*puVar2);
      return 0;
    }
  } while( true );
}


