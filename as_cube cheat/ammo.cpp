#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "globals.hpp"

void infAmmo() {
    struct AmmoInfo {
        const char* name;
        uintptr_t offset;
    } ammoTypes[] = {
        { "assault rifle", 0x140 },
        { "pistol",        0x12C },
        { "smg",           0x138 },
        { "sniper",        0x13C },
        { "shotgun",       0x134 },
        { "carbine",       0x130 }
    };

    int ammo = 0;
    for (const auto& ammoType : ammoTypes) {
        uintptr_t addr = playerBase + ammoType.offset;

        if (ReadProcessMemory(hProcess, (LPCVOID)addr, &ammo, sizeof(ammo), nullptr)) {
         // std::cout << "\t[+] " << ammoType.name << " ammo: " << std::dec << ammo << std::endl;
        } else {
            std::cout << "\t[-] failed to read " << ammoType.name << " ammo\n";
        }
    }

    int newAmmo = 1;
    std::cout << "\t[!] freezing all ammo types\n";
    while (true) {
        for (const auto& ammoType : ammoTypes) {
            uintptr_t addr = playerBase + ammoType.offset;

            if (!WriteProcessMemory(hProcess, (LPVOID)addr, &newAmmo, sizeof(newAmmo), nullptr)) {
                std::cout << "\t[-] failed to write " << ammoType.name << " ammo\n";
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}