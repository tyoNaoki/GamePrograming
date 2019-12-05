#pragma once

#include "ObjectBase.h"
#include "CharacterBase.h"
#include "_CharaGroup.h"
#include "ObjectGroup.h"
#include <vector>
#include <unordered_map>

class _CharaGroup;
class ObjectGroup;
class ObjectBase;
class CharacterBase;

enum class CharaCategory {
	Player,
	NormalEnemy,
	TargetEnemy,
	Boss,
	None
};

enum class ObjectCategory {
	Wall,
	DiffenceTarget,
	Gate,
	Trap,
	None
};

enum class EnemyCategory {
	Goblin,
	BossGoblin,
};

class ObjectManager
{
public:
	ObjectManager(World*_world,Render*renderer);
	~ObjectManager();
	void Initialize();
	void Update(float Deltatime);
	void Draw(float Deltatime, Render &renderer);

	void AddGroup(CharaCategory CharacterType);
	void AddChildren(CharaCategory CharaType,std::string TargetName);
	void AddChildren(CharaCategory CharaType, std::string TargetName, EnemyCategory EnemyType);
	//void AddChildren(ObjectCategory ObjectType, std::string TargetName);

	void RemoveGroup(CharaCategory CharaType);
	void RemoveGroup(ObjectCategory ObjectType) {};

	_CharaGroup* FindGroup(CharaCategory CharaType);
	//void FindGroup(GroupCategory name, ObjectCategory ObjectType);
	//ObjectBase* FindChildren(ObjectCategory ObjectType, std::string ObjectName);
	CharacterBase* FindChildren(CharaCategory CharaType, std::string CharaName);

private:
	//各キャラクターの親を入れる
	std::unordered_map<CharaCategory, _CharaGroup*>Characters;
	std::unordered_map<ObjectCategory, ObjectGroup*>Objects;

	World *world;
	Render *render;
};
