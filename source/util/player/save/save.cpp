#include "include/save.hpp"
#include "../../include/keycodes.h"

bool checkKeyIsHeld(){
    uintptr_t targetAddress = ADDRESS_BASE + ADDRESS_0; // address is first updated. any address_x can be used however.
    int* ptr = reinterpret_cast<int*>(targetAddress);
    if (ptr != nullptr && *ptr != 0) {
        return true;
    } else {
        return false;
    }
}

class Process {
public:
    static uint8_t memory[0x8000000];

    static bool Read32(uintptr_t offset, uint32_t& outValue) {
        if (offset + sizeof(uint32_t) > sizeof(memory)) {
            return false;
        }
        std::memcpy(&outValue, &memory[offset], sizeof(uint32_t));
        return true;
    }

    static bool Read16(uintptr_t offset, uint16_t& outValue) {
        if (offset + sizeof(uint16_t) > sizeof(memory)) {
            return false;
        }
        std::memcpy(&outValue, &memory[offset], sizeof(uint16_t));
        return true;
    }

    static void Write8(uintptr_t offset, uint8_t value) {
        if (offset < sizeof(memory)) {
            memory[offset] = value;
        }
    }

    static void Write32(uintptr_t offset, uint32_t value) {
        if (offset + sizeof(uint32_t) <= sizeof(memory)) {
            std::memcpy(&memory[offset], &value, sizeof(uint32_t));
        }
    }

    static void InitializeMemory() {
        std::memset(memory, 0, sizeof(memory));
    }
};

void saveFunction() {
    Process::InitializeMemory();
    offset = 0x00000000;
    data8 = 0x00;
    kDown = checkKeyIsHeld();
    Process::WRITEU8(offset + 0x1E81000, 0x00);
    Process::WRITEU8(offset + 0x1E81001, 0x00);
    if (KEY_ZR && kDown)
    {
        Process::WRITEU8(offset + 0x1E81000, 0x01);
    }
    if (KEY_ZL && kDown)
    {
        Process::WRITEU8(offset + 0x1E81001, 0x01);
    }
    if (READU16(offset + 0x1E81000) == 0x101)
    {
        Process::WRITEU32(offset + 0x0A3103C, 0x00000031);
    }
}
