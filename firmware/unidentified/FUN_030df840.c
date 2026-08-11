/**
 * FUN_030df840 @ 0x030df840
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030df840(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_r6;
  int *piVar4;
  int unaff_r9;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(param_1 + 0x30);
  iVar1 = param_1 + param_2 * 0x4800;
  piVar4 = (int *)(iVar1 + 0x48);
  hifi_flac_helper(param_1 + 0x20,0x400);
  iVar6 = 0;
  if (0 < param_3) {
    do {
      iVar2 = flac_bitstream_getbits_s(param_1 + 0x20,*(undefined4 *)(param_1 + 0x34));
      piVar4[iVar6] = iVar2;
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_3);
  }
  iVar6 = hifi_flac_dec(param_1,param_2,param_3);
  if (-1 < iVar6) {
    if (0 < param_3) {
      param_1 = piVar4[param_3 + -1];
    }
    if (1 < param_3) {
      param_2 = param_1 - piVar4[param_3 + -2];
    }
    if (2 < param_3) {
      unaff_r6 = (param_2 - piVar4[param_3 + -2]) + piVar4[param_3 + -3];
    }
    if (3 < param_3) {
      unaff_r9 = ((unaff_r6 - piVar4[param_3 + -2]) + piVar4[param_3 + -3] * 2) -
                 piVar4[param_3 + -4];
    }
    switch(param_3) {
    case 0:
      break;
    case 1:
      uVar3 = iVar5 - 1;
      if (0 < (int)uVar3) {
        if ((uVar3 & 1) != 0) {
          piVar4 = (int *)(iVar1 + 0x4c);
          param_1 = param_1 + *piVar4;
          *piVar4 = param_1;
        }
        for (iVar1 = (int)uVar3 >> 1; iVar1 != 0; iVar1 = iVar1 + -1) {
          iVar5 = piVar4[1];
          piVar4[1] = iVar5 + param_1;
          piVar4 = piVar4 + 2;
          param_1 = *piVar4 + iVar5 + param_1;
          *piVar4 = param_1;
        }
      }
      break;
    case 2:
      uVar3 = iVar5 - 2;
      if (0 < (int)uVar3) {
        piVar4 = (int *)(iVar1 + 0x4c);
        if ((uVar3 & 1) != 0) {
          piVar4 = (int *)(iVar1 + 0x50);
          param_2 = param_2 + *piVar4;
          param_1 = param_1 + param_2;
          *piVar4 = param_1;
        }
        for (iVar1 = (int)uVar3 >> 1; iVar1 != 0; iVar1 = iVar1 + -1) {
          iVar5 = piVar4[1];
          param_1 = param_1 + iVar5 + param_2;
          piVar4[1] = param_1;
          piVar4 = piVar4 + 2;
          param_2 = *piVar4 + iVar5 + param_2;
          param_1 = param_1 + param_2;
          *piVar4 = param_1;
        }
      }
      break;
    case 3:
      uVar3 = iVar5 - 3;
      if (0 < (int)uVar3) {
        piVar4 = (int *)(iVar1 + 0x50);
        if ((uVar3 & 1) != 0) {
          piVar4 = (int *)(iVar1 + 0x54);
          unaff_r6 = unaff_r6 + *piVar4;
          param_2 = param_2 + unaff_r6;
          param_1 = param_1 + param_2;
          *piVar4 = param_1;
        }
        for (iVar1 = (int)uVar3 >> 1; iVar1 != 0; iVar1 = iVar1 + -1) {
          iVar5 = piVar4[1];
          param_2 = param_2 + iVar5 + unaff_r6;
          param_1 = param_1 + param_2;
          piVar4[1] = param_1;
          piVar4 = piVar4 + 2;
          unaff_r6 = *piVar4 + iVar5 + unaff_r6;
          param_2 = param_2 + unaff_r6;
          param_1 = param_1 + param_2;
          *piVar4 = param_1;
        }
      }
      break;
    case 4:
      uVar3 = iVar5 - 4;
      if (0 < (int)uVar3) {
        piVar4 = (int *)(iVar1 + 0x54);
        if ((uVar3 & 1) != 0) {
          piVar4 = (int *)(iVar1 + 0x58);
          unaff_r9 = unaff_r9 + *piVar4;
          unaff_r6 = unaff_r6 + unaff_r9;
          param_2 = param_2 + unaff_r6;
          param_1 = param_1 + param_2;
          *piVar4 = param_1;
        }
        for (iVar1 = (int)uVar3 >> 1; iVar1 != 0; iVar1 = iVar1 + -1) {
          iVar5 = piVar4[1];
          iVar6 = unaff_r6 + iVar5 + unaff_r9;
          param_2 = param_2 + iVar6;
          param_1 = param_1 + param_2;
          piVar4[1] = param_1;
          piVar4 = piVar4 + 2;
          unaff_r9 = *piVar4 + iVar5 + unaff_r9;
          unaff_r6 = iVar6 + unaff_r9;
          param_2 = param_2 + unaff_r6;
          param_1 = param_1 + param_2;
          *piVar4 = param_1;
        }
      }
      break;
    default:
      goto LAB_030df9f2;
    }
    return 0;
  }
LAB_030df9f2:
  return 0xffffffff;
}


