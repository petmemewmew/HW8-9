//
// Created by 26963 on 2022/6/3.
//

#include "Alphatron.h"

Alphatron::Alphatron(int x, int y, int HP, int hit, int speed, GameWorld *world) : Enemy(IMGID_ALPHATRON, x, y, HP, hit,
                                                                                         speed, world) {
    energy = 25;
}

void Alphatron::destructed() {
    this_world->add_item(new Explosion(GetX(), GetY(), this_world));
    this_world->IncreaseScore(150);
    this_world->add_kill();
}

void Alphatron::attack() {
    if (abs(this_world->return_Dawnbreaker()->GetX() - GetX()) <= 10 ) {
        if (energy >= 25) {
            if (int i = randInt(1, 4) == 1) {
                energy -= 25;
                this_world->add_item(new Red_Bullet(GetX(), GetY() - 50, 180, hurt, this_world));
            }
        }
    }

    if (energy < 25){
        energy++;
    }
}





//void Alphatron::Update() {
//    if (is_dead) {
//        return;
//    }
//    if (GetY() < 0) {
//        set_dead();
//        return;
//    }
//    for (auto it = this_world->return_list().begin(); it != this_world->return_list().end(); it++) {
//        if((GetY() == (*it)->GetY()) && GetX() == (*it)-> GetX()){
//            if((*it)->is_blue_bullet()){
//                HP -= (*it)->return_hurt;
//
//            }
//            if((*it)->is_meteor()){
//                is_dead = 1;
//            }
////            if()
//        }
//    }
//
//}

