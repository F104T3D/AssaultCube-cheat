#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "globals.hpp"

void infhealth() {
    uintptr_t healthAddress = playerBase + HEALTH_OFFSET;

//  int health = 0;
//  if (ReadProcessMemory(hProcess, (LPCVOID)healthAddress, &health, sizeof(health), nullptr)) {
//      std::cout << "\t[+] current health: " << std::dec << health << std::endl;
//  } else {
//      std::cout << "\t[-]" << GetLastError() << " failed to read health value error: " << "\n";
//  }

    int newHealth = 100;
    std::cout << "\t[!] freezing health - F12 to exit\n";
    while (true) {
        if (GetAsyncKeyState(VK_F12)) break;

        if (!WriteProcessMemory(hProcess, (LPVOID)healthAddress, &newHealth, sizeof(newHealth), nullptr)) {
            std::cout << "\t[-]" << GetLastError() << " failed to write health\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << "[!] exited health loop";
}