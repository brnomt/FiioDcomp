/**
 * FUN_030206ea @ 0x030206ea
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint FUN_030206ea(int param_1,int param_2,uint *param_3,uint *param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [12];
  
  puVar1 = DAT_0302069c;
  iVar5 = DAT_03020698;
  if (param_2 == 0) {
    uVar3 = FUN_03020032(param_3);
    return uVar3;
  }
  if (param_2 == 1) {
    return 0;
  }
  if (param_2 != 2) {
    return 0xffffffff;
  }
  local_38 = 2;
  if (*(int *)(DAT_03020698 + 0x18) == 0) {
    return 0xffffffff;
  }
  if (((*param_3 & 0xffffff) >> 0x10 != 1) ||
     ((param_4 != (uint *)0x0 && ((*param_4 & 0xffffff) >> 0x10 != 1)))) {
    return 0xfffffffc;
  }
  uVar3 = param_3[1];
  *DAT_0302069c = (uint)(uVar3 != 0);
  *(uint *)(param_1 + 0xc4) = uVar3 & 1;
  if ((int)param_3[3] < 0) {
    if (param_4 != (uint *)0x0) {
      param_4[1] = 0;
    }
    return 0xfffffffb;
  }
  do {
    while( true ) {
      iVar4 = FUN_0301e944(iVar5,param_1,auStack_30,&local_38);
      uVar2 = local_38;
      uVar3 = *(uint *)(param_1 + 100);
      bVar8 = 0x13f < uVar3;
      bVar7 = uVar3 == 0x140;
      if (uVar3 < 0x141) {
        bVar8 = 0xef < *(uint *)(param_1 + 0x68);
        bVar7 = *(uint *)(param_1 + 0x68) == 0xf0;
      }
      if (bVar8 && !bVar7) {
        *puVar1 = 1;
      }
      if (iVar4 == -1) {
        if (param_4 != (uint *)0x0) {
          param_4[1] = 0;
        }
        FUN_0301e888(iVar5);
        uVar3 = FUN_0301e896(iVar5);
        return uVar3 >> 3;
      }
      if (iVar4 != -2) break;
LAB_0302061c:
      if (param_4 != (uint *)0x0) {
        param_4[1] = 0xffffffff;
        param_4[2] = 0;
        param_4[3] = *(uint *)(param_1 + 100);
        param_4[4] = *(uint *)(param_1 + 0x68);
        param_4[5] = *(uint *)(param_1 + 0x38);
        param_4[6] = *(uint *)(param_1 + 0x3c);
        param_4[7] = *(uint *)(param_1 + 0x40);
        FUN_0301e888(iVar5);
        uVar3 = FUN_0301e896(iVar5);
        goto LAB_03020648;
      }
    }
    if (iVar4 == -3) {
      uVar6 = uVar3 + 0xf >> 4;
      *(uint *)(param_1 + 0x74) = uVar6;
      uVar3 = *(int *)(param_1 + 0x68) + 0xfU >> 4;
      *(uint *)(param_1 + 0x78) = uVar3;
      *(uint *)(param_1 + 0x6c) = uVar6 * 0x10 + 0x80;
      *(uint *)(param_1 + 0x70) = uVar3 * 0x10 + 0x80;
      goto LAB_0302061c;
    }
    if (*(int *)(param_1 + 0x88) != 0) {
      if (iVar4 == 4 || iVar4 == 2) {
        *puVar1 = 1;
        goto LAB_030205d6;
      }
      if (iVar4 != 0) {
        *puVar1 = 1;
        goto LAB_030205b8;
      }
      goto LAB_03020654;
    }
    if (iVar4 == 0) {
LAB_03020654:
      uVar6 = *(uint *)(param_1 + 0x78);
      uVar3 = 0;
      if (uVar6 != 0) {
        do {
          FUN_030202ce(param_1,iVar5,uVar2,uStack_34);
          uVar3 = uVar3 + 1;
          *DAT_030206a0 = *DAT_030206a0 + 1;
        } while (uVar3 < uVar6);
      }
      *DAT_030206a0 = 0;
      *DAT_030206a4 = 1;
LAB_030205b8:
      if (param_4 != (uint *)0x0) {
        param_4[1] = iVar4 + 1;
      }
      *(int *)(param_1 + 0x80) = iVar4;
      *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
LAB_030205d6:
      iVar5 = FUN_0301e896(iVar5);
      uVar3 = iVar5 + 7;
LAB_03020648:
      return uVar3 >> 3;
    }
  } while( true );
}


