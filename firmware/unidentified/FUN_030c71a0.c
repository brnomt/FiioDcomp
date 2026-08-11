/**
 * FUN_030c71a0 @ 0x030c71a0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_030c71a0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  undefined8 uVar9;
  int *piStack_50;
  int *piStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined1 auStack_3c [24];
  
  if ((param_1[0xd] & 0x80000000) != 0) {
    return;
  }
  do {
    iVar1 = param_1[1];
    if (iVar1 == 0) {
      return;
    }
    if (-1 < (int)param_1[0xc]) {
      iVar1 = FUN_030c67be(iVar1,param_1[0xc] + 0x1b);
      param_1[1] = iVar1;
    }
    param_1[0xc] = 0;
    param_1[0x11] = 0;
    param_1[0x10] = 0;
    if (iVar1 == 0) {
      *param_1 = 0;
      return;
    }
    iVar2 = FUN_030c68e6(auStack_3c);
    if (iVar2 == 0) {
      iVar2 = FUN_030c69b6(auStack_3c,0x12);
    }
    else {
      iVar2 = -1;
    }
    piVar7 = (int *)param_1[1];
    memset_byte(&piStack_50,0,0x14);
    if (piVar7 != (int *)0x0) {
      uStack_44 = 0;
      iStack_40 = piVar7[2];
      iStack_48 = *piVar7 + piVar7[1];
      piStack_50 = piVar7;
      piStack_4c = piVar7;
    }
    uVar3 = sbuf_byte_at(&piStack_50,0x1a);
    param_1[0xc] = uVar3;
    if (1 < iVar2) {
      param_1[7] = iVar2;
    }
    if (param_1[7] != iVar2) {
      if (param_1[7] == -1) {
        param_1[0xe] = 1;
      }
      else {
        param_1[0xe] = 2;
      }
      iVar4 = FUN_030c67be(param_1[3],param_1[0xd]);
      param_1[3] = iVar4;
      if (iVar4 == 0) {
        param_1[2] = 0;
      }
      param_1[0xd] = 0;
    }
    iVar4 = FUN_030c68e6(auStack_3c,iVar1);
    if ((iVar4 == 0) && (uVar5 = sbuf_byte_at(auStack_3c,5), (uVar5 & 1) == 0)) {
      if (param_1[0xd] != 0) {
        iVar4 = FUN_030c67be(param_1[3]);
        param_1[3] = iVar4;
        if (iVar4 == 0) {
          param_1[2] = 0;
        }
        param_1[0xd] = 0;
        iVar4 = param_1[0xf];
        bVar8 = iVar4 == 0;
        if (bVar8) {
          iVar4 = param_1[0xe];
        }
        if (bVar8 && iVar4 == 0) {
LAB_030c730a:
          param_1[0xf] = 2;
        }
      }
    }
    else if (param_1[0xd] == 0) {
      param_1[0x12] = 0;
      iVar4 = param_1[0x11];
      if (iVar4 < (int)param_1[0xc]) {
        do {
          param_1[0x11] = iVar4 + 1;
          iVar4 = sbuf_byte_at(&piStack_50,iVar4 + 0x1b);
          iVar6 = param_1[0x12];
          param_1[0x12] = iVar6 + iVar4;
          if (iVar4 < 0xff) {
            param_1[0x10] = 1;
            param_1[0x12] = iVar6 + iVar4 | 0x80000000;
            break;
          }
          iVar4 = param_1[0x11];
        } while (iVar4 < (int)param_1[0xc]);
      }
      iVar4 = FUN_030c67be(param_1[3],param_1[0x12] & 0x7fffffff);
      param_1[3] = iVar4;
      if (iVar4 == 0) {
        param_1[2] = 0;
      }
      iVar4 = param_1[0xf];
      bVar8 = iVar4 == 0;
      if (bVar8) {
        iVar4 = param_1[0xe];
      }
      if (bVar8 && iVar4 == 0) goto LAB_030c730a;
    }
    if ((int)param_1[0x11] < (int)param_1[0xc]) {
      iVar4 = FUN_030c68e6(auStack_3c,iVar1);
      if (iVar4 == 0) {
        uVar9 = FUN_030c6a2a(auStack_3c,6);
      }
      else {
        uVar9 = 0xffffffffffffffff;
      }
      param_1[0x12] = 0;
      *(undefined8 *)(param_1 + 10) = uVar9;
      iVar4 = param_1[0x11];
      if (iVar4 < (int)param_1[0xc]) {
        do {
          param_1[0x11] = iVar4 + 1;
          iVar4 = sbuf_byte_at(&piStack_50,iVar4 + 0x1b);
          iVar6 = param_1[0x12];
          param_1[0x12] = iVar6 + iVar4;
          if (iVar4 < 0xff) {
            param_1[0x10] = 1;
            param_1[0x12] = iVar6 + iVar4 | 0x80000000;
            break;
          }
          iVar4 = param_1[0x11];
        } while (iVar4 < (int)param_1[0xc]);
      }
      iVar4 = param_1[0x12];
      param_1[0x12] = 0;
      param_1[0xd] = param_1[0xd] + iVar4;
      iVar4 = param_1[0x11];
      if (iVar4 < (int)param_1[0xc]) {
        do {
          param_1[0x11] = iVar4 + 1;
          iVar4 = sbuf_byte_at(&piStack_50,iVar4 + 0x1b);
          iVar6 = param_1[0x12];
          param_1[0x12] = iVar6 + iVar4;
          if (iVar4 < 0xff) {
            param_1[0x10] = 1;
            param_1[0x12] = iVar6 + iVar4 | 0x80000000;
            break;
          }
          iVar4 = param_1[0x11];
        } while (iVar4 < (int)param_1[0xc]);
      }
    }
    param_1[7] = iVar2 + 1;
    iVar2 = FUN_030c68e6(auStack_3c,iVar1);
    if (iVar2 == 0) {
      uVar5 = sbuf_byte_at(auStack_3c,5);
      uVar5 = uVar5 & 4;
    }
    else {
      uVar5 = 0xffffffff;
    }
    param_1[4] = uVar5;
    iVar1 = FUN_030c68e6(auStack_3c,iVar1);
    if (iVar1 == 0) {
      uVar5 = sbuf_byte_at(auStack_3c,5);
      uVar5 = uVar5 & 2;
    }
    else {
      uVar5 = 0xffffffff;
    }
    param_1[5] = uVar5;
    if ((param_1[0xd] & 0x80000000) != 0) {
      return;
    }
  } while( true );
}


