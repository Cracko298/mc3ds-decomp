#include "include/spawnLimit.hpp"

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

    static void Write8(uintptr_t offset, uint8_t value) {
        if (offset < sizeof(memory)) {
            memory[offset] = value;
        }
    }

    static void InitializeMemory() {
        std::memset(memory, 0, sizeof(memory));
    }
};

void setMobSpawnLimit(){
    Process::InitializeMemory();
    offset = 0x00000000;
    data32 = 0x00000000;
    data16 = 0x0000;
    data8 = 0x00;
    cmp32 = 0;

    if (Process::Read32(offset + 0x0A338AC, cmp32) && cmp32 < 0x0000000F)
    {
        Process::Write8(offset + 0x0A338AC, 0x00);
    }
    if (Process::Read32(offset + 0x0A338A8, cmp32) && cmp32 < 0x0000000F)
    {
        Process::Write8(offset + 0x0A338A8, 0x00);
    }
    if (Process::Read32(offset + 0x0A338B4, cmp32) && cmp32 < 0x0000000E)
    {
        Process::Write8(offset + 0x0A338B4, 0x00);
    }
    if (Process::Read32(offset + 0x0A338BC, cmp32) && cmp32 == 0x00000001)
    {
        Process::Write8(offset + 0x0A338BC, 0x00);
    }
    if (Process::Read32(offset + 0x0A338C0, cmp32) && cmp32 < 0x00000003)
    {
        Process::Write8(offset + 0x0A338C0, 0x00);
    }
    if (Process::Read32(offset + 0x0A338B8, cmp32) && cmp32 < 0x00000006)
    {
        Process::Write8(offset + 0x0A338B8, 0x00);
    }
    if (Process::Read32(offset + 0x0A338B0, cmp32) && cmp32 < 0x00000007)
    {
        Process::Write8(offset + 0x0A338B0, 0x00);
    }
}