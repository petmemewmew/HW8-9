#include "GameObjects.h"

GameObject::GameObject(int imageID, int x, int y, int direction, int layer, double size, GameWorld* world): ObjectBase(imageID,x,y,direction,layer,size){
    is_dead = 0;
    this_world = world;
};

void GameObject::clear() {
    delete this;
}

int GameObject::check_dead() const {
    return is_dead;
}

GameObject::~GameObject() {
}

void GameObject::set_dead() {
    is_dead = 1;
}

int GameObject::return_hurt() {
    return 0;
}
