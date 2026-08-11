/**
 * FUN_030c6e3e @ 0x030c6e3e
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030c6e3e(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_38 [24];
  
  iVar7 = 0;
  if (param_2 != (undefined4 *)0x0) {
    FUN_030c673e(*param_2);
    FUN_030c673e(param_2[2]);
    memset_byte(param_2,0,0x10);
  }
  iVar3 = DAT_030c7028;
  iVar8 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(DAT_030c7028 + 0x10) = 0;
  FUN_030c68e6(auStack_38,*(undefined4 *)(param_1 + 8));
  if (*(int *)(iVar3 + 8) < 0xff55) {
    if (*(int *)(iVar3 + 8) == 3) {
      if (iVar8 < 0x1b) {
        return 0;
      }
      iVar1 = sbuf_byte_at(auStack_38,0);
      if ((((iVar1 != 0x4f) || (iVar1 = sbuf_byte_at(auStack_38,1), iVar1 != 0x67)) ||
          (iVar1 = sbuf_byte_at(auStack_38,2), iVar1 != 0x67)) ||
         (iVar1 = sbuf_byte_at(auStack_38,3), iVar1 != 0x53)) goto LAB_030c6f56;
      iVar1 = sbuf_byte_at(auStack_38,0x1a);
      *(int *)(param_1 + 0x14) = iVar1 + 0x1b;
      *(undefined4 *)(iVar3 + 8) = 0xffffffff;
    }
    if (*(int *)(param_1 + 0x14) == 0) {
      if (iVar8 < 0x1b) {
        return 0;
      }
      iVar1 = sbuf_byte_at(auStack_38,0);
      if (((iVar1 != 0x4f) || (iVar1 = sbuf_byte_at(auStack_38,1), iVar1 != 0x67)) ||
         ((iVar1 = sbuf_byte_at(auStack_38,2), iVar1 != 0x67 ||
          (iVar1 = sbuf_byte_at(auStack_38,3), iVar1 != 0x53)))) goto LAB_030c6f56;
      iVar1 = sbuf_byte_at(auStack_38,0x1a);
      *(int *)(param_1 + 0x14) = iVar1 + 0x1b;
      if (*(int *)(iVar3 + 0x18) != 0) {
        uVar5 = sbuf_byte_at(auStack_38);
        *(undefined4 *)(iVar3 + 8) = uVar5;
      }
    }
    if (iVar8 < *(int *)(param_1 + 0x14)) {
      return 0;
    }
    if (*(int *)(param_1 + 0x18) != 0) goto LAB_030c7046;
  }
  else {
    iVar1 = sbuf_byte_at(auStack_38,0);
    if (((iVar1 != 0x4f) || (iVar1 = sbuf_byte_at(auStack_38,1), iVar1 != 0x67)) ||
       ((iVar1 = sbuf_byte_at(auStack_38,2), iVar1 != 0x67 ||
        (iVar1 = sbuf_byte_at(auStack_38,3), iVar1 != 0x53)))) {
LAB_030c6f56:
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      piVar2 = (int *)FUN_030c67be(*(undefined4 *)(param_1 + 8),1);
      iVar7 = -1;
      *(int **)(param_1 + 8) = piVar2;
      do {
        if (piVar2 == (int *)0x0) {
LAB_030c70e2:
          *(undefined4 *)(param_1 + 4) = 0;
LAB_030c70e4:
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar7;
          return iVar7;
        }
        iVar8 = *piVar2;
        iVar1 = piVar2[1];
        iVar3 = FUN_030c0fc8(iVar8 + iVar1,0x4f,piVar2[2]);
        if (iVar3 != 0) {
          iVar3 = iVar3 - (iVar8 + iVar1);
          iVar8 = FUN_030c67be(*(undefined4 *)(param_1 + 8),iVar3);
          iVar7 = iVar7 - iVar3;
          *(int *)(param_1 + 8) = iVar8;
          if (iVar8 != 0) goto LAB_030c70e4;
          goto LAB_030c70e2;
        }
        iVar7 = iVar7 - *(int *)(*(int *)(param_1 + 8) + 8);
        piVar2 = (int *)FUN_030c67be();
        *(int **)(param_1 + 8) = piVar2;
      } while( true );
    }
    iVar1 = sbuf_byte_at(auStack_38,0x1a);
    *(int *)(param_1 + 0x14) = iVar1 + 0x1b;
    *(undefined4 *)(iVar3 + 8) = 3;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x14) + -0x1b) {
    do {
      iVar4 = sbuf_byte_at(auStack_38,iVar1 + 0x1b);
      iVar1 = iVar1 + 1;
      *(int *)(param_1 + 0x18) = iVar4 + *(int *)(param_1 + 0x18);
    } while (iVar1 < *(int *)(param_1 + 0x14) + -0x1b);
  }
  if ((*(int *)(iVar3 + 8) == 3) && (iVar1 = 0, 0 < *(int *)(param_1 + 0x14) + -0x1b)) {
    do {
      iVar4 = sbuf_byte_at(auStack_38,iVar1 + 0x1b);
      iVar6 = *(int *)(iVar3 + 0x10) + iVar4;
      *(int *)(iVar3 + 0x10) = iVar6;
      if (iVar4 != 0xff) {
        iVar6 = *(int *)(param_1 + 0x18) - iVar6;
        *(int *)(iVar3 + 0x14) = iVar6;
        *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(param_1 + 0x14);
        *(undefined4 *)(param_1 + 0xc) = 0;
        *(int *)(param_1 + 0x18) = iVar6;
        return *(int *)(iVar3 + 8);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x14) + -0x1b);
  }
  if (*(int *)(param_1 + 0x18) == *(int *)(iVar3 + 0x10)) {
    *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + 1;
    return *(int *)(iVar3 + 0x10);
  }
LAB_030c7046:
  if (*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x14) <= iVar8) {
    uVar5 = FUN_030c69b6(auStack_38,0x16);
    FUN_030c6916(auStack_38,0,0x16);
    FUN_030c6916(auStack_38,uVar5,0x16);
    if (param_2 == (undefined4 *)0x0) {
      iVar7 = FUN_030c67be(*(undefined4 *)(param_1 + 8),
                           *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x14));
      *(int *)(param_1 + 8) = iVar7;
      if (iVar7 == 0) {
        *(undefined4 *)(param_1 + 4) = 0;
      }
    }
    else {
      uVar5 = FUN_030c662c(param_1 + 8,param_1 + 4,*(undefined4 *)(param_1 + 0x14));
      *param_2 = uVar5;
      param_2[1] = *(undefined4 *)(param_1 + 0x14);
      uVar5 = FUN_030c662c(param_1 + 8,param_1 + 4,*(undefined4 *)(param_1 + 0x18));
      param_2[2] = uVar5;
      param_2[3] = *(undefined4 *)(param_1 + 0x18);
    }
    iVar7 = *(int *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    iVar7 = iVar7 + *(int *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) - iVar7;
  }
  return iVar7;
}


