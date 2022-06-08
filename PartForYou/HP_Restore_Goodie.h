//
// Created by 26963 on 2022/6/3.
//

#ifndef DAWNBREAKER_HP_RESTORE_GOODIE_H
#define DAWNBREAKER_HP_RESTORE_GOODIE_H

#include "GameObjects.h "
#include "GameWorld.h"
#include "Goodie.h"

class HP_Restore_Goodie: public Goodie{
public:
    HP_Restore_Goodie(int x, int y, GameWorld* world);

    void crash() override;

};

#endif //DAWNBREAKER_HP_RESTORE_GOODIE_H
