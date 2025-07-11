#include <windows.h>
#include <iostream>
#include "globals.hpp"

void infhealth() {
    uintptr_t healthSubInstruction = 0x00484499;

    if(!nop(healthSubInstruction, 6)){
        std::cout << "[-] failed to nop health instruction\n";
        return;
    }

}
