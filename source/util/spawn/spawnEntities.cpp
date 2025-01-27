#include "include/spawnEntities.hpp"

int blockEntityList[] = {0xB3, 0x4B, 0xE2, 0x0F}; // not correct list, do not know id's for sure. example block id list.

bool isNumberInList(int number, const int *list, size_t listSize) {
    for (size_t i = 0; i < listSize; i++) {
        if (list[i] == number) {
            return true;
        }
    }
    return false;
}

bool checkEntityType(Mob mob) { // checks if mob is spawnable
    if (mob.getEntityTypeId() == EntityType_Agent) {
        return false;
    }
    if (mob.getEntityTypeId() == EntityType_TripodCamera) {
        return false;
    }
    if (mob.getEntityTypeId() == EntityType_Lightning) {
        return false;
    }
    if (mob.getEntityTypeId() == EntityType_NPC) {
        return false;
    }
    if (isNumberInList(mob.getEntityTypeId(), blockEntityList, sizeof(blockEntityList) / sizeof(blockEntityList[0]))) { // checks if mob is block entity
        return false;
    }
    return true;
}