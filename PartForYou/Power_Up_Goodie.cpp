//
// Created by 26963 on 2022/6/3.
//

#include "Power_Up_Goodie.h"

Power_Up_Goodie::Power_Up_Goodie(int x, int y, GameWorld *world):Goodie(IMGID_POWERUP_GOODIE,x, y, world) {
}

void Power_Up_Goodie::crash() {
    this_world->level_up();
    this_world->IncreaseScore(20);

}
