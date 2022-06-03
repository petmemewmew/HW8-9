#ifndef GAMEOBJECTS_H__
#define GAMEOBJECTS_H__
#include "ObjectBase.h"
#include "GameWorld.h"

class GameWorld;

class GameObject : public ObjectBase {
protected:
    GameObject(int imageID, int x, int y, int direction, int layer, double size, GameWorld* world);
    int is_dead = 0;
    GameWorld* this_world;

public:
    void clear();
    int check_dead() const;
    ~GameObject() override;
};

class Dawnbreaker: public GameObject{
public:
    Dawnbreaker(GameWorld* world);
    void Update() override;
private:
    int energy = 10;
    int HP = 100;
};

class Star: public GameObject{
public:
    Star(int x, int y, double size, GameWorld* world);
    void Update() override;
};

class Blue_Bullet: public GameObject{
public:
    Blue_Bullet(int x, int y, double size, int hit, GameWorld* world);
    void Update() override;

private:
    int hurt;
};

#endif // GAMEOBJECTS_H__
