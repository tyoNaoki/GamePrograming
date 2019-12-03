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
	void RegisterGroup(GroupCategory name, _CharaGroup *Group);
	void AddChildren(GroupCategory name, std::string TargetName, CharacterBase *Target);
	void AddChildren(GroupCategory name, std::string TargetName, ObjectBase *Target);
	Vector3 GetStartPosition();
	GameTurn GetTurn();
private:
	StageBase *stageBase;
	ObjectManager *objectManager;
	StageBase *curretnStage;
	Render *renderer;
};

