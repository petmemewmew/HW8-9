//
// Created by 26963 on 2022/6/3.
//

#include "Omegatron.h"

Omegatron::Omegatron(int x, int y, int HP, int hit, int speed, GameWorld *world) : Enemy(IMGID_OMEGATRON, x, y, HP, hit,
                                                                                         speed, world) {
    std::cout<<"successssss"<<std::endl;
    energy = 50;
}

void Omegatron::destructed() {
    this_world->add_item(new Explosion(GetX(), GetY(), this_world));

    this_world->add_kill();

    this_world->IncreaseScore(200);

    int i = randInt(1, 5);
//    if (i == 1 || i == 2) {
    if (i == 1 || i == 2) {
        if (randInt(1, 5) == 1) {
            this_world->add_item(new Meteor_Goodie(GetX(), GetY(), this_world));//not written
        } else {
            this_world->add_item(new Power_Up_Goodie(GetX(), GetY(), this_world));
        }
    }
}

void Omegatron::attack() {
    if (energy >= 50) {
        energy -= 50;
        this_world->add_item(new Red_Bullet(GetX(), GetY() - 50, 162, hurt, this_world));
        this_world->add_item(new Red_Bullet(GetX(), GetY() - 50, 198, hurt, this_world));
    }

    if (energy < 50) {
        energy++;
    }
}

