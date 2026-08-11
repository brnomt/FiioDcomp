/**
 * FUN_030506de @ 0x030506de
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


int FUN_030506de(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_r4;
  undefined4 uVar4;
  int iVar5;
  uint in_stack_00000004;
  
  cVar1 = *(char *)(DAT_030509b0 + 0x218);
  if (cVar1 == '\0') {
    uVar4 = 4;
  }
  else if (cVar1 == '\x01') {
    uVar4 = 6;
  }
  else {
    uVar4 = unaff_r4;
    if (cVar1 == '\x02') {
      uVar4 = 8;
    }
  }
  uVar3 = *(undefined4 *)(DAT_030509a4 + 0x18);
  switch(param_1) {
  case 0:
    FUN_0303323a(6,uVar3);
                    /* WARNING: Call to offcut address within same function */
    func_0x03023368(2);
    FUN_0302336a(uVar4);
    break;
  case 1:
    iVar5 = FUN_0303323a(2,uVar3);
    return iVar5;
  case 2:
    FUN_0303323a(4,uVar3);
    FUN_0302336a(uVar4);
    break;
  case 3:
    FUN_0303323a(7,uVar3);
                    /* WARNING: Call to offcut address within same function */
    func_0x03023368(2);
    FUN_0302336a(uVar4);
    break;
  case 4:
    FUN_0303323a(8,uVar3);
                    /* WARNING: Call to offcut address within same function */
    func_0x03023368(2);
    FUN_0302336a(uVar4);
    break;
  default:
    return DAT_030509a4;
  }
  iVar5 = (in_stack_00000004 >> 0x18) + in_stack_00000004 * 0x1000000 +
          (in_stack_00000004 >> 8 & 0xff) * 0x10000 + (in_stack_00000004 >> 0x10 & 0xff) * 0x100;
  if (0x200 < iVar5) {
    iVar5 = 0x200;
  }
  iVar2 = FUN_02ffc9d6(&stack0x0000000c,6,unaff_r4);
  if ((0 < iVar2) && (-1 < iVar5)) {
    iVar5 = FUN_02ff89ce(&stack0x0000000c,s_image__03023674,6);
    return iVar5;
  }
  return 0;
}


