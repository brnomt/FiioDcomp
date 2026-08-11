/**
 * FUN_030256b6 @ 0x030256b6
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x030257be) */
/* WARNING: Removing unreachable block (ram,0x03025826) */
/* WARNING: Removing unreachable block (ram,0x0302582e) */
/* WARNING: Removing unreachable block (ram,0x03025840) */
/* WARNING: Removing unreachable block (ram,0x03025842) */
/* WARNING: Removing unreachable block (ram,0x03025844) */
/* WARNING: Removing unreachable block (ram,0x03025846) */
/* WARNING: Removing unreachable block (ram,0x03025854) */
/* WARNING: Removing unreachable block (ram,0x03025866) */
/* WARNING: Removing unreachable block (ram,0x0302585e) */
/* WARNING: Removing unreachable block (ram,0x03025876) */
/* WARNING: Removing unreachable block (ram,0x03025886) */
/* WARNING: Removing unreachable block (ram,0x03025892) */
/* WARNING: Removing unreachable block (ram,0x030258a6) */
/* WARNING: Removing unreachable block (ram,0x0302589e) */
/* WARNING: Removing unreachable block (ram,0x030258a4) */
/* WARNING: Removing unreachable block (ram,0x030258dc) */
/* WARNING: Removing unreachable block (ram,0x03025940) */
/* WARNING: Removing unreachable block (ram,0x030258f8) */
/* WARNING: Removing unreachable block (ram,0x03025906) */
/* WARNING: Removing unreachable block (ram,0x03025908) */
/* WARNING: Removing unreachable block (ram,0x0302590a) */
/* WARNING: Removing unreachable block (ram,0x03025918) */
/* WARNING: Removing unreachable block (ram,0x0302592a) */
/* WARNING: Removing unreachable block (ram,0x03025938) */
/* WARNING: Removing unreachable block (ram,0x03025998) */
/* WARNING: Removing unreachable block (ram,0x030259a8) */
/* WARNING: Removing unreachable block (ram,0x030258c0) */
/* WARNING: Removing unreachable block (ram,0x030258c2) */
/* WARNING: Removing unreachable block (ram,0x030258c8) */
/* WARNING: Removing unreachable block (ram,0x030258ca) */
/* WARNING: Removing unreachable block (ram,0x030258ce) */
/* WARNING: Removing unreachable block (ram,0x030258da) */
/* WARNING: Removing unreachable block (ram,0x030259ba) */
/* WARNING: Removing unreachable block (ram,0x030259c4) */
/* WARNING: Removing unreachable block (ram,0x030259c6) */

int FUN_030256b6(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  
  cVar1 = (char)param_1;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  uVar2 = FUN_02ffc9d6(&local_60,0x1e);
  if (0x1d < uVar2) {
    local_64 = FUN_02ffce8c((int)cVar1);
    local_90 = *(undefined4 *)(DAT_03025944 + 0x74);
    local_8c = *(undefined4 *)(DAT_03025944 + 0x78);
    local_88 = *(undefined4 *)(DAT_03025944 + 0x7c);
    local_84 = *(undefined4 *)(DAT_03025944 + 0x80);
    local_80 = *(undefined4 *)(DAT_03025944 + 0x84);
    local_a8 = 0;
    local_94 = 0;
    local_a4 = 0;
    local_a0 = 0;
    local_9c = 0;
    local_98 = 0;
    if (0 < local_48) {
      local_7c = FUN_02ffce8c((int)cVar1);
      uVar2 = FUN_02ffc9d6(&local_a8,0x18,(int)cVar1);
      if (0x17 < uVar2) {
        iVar3 = FUN_02ff89ce(&local_a8,&local_90,0x10);
        return iVar3;
      }
    }
    iVar3 = FUN_02ffcece(local_64,0,(int)cVar1);
    if (((iVar3 == 0) && (iVar3 = FUN_030261be(param_1,local_48), -1 < iVar3)) &&
       (iVar3 = FUN_03024614(param_1), -1 < iVar3)) {
      return iVar3;
    }
  }
  return -1;
}


