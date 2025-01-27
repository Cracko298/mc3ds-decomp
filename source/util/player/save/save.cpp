#include <ninsdk/3ds/utils/keypad.h> // I have no idea, is_pressed is defined here, no time to look into further
#include "include/save.hpp"

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
    Process::WRITEU8(offset + 0x1E81000, 0x00);
    Process::WRITEU8(offset + 0x1E81001, 0x00);
    if (is_pressed(0x00008000))
    {
        Process::WRITEU8(offset + 0x1E81000, 0x01);
    }
    if (is_pressed(0x00004000))
    {
        Process::WRITEU8(offset + 0x1E81001, 0x01);
    }
    if (READU16(offset + 0x1E81000) == 0x101)
    {
        Process::WRITEU32(offset + 0x0A3103C, 0x00000031);
    }
}