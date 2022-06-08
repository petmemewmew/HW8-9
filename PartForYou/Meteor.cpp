//
// Created by 26963 on 2022/6/3.
//

#include "Meteor.h"

Meteor::Meteor(int x, int y, GameWorld *world) : GameObject(IMGID_METEOR, x, y, 0, 1, 2.0, world) {
}

void Meteor::Update() {
    if (is_dead) {
        return;
    }

    if (GetY() >= WINDOW_HEIGHT) {
        set_dead();
    }
    if (this_world->iterate_crash(this) != nullptr) {
        if (this_world->iterate_crash(this)->return_type() == "Enemy") {
            this_world->iterate_crash(this)->set_dead();

        }
    }

    MoveTo(GetX(), GetY() + 2);
    SetDirection(GetDirection() + 5);

    if (this_world->iterate_crash(this) != nullptr) {
        if (this_world->iterate_crash(this)->return_type() == "Enemy") {
            this_world->iterate_crash(this)->set_dead();

        }
    }

}

std::string Meteor::return_type() {
    std::string type = "Meteor";
    return type;
}

int Meteor::return_hurt() {
    return hurt;
}
