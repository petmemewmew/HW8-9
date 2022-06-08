//
// Created by 26963 on 2022/6/3.
//

#ifndef PARTFORYOU_DAWNBREAKER_H
#define PARTFORYOU_DAWNBREAKER_H

#include "GameObjects.h "
#include "GameWorld.h"

class Enemy;

class GameObject;

class GameWorld;

class Dawnbreaker : public GameObject {
public:
    Dawnbreaker(GameWorld *world);

    void Update() override;

    void life_cost(int hurt);

    std::string return_type() override;


private:
    int energy = 10;
    int HP = 100;
};


#endif //PARTFORYOU_DAWNBREAKER_H
