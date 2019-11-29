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

class World
{
public:
	World();
	~World();
	void Initialize();
	void Update(float Deltatime);
	void Draw(float Delattime, Render &renderer);
	void AddGroup(GroupCategory name, _CharaGroup *Group);
	template<typename T>
	void AddTarget(GroupCategory name, std::string TargetName, T *target);
	Vector3 GetStartPosition();
	GameTurn GetTurn();
private:
	StageBase *stageBase;
	ObjectManager *objectManager;
	StageBase *curretnStage;
};

