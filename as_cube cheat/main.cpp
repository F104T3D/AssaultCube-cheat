#include <windows.h>
#include <tlhelp32.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "globals.hpp"

int main() {

	// take image (snapshot) of ALL (TH32C_) proc running - return val is HANDLE a reference to the snapshot in mem
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // 0 no specific proc
	if (snapshot == INVALID_HANDLE_VALUE) {
		std::cout << "Process snapshot failed\n";
		return 1; // exit
	}

	PROCESSENTRY32 entry; // struct - box of data about one proc
	entry.dwSize = sizeof(PROCESSENTRY32); // dwSize must be set before using - windows uses it to know the version/size of the struct.

	DWORD acPID = 0;
	// Process32First fills the entry struct with info about the first process.
	if (Process32First(snapshot, &entry)) {
		do {
			if (_wcsicmp(entry.szExeFile, L"ac_client.exe") == 0) {
				std::cout << "\nFound ac_client process.\n";
				acPID = entry.th32ProcessID;
				break;
			}
		} while (Process32Next(snapshot, &entry));
	}
	CloseHandle(snapshot);

	if (acPID != 0) {
		std::cout << "ac_client.exe PID is: " << acPID << std::endl;
	}
	else {
		std::cout << "ac_client.exe not found.\n";
		std::cin.get();
		return 1;
	}

	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, acPID); // Full access, We dont want the handle inheritable by child processes, The PID
	if (hProcess == NULL) {
		std::cout << "failed to open process.\n";
		return 1;
	}
	else {
		std::cout << "opened handle to ac_client.exe successfully.\n";
	}

	HANDLE moduleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, acPID); // Give list of all modules inside this proc 
	if (moduleSnap == INVALID_HANDLE_VALUE) {
		std::cout << "failed to take module snapshot.\n";
		return 1;
	}
	modEntry.dwSize = sizeof(MODULEENTRY32);



	if (Module32First(moduleSnap, &modEntry)) { // Get first module
		do {
			if (_wcsicmp(modEntry.szModule, L"ac_client.exe") == 0) { // szModule - name of module
				std::cout << "found module: ac_client.exe" << std::endl;
				break;
			}
		} while (Module32Next(moduleSnap, &modEntry)); // Move to next module
		baseAddress = reinterpret_cast<uintptr_t>(modEntry.modBaseAddr);
		std::cout << "Base address of ac_client.exe: 0x" << std::hex << baseAddress << std::endl;
	}
	CloseHandle(moduleSnap);

	uintptr_t playerPtrAddress = baseAddress + 0x0045E3E6;

	uintptr_t playerBase = 0;
	if (ReadProcessMemory(hProcess, (LPCVOID)playerPtrAddress, &playerBase, sizeof(playerBase), nullptr)) {
		std::cout << "Player base address: 0x" << std::hex << playerBase << std::endl;
	}
	else {
		std::cout << "Failed to read player base address.\n";
		return 1;
	}

	std::thread healthThread{ infhealth };
	std::thread ammoThread{ infAmmo };

	healthThread.join();
	ammoThread.join();
	std::cin.get();
}