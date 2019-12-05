#pragma once
#include "SceneController.h"
#include "StageBase.h"
#include "ObjectManager.h"
#include "CharacterBase.h"
#include "_CharaGroup.h"
#include "Vector3.h"

class CharacterBase;
class ObjectManager;
class StageBase;
enum class GroupCategory;
class Render;

class World
{
public:
	World(Render *renderer);
	~World();
	void Initialize();
	void Update(float Deltatime);
	void Draw(float Delattime, Render &renderer);
	template <class T>
	void AddGroup(T category);
	template <class T>
	void AddChildren(T category,std::string name);
	Vector3 GetStartPosition();
	GameTurn GetTurn();
private:
	StageBase *Stages;
	ObjectManager *objectManager;
	StageBase *curretStage;
	Render *renderer;
};

