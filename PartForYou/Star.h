//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_STAR_H
#define DAWNBREAKER_STAR_H

#include "GameObjects.h "
#include "GameWorld.h"

class GameObject;

class GameWorld;

class Star : public GameObject {
public:
    Star(int x, int y, double size, GameWorld *world);

    void Update() override;

    std::string return_type() override;
};

#endif //DAWNBREAKER_STAR_H
