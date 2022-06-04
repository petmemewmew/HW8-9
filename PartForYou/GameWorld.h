#ifndef GAMEWORLD_H__
#define GAMEWORLD_H__

#include <list>

#include "WorldBase.h"

#include "GameObjects.h"
class ObjectBase;
class GameObject;
class Dawnbreaker;
class GameWorld : public WorldBase {
public:
  GameWorld();
  virtual ~GameWorld();

  virtual void Init() override;

  virtual LevelStatus Update() override;

  virtual void CleanUp() override;

  virtual bool IsGameOver() const override;

  void add_item(GameObject* object);

  int object_num();

private:
    std::list<GameObject*> object_list;
    int Game_life = 3;
    Dawnbreaker *player;

};

#endif // !GAMEWORLD_H__
