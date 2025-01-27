#ifndef SETSPAWNABLEENTITIES_H
#define SETSPAWNABLEENTITIES_H

#include <stdbool.h> // assumed import because of C requiring it (after C99).
#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <cstring>

typedef struct {
    int (*getEntityTypeId)(void);
} Mob;

// decl checkEntityType and isNumberInList
bool isNumberInList(int number, int *list, size_t size);
bool checkEntityType(int mob);

#define EntityType_Agent 0xDE // real entity id's
#define EntityType_TripodCamera 0xC9
#define EntityType_Lightning 0x0D
#define EntityType_NPC 0x17

#endif