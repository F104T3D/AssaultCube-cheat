#include <windows.h>
#include <TlHelp32.h>
#include "globals.hpp"

HANDLE hProcess = nullptr;
MODULEENTRY32 modEntry;
uintptr_t playerBase = 0;
uintptr_t baseAddress = 0;