/**
 * FUN_03011192 @ 0x03011192
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_03011192(int param_1)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = DAT_030114c8;
  bVar2 = false;
  uVar7 = 1;
  *(undefined4 *)(DAT_030114c8 + 0x40) = 0;
  *(undefined4 *)(iVar5 + 0x44) = 0;
  *(undefined4 *)(iVar5 + 0x48) = 0;
  *(undefined4 *)(iVar5 + 0x4c) = 0;
  bVar4 = false;
  if (*(char *)(iVar5 + 9) == 'X') {
    *(undefined4 *)(iVar5 + 0x30) = 0;
    *(undefined4 *)(iVar5 + 0x34) = 0;
    *(undefined4 *)(iVar5 + 0x20) = 1;
    *(undefined4 *)(iVar5 + 0x24) = 0;
    *(undefined1 *)(iVar5 + 4) = 0;
  }
  else {
    *(undefined4 *)(iVar5 + 0x28) = 0;
    *(undefined4 *)(iVar5 + 0x2c) = 0;
    *(undefined4 *)(iVar5 + 0x30) = 0;
    *(undefined4 *)(iVar5 + 0x34) = 0;
    *(undefined4 *)(iVar5 + 0x18) = 1;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    *(undefined4 *)(iVar5 + 0x20) = 1;
    *(undefined4 *)(iVar5 + 0x24) = 0;
    *(undefined1 *)(iVar5 + 3) = 0;
    *(undefined1 *)(iVar5 + 4) = 0;
    do {
      uVar8 = (uint)*(byte *)(iVar5 + 0x65 + uVar7);
      if (uVar8 == 0x12) {
        bVar2 = true;
        *(undefined1 *)(iVar5 + 3) = 1;
        bVar4 = bVar2;
      }
      else {
        if (uVar8 == 0xff) break;
        if (bVar2) {
          *(ulonglong *)(iVar5 + 0x40) =
               (ulonglong)*(uint *)(iVar5 + 0x40) * 10 + CONCAT44(*(int *)(iVar5 + 0x44) * 10,uVar8)
          ;
          *(byte *)(iVar5 + 3) = bVar4 + 1U;
          lVar1 = (ulonglong)*(uint *)(iVar5 + 0x18) * 10;
          *(int *)(iVar5 + 0x18) = (int)lVar1;
          *(int *)(iVar5 + 0x1c) = *(int *)(iVar5 + 0x1c) * 10 + (int)((ulonglong)lVar1 >> 0x20);
          bVar4 = (bool)(bVar4 + 1U & 1);
        }
        else {
          *(ulonglong *)(iVar5 + 0x28) =
               (ulonglong)*(uint *)(iVar5 + 0x28) * 10 + CONCAT44(*(int *)(iVar5 + 0x2c) * 10,uVar8)
          ;
        }
      }
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < 0x16);
  }
  iVar6 = DAT_030114cc;
  bVar2 = false;
  cVar3 = '\0';
  uVar7 = 1;
  do {
    uVar8 = (uint)*(byte *)(iVar6 + uVar7);
    if (uVar8 == 0x12) {
      bVar2 = true;
      cVar3 = '\x01';
      *(undefined1 *)(iVar5 + 4) = 1;
    }
    else {
      if (uVar8 == 0xff) break;
      if (bVar2) {
        cVar3 = cVar3 + '\x01';
        *(ulonglong *)(iVar5 + 0x48) =
             (ulonglong)*(uint *)(iVar5 + 0x48) * 10 + CONCAT44(*(int *)(iVar5 + 0x4c) * 10,uVar8);
        *(char *)(iVar5 + 4) = cVar3;
        lVar1 = (ulonglong)*(uint *)(iVar5 + 0x20) * 10;
        *(int *)(iVar5 + 0x20) = (int)lVar1;
        *(int *)(iVar5 + 0x24) = *(int *)(iVar5 + 0x24) * 10 + (int)((ulonglong)lVar1 >> 0x20);
      }
      else {
        *(ulonglong *)(iVar5 + 0x30) =
             (ulonglong)*(uint *)(iVar5 + 0x30) * 10 + CONCAT44(*(int *)(iVar5 + 0x34) * 10,uVar8);
      }
    }
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 0x16);
  if (param_1 == 0) {
    return;
  }
  if (*(char *)(iVar5 + 9) != 'X') {
    uVar7 = *(uint *)(iVar5 + 0x28);
    lVar1 = (ulonglong)uVar7 * (ulonglong)*(uint *)(iVar5 + 0x18);
    uVar8 = (uint)lVar1;
    *(uint *)(iVar5 + 0x28) = uVar8 + *(uint *)(iVar5 + 0x40);
    *(uint *)(iVar5 + 0x2c) =
         *(int *)(iVar5 + 0x44) +
         uVar7 * *(int *)(iVar5 + 0x1c) +
         *(int *)(iVar5 + 0x2c) * *(uint *)(iVar5 + 0x18) + (int)((ulonglong)lVar1 >> 0x20) +
         (uint)CARRY4(uVar8,*(uint *)(iVar5 + 0x40));
  }
  uVar7 = *(uint *)(iVar5 + 0x30);
  lVar1 = (ulonglong)uVar7 * (ulonglong)*(uint *)(iVar5 + 0x20);
  uVar8 = (uint)lVar1;
  *(uint *)(iVar5 + 0x30) = uVar8 + *(uint *)(iVar5 + 0x48);
  *(uint *)(iVar5 + 0x34) =
       uVar7 * *(int *)(iVar5 + 0x24) +
       *(int *)(iVar5 + 0x34) * *(uint *)(iVar5 + 0x20) + (int)((ulonglong)lVar1 >> 0x20) +
       *(int *)(iVar5 + 0x4c) + (uint)CARRY4(uVar8,*(uint *)(iVar5 + 0x48));
  *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar5 + 0x18);
  *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar5 + 0x1c);
  *(undefined4 *)(iVar5 + 0x38) = *(undefined4 *)(iVar5 + 0x28);
  *(undefined4 *)(iVar5 + 0x3c) = *(undefined4 *)(iVar5 + 0x2c);
  *(undefined1 *)(iVar5 + 5) = *(undefined1 *)(iVar5 + 3);
  *(undefined1 *)(iVar5 + 0xc) = *DAT_030114d0;
  return;
}


