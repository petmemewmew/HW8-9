//
// Created by 26963 on 2022/6/8.
//

#include "Goodie.h"

Goodie::Goodie(int IMGID, int x, int y, GameWorld *world) : GameObject(IMGID, x, y, 0, 2, 0.5, world) {
}

void Goodie::Update() {
    if (is_dead) {
        return;
    }
    if (GetY() < 0) {
        is_dead = 1;
        return;
    }

    if (this_world->is_crash(this, this_world->return_Dawnbreaker())){
//            this_world->add_HP(50);
//            this_world->IncreaseScore(20);
            crash();
            is_dead = 1;
            return;
        }

    MoveTo(GetX(), GetY() - 2);

    if (this_world->is_crash(this_world->return_Dawnbreaker(), this)) {
        crash();
        is_dead = 1;
        return;
    }
}


std::string Goodie::return_type() {
    std::string type = "Goodie";
    return type;
}


