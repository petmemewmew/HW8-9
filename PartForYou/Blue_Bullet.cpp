//
// Created by 26963 on 2022/6/3.
//
#include "Blue_Bullet.h"

Blue_Bullet::Blue_Bullet(int x, int y, double size, int hit, GameWorld *world) : GameObject(IMGID_BLUE_BULLET, x, y, 0,
                                                                                            1, size, world) {
    hurt = hit;
}

void Blue_Bullet::Update() {
    if (is_dead) {
        return;
    } else {
        if (GetY() > WINDOW_HEIGHT) {
            is_dead = 1;
            return;
        } else {
            MoveTo(GetX(), GetY() + 6);
        }
    }
}


int Blue_Bullet::return_hurt() {
    return hurt;
}

std::string Blue_Bullet::return_type() {
    std::string type = "Blue_Bullet";
    return type;
}
