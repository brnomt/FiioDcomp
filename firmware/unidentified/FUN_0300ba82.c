/**
 * FUN_0300ba82 @ 0x0300ba82
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300ba82(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined1 *puVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int unaff_r4;
  uint uVar13;
  int unaff_r5;
  undefined4 unaff_r7;
  char unaff_r8;
  char in_ZR;
  bool bVar14;
  char cStack00000000;
  char cStack00000001;
  char cStack00000002;
  undefined4 in_stack_00000204;
  undefined4 in_stack_00000208;
  uint in_stack_00000210;
  undefined4 in_stack_00000214;
  int in_stack_00000218;
  undefined4 in_stack_00000286;
  undefined4 in_stack_0000028a;
  undefined4 in_stack_0000028e;
  undefined2 in_stack_000002ba;
  
  pcVar6 = DAT_0300bc54;
  if (in_ZR != '\0') {
    FUN_02fffd02(1,&stack0x00000b88,0x800);
    (&stack0x00000b88)[unaff_r4 * 8] = (char)unaff_r7;
    FUN_02fface0(2,7);
    FUN_02fffd74(1,&stack0x00000b88,0x800);
    FUN_02feb4bc();
    return 0;
  }
  *DAT_0300bc54 = unaff_r8;
  FUN_02feb5d6();
  iVar9 = FUN_0300cb04();
  puVar7 = DAT_0300bc58;
  puVar1 = DAT_0300bc2c;
  if (iVar9 == 1) {
    *DAT_0300bc2c = 3;
    *puVar7 = 0;
  }
  else {
    if (cStack00000000 == -1) {
      if (cStack00000001 == -2) {
        *DAT_0300bc2c = unaff_r7;
        goto LAB_0300bae8;
      }
    }
    else {
      bVar14 = cStack00000000 == -0x11;
      if (bVar14) {
        cStack00000000 = cStack00000001;
      }
      if ((bVar14 && cStack00000000 == -0x45) && (cStack00000002 == -0x41)) {
        *DAT_0300bc2c = 3;
        *puVar7 = 3;
        goto LAB_0300bae8;
      }
    }
    *DAT_0300bc2c = 2;
  }
LAB_0300bae8:
  *(undefined2 *)(DAT_0300bc4c + 0x21d) = in_stack_000002ba;
  FUN_02fe750e(puVar1 + 4,unaff_r5 + 0x20,0x66);
  *(undefined4 *)((int)puVar1 + 0x76) = in_stack_00000286;
  *(undefined4 *)((int)puVar1 + 0x7a) = in_stack_0000028a;
  *(undefined4 *)((int)puVar1 + 0x7e) = in_stack_0000028e;
  FUN_02fe750e((int)puVar1 + 0x82,unaff_r5 + 0x92,0x28);
  FUN_02febace(0,0,(int)*pcVar6);
  puVar2 = DAT_0300bc34;
  puVar1[1] = in_stack_00000204;
  puVar5 = DAT_0300bc48;
  puVar1 = DAT_0300bc44;
  *puVar2 = in_stack_00000208;
  *puVar5 = in_stack_00000208;
  *puVar1 = in_stack_00000208;
  iVar9 = FUN_02ffa6f4(200);
  puVar8 = DAT_0300bc5c;
  if (iVar9 == 0) {
    uVar13 = 0;
    do {
      FUN_0300c65a();
      uVar13 = uVar13 + 1;
    } while (uVar13 < 0xc);
  }
  else {
    if (*DAT_0300bc5c == 0) {
      FUN_02ffa6d6(200);
      uVar13 = 0;
      do {
        FUN_0300c65a();
        uVar13 = uVar13 + 1;
      } while (uVar13 < 0xc);
    }
    if (in_stack_00000210 < *puVar8) {
      FUN_02ffa6d6(200);
      uVar13 = 0;
      do {
        FUN_0300c65a();
        uVar13 = uVar13 + 1;
      } while (uVar13 < 0xc);
    }
  }
  piVar3 = DAT_0300bc38;
  *puVar2 = in_stack_00000208;
  puVar4 = DAT_0300bc3c;
  *piVar3 = in_stack_00000218;
  puVar1 = DAT_0300bc40;
  *puVar4 = in_stack_00000210;
  *puVar1 = in_stack_00000214;
  iVar9 = DAT_0300bc30;
  uVar13 = 0;
  do {
    *(undefined4 *)(iVar9 + uVar13 * 4) = *(undefined4 *)(unaff_r5 + uVar13 * 4 + 0xbc);
    uVar13 = uVar13 + 1;
  } while (uVar13 < 0x32);
  iVar10 = FUN_02ffa6f4(200);
  if (iVar10 != 0) {
    uVar13 = *puVar8;
    if ((uVar13 == 0) || (*puVar4 < uVar13)) {
      FUN_02ffa6d6(200);
    }
    else {
      uVar12 = (uVar13 - 1) / 400;
      *puVar8 = uVar13 - 1;
      uVar11 = *(undefined4 *)(iVar9 + uVar12 * 4);
      *puVar5 = uVar11;
      *puVar2 = uVar11;
      *piVar3 = uVar12 * 400;
      uVar13 = 0;
      do {
        FUN_0300c65a();
        uVar13 = uVar13 + 1;
      } while (uVar13 < 0xc);
    }
  }
  return 1;
}


