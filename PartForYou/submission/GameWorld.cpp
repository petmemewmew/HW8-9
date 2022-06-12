#include "GameWorld.h"
#include <algorithm>
#include "Enemy.h"
#include "Alphatron.h"
#include "Sigmatron.h"
#include "Omegatron.h"
#include "string"


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
    kill_count = 0;
    require = 3 * GetLevel();
    on_screen = 0;
    to_destroy = require - kill_count;
    max_on_screen = (5 + GetLevel()) / 2;
    allowed = std::min(max_on_screen, to_destroy);
}

void GameWorld::add_item(GameObject *object) {
    object_list.push_back(object);
}

LevelStatus GameWorld::Update() {
//    if(on_screen < allowed)
//    object_list.push_back(new Alphatron(randInt(1,WINDOW_WIDTH), 500, 1, 1, 1, this));
    int if_star = randInt(1, 30);
    if (if_star == 1) {
        int x = randInt(0, WINDOW_WIDTH - 1);
        int y = WINDOW_HEIGHT - 1;
        double size = randInt(10, 40) * 1.0 / 100;
        object_list.push_back(new Star(x, y, size, this));
    }

    if (on_screen < allowed) {
        int ranI = randInt(1, 100);
        if (ranI <= (allowed - on_screen)) {
            int p1 = 6;
            int p2 = 2 * std::max(GetLevel() - 1, 0);
            int p3 = 3 * std::max(GetLevel() - 2, 0);
//            std::cout << p1 << ',' << p2 << ',' << p3 << std::endl;
            int ranJ = randInt(1, p1 + p2 + p3);
            if (ranJ <= p1) {
                int x = randInt(0, WINDOW_WIDTH - 1);
                int y = WINDOW_HEIGHT - 1;
                int HP = 20 + 2 * GetLevel();
                int hit = 4 + GetLevel();
                int speed = 2 + (GetLevel() / 5);
//                std::cout << x << "," << y << "," << HP << "," << hit << "," << speed << "," << std::endl;
                object_list.push_back(new Alphatron(x, y, HP, hit, speed, this));
            } else if (ranJ <= p1+p2) {
                int x = randInt(0, WINDOW_WIDTH - 1);
                int y = WINDOW_HEIGHT - 1;
                int HP = 25 + 5 * GetLevel();
                int speed = 2 + (GetLevel() / 5);
                object_list.push_back(new Sigmatron(x, y, HP, speed, this));
            } else {
                int x = randInt(0, WINDOW_WIDTH - 1);
                int y = WINDOW_HEIGHT - 1;
                int HP = 20 + GetLevel();
                int hit = 2 + 2 * GetLevel();
                int speed = 3 + (GetLevel() / 4);

//                std::cout<<x<<","<<y<<","<<HP<<","<<hit<<","<<speed<<","<<std::endl;
                object_list.push_back(new Omegatron(x, y, HP, hit, speed, this));
            }
        }
    }


    player->Update();
    for (auto &it: object_list) {
        it->Update();
    }

    if (player->check_dead()) {
        Game_life--;
        return LevelStatus::DAWNBREAKER_DESTROYED;
    }

    if (kill_count >= require) {
        return LevelStatus::LEVEL_CLEARED;
    }
//    else{
//        return LevelStatus::LEVEL_CLEARED;
//    }
//    std::list<GameObject*>::iterator it;
    for (auto it = object_list.begin(); it != object_list.end();) {
        if ((*it)->check_dead()) {
            GameObject *temp = *it;
            it = object_list.erase(it++);
            delete temp;
        } else {
            ++it;
        }
    }
    std::string bar = "HP: " + std::to_string(player->get_life()) + "/100   Meteors: " +
                      std::to_string(player->meteor_count_fun()) + "   Lives: " + std::to_string(Game_life) + "   Level: " +
                      std::to_string(GetLevel()) + "   Enemies: " + std::to_string(kill_count) + "/" +
                      std::to_string(require) + "   Score: " +
                      std::to_string(GetScore());

    SetStatusBarMessage(bar);

//    std::cout << object_num() << std::endl;
    return LevelStatus::ONGOING;
}

void GameWorld::CleanUp() {
//    std::cout << "aaaaaaaaaaaaaaaasefefweseaferfWEF" << std::endl;
    for (auto it = object_list.begin(); it != object_list.end();) {
        GameObject *temp = *it;
        it = object_list.erase(it++);
//        std::cout << object_list.size() << std::endl;
        delete temp;
    }
    delete player;
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

bool GameWorld::is_crash(GameObject *object1, GameObject *object2) {
//    double d = sqrt((object1->GetX() - object2->GetX()) * (object1->GetX() - object2->GetX()) +
//                    (object1->GetY() - object2->GetY()) * (object1->GetY() - object2->GetY()));
    double d = pow(object1->GetX() - object2->GetX(), 2) + pow(object1->GetY() - object2->GetY(), 2);
    if (d < pow(30.0 * (object1->GetSize() + object2->GetSize()), 2)) {
        return true;
    } else {
        return false;
    }
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

void GameWorld::level_up() {
    player->level_count();
}

void GameWorld::get_meteor() {
    player->get_meteor();
}

GameObject *GameWorld::iterate_crash(GameObject *object) {
    for (auto it = object_list.begin(); it != object_list.end(); it++) {
        if (is_crash(*it, object)) {
            if (*it != object) {
                if (!(*it)->check_dead()) {
                    return *it;
                }
            }
        }
    }
    if (is_crash(player, object)) {
        return player;
    }
    return nullptr;
}

void GameWorld::count_an_enemy() {
    on_screen++;
}

void GameWorld::kill_an_enemy() {
    on_screen--;
}


