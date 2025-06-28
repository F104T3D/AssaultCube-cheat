#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <windows.h>
#include <cstdint>
#include <TlHelp32.h>

extern HANDLE hProcess;
extern MODULEENTRY32 modEntry;
extern uintptr_t playerBase;
extern uintptr_t baseAddress;

void infhealth();
void infAmmo();

#endif	