//
// Created by 26963 on 2022/6/3.
//

#include "HP_Restore_Goodie.h"

HP_Restore_Goodie::HP_Restore_Goodie(int x, int y, GameWorld *world): Goodie(IMGID_HP_RESTORE_GOODIE,x, y, world) {
}

void HP_Restore_Goodie::crash() {
    this_world->add_HP(50);
    this_world->IncreaseScore(20);
}