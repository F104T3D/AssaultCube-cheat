#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "globals.hpp"

void infhealth() {

    uintptr_t healthAddress = playerBase + 0xEC;

    int health = 0;
    if (ReadProcessMemory(hProcess, (LPCVOID)healthAddress, &health, sizeof(health), nullptr)) {
        std::cout << "\t[+] current health: " << std::dec << health << std::endl;
    } else {
        std::cout << "\t[-] failed to read health value error: " << GetLastError() << "\n";
    }

    int newHealth = 100;
    std::cout << "\t[!] freezing health at " << newHealth << "...\n";
    while (true) {
        if (!WriteProcessMemory(hProcess, (LPVOID)healthAddress, &newHealth, sizeof(newHealth), nullptr)) {
            std::cout << "\t[-] failed to write health\n";
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}