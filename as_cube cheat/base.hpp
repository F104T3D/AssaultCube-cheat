#ifndef BASE_HPP
#define BASE_HPP

#include <windows.h>
#include <tlhelp32.h>
#include <thread>
#include <chrono>
#include <iostream>

void readBase() {
	uintptr_t baseAddress = reinterpret_cast<uintptr_t>(modEntry.modBaseAddr);

	std::cout << "base address of ac_client.exe: 0x" << std::hex << baseAddress << std::endl;

	uintptr_t playerPtrAddress = baseAddress + 0x0018AC00;

	playerBase = 0;

	if (ReadProcessMemory(
		hProcess,                     // Handle to ac_client.exe
		(LPCVOID)playerPtrAddress,    // The address we want to read from
		&playerBase,                  // Where we want to store what we read
		sizeof(playerBase),          // How much data to read
		nullptr                      // We don't care how many bytes were read
	)) {
		std::cout << "player base address : 0x" << std::hex << playerBase << std::endl;
	}
	else {
		std::cout << "failed to read player base address.\n";
		std::cin.get();
	}
}

#endif