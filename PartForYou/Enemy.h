//
// Created by 26963 on 2022/6/6.
//

#ifndef ALPHATRON_CPP_ENEMY_H
#define ALPHATRON_CPP_ENEMY_H


#include "GameObjects.h "
#include "GameWorld.h"
#include "Red_Bullet.h"

class Enemy: public GameObject{
public:
    Enemy(int IMGID, int x, int y, int in_HP, int in_hit, int in_speed, GameWorld* world);

    void Update() override;

    void crash(GameObject* it);

    virtual void destructed() = 0;

    void set_dead() override;

    void cost_life(int hit);

    virtual void attack() = 0;

    std::string return_type() override;

protected:
    int speed;
    int strategy;
    int energy;
    int strategy_time = 0;

};


#endif //ALPHATRON_CPP_ENEMY_H
