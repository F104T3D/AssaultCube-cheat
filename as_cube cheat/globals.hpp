#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <windows.h>
#include <cstdint>
#include <TlHelp32.h>

// offsets from base module
constexpr uintptr_t PLAYER_POINTER_OFFSET = 0x195404;

// offsets from player base
constexpr uintptr_t HEALTH_OFFSET = 0xEC;

// ammo offsets
constexpr uintptr_t AMMO_CARBINE_OFFSET = 0x130;
constexpr uintptr_t AMMO_PISTOL_OFFSET = 0x12C;
constexpr uintptr_t AMMO_SHOTGUN_OFFSET = 0x134;
constexpr uintptr_t AMMO_SMG_OFFSET = 0x138;
constexpr uintptr_t AMMO_SNIPER_OFFSET = 0x13C;
constexpr uintptr_t AMMO_ASSAULTRIFLE_OFFSET = 0x140;

struct AmmoInfo {
    const char* name;
    uintptr_t offset;
};


extern HANDLE hProcess;
extern MODULEENTRY32 modEntry;
extern uintptr_t playerBase;
extern uintptr_t baseAddress;

void infhealth();
void infAmmo();


#endif	