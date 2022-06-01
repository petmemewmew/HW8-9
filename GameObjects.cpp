#include "GameObjects.h"

GameObject::GameObject(int imageID, int x, int y, int direction, int layer, double size): ObjectBase(imageID,x,y,direction,layer,size){};

Dawnbreaker::Dawnbreaker(): GameObject(IMGID_DAWNBREAKER, 300,100, 0, 0, 1.0) {
    HP = 100;
    energy = 10;
}

int GameObject::check_dead() {
    return is_dead;
}

void Dawnbreaker::Update() {
    if(HP <= 0) {
        is_dead = 1;
        return;
    }else{
        if(energy < 10){
            energy++;
        }
        return;
    }
}

Star::Star(int x, int y, double size) : GameObject(IMGID_STAR, x , y, 0, 4, size){};

void Star::Update() {
    if(GetY() < 0){
        is_dead = 1;
        return;
    }else{
        MoveTo(GetX(), GetY() - 1);
    }
}

Blue_Bullet::Blue_Bullet(int x, int y, double size, int hit) : GameObject(IMGID_BLUE_BULLET ,x , y, 0, 1, size){
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
            MoveTo(GetX(), GetY()+6)
        }
    }
}
