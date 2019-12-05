#pragma once

#include "ObjectBase.h"
#include "CharacterBase.h"
#include "_CharaGroup.h"
#include "ObjectGroup.h"
#include <vector>
#include <unordered_map>

class _CharaGroup;
class ObjectBase;
class CharacterBase;

enum class GroupCategory {
	CharacterGroup,
	ObjectGroup,
};

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

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void Initialize();
	void Update(float Deltatime);
	void Draw(float Deltatime, Render &renderer);

	void AddGroup(GroupCategory GroupType,CharaCategory CharacterType);
	void AddChildren(CharaCategory CharaType,std::string TargetName);
	void AddChildren(ObjectCategory ObjectType, std::string TargetName);

	void RemoveGroup(GroupCategory name);

	void FindGroup(GroupCategory name,CharaCategory CharaType);
	void FindGroup(GroupCategory name, ObjectCategory ObjectType);
	ObjectBase* FindChildren(ObjectCategory ObjectType, std::string ObjectName);
	CharacterBase* FindChildren(CharaCategory CharaType, std::string CharaName);

private:
	//各キャラクターの親を入れる
	std::unordered_map<GroupCategory,_CharaGroup*>Characters;
	std::unordered_map<GroupCategory,ObjectGroup*>Objects;
	
	World *world;
	Render *renderer;
};
