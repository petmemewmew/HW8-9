//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_RED_BULLET_H
#define DAWNBREAKER_RED_BULLET_H

#include "GameObjects.h "
#include "GameWorld.h"

class GameObject;

class GameWorld;

class Red_Bullet : public GameObject {
public:
    Red_Bullet(int x, int y, int direction, int hit, GameWorld *world);

    void Update() override;

    std::string return_type() override;
private:
    int hurt;
};


#endif //DAWNBREAKER_RED_BULLET_H
