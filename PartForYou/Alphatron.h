//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_ALPHATRON_H
#define DAWNBREAKER_ALPHATRON_H
#include "Enemy.h"
#include "Explosion.h"

class Alphatron: public Enemy{
public:
    Alphatron(int x, int y, int HP, int hit, int speed, GameWorld* world);

    void destructed() override;

    void attack() override;
};
#endif //DAWNBREAKER_ALPHATRON_H
