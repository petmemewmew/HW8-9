//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_OMEGATRON_H
#define DAWNBREAKER_OMEGATRON_H

#include "Enemy.h"
#include "Explosion.h"

class Omegatron: public Enemy{
public:
    Omegatron(int x, int y, int HP, int hit, int speed, GameWorld* world);

    void destructed() override;

    void attack() override;

};
#endif //DAWNBREAKER_OMEGATRON_H
