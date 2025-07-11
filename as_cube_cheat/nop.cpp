#include <iostream>
#include "globals.hpp"

bool nop(uintptr_t address, size_t length) {
    BYTE* nopArray = new BYTE[length];
    memset(nopArray, 0x90, length);

    DWORD oldProtect;
    if (!VirtualProtectEx(hProcess, (LPVOID)address, length, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        std::cout << "[-] VirtualProtectEx failed. Error: " << GetLastError() << "\n";
        delete[] nopArray;
        return false;
    }

    if (!WriteProcessMemory(hProcess, (LPVOID)address, nopArray, length, nullptr)) {
        std::cout << "[-] WriteProcessMemory failed. Error: " << GetLastError() << "\n";
        VirtualProtectEx(hProcess, (LPVOID)address, length, oldProtect, &oldProtect);
        delete[] nopArray;
        return false;
    }

    VirtualProtectEx(hProcess, (LPVOID)address, length, oldProtect, &oldProtect);
    delete[] nopArray;

    std::cout << "[+] NOPed " << length << " bytes at 0x" << std::hex << address << "\n";
    return true;
}
