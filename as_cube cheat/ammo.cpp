#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "globals.hpp"

void infAmmo() {
    AmmoInfo ammoTypes[] = {
        { "assault rifle", AMMO_ASSAULTRIFLE_OFFSET },
        { "pistol",        AMMO_PISTOL_OFFSET },
        { "smg",           AMMO_SMG_OFFSET },
        { "sniper",        AMMO_SNIPER_OFFSET },
        { "shotgun",       AMMO_SHOTGUN_OFFSET },
        { "carbine",       AMMO_CARBINE_OFFSET }
    };

// int ammo = 0;
// for (const auto& ammoType : ammoTypes) {
//     uintptr_t addr = playerBase + ammoType.offset;
//
//     if (ReadProcessMemory(hProcess, (LPCVOID)addr, &ammo, sizeof(ammo), nullptr)) {
//         std::cout << "\t[+] " << ammoType.name << " ammo: " << std::dec << ammo << std::endl;
//     } else {
//         std::cout << "\t[-]" << GetLastError() << " failed to read " << ammoType.name << " ammo\n";
//     }
// }

    int newAmmo = 1;
    std::cout << "\t[!] freezing all ammo types - F12 to exit\n";
    while (true) {
        if (GetAsyncKeyState(VK_F11)) break;

        for (const auto& ammoType : ammoTypes) {
            uintptr_t addr = playerBase + ammoType.offset;

            if (!WriteProcessMemory(hProcess, (LPVOID)addr, &newAmmo, sizeof(newAmmo), nullptr)) {
                std::cout << "\t[-]" << GetLastError() << " failed to write " << ammoType.gun << " ammo\n";
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "[!] exited health loop";
}