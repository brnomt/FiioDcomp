/**
 * FUN_030111fe @ 0x030111fe
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030111fe(uint param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  longlong lVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint unaff_r4;
  int unaff_r7;
  int unaff_r8;
  int unaff_r9;
  uint uVar6;
  int unaff_lr;
  bool bVar7;
  
  bVar7 = (param_1 & 0x1000000) != 0;
  iVar4 = param_1 << 8;
  do {
    uVar3 = param_1 + 1;
    *(int *)(unaff_r7 + 0x40) = iVar4;
    *(uint *)(unaff_r7 + 0x44) = param_4 + unaff_r8 + (uint)bVar7;
    param_1 = uVar3 & 0xff;
    *(char *)(unaff_r7 + 3) = (char)uVar3;
    lVar1 = (ulonglong)*(uint *)(unaff_r7 + 0x18) * 10;
    *(int *)(unaff_r7 + 0x18) = (int)lVar1;
    *(int *)(unaff_r7 + 0x1c) = *(int *)(unaff_r7 + 0x1c) * 10 + (int)((ulonglong)lVar1 >> 0x20);
LAB_03011226:
    iVar4 = DAT_030114cc;
    param_2 = param_2 + 1 & 0xff;
    if (0x15 < param_2) {
LAB_0301122e:
      bVar7 = false;
      cVar2 = '\0';
      uVar3 = 1;
      break;
    }
    uVar3 = (uint)*(byte *)(unaff_lr + param_2);
    if (uVar3 == 0x12) {
      param_1 = 1;
      *(undefined1 *)(unaff_r7 + 3) = 1;
      unaff_r4 = param_1;
      goto LAB_03011226;
    }
    if (uVar3 == 0xff) goto LAB_0301122e;
    if (unaff_r4 == 0) {
      lVar1 = (ulonglong)*(uint *)(unaff_r7 + 0x28) * 10;
      uVar5 = (uint)lVar1;
      *(uint *)(unaff_r7 + 0x28) = uVar5 + uVar3;
      *(uint *)(unaff_r7 + 0x2c) =
           *(int *)(unaff_r7 + 0x2c) * 10 + (int)((ulonglong)lVar1 >> 0x20) +
           unaff_r8 + (uint)CARRY4(uVar5,uVar3);
      goto LAB_03011226;
    }
    lVar1 = (ulonglong)*(uint *)(unaff_r7 + 0x40) * 10;
    uVar5 = (uint)lVar1;
    param_4 = *(int *)(unaff_r7 + 0x44) * 10 + (int)((ulonglong)lVar1 >> 0x20);
    bVar7 = CARRY4(uVar5,uVar3);
    iVar4 = uVar5 + uVar3;
  } while( true );
  do {
    uVar5 = (uint)*(byte *)(iVar4 + uVar3);
    if (uVar5 == 0x12) {
      bVar7 = true;
      cVar2 = '\x01';
      *(undefined1 *)(unaff_r7 + 4) = 1;
    }
    else {
      if (uVar5 == 0xff) break;
      if (bVar7) {
        lVar1 = (ulonglong)*(uint *)(unaff_r7 + 0x48) * 10;
        uVar6 = (uint)lVar1;
        cVar2 = cVar2 + '\x01';
        *(uint *)(unaff_r7 + 0x48) = uVar6 + uVar5;
        *(uint *)(unaff_r7 + 0x4c) =
             *(int *)(unaff_r7 + 0x4c) * 10 + (int)((ulonglong)lVar1 >> 0x20) +
             unaff_r8 + (uint)CARRY4(uVar6,uVar5);
        *(char *)(unaff_r7 + 4) = cVar2;
        lVar1 = (ulonglong)*(uint *)(unaff_r7 + 0x20) * 10;
        *(int *)(unaff_r7 + 0x20) = (int)lVar1;
        *(int *)(unaff_r7 + 0x24) = *(int *)(unaff_r7 + 0x24) * 10 + (int)((ulonglong)lVar1 >> 0x20)
        ;
      }
      else {
        lVar1 = (ulonglong)*(uint *)(unaff_r7 + 0x30) * 10;
        uVar6 = (uint)lVar1;
        *(uint *)(unaff_r7 + 0x30) = uVar6 + uVar5;
        *(uint *)(unaff_r7 + 0x34) =
             *(int *)(unaff_r7 + 0x34) * 10 + (int)((ulonglong)lVar1 >> 0x20) +
             unaff_r8 + (uint)CARRY4(uVar6,uVar5);
      }
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0x16);
  if (param_5 == 0) {
    return;
  }
  if (unaff_r9 != 0x58) {
    uVar3 = *(uint *)(unaff_r7 + 0x28);
    lVar1 = (ulonglong)uVar3 * (ulonglong)*(uint *)(unaff_r7 + 0x18);
    uVar5 = (uint)lVar1;
    *(uint *)(unaff_r7 + 0x28) = uVar5 + *(uint *)(unaff_r7 + 0x40);
    *(uint *)(unaff_r7 + 0x2c) =
         *(int *)(unaff_r7 + 0x44) +
         uVar3 * *(int *)(unaff_r7 + 0x1c) +
         *(int *)(unaff_r7 + 0x2c) * *(uint *)(unaff_r7 + 0x18) + (int)((ulonglong)lVar1 >> 0x20) +
         (uint)CARRY4(uVar5,*(uint *)(unaff_r7 + 0x40));
  }
  uVar3 = *(uint *)(unaff_r7 + 0x30);
  lVar1 = (ulonglong)uVar3 * (ulonglong)*(uint *)(unaff_r7 + 0x20);
  uVar5 = (uint)lVar1;
  *(uint *)(unaff_r7 + 0x30) = uVar5 + *(uint *)(unaff_r7 + 0x48);
  *(uint *)(unaff_r7 + 0x34) =
       uVar3 * *(int *)(unaff_r7 + 0x24) +
       *(int *)(unaff_r7 + 0x34) * *(uint *)(unaff_r7 + 0x20) + (int)((ulonglong)lVar1 >> 0x20) +
       *(int *)(unaff_r7 + 0x4c) + (uint)CARRY4(uVar5,*(uint *)(unaff_r7 + 0x48));
  *(undefined4 *)(unaff_r7 + 0x10) = *(undefined4 *)(unaff_r7 + 0x18);
  *(undefined4 *)(unaff_r7 + 0x14) = *(undefined4 *)(unaff_r7 + 0x1c);
  *(undefined4 *)(unaff_r7 + 0x38) = *(undefined4 *)(unaff_r7 + 0x28);
  *(undefined4 *)(unaff_r7 + 0x3c) = *(undefined4 *)(unaff_r7 + 0x2c);
  *(undefined1 *)(unaff_r7 + 5) = *(undefined1 *)(unaff_r7 + 3);
  *(undefined1 *)(unaff_r7 + 0xc) = *DAT_030114d0;
  return;
}


