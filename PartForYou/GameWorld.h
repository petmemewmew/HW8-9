#ifndef GAMEWORLD_H__
#define GAMEWORLD_H__

#include <list>

#include "WorldBase.h"

#include "GameObjects.h"

#include "Dawnbreaker.h"

#include "Star.h"

#include "Blue_Bullet.h"

class ObjectBase;

class GameObject;

class Dawnbreaker;

class GameWorld : public WorldBase {
public:
    GameWorld();

    virtual ~GameWorld();

    virtual void Init() override;

    virtual LevelStatus Update() override;

    virtual void CleanUp() override;

    virtual bool IsGameOver() const override;

    void add_item(GameObject *object);

    int object_num();

    int Get_Dawnbreaker_X();

    int Get_Dawnbreaker_Y();

    Dawnbreaker *return_Dawnbreaker();

    bool is_crash(GameObject *object1, GameObject *object2);

    int iterate_crash(Enemy *enemy);

    void add_kill();

private:
    std::list<GameObject *> object_list;

    int Game_life = 3;

    int kill_count = 0;

    Dawnbreaker *player;
};

#endif // !GAMEWORLD_H__
