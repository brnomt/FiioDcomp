/**
 * FUN_03064746 @ 0x03064746
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_03064746(undefined4 param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar2 = DAT_03064890;
  iVar3 = DAT_0306487c;
  switch(param_1) {
  case 0xab:
    *(undefined4 *)(DAT_0306487c + 0xc) = *DAT_03064890;
    FUN_030646f8();
    (**(code **)(iVar3 + 0x24))(*(undefined1 *)(DAT_03064894 + 0x1c0));
    FUN_030376b8(100);
    (**(code **)(iVar3 + 0x40))(1);
    *(undefined4 *)(iVar3 + 0xc) = *puVar2;
    FUN_0303a488(0xb7);
    return 1;
  case 0xac:
    *DAT_03064898 = 0;
    FUN_0303a488(0xa2);
    iVar3 = DAT_0306487c;
    iVar6 = *(int *)(DAT_0306487c + 0x14);
    (**(code **)(DAT_0306487c + 0x28))
              (*(undefined4 *)(iVar6 + 0xc),1,*(undefined1 *)(iVar6 + 8),*(undefined2 *)(iVar6 + 4))
    ;
    if (param_2 != 0) {
      (**(code **)(iVar3 + 0x40))(0);
    }
    if (*(char *)(*(int *)(iVar3 + 0x14) + 8) != '\x01') {
      return 1;
    }
    uVar5 = 0;
    uVar4 = 0xb4;
    goto LAB_03064872;
  case 0xad:
    FUN_03064690();
    break;
  case 0xae:
    iVar3 = FUN_03064616(param_2);
    goto joined_r0x03064808;
  case 0xaf:
    iVar3 = FUN_030645c8(param_2);
joined_r0x03064808:
    if (iVar3 != 0) {
      return 1;
    }
    break;
  case 0xb0:
    cVar1 = *(char *)(DAT_03064894 + 0x1c1);
    *(char *)(*(int *)(DAT_0306487c + 0x14) + 8) = cVar1;
    (**(code **)(DAT_03064884 + 8))(cVar1 != '\x01');
    break;
  case 0xb1:
    FUN_0306444c(*(undefined2 *)(*(int *)(DAT_0306487c + 0x14) + 2),10);
    iVar3 = *(int *)(iVar3 + 0x14);
    *(uint *)(iVar3 + 0xc) =
         (uint)((ulonglong)DAT_03064880 * (ulonglong)*(uint *)(iVar3 + 0xc) >> 0x23) * 10;
    *(undefined2 *)(iVar3 + 10) = 0;
    break;
  case 0xb2:
    break;
  case 0xb3:
    if (*(short *)(*(int *)(DAT_0306487c + 0x14) + 2) == 0) {
      FUN_03064360();
    }
    else {
      FUN_030643c0();
    }
    FUN_0303a488(0x8b);
    goto LAB_0306486e;
  case 0xb4:
    FUN_0303a488(0x8a);
    return 1;
  case 0xb5:
    FUN_030642f4(0);
    iVar3 = DAT_03064cac;
    (**(code **)(DAT_03064cac + 0x1c))(1);
    (**(code **)(iVar3 + 0x10))();
    return 1;
  case 0xb6:
    FUN_030642f4(*(undefined1 *)(DAT_03064894 + 0x12));
    if (*DAT_0306489c != '\0') {
      return 1;
    }
    *DAT_0306489c = '\x01';
    return 1;
  default:
    return 0;
  }
LAB_0306486e:
  uVar5 = 1;
  uVar4 = 0xac;
LAB_03064872:
  FUN_03064746(uVar4,uVar5);
  return 1;
}


