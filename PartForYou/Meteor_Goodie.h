//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_METEOR_GOODIE_H
#define DAWNBREAKER_METEOR_GOODIE_H
#include "GameObjects.h "
#include "GameWorld.h"
#include "Goodie.h"

class Meteor_Goodie: public Goodie{
public:
    Meteor_Goodie(int x, int y, GameWorld* world);

    void crash() override;

};


#endif //DAWNBREAKER_METEOR_GOODIE_H
