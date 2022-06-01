#include "GameObjects.h"

GameObject::GameObject(int imageID, int x, int y, int direction, int layer, double size, GameWorld* world): ObjectBase(imageID,x,y,direction,layer,size){
    this_world = world;
};

Dawnbreaker::Dawnbreaker(GameWorld* world): GameObject(IMGID_DAWNBREAKER, 300,100, 0, 0, 1.0,world) {
    HP = 100;
    energy = 10;
}

void GameObject::clear() {
    delete this;
}

int GameObject::check_dead() {
    return is_dead;
}

void Dawnbreaker::Update() {
    if(HP <= 0) {
        is_dead = 1;
        return;
    }else{
        if(this_world->GetKey(KeyCode::UP)) {
            if (GetY() + 4 <= (WINDOW_HEIGHT - 1)) {
                MoveTo(GetX(), GetY() + 4);
            }
        }
        if(this_world->GetKey(KeyCode::DOWN)) {
            if (GetY() - 4 >= 50) {
                MoveTo(GetX(), GetY() - 4);
            }
        }
        if(this_world->GetKey(KeyCode::LEFT)) {
            if (GetX() - 4 >= 0) {
                MoveTo(GetX() - 4, GetY());
            }
        }
        if(this_world->GetKey(KeyCode::RIGHT)) {
            if (GetX() + 4 <= (WINDOW_WIDTH - 1)) {
                MoveTo(GetX() + 4, GetY());
            }
        }
        if(this_world->GetKey(KeyCode::FIRE1)){
            if(energy >= 10){
                this_world->add_item(new Blue_Bullet(GetX(), GetY()+50, 0.5, 5, this_world));
            }
        }
        if(energy < 10){
            energy++;
        }
        return;
    }
}

Star::Star(int x, int y, double size, GameWorld* world) : GameObject(IMGID_STAR, x , y, 0, 4, size, world){};

void Star::Update() {
    if(GetY() < 0){
        is_dead = 1;
        return;
    }else{
        MoveTo(GetX(), GetY() - 1);
    }
}

Blue_Bullet::Blue_Bullet(int x, int y, double size, int hit, GameWorld* world) : GameObject(IMGID_BLUE_BULLET ,x , y, 0, 1, size, world){
    hurt = hit;
}

void Blue_Bullet::Update() {
    if(is_dead){
        return;
    }else{
        if(GetY() >= WINDOW_HEIGHT){
            is_dead = 1;
            return;
        }else{
            MoveTo(GetX(), GetY()+6);
        }
    }
}
