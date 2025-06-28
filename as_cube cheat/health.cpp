#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "globals.hpp"
#include "base.hpp"

void infhealth() {

    uintptr_t healthAddress = playerBase + 0xEC;

    int health = 0;
    if (ReadProcessMemory(hProcess, (LPCVOID)healthAddress, &health, sizeof(health), nullptr)) {
        std::cout << "current health: " << std::dec << health << std::endl;
    }
    else {
        std::cout << "failed to read health value.\n";
    }
    int newHealth = 9999;

    std::cout << "Freezing health at " << newHealth << "...\n";
    while (true) {
        if (!WriteProcessMemory(hProcess, (LPVOID)healthAddress, &newHealth, sizeof(newHealth), nullptr)) {
            std::cout << "Failed to write health.\n";
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}