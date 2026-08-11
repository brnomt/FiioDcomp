/**
 * FUN_030251a2 @ 0x030251a2
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


/* WARNING: Removing unreachable block (ram,0x0302524c) */
/* WARNING: Removing unreachable block (ram,0x030252e6) */
/* WARNING: Removing unreachable block (ram,0x03025256) */
/* WARNING: Removing unreachable block (ram,0x0302525a) */
/* WARNING: Removing unreachable block (ram,0x03025260) */
/* WARNING: Removing unreachable block (ram,0x030252ec) */
/* WARNING: Removing unreachable block (ram,0x03025304) */
/* WARNING: Removing unreachable block (ram,0x03025322) */
/* WARNING: Removing unreachable block (ram,0x03025330) */
/* WARNING: Removing unreachable block (ram,0x0302533e) */
/* WARNING: Removing unreachable block (ram,0x03025348) */
/* WARNING: Removing unreachable block (ram,0x03025358) */
/* WARNING: Removing unreachable block (ram,0x03025368) */
/* WARNING: Removing unreachable block (ram,0x03025382) */
/* WARNING: Removing unreachable block (ram,0x03025390) */
/* WARNING: Removing unreachable block (ram,0x030253a4) */
/* WARNING: Removing unreachable block (ram,0x03025270) */
/* WARNING: Removing unreachable block (ram,0x03025288) */
/* WARNING: Removing unreachable block (ram,0x03025386) */
/* WARNING: Removing unreachable block (ram,0x03025290) */
/* WARNING: Removing unreachable block (ram,0x0302529e) */
/* WARNING: Removing unreachable block (ram,0x030252b0) */
/* WARNING: Removing unreachable block (ram,0x030252be) */
/* WARNING: Removing unreachable block (ram,0x030252cc) */
/* WARNING: Removing unreachable block (ram,0x030252d6) */
/* WARNING: Removing unreachable block (ram,0x030252e4) */
/* WARNING: Removing unreachable block (ram,0x030253de) */
/* WARNING: Removing unreachable block (ram,0x030253fa) */
/* WARNING: Removing unreachable block (ram,0x03025402) */
/* WARNING: Removing unreachable block (ram,0x03025416) */
/* WARNING: Removing unreachable block (ram,0x03025384) */
/* WARNING: Removing unreachable block (ram,0x03025426) */
/* WARNING: Removing unreachable block (ram,0x0302542a) */
/* WARNING: Removing unreachable block (ram,0x0302542c) */
/* WARNING: Removing unreachable block (ram,0x0302542e) */

undefined4 FUN_030251a2(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_0302552c;
  *DAT_0302552c = 0;
  puVar1[1] = 0;
  *(undefined2 *)(puVar1 + 2) = 0;
  FUN_02ff8972(DAT_0302552c,&DAT_03025530,3);
  puVar1 = DAT_0302552c;
  *(undefined1 *)((int)DAT_0302552c + 3) = 3;
  uVar2 = FUN_02ffc9d6(puVar1,3);
  if (uVar2 < 3) {
    return 0xffffffff;
  }
  uVar3 = FUN_02ff89ce(puVar1,&DAT_03025530,3);
  return uVar3;
}


