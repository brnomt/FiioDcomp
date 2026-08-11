/**
 * FUN_03051018 @ 0x03051018
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x0305133c) */
/* WARNING: Removing unreachable block (ram,0x0305108a) */
/* WARNING: Removing unreachable block (ram,0x0305118a) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_03051018(undefined4 param_1,int param_2)

{
  ushort *puVar1;
  ushort uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  uint *puVar13;
  undefined1 *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  ushort auStack_248 [128];
  ushort auStack_148 [128];
  int iStack_48;
  uint uStack_44;
  uint uStack_40;
  int iStack_3c;
  int iStack_38;
  ushort auStack_34 [4];
  undefined4 uStack_2c;
  int iStack_28;
  
  puVar5 = DAT_0305123c;
  uVar4 = DAT_03051238;
  piVar3 = DAT_03051234;
  if (999 < *(ushort *)(DAT_03051230 + 0x3a)) {
    return;
  }
  uVar16 = 0;
  uStack_2c = param_1;
  iStack_28 = param_2;
  if (*(ushort *)(DAT_03051230 + 0x3a) == 0) {
LAB_0305108e:
    uVar16 = 0;
    iStack_38 = *piVar3 + 0x44000;
    FUN_0303aade(uVar4,iStack_38,1,DAT_0305123c);
    *puVar5 = 0xffffffff;
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0x3c00;
    puVar5[3] = 1;
    iStack_48 = -1;
    uStack_44 = puVar5[1];
    uStack_40 = 0x3c00;
    iStack_3c = 1;
    FUN_0303ab26(uVar4,iStack_38,1,DAT_0305123c);
  }
  else {
    do {
      func_0x0303a724(uVar4,*piVar3 * 0x200 + 0x8800000 + uVar16 * 0x10,0x10,&iStack_48);
      if (iStack_3c == 3) {
        iStack_38 = *piVar3 + (uVar16 >> 5) + 0x44000;
        FUN_0303aade(uVar4,iStack_38,1,DAT_03051648);
        uVar7 = DAT_03051648;
        piVar12 = puVar5 + (uVar16 & 0x1f) * 4;
        piVar12[3] = 1;
        iStack_48 = *piVar12;
        uStack_44 = piVar12[1];
        uStack_40 = piVar12[2];
        iStack_3c = 1;
        FUN_0303ab26(uVar4,iStack_38,1,uVar7);
        goto LAB_030510d8;
      }
      uVar16 = uVar16 + 1 & 0xffff;
      if (999 < uVar16) goto LAB_0305108e;
    } while (iStack_48 != -1);
    iStack_38 = *piVar3 + ((uVar16 - 1 & 0xfffffff) >> 5) + 0x44000;
    FUN_0303aade(uVar4,iStack_38,2,DAT_03051648);
    puVar13 = puVar5 + (uVar16 - 1 & 0x1f) * 4;
    uStack_40 = uVar16 + 0x3c00;
    *puVar13 = uVar16;
    puVar13[6] = uStack_40;
    puVar13[5] = 0xffffffff;
    puVar13[4] = 0xffffffff;
    puVar13[7] = 1;
    iStack_48 = -1;
    uStack_44 = puVar13[5];
    iStack_3c = 1;
    FUN_0303ab26(uVar4,iStack_38,2,DAT_03051648);
  }
LAB_030510d8:
  iVar17 = *piVar3 + (uStack_40 & 0x1fffff) * 4 + 0x20000;
  FUN_0303aade(uVar4,iVar17,4,DAT_0305123c);
  func_0x0302d3d0(param_1,iStack_28,3,auStack_148);
  puVar15 = puVar5 + 0xc0;
  uVar9 = 0;
  do {
    puVar14 = (undefined1 *)((int)puVar15 + 1);
    *(char *)puVar15 = (char)auStack_148[uVar9];
    puVar15 = (undefined4 *)((int)puVar15 + 2);
    *puVar14 = (char)(auStack_148[uVar9] >> 8);
    puVar6 = DAT_0305123c;
    puVar1 = auStack_148 + uVar9;
    if (*puVar1 != 0) {
      uVar9 = uVar9 + 1;
    }
  } while (*puVar1 != 0 && uVar9 < 0x80);
  *DAT_0305123c = param_1;
  uVar4 = DAT_03051238;
  puVar5[1] = iStack_28 + 1;
  *(undefined1 *)(puVar5 + 0xb) = 0;
  *(undefined1 *)((int)puVar5 + 0x2d) = 0x46;
  *(undefined1 *)((int)puVar5 + 0x2e) = 0;
  *(undefined1 *)((int)puVar5 + 0x2f) = 0x49;
  *(undefined1 *)(puVar5 + 0xc) = 0;
  *(undefined1 *)((int)puVar5 + 0x31) = 0x4c;
  *(undefined1 *)((int)puVar5 + 0x32) = 0;
  *(undefined1 *)((int)puVar5 + 0x33) = 0x45;
  FUN_0303ab26(uVar4,iVar17,4,puVar6);
  uVar4 = DAT_03051238;
  if (*(short *)(DAT_03051230 + 0x3a) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = (uint)(ushort)(*(short *)(DAT_03051230 + 0x3a) - 1);
    func_0x0303a724(DAT_03051238,*piVar3 * 0x200 + 0xa800000 + uVar9 * 2,2,auStack_34);
    func_0x0303a724(uVar4,*piVar3 * 0x200 + 0x8800000 + (uint)auStack_34[0] * 0x10,0x10,&iStack_48);
    func_0x0303a724(uVar4,*piVar3 * 0x200 + uStack_40 * 0x800 + 0x4000300,0x100,auStack_248);
    uVar10 = 0;
    while( true ) {
      uVar2 = auStack_148[uVar10];
      if (auStack_248[uVar10] < uVar2) break;
      if (uVar2 < auStack_248[uVar10]) {
        if (uVar9 == 0) goto LAB_0305134c;
        func_0x0303a724(DAT_03051644,*piVar3 * 0x200 + 0xa800000,2,auStack_34);
        func_0x0303a724(DAT_03051644,*piVar3 * 0x200 + 0x8800000 + (uint)auStack_34[0] * 0x10,0x10,
                        &iStack_48);
        func_0x0303a724(DAT_03051644,*piVar3 * 0x200 + uStack_40 * 0x800 + 0x4000300,0x100,
                        auStack_248);
        uVar10 = 0;
        goto LAB_03051292;
      }
      if ((uVar2 == 0) || (uVar10 = uVar10 + 1, 0x7f < uVar10)) break;
    }
    uVar9 = uVar9 + 1 & 0xffff;
  }
  goto LAB_0305134c;
  while (((auStack_248[uVar10] <= uVar2 && (uVar2 != 0)) && (uVar10 = uVar10 + 1, uVar10 < 0x80))) {
LAB_03051292:
    uVar2 = auStack_148[uVar10];
    if (auStack_248[uVar10] < uVar2) {
      uVar10 = uVar9;
      uVar18 = 0;
      if (uVar9 == 0) {
        uVar9 = 1;
      }
      else {
        do {
          uVar4 = DAT_03051644;
          uVar9 = uVar18 + uVar10 >> 1;
          func_0x0303a724(DAT_03051644,*piVar3 * 0x200 + 0xa800000 + uVar9 * 2,2,auStack_34);
          func_0x0303a724(uVar4,*piVar3 * 0x200 + 0x8800000 + (uint)auStack_34[0] * 0x10,0x10,
                          &iStack_48);
          func_0x0303a724(uVar4,*piVar3 * 0x200 + uStack_40 * 0x800 + 0x4000300,0x100,auStack_248);
          uVar11 = 0;
          while( true ) {
            uVar2 = auStack_148[uVar11];
            uVar8 = uVar10;
            uVar19 = uVar9;
            if ((auStack_248[uVar11] < uVar2) ||
               (uVar8 = uVar9, uVar19 = uVar18, uVar2 < auStack_248[uVar11])) break;
            if ((uVar2 == 0) || (uVar11 = uVar11 + 1, 0x7f < uVar11)) goto LAB_0305134c;
          }
          uVar9 = uVar8;
          if (uVar19 != uVar9) {
            uVar11 = uVar9 - 1;
          }
          uVar10 = uVar9;
          uVar18 = uVar19;
        } while (uVar19 != uVar9 && uVar19 != uVar11);
      }
      goto LAB_0305134c;
    }
  }
  uVar9 = 0;
LAB_0305134c:
  uVar4 = DAT_03051644;
  FUN_0303aade(DAT_03051644,*piVar3 + 0x54000,4,DAT_03051648);
  iVar17 = DAT_0305164c;
  for (uVar10 = (uint)*(ushort *)(DAT_0305164c + 0x3a); uVar9 < uVar10; uVar10 = uVar10 - 1) {
    *(undefined2 *)((int)puVar5 + uVar10 * 2) = *(undefined2 *)((int)puVar5 + uVar10 * 2 + -2);
  }
  *(short *)((int)puVar5 + uVar9 * 2) = (short)uVar16;
  FUN_0303ab26(uVar4,*piVar3 + 0x54000,4,DAT_03051648);
  puVar5 = DAT_03051650;
  *DAT_03051650 = 0xffffffff;
  puVar5[1] = 0xffffffff;
  puVar5[2] = 0xffffffff;
  *(short *)(iVar17 + 0x3a) = *(short *)(iVar17 + 0x3a) + 1;
  FUN_0303fb7c(1);
  return;
}


