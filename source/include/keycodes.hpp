// keycodes declared here as title suggests
#ifndef KEYCODES_H
#define KEYCODES_H
#define KEYCODES

// include c-int
#include <iostream>
#include <cstdint>
#include <string>
#include <map>

// uint8 keycodes
uint8_t KEY_A = 0x01;
uint8_t KEY_B = 0x02;
uint8_t KEY_SELECT = 0x4;
uint8_t KEY_START = 0x8;
uint8_t KEY_RIGHT = 0x10;
uint8_t KEY_LEFT = 0x20;
uint8_t KEY_UP = 0x40;
uint8_t KEY_DOWN = 0x80;

// uint16 keycodes
uint16_t KEY_R = 0x100;
uint16_t KEY_L = 0x200;
uint16_t KEY_X = 0x400;
uint16_t KEY_Y = 0x800;
uint16_t KEY_ZL = 0x4000;
uint16_t KEY_ZR = 0x8000;

// uint32 keycodes
uint32_t KEY_TOUCH = 0x100000;
uint32_t KEY_CSTICK_RIGHT = 0x1000000;
uint32_t KEY_CSTICK_LEFT = 0x2000000;
uint32_t KEY_CSTICK_UP = 0x4000000;
uint32_t KEY_CSTICK_DOWN = 0x8000000;
uint32_t KEY_CPAD_RIGHT = 0x10000000;
uint32_t KEY_CPAD_LEFT = 0x20000000;
uint32_t KEY_CPAD_UP = 0x40000000;
uint32_t KEY_CPAD_DOWN = 0x80000000;

// static pointers to address'
uintptr_t ADDRESS_0 = 0x1F89E8; // add0 and add9 do not follow pattern found in add1-8 (self comment)
uintptr_t ADDRESS_1 = 0x1F8948;
uintptr_t ADDRESS_2 = 0x1F8A00;
uintptr_t ADDRESS_3 = 0x1F8A18;
uintptr_t ADDRESS_4 = 0x1F8A30;
uintptr_t ADDRESS_5 = 0x1F8A48;
uintptr_t ADDRESS_6 = 0x1F8A60;
uintptr_t ADDRESS_7 = 0x1F8A78;
uintptr_t ADDRESS_8 = 0x1F8A90;
uintptr_t ADDRESS_9 = 0x1F8AB0;

// executable size (base address)
uint64_t ADDRESS_BASE = 0x93A000;

#endif
