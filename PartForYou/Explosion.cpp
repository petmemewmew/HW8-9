//
// Created by 26963 on 2022/6/3.
//

#include "Explosion.h"

Explosion::Explosion(int x, int y,GameWorld* world): GameObject(IMGID_EXPLOSION, x, y, 0, 3, 4.5, world) {
    tick = 0;
}

void Explosion::Update() {
    SetSize(GetSize() - 0.2);
    tick++;
    if (tick == 20){
        is_dead = 1;
    }
}

int Explosion::is_enemy() {
    return 0;
}

int Explosion::is_blue_bullet() {
    return 0;
}


