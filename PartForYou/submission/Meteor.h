//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_METEOR_H
#define DAWNBREAKER_METEOR_H
#include "GameObjects.h "
#include "GameWorld.h"

class Meteor: public GameObject {
public:
    Meteor(int x, int y,  GameWorld *world);

    void Update() override;

    std::string return_type() override;

    int return_hurt() override;

private:
    int hurt;
};

#endif //DAWNBREAKER_METEOR_H
