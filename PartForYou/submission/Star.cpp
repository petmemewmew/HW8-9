//
// Created by 26963 on 2022/6/3.
//
#include "Star.h"


Star::Star(int x, int y, double size, GameWorld* world) : GameObject(IMGID_STAR, x , y, 0, 4, size, world){};

void Star::Update() {
    if(GetY() < 0){
        is_dead = 1;
        return;
    }else{
        MoveTo(GetX(), GetY() - 1);
    }
}

std::string Star::return_type() {
    std::string type = "Star";
    return type;
}
