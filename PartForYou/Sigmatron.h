//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_SIGMATRON_H
#define DAWNBREAKER_SIGMATRON_H

#include "Enemy.h"
#include "Explosion.h"

class Sigmatron: public Enemy{
public:
    Sigmatron(int x, int y, int HP, int speed, GameWorld* world);

    void destructed() override;

    void attack() override;

};

#endif //DAWNBREAKER_SIGMATRON_H
