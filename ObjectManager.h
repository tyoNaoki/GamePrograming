#pragma once

#include "ObjectBase.h"
#include "CharacterBase.h"
#include "_CharaGroup.h"
#include <vector>
#include <unordered_map>

class _CharaGroup;
class ObjectBase;
class CharacterBase;

enum class GroupCategory {
	PlayerGroup,
	EnemyGroup,
	Barricade,
	GardTarget,
	None
};

enum class CharaCategory {
	Player,
	NormalEnemy,
	TargetEnemy,
	Boss,
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

	void AddGroup(GroupCategory GroupType);
	void AddChildren(GroupCategory GroupType,CharaCategory CharaType,std::string TargetName);

	void RemoveGroup(GroupCategory name);
	_CharaGroup* FindGroup(GroupCategory name);
	ObjectBase* FindObject(GroupCategory name, std::string ObjectName);
	CharacterBase* FindChara(GroupCategory name, std::string CharaName);

private:

	std::unordered_map<GroupCategory, _CharaGroup*>Group;
	World *world;
	Render *renderer;
};
