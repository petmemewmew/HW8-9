#ifndef GAMEOBJECTS_H__
#define GAMEOBJECTS_H__

#include "ObjectBase.h"
#include "GameWorld.h"

class GameObject : public ObjectBase {
protected:
    GameObject(int imageID, int x, int y, int direction, int layer, double size );
    int is_dead = 0;

public:
    int check_dead();
};

class Dawnbreaker: public GameObject{
public:
    Dawnbreaker();
    void Update() override;
private:
    int energy = 10;
    int HP = 100;
};

class Star: public GameObject{
public:
    Star(int x, int y, double size);
    void Update() override;
};

class Blue_Bullet: public GameObject{
public:
    Blue_Bullet(int x, int y, double size, int hit);
    void Update() override;

private:
    int hurt;
};

#endif // GAMEOBJECTS_H__
