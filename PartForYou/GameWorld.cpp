#include "GameWorld.h"
#include <algorithm>
#include "Enemy.h"


GameWorld::GameWorld() {
    Game_life = 3;
}

GameWorld::~GameWorld() {

}

void GameWorld::Init() {
    player = new Dawnbreaker(this);
    for (int i = 0; i < 30; i++) {
        int x = randInt(0, WINDOW_WIDTH - 1);
        int y = randInt(0, WINDOW_HEIGHT - 1);
        double size = randInt(10, 40) * 1.0 / 100;
        GameObject *p = new Star(x, y, size, this);
        object_list.push_back(p);
//        std::cout<<object_list.size()<<std::endl;
    }
}

void GameWorld::add_item(GameObject *object) {
    object_list.push_back(object);
}

LevelStatus GameWorld::Update() {
    int if_star = randInt(1, 30);
    if (if_star == 1) {
        int x = randInt(0, WINDOW_WIDTH - 1);
        int y = WINDOW_HEIGHT - 1;
        double size = randInt(10, 40) * 1.0 / 100;
        object_list.push_back(new Star(x, y, size, this));
    }
//    std::list<GameObject*>::iterator it;
    player->Update();
    for (auto it = object_list.begin(); it != object_list.end(); it++) {
        (*it)->Update();
    }

    if (player->check_dead()) {
        Game_life--;
        return LevelStatus::DAWNBREAKER_DESTROYED;
    }
//    else{
//        return LevelStatus::LEVEL_CLEARED;
//    }
//    std::list<GameObject*>::iterator it;
    for (auto it = object_list.begin(); it != object_list.end();) {
        if ((*it)->check_dead()) {
            GameObject *temp = *it;
            it = object_list.erase(it);
            delete temp;
        } else {
            ++it;
        }
    }

//    std::cout<<object_num()<<std::endl;
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
//    std::list<GameObject*>::iterator it;
//    for(it = object_list.begin(); it != object_list.end(); it++){
//        delete *(it++);
//    }
    for (auto it = object_list.begin(); it != object_list.end(); it++) {
        it = object_list.erase(it);
    }
}


bool GameWorld::IsGameOver() const {
    if (Game_life == 0) {
        return true;
    } else {
        return false;
    }
}

int GameWorld::object_num() {
    return object_list.size();
}

int GameWorld::Get_Dawnbreaker_X() {
    return player->GetX();
}

int GameWorld::Get_Dawnbreaker_Y() {
    return player->GetY();
}

Dawnbreaker *GameWorld::return_Dawnbreaker() {
    return player;
}

bool GameWorld::is_crash(GameObject* object1, GameObject* object2) {
    if (object1->GetX() == object2->GetX()){
        if(object1->GetY() == object2->GetY()){
            return true;
        }
    }
    return false;
}

int GameWorld::iterate_crash(Enemy* enemy) {
    for(auto it = object_list.begin(); it != object_list.end(); it++){
        if (is_crash(*it, enemy)){
            if ((*it)->return_type() == "Blue_Bullet"){
                return 1;
            }
            if ((*it)->return_type() == "Meteor"){
                return 2;
            }
        }
    }
    if ((player->GetY() == enemy->GetY()) && (player->GetX() == enemy->GetX())){
        return 3;
    }
    return 0;
}

void GameWorld::add_kill() {
    kill_count++;
}

int GameWorld::return_HP() {
    return player->get_life();
}

void GameWorld::add_HP(int amount) {
    player->life_increase(amount);
}


