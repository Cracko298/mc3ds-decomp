#ifndef PLAYERSAVEGAME_H
#define PLAYERSAVEGAME_H

#include <iostream>
#include <cstdint>
#include <cstring>

// decl saveFunction
void saveFunction(void);

extern uint64_t offset;
extern uint8_t data8;
extern uint8_t memory[0x100000];

#endif