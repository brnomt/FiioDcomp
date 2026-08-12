# Task for worker

[Read from: C:\Users\brnomt\Desktop\ReChord\context.md, C:\Users\brnomt\Desktop\ReChord\plan.md]

You are a delegated subagent running from a fork of the parent session. Treat the inherited conversation as reference-only context, not a live thread to continue. Do not continue or answer prior messages as if they are waiting for a reply. Your sole job is to execute the task below and return a focused result for that task using your tools.

Task:
Create a tool that builds DISPATCH-MAPPING test IMGs for the FiiO Echo Mini: take the STOCK IMG and patch section_3 code at specific RAM offsets to 'b .' (infinite loop, little-endian 0xE7FE = FE E7), to empirically map which menu feature calls which section_3 dispatch offset.
Project root: C:/Users/brnomt/Desktop/ReChord. Stock IMG: stock/3.7.0/ECHO MINI V3.7.0/HIFIEC37.IMG. Section_3 starts at IMG offset 0x81A14; RAM 0x03000000 == IMG 0x81A14, so RAM offset X == IMG 0x81A14 + X.
CONTEXT (already established on device): firmware_entry (RAM 0x03000010) is called for MEDIA operations (media library, music playback), NOT boot — patching it to 'b .' made media crash while menu/file browser/settings kept working.
KNOWN DISPATCH OFFSETS (RAM): 0x03000010 (firmware_entry, known: media), 0x03000162 (stock = bx lr no-op, SKIP), 0x0300016c (WriteData_To_Flash), 0x0300024e (MscTestUnitReady), 0x03000296, 0x030004f4, 0x03000546, 0x03000a72, 0x03000a74, 0x03000aba (main2_entry USB MSC), 0x0300710a (application_start).
BUILD tools/make_v019_dispatch_map.py: takes a list of RAM offsets, patches each to FE E7, verifies each location currently holds plausible Thumb code (not 0x00/0xFF), writes an IMG. Keeps everything else byte-identical to stock.
BUILD these IMGs:
  - build/ReChord_V0.19_map_USB.IMG: hang {0x0300016c, 0x0300024e, 0x03000aba}
  - build/ReChord_V0.19_map_misc.IMG: hang {0x03000296, 0x030004f4, 0x03000546, 0x03000a72, 0x03000a74}
  - build/ReChord_V0.19_map_appstart.IMG: hang {0x0300710a}
Verify each output IMG differs from stock ONLY at the patched offsets (print the diff offsets). Do NOT flash anything. Report tool path, the 3 IMG paths, and per-IMG diff verification.

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