//
// Created by 26963 on 2022/6/3.
//

#include "Meteor_Goodie.h"

Meteor_Goodie::Meteor_Goodie(int x, int y, GameWorld *world) : Goodie(IMGID_METEOR_GOODIE, x, y, world) {
}

void Meteor_Goodie::crash() {
    this_world->get_meteor();
    this_world->IncreaseScore(20);
}
