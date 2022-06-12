#ifndef GAMEOBJECTS_H__
#define GAMEOBJECTS_H__

#include "ObjectBase.h"


class GameWorld;

class GameObject : public ObjectBase {
protected:
    GameObject(int imageID, int x, int y, int direction, int layer, double size, GameWorld *world);

    int is_dead = 0;

    GameWorld *this_world;

    int HP = 0;

    int hurt = 0;

public:
    void clear();

    virtual int return_hurt();

    int check_dead() const;

    ~GameObject() override;

    virtual void set_dead();

    void get_hurt(int hurt);

    virtual std::string return_type() = 0;

};


#endif // GAMEOBJECTS_H__