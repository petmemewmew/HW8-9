//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_POWER_UP_GOODIE_H
#define DAWNBREAKER_POWER_UP_GOODIE_H

#include "GameObjects.h "
#include "GameWorld.h"
#include "Goodie.h"

class Power_Up_Goodie : public Goodie {
public:
    Power_Up_Goodie(int x, int y, GameWorld *world);

    void crash() override;

};

#endif //DAWNBREAKER_POWER_UP_GOODIE_H
