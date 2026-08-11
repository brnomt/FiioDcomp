/**
 * FUN_030b0b22 @ 0x030b0b22
 * Tags: unidentified
 * Auto-exported from Ghidra decompilation
 */


undefined4 FUN_030b0b22(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  FUN_030ab3d6(DAT_030b0cb8,0,0x5004);
  iVar2 = DAT_030b0cbc;
  if (param_1 != -1) {
    *(undefined2 *)(DAT_030b0cbc + 0x200) = 0;
    *(undefined2 *)(iVar2 + 0x202) = 0;
    *(int *)(iVar2 + 0x204) = param_1;
    buffered_fseek(iVar2,0,0);
    iVar4 = *DAT_030b0cc0;
    iVar2 = FUN_030ae552(0xc);
    piVar3 = DAT_030b0cc4;
    *DAT_030b0cc4 = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_030ae552(0x208);
      piVar3 = (int *)*piVar3;
      *piVar3 = iVar2;
      if (iVar2 != 0 && iVar4 != -1) {
        *(undefined2 *)(iVar2 + 0x200) = 0;
        *(undefined2 *)(iVar2 + 0x202) = 0;
        *(int *)(iVar2 + 0x204) = iVar4;
        piVar1 = DAT_030b0cc8;
        piVar3[1] = 0;
        piVar3[2] = 0;
        iVar4 = *piVar1;
        iVar2 = FUN_030ae552(0xc);
        piVar3 = DAT_030b0ccc;
        *DAT_030b0ccc = iVar2;
        if (iVar2 != 0) {
          iVar2 = FUN_030ae552(0x208);
          piVar3 = (int *)*piVar3;
          *piVar3 = iVar2;
          if (iVar2 != 0 && iVar4 != -1) {
            *(undefined2 *)(iVar2 + 0x200) = 0;
            *(undefined2 *)(iVar2 + 0x202) = 0;
            *(int *)(iVar2 + 0x204) = iVar4;
            piVar3[1] = 0;
            piVar3[2] = 0;
            return 0;
          }
        }
      }
    }
  }
  return 0xffffffff;
}


