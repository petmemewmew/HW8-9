//
// Created by 26963 on 2022/6/6.
//

#include "Enemy.h"

Enemy::Enemy(int IMGID, int x, int y, int in_HP, int in_hit, int in_speed, GameWorld *world) : GameObject(IMGID, x, y,
                                                                                                          180, 0, 1.0,
                                                                                                          world) {
    HP = in_HP;
    hurt = in_hit;
    speed = in_speed;
}

int Enemy::is_enemy() {
    return 1;
}

int Enemy::is_blue_bullet() {
    return 0;
}

int Enemy::is_meteor() {
    return 0;
}

void Enemy::cost_life(int hit) {
    HP -= hit;
}

void Enemy::crash(GameObject *it) {

}

void Enemy::Update() {
    if (is_dead) {
        return;
    }
    if (GetY() < 0) {
        is_dead = 1;
        return;
    }
    //crash not written

    if (HP <= 0) {
        destructed();
        return;
    }

    attack();
//    if (abs(this_world->return_Dawnbreaker()->GetX() - GetX())) {
//        if (energy >= 25) {
//            if (int i = randInt(1, 4) == 1) {
//                energy -= 25;
//                this_world->add_item(new Red_Bullet(GetX(), GetY() - 50, 180, hurt, this_world));
//            }
//        }
//    }
//
//    if (energy < 25){
//        energy++;
//    }

    if (strategy_time == 0) {
        strategy_time = randInt(10, 50);
        switch (int j = randInt(1, 3)) {
            case 1:
                strategy = 1;
                break;
            case 2:
                strategy = 2;
                break;
            case 3:
                strategy = 3;
                break;
            default:
                break;
        }
    }
    if (GetX() < 0) {
        strategy = 3;
        strategy_time = randInt(10, 50);
    }

    if (GetX() > WINDOW_WIDTH) {
        strategy = 2;
        strategy_time = randInt(10, 50);
    }

    strategy_time--;
    switch (strategy) {
        case 1:
            MoveTo(GetX(), GetY() - speed);
            break;
        case 2:
            MoveTo(GetX() - speed, GetY() - speed);
            break;
        case 3:
            MoveTo(GetX() + speed, GetY() - speed);
            break;
    }

    //check crash
}

