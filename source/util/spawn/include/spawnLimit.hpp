#ifndef SETMOBSPAWNLIMIT_H
#define SETMOBSPAWNLIMIT_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <cstring>

// func declaration for setMobSpawnLimit
void setMobSpawnLimit(void);

// allow calling of proc_read
bool Process_Read32(uintptr_t offset, uint32_t *outValue);
void Process_Write8(uintptr_t offset, uint8_t value);

// declarations
extern uint64_t offset;
extern uint32_t data32;
extern uint32_t cmp32;
extern uint16_t data16;
extern uint8_t data8;
extern uint8_t memory[0x100000];
#endif