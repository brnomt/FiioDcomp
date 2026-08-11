/**
 * FUN_0300016c @ 0x0300016c
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_0300016c(int param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  ushort *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  
  iVar8 = DAT_030005b8;
  puVar2 = DAT_030005b4;
  uVar10 = 0;
  if (param_1 == 0xd) {
    param_1 = 10;
LAB_03000194:
    if (*(char *)(DAT_030005b8 + 0xf) == '\x04') {
      iVar9 = func_0x02fdcf12(0,0xb);
      if (iVar9 != 0) {
        *(undefined2 *)(iVar8 + 0x42) = 1;
        goto LAB_030001fc;
      }
      if (*(char *)(iVar8 + 0xe) == '\x04') goto LAB_03000206;
      iVar9 = func_0x02fddf08(*puVar2,DAT_030005bc);
      if (iVar9 == 1) {
        func_0x02fdde60(DAT_030005b4,DAT_030005bc);
        *(undefined1 *)(iVar8 + 0x6c) = 0;
      }
      uVar7 = 4;
      *(undefined1 *)(iVar8 + 0xe) = 4;
    }
    else {
      if (*(char *)(DAT_030005b8 + 0xe) != '\x04') goto LAB_03000206;
      iVar9 = func_0x02fddf08(*DAT_030005b4,DAT_030005bc);
      if (iVar9 == 1) {
        func_0x02fdde60(DAT_030005b4,DAT_030005bc);
        *(undefined1 *)(iVar8 + 0x6c) = 0;
      }
LAB_030001fc:
      *(undefined1 *)(iVar8 + 0xe) = 2;
      uVar7 = 2;
    }
    func_0x02fde73a(uVar7);
  }
  else if (param_1 != 0) goto LAB_03000194;
LAB_03000206:
  puVar3 = DAT_030005c0;
  if (param_1 == 6) {
    iVar9 = func_0x02fddf08(*puVar2,DAT_030005bc);
    if (iVar9 == 1) {
      func_0x02fdde60(DAT_030005b4,DAT_030005bc);
    }
    *(undefined1 *)(iVar8 + 0x6c) = 0;
    *(undefined2 *)(iVar8 + 0x42) = 1;
    local_48 = CONCAT22(local_48._2_2_,1);
    FUN_02fef0a6(0xd,&local_48);
    return 1;
  }
  if (param_1 < 7) {
    switch(param_1) {
    case 0:
      iVar5 = func_0x02fddf08(*puVar2,DAT_030005bc);
      iVar9 = DAT_030005c4;
      if (iVar5 == 1) {
        *puVar3 = *(ushort *)(DAT_030005c4 + 0xf2);
        rom_hw_init(0x17c);
        local_48 = CONCAT22(*(undefined2 *)(DAT_030005d4 + (uint)*puVar3 * 6 + 2),
                            *(undefined2 *)(iVar9 + 2));
        FUN_02fef0a6(3,&local_48);
        return 1;
      }
      if (*(char *)(iVar8 + 0x6c) != '\0') {
        rom_hw_init(0x17c);
LAB_0300025e:
        iVar5 = DAT_030005c8;
        iVar9 = DAT_030005c4;
        if (*(char *)(iVar8 + 0x6c) == '\0') {
          return 0;
        }
        uVar1 = *(ushort *)(iVar8 + 0x91);
        *(ushort *)(DAT_030005c4 + 0xf2) = uVar1;
        *puVar3 = uVar1;
        uVar6 = 0;
        do {
          *(undefined2 *)(iVar5 + uVar6 * 2) = *(undefined2 *)(iVar8 + uVar6 * 2 + 0x93);
          uVar6 = uVar6 + 1 & 0xffff;
        } while (uVar6 < 0x80);
        *(undefined4 *)(iVar9 + 0x10) = DAT_030005cc;
        puVar4 = DAT_030005d0;
        *(undefined2 *)(iVar9 + 6) = *(undefined2 *)(iVar8 + 0x66);
        *puVar4 = (uint)*(ushort *)(iVar8 + 0x19f);
        func_0x02fdb37c();
        local_48 = CONCAT22(*(undefined2 *)(DAT_030005d4 + (uint)*puVar3 * 6 + 2),
                            *(undefined2 *)(iVar8 + 0x66));
        FUN_02fef0a6(3,&local_48);
        rom_hw_init(0x18c);
        return 1;
      }
      *puVar3 = 1;
      break;
    case 1:
    case 3:
    case 4:
    case 5:
      goto switchD_03000216_caseD_1;
    case 2:
      *DAT_030005c0 = (ushort)param_1;
      local_48._2_2_ = 0x61;
      if (*(short *)(iVar8 + 0x38) != 0) {
LAB_030003b6:
        local_48 = (uint)local_48._2_2_ << 0x10;
        *DAT_030005d8 = 0;
        FUN_02fef0a6(2,&local_48);
        return 1;
      }
      iVar8 = FUN_02feee98(0x1dc);
joined_r0x030003d2:
      if (iVar8 == 0) {
        local_48 = 0x460038;
        local_44 = 2;
        local_42 = 0;
        local_40 = 1;
        func_0x02fddd78(DAT_030005e0,DAT_030005dc,&local_48);
      }
      else {
        rom_hw_init2(0x16f);
      }
    default:
      goto switchD_03000216_default;
    }
  }
  else {
    if (param_1 == 10) {
      *DAT_030005c0 = 10;
      local_48 = 1;
      *DAT_030005f8 = 0;
      FUN_02fef0a6(9,&local_48);
      return 1;
    }
    if (param_1 < 0xb) {
      if (param_1 != 8) {
        return 0;
      }
      *DAT_030005c0 = 8;
      local_48._2_2_ = 0x60;
      uVar7 = func_0x02fdf458(s_U__RECORD_030005e4);
      iVar8 = FUN_02fe190a(uVar7,DAT_030005f4,3);
      if (iVar8 != 0) goto LAB_030003b6;
      iVar8 = FUN_02feee98(0x1dc);
      goto joined_r0x030003d2;
    }
    if (param_1 == 0xb) goto LAB_0300025e;
    if (param_1 != 100) {
      return 0;
    }
switchD_03000216_caseD_1:
    *DAT_030005c0 = (ushort)param_1;
  }
  if (*(short *)(iVar8 + 0x2e) == 0) {
    iVar8 = FUN_02feee98(0x1dc);
    if ((iVar8 == 0) && (iVar8 = FUN_02feee98(0x18c), iVar8 == 0)) {
      local_48 = 0x460038;
      local_44 = 2;
      local_42 = 0;
      local_40 = 1;
      func_0x02fddd78(DAT_030005e0,DAT_030005dc,&local_48);
    }
    else {
      rom_hw_init2(0x16f);
    }
  }
  else {
    local_48 = (uint)*(ushort *)(DAT_030005d4 + (uint)*puVar3 * 6 + 2) << 0x10;
    *DAT_030005d8 = 0;
    FUN_02fef0a6(2,&local_48);
    uVar10 = 1;
  }
  rom_hw_init(0x18c);
switchD_03000216_default:
  return uVar10;
}


