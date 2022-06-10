//
// Created by 26963 on 2022/6/3.
//

#include "Sigmatron.h"

Sigmatron::Sigmatron(int x, int y, int HP, int speed, GameWorld *world): Enemy(IMGID_SIGMATRON, x, y, HP, 0, speed, world){
    energy = 0;
//    std::cout<<"successssss"<<std::endl;
}

void Sigmatron::destructed() {
    this_world->add_item(new Explosion(GetX(), GetY(), this_world));

    this_world->add_kill();

    this_world->IncreaseScore(100);

    if(randInt(1, 5) == 1){
        this_world->add_item(new HP_Restore_Goodie(GetX(), GetY(), this_world));//not written
    }
}

void Sigmatron::attack() {
    if(abs(GetX() - this_world->Get_Dawnbreaker_X()) <= 10){
        strategy = 1;
        speed = 10;
        strategy_time = WINDOW_HEIGHT;
    }
}