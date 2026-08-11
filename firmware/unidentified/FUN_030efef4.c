/**
 * FUN_030efef4 @ 0x030efef4
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_030efef4(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 auStack_41f8 [16840];
  int iStack_30;
  int iStack_2c;
  
  piVar2 = (int *)(param_1 + 0x954);
  piVar8 = (int *)(param_1 + 0x4954);
  if ((~*(uint *)(param_1 + 0x1c) & 3) == 0) {
    return;
  }
  iStack_30 = param_1;
  iStack_2c = param_2;
  FUN_030f03cc(param_1,param_2,1);
  iVar6 = iStack_2c;
  if (1000 < *(int *)(param_1 + 0xc)) {
    FUN_030f1934(0,iStack_2c);
    FUN_030eeeee(0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
    FUN_030f191c(0,iVar6);
    uVar1 = DAT_030f02dc;
    uVar4 = DAT_030f02d8;
    FUN_030f188a(piVar2,DAT_030f02dc,iVar6,DAT_030f02d8);
    if (piVar8 != (int *)0x0) {
      FUN_030f1934(0,iVar6,0x20000000);
      FUN_030eeeee(0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
      FUN_030f191c(0,iVar6,0x20000000);
      FUN_030f188a(piVar8,uVar1,iVar6,uVar4);
    }
  }
  iVar6 = iStack_2c;
  puVar3 = (undefined4 *)(param_1 + 0x28);
  puVar7 = (undefined4 *)(param_1 + 0x954);
  FUN_030ed0a6(auStack_41f8,*puVar3,0xcc);
  iVar10 = 0;
  piVar9 = piVar8;
  if (0 < iVar6) {
    do {
      puVar11 = auStack_41f8 + iVar10 * 4;
      uVar4 = FUN_030efaa4(puVar3,*puVar7,0,puVar11);
      *puVar7 = uVar4;
      iVar5 = FUN_030efaa4(puVar3,*piVar9,1,puVar11);
      iVar10 = iVar10 + 1;
      *piVar9 = iVar5;
      puVar7 = puVar7 + 1;
      piVar9 = piVar9 + 1;
    } while (iVar10 < iVar6);
  }
  FUN_030ed0a6(*puVar3,auStack_41f8 + iVar6 * 4,0xcc);
  if (0 < iStack_2c) {
    do {
      iVar6 = *piVar2;
      if (iVar6 < 0) {
        iVar10 = -(-iVar6 >> 1);
      }
      else {
        iVar10 = iVar6 >> 1;
      }
      iVar5 = *piVar8;
      iStack_2c = iStack_2c + -1;
      *piVar2 = iVar5 - iVar10;
      *piVar8 = iVar6 + (iVar5 - iVar10);
      piVar8 = piVar8 + 1;
      piVar2 = piVar2 + 1;
    } while (iStack_2c != 0);
  }
  return;
}


