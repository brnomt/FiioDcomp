/**
 * MediaGetFilePathByCurNum @ 0x030245f0
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */

/* WARNING: Removing unreachable block (ram,0x030255e2) */
/* WARNING: Removing unreachable block (ram,0x030255ec) */
/* WARNING: Removing unreachable block (ram,0x03025638) */
/* WARNING: Removing unreachable block (ram,0x030255da) */

void MediaGetFilePathByCurNum(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  iVar2 = DAT_03025534;
  USBMSCHost_Read(0,0,(int)*(char *)(DAT_03025534 + 8));
  iVar1 = DAT_0302552c;
  *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 10) = 0;
  *(undefined4 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(iVar1 + 0x12) = 0;
  iVar3 = DAT_03025944;
  *(undefined1 *)(iVar1 + 0x14) = 0;
  uStack_38 = *(undefined4 *)(iVar3 + 8);
  uStack_34 = *(undefined4 *)(iVar3 + 0xc);
  uStack_30 = *(undefined4 *)(iVar3 + 0x10);
  uStack_2c = *(undefined4 *)(iVar3 + 0x14);
  uStack_28 = *(undefined4 *)(iVar3 + 0x18);
  uStack_50 = 0;
  uStack_3c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uVar4 = memset(&uStack_58,0x10,(int)*(char *)(iVar2 + 8));
  if ((9 < uVar4) && (0 < (int)uVar4)) {
    rkos_memory_malloc(&uStack_58,&DAT_03025530,3);
    return;
  }
  *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 10) = 0;
  *(undefined4 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(iVar1 + 0x12) = 0;
  *(undefined1 *)(iVar1 + 0x14) = 0;
  USBMSCHost_Read(0,0,(int)*(char *)(iVar2 + 8));
  return;
}
