#include "GameWorld.h"
#include <algorithm>

GameWorld::GameWorld() {

}

GameWorld::~GameWorld() {

}

void GameWorld::Init() {
    player = new Dawnbreaker(this);
    Game_life = 3;
    for(int i = 0; i < 30; i++){
        int x = randInt(0, WINDOW_WIDTH-1);
        int y = randInt(0, WINDOW_HEIGHT-1);
        double size = randInt(10,40)* 1.0 / 100 ;
        GameObject* p = new Star(x,y,size, this);
        object_list.push_back(p);
//        std::cout<<object_list.size()<<std::endl;
    }
}

void GameWorld::add_item(GameObject *object) {
    object_list.push_back(object);
}

LevelStatus GameWorld::Update() {
    int if_star = randInt(1,30);
    if(if_star == 1){
        int x = randInt(0, WINDOW_WIDTH-1);
        int y = WINDOW_HEIGHT-1;
        double size = randInt(10,40)*1.0 / 100;
        object_list.push_back(new Star(x,y,size, this));
    }
//    std::list<GameObject*>::iterator it;
    player->Update();
    for(auto it = object_list.begin(); it!= object_list.end(); it++){
        (*it)->Update();
    }

    if (player->check_dead()){
        Game_life --;
        return LevelStatus::DAWNBREAKER_DESTROYED;
    }
//    else{
//        return LevelStatus::LEVEL_CLEARED;
//    }
//    std::list<GameObject*>::iterator it;
    for(auto it = object_list.begin(); it != object_list.end();){
        if((*it)->check_dead()){
            GameObject* temp = *it;
            it = object_list.erase(it);
            delete temp;
        }else{
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


