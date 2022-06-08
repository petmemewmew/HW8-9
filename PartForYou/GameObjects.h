#ifndef GAMEOBJECTS_H__
#define GAMEOBJECTS_H__

#include "ObjectBase.h"


class GameWorld;

class GameObject : public ObjectBase {
protected:
    GameObject(int imageID, int x, int y, int direction, int layer, double size, GameWorld *world);

    int is_dead = 0;

    GameWorld *this_world;

public:
    void clear();

    virtual int return_hurt();

    int check_dead() const;

    ~GameObject() override;

    void set_dead();

};


#endif // GAMEOBJECTS_H__