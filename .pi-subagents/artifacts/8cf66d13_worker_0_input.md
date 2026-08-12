# Task for worker

[Read from: C:\Users\brnomt\Desktop\ReChord\context.md, C:\Users\brnomt\Desktop\ReChord\plan.md]

You are a delegated subagent running from a fork of the parent session. Treat the inherited conversation as reference-only context, not a live thread to continue. Do not continue or answer prior messages as if they are waiting for a reply. Your sole job is to execute the task below and return a focused result for that task using your tools.

Task:
Build a QEMU test harness that runs OUR REAL firmware logic in QEMU (mps2-an385), no device flashing.
Project root: C:/Users/brnomt/Desktop/ReChord (Windows, bash via git-bash). QEMU: '/c/Program Files/qemu/qemu-system-arm.exe'.
WORKING REFERENCE (already proven): build/qemu_fault_probe.elf from firmware/qemu/qemu_fault_probe.c + firmware/qemu/qemu_echo_ld.ld runs in QEMU. mps2-an385 has RAM at 0x00000000 (4MB) + 0x20000000 (4MB). Monitor read pattern: (sleep 2; echo 'xp /8xw 0x20008000'; echo quit) | qemu-system-arm -machine mps2-an385 -kernel build/FILE.bin -nographic -monitor stdio
GOAL: verify our real firmware's boot logic in QEMU: firmware_entry -> Main2 heartbeat loop writes the framebuffer (0x03024868 in the real code).
KEY FILES:
  - firmware/entry_stubs.S: firmware_entry @0x03000010 does 'b Main2' (V0.17).
  - firmware/rockchip/bbsystem/Main2.c: int Main2(void). Its while(1) loop has a ReChord heartbeat: fills fb 0x03024868 red/black, calls ROM display fns via absolute fn pointers (0x02fef124 wait, 0x02fea848/0x02fea824 save, 0x02feb0f6 color, 0x02fea8f4 rect, 0x02feabea refresh), writes boot marker to ((volatile uint32_t*)0x03000118)[2], delay loop.
  - firmware/rechord_app.c: rechord_firmware_entry() (V0.15 stock-mirror init: rom_alloc @0x02feeedc, rom_hw_init @0x02feeebe, rom_hw_init2 @0x02feee7c, rom_early_init @0x02fe860e; writes boot layout to 0x03000164; mode check returns 0x18f/0x191).
PROBLEM: the real code uses absolute addresses (0x03000000 code, 0x02FE0000+ ROM, 0x400B0000 INTC, 0x03024868 fb) not mapped in QEMU.
APPROACH (pragmatic):
  1. Add '#ifdef RECHORD_QEMU_TEST' stubs to the firmware sources OR make a QEMU test build: redirect ROM fns to local stubs (rom_alloc returns a RAM ptr, hw_init/early_init no-op), redirect fb/boot-log/crash-log addresses to QEMU RAM (0x20000000+), make Main2's BSP_Init2 hardware writes harmless (stub BSP_Init2 or the INTC writes).
  2. Create a QEMU test main mimicking the bootloader: vector table (HardFault -> a fault handler like fault.c's), set VTOR, jump firmware_entry (or Main2 directly).
  3. Link with a QEMU linker script (firmware/qemu/qemu_echo_ld.ld pattern), objcopy to .bin, run in QEMU, READ the framebuffer + logs via the monitor to verify: entry ran, Main2 reached its loop, fb was written (non-zero).
MINIMUM DELIVERABLE: a runnable QEMU test proving firmware_entry+Main2 heartbeat executes and writes the fb (monitor-readable), with the exact build+run commands. Keep it simple. Create files under firmware/qemu/ and build/.
Do NOT flash anything. Do NOT modify stock/ or the device. If running full Main2 is too hard (BSP_Init2 MMIO), valid fallback: prove rechord_firmware_entry (V0.15) runs and returns 0x191 with mode 0xb, PLUS a minimal test reproducing the heartbeat fb write. Report exactly what you verified.
Report: files created, exact commands, monitor output proving each step.

## Acceptance Contract
Acceptance level: checked
Completion is not accepted from prose alone. End with a structured acceptance report.

Criteria:
- criterion-1: Implement the requested change without widening scope

Required evidence: changed-files, tests-added, commands-run, residual-risks, no-staged-files

Finish with a fenced JSON block tagged `acceptance-report` in this shape:
Use empty arrays when no items apply; array fields contain strings unless object entries are shown.
`criteriaSatisfied[].status` must be exactly one of: satisfied, not-satisfied, not-applicable.
`commandsRun[].result` must be exactly one of: passed, failed, not-run.
`manualNotes` and `notes` are optional strings; an empty string means no note and does not satisfy `manual-notes` evidence.
```acceptance-report
{
  "criteriaSatisfied": [
    {
      "id": "criterion-1",
      "status": "satisfied",
      "evidence": "specific proof"
    }
  ],
  "changedFiles": [
    "src/file.ts"
  ],
  "testsAddedOrUpdated": [
    "test/file.test.ts"
  ],
  "commandsRun": [
    {
      "command": "command",
      "result": "passed",
      "summary": "short result"
    }
  ],
  "validationOutput": [
    "validation output or concise summary"
  ],
  "residualRisks": [
    "none"
  ],
  "noStagedFiles": true,
  "diffSummary": "short description of the diff",
  "reviewFindings": [
    "blocker: file.ts:12 - issue found, or no blockers"
  ],
  "manualNotes": "anything else the parent should know"
}
```