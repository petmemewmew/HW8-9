//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_EXPLOSION_H
#define DAWNBREAKER_EXPLOSION_H

#include "GameObjects.h "
#include "GameWorld.h"

class Explosion : public GameObject{
public:
    Explosion(int x, int y, GameWorld* world);

    void Update() override;

    std::string return_type() override;
private:
    int tick = 0;
};

#endif //DAWNBREAKER_EXPLOSION_H
