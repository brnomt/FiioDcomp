/**
 * FUN_0301947a @ 0x0301947a
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


void FUN_0301947a(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  ushort *puVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  puVar4 = DAT_03019670;
  uVar1 = *DAT_03019670;
  uVar2 = DAT_03019670[1];
  uVar5 = FUN_02ffef2c(1);
  uVar6 = FUN_02ffef08(2);
  *puVar4 = 0xffff;
  puVar4[1] = *DAT_03019674;
  iVar7 = ui_refresh_and_redraw(0x26);
  if ((iVar7 != 0) || (iVar7 = func_0x030037c4(0x2f), iVar7 != 0)) {
    func_0x030037a8(0xb9);
    func_0x030037a8(0xbb);
    func_0x030037a8(0xba);
    func_0x030037a8(0x1a9);
  }
  iVar7 = func_0x030037c4(0xb9);
  if (iVar7 != 0) {
    func_0x030037a8(0xba);
    FUN_02fff7da(0x161);
    func_0x030037a8(0x21);
    func_0x030037a8(0x1a9);
    FUN_02fff2ce(1);
  }
  FUN_02fff2ce(0);
  iVar7 = func_0x030037c4(0xba);
  if (iVar7 != 0) {
    FUN_02ffefd8(0,3,0x140,0x10,2,0xfe);
  }
  iVar8 = func_0x030037c4(0xbb);
  puVar3 = DAT_03019644;
  iVar7 = DAT_0301963c;
  if (iVar8 != 0) {
    uVar9 = 0;
    do {
      if (uVar9 == *puVar3) {
        func_0x030037a8(0x1b2);
      }
      else {
        iVar8 = (int)(short)((short)uVar9 * 0x37 + 0x26);
        FUN_02fffc76(0x15f,iVar8,0x1a);
        FUN_02fffc76(0x160,iVar8,(int)(short)(*(short *)(iVar7 + uVar9 * 2 + 0x77) * -5 + 0x8e));
      }
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < 5);
  }
  iVar8 = func_0x030037c4(0x1b2);
  if (iVar8 != 0) {
    FUN_02fffc76(0x15d,(int)(short)(*puVar3 * 0x37 + 0x26),0x1a);
    FUN_02fffc76(0x15e,(int)(short)(*puVar3 * 0x37 + 0x26),
                 (int)(short)(*(short *)(iVar7 + (uint)*puVar3 * 2 + 0x77) * -5 + 0x8e));
  }
  FUN_02ffef2c(uVar5);
  puVar4[1] = uVar2;
  *puVar4 = uVar1;
  FUN_02ffef08(uVar6);
  return;
}


