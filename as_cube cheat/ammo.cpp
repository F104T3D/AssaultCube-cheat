#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "globals.hpp"

void infAmmo() {

    uintptr_t ammoCurrentAddress = playerBase + 0x140;

    int ammo = 0;
    if (ReadProcessMemory(hProcess, (LPCVOID)ammoCurrentAddress, &ammo, sizeof(ammo), nullptr)) {
        std::cout << "\t[+] ammo current: " << std::dec << ammo << std::endl;
    }
    else {
        std::cout << "\t[-] failed to read ammo current value\n";
    }
    int newAmmoCurrent = 1;

    std::cout << "\t[!] freezing ammo current at " << newAmmoCurrent << "...\n";
    while (true) {
        if (!WriteProcessMemory(hProcess, (LPVOID)ammoCurrentAddress, &newAmmoCurrent, sizeof(newAmmoCurrent), nullptr)) {
            std::cout << "\t[-] failed to write ammo current\n";
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}