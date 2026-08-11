/**
 * FUN_0306415a @ 0x0306415a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0306415a(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int extraout_r2;
  uint uVar6;
  uint unaff_r5;
  int unaff_r7;
  uint uVar7;
  
  iVar1 = DAT_03064474;
  if (*(int *)(DAT_03064474 + 0x20) != 0) {
    return;
  }
  uVar3 = func_0x03021fea(0);
  piVar2 = DAT_03064480;
  iVar4 = *DAT_03064480;
  *DAT_03064480 = 1 - iVar4;
  FUN_030324b2(5,uVar3,piVar2 + (1 - iVar4) * 0xc00 + 0xd5,*(undefined4 *)(iVar1 + 0x1c));
  if (*DAT_03064484 != 1) {
    return;
  }
  iVar4 = *piVar2;
  uVar5 = *(uint *)(iVar1 + 0x1c);
  iVar1 = (1 - iVar4) * 0x3000 + 0x354;
  uVar6 = 0;
  if (*(int *)(extraout_r2 + 0x24) == 0xf) {
    if (uVar5 >> 2 != 0) {
      do {
        uVar7 = *(uint *)(unaff_r7 + 0xc004);
        *(int *)(uVar7 + unaff_r7) = piVar2[(1 - iVar4) * 0xc00 + uVar6 + 0xd5];
        uVar7 = (uVar7 & 0xffff) + 4;
        *(uint *)(unaff_r7 + 0xc004) = uVar7 - unaff_r5 * (uVar7 / unaff_r5);
        uVar6 = uVar6 + 1;
        *(int *)(unaff_r7 + 0xc008) = *(int *)(unaff_r7 + 0xc008) + 4;
      } while (uVar6 < uVar5 >> 2);
      return;
    }
    return;
  }
  if (uVar5 >> 2 != 0) {
    do {
      uVar7 = (uint)*(ushort *)(unaff_r7 + 0xc004);
      *(undefined1 *)(unaff_r7 + uVar7) = *(undefined1 *)((int)piVar2 + uVar6 * 4 + 1 + iVar1);
      *(undefined1 *)(unaff_r7 + uVar7 + 1) = *(undefined1 *)((int)piVar2 + uVar6 * 4 + 2 + iVar1);
      *(undefined1 *)(unaff_r7 + uVar7 + 2) = *(undefined1 *)((int)piVar2 + uVar6 * 4 + 3 + iVar1);
      *(uint *)(unaff_r7 + 0xc004) = (uVar7 + 3) - unaff_r5 * ((uVar7 + 3) / unaff_r5);
      uVar6 = uVar6 + 1;
      *(int *)(unaff_r7 + 0xc008) = *(int *)(unaff_r7 + 0xc008) + 3;
    } while (uVar6 < uVar5 >> 2);
    return;
  }
  return;
}


