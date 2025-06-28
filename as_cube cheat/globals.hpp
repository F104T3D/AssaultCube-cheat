#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <windows.h>
#include <cstdint>

extern HANDLE hProcess;
extern uintptr_t healthAddress;
extern MODULEENTRY32 modEntry; // Info on one module
extern uintptr_t playerBase;

void infhealth();

#endif	