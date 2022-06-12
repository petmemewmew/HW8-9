//
// Created by 26963 on 2022/6/6.
//

#include "Enemy.h"

Enemy::Enemy(int IMGID, int x, int y, int in_HP, int in_hit, int in_speed, GameWorld *world) : GameObject(IMGID, x, y,
                                                                                                          180, 0, 1.0,
                                                                                                          world) {
    this_world->count_an_enemy();
    HP = in_HP;
    strategy_time = 0;
    hurt = in_hit;
    speed = in_speed;
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
        this_world->kill_an_enemy();
        return;
    }
    GameObject* crash_item = this_world->iterate_crash(this);
    if (crash_item != nullptr) {
        if (crash_item->return_type() == "Blue_Bullet") {
//            get_hurt(this_world->iterate_crash(this)->return_hurt());
            HP -= crash_item->return_hurt();
            crash_item->set_dead();
        } else if (this_world->is_crash(this_world->return_Dawnbreaker(), this)) {
//            std::cout<<"111111111111"<<std::endl;
            this_world->return_Dawnbreaker()->get_hurt(20);
            set_dead();
            return;
        } else if (crash_item->return_type() == "Meteor") {
            set_dead();
            return;
        }
    }

    if (HP <= 0) {
        set_dead();
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

    GameObject* crash_item1 = this_world->iterate_crash(this);
    if (crash_item1 != nullptr) {
        if (crash_item1->return_type() == "Blue_Bullet") {
//            get_hurt(this_world->iterate_crash(this)->return_hurt());
            HP -= crash_item1->return_hurt();
            crash_item1->set_dead();
        } else if (this_world->is_crash(this_world->return_Dawnbreaker(), this)) {
//            std::cout<<"1111111111112"<<std::endl;
            this_world->return_Dawnbreaker()->get_hurt(20);
            set_dead();
            return;
        } else if (crash_item1->return_type() == "Meteor") {
            set_dead();
            return;
        }
    }

    if (HP <= 0) {
        set_dead();
        return;
    }

}

std::string Enemy::return_type() {
    std::string type = "Enemy";
    return type;
}

void Enemy::set_dead() {
    this_world->kill_an_enemy();
    destructed();
    is_dead = 1;
}

