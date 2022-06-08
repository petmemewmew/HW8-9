//
// Created by 26963 on 2022/6/3.
//

#include "Omegatron.h"

Omegatron::Omegatron(int x, int y, int HP, int hit, int speed, GameWorld *world): Enemy(IMGID_OMEGATRON, x, y, HP, hit, speed, this_world){
    energy = 50;
}

void Omegatron::destructed() {
    this_world->add_item(new Explosion(GetX(), GetY(), this_world));

    this_world->add_kill();

    this_world->IncreaseScore(200);

    if(int i = randInt(1,5) == 1 || i == 2){
        if(int j = randInt(1,5) == 1) {
            this_world->add_item();//not written
        }else{
            this_world->add_item();
        }
    }
}
