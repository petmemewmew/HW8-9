//
// Created by 26963 on 2022/6/3.
//

#include "Dawnbreaker.h"

Dawnbreaker::Dawnbreaker(GameWorld *world) : GameObject(IMGID_DAWNBREAKER, 300, 100, 0, 0, 1.0, world) {
    HP = 100;
    energy = 10;
}


void Dawnbreaker::Update() {
    if (HP <= 0) {
        is_dead = 1;
        return;
    } else {
        if (this_world->GetKey(KeyCode::UP)) {
            if (GetY() + 4 <= (WINDOW_HEIGHT - 1)) {
                MoveTo(GetX(), GetY() + 4);
            }
        }
        if (this_world->GetKey(KeyCode::DOWN)) {
            if (GetY() - 4 >= 50) {
                MoveTo(GetX(), GetY() - 4);
            }
        }
        if (this_world->GetKey(KeyCode::LEFT)) {
            if (GetX() - 4 >= 0) {
                MoveTo(GetX() - 4, GetY());
            }
        }
        if (this_world->GetKey(KeyCode::RIGHT)) {
            if (GetX() + 4 <= (WINDOW_WIDTH - 1)) {
                MoveTo(GetX() + 4, GetY());
            }
        }
        if (this_world->GetKey(KeyCode::FIRE1)) {
            if (energy >= 10) {
                this_world->add_item(new Blue_Bullet(GetX(), GetY() + 50, 0.5, 5, this_world));
//                std::cout<<this_world->object_num()<<std::endl;
                energy -= 10;
            }
        }
        if (energy < 10) {
            energy++;
        }
        return;
    }
}

void Dawnbreaker::life_cost(int hurt) {
    HP -= hurt;
}

int Dawnbreaker::is_enemy() {
    return 0;
}

int Dawnbreaker::is_blue_bullet() {
    return 0;
}

int Dawnbreaker::is_meteor() {
    return 0;
}


