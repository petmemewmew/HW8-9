//
// Created by 26963 on 2022/6/3.
//

#ifndef PARTFORYOU_DAWNBREAKER_H
#define PARTFORYOU_DAWNBREAKER_H

#include "GameObjects.h "
#include "GameWorld.h"
#include "Meteor.h"

class Enemy;

class GameObject;

class GameWorld;

class Dawnbreaker : public GameObject {
public:
    Dawnbreaker(GameWorld *world);

    void Update() override;

    void life_cost(int hurt);

    std::string return_type() override;

    int get_life();

    void life_increase(int amount);

    void level_count();

    void get_meteor();

    int meteor_count_fun();


private:
    int meteor_count = 0;
    int energy = 10;
    int level_up = 0;
};


#endif //PARTFORYOU_DAWNBREAKER_H
