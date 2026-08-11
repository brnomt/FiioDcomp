#!/usr/bin/env python3
"""Set GHIDRA_MCP_ALLOW_SCRIPTS=1 as a persistent User env var."""
import subprocess
result = subprocess.run(
    ["powershell", "-Command",
     "[System.Environment]::SetEnvironmentVariable('GHIDRA_MCP_ALLOW_SCRIPTS', '1', 'User')"],
    capture_output=True, text=True
)
print(f"Exit code: {result.returncode}")
print(f"Set GHIDRA_MCP_ALLOW_SCRIPTS=1 as User env var")
print("Now close Ghidra completely and reopen it.")
