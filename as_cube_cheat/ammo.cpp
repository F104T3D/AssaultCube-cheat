#include <windows.h>
#include "globals.hpp"
#include <iostream>

void infAmmo() {
    uintptr_t ammoSubInstruction = 0x004C7288;

    if (!nop(ammoSubInstruction, 6)) {
        std::cout << "[-] failed to nop ammo instruction\n";
        return;
    }
}
