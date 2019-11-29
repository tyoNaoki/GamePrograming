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

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void Initialize();
	void Update(float Deltatime);
	void Draw(float Deltatime, Render &renderer);
	void RegisterGroup(GroupCategory Gname);
	void AddGroup(GroupCategory name,_CharaGroup *Group);

	template<typename T>
	void Add(GroupCategory name,std::string TargetName,T *target);

	void RemoveGroup(GroupCategory name);
	_CharaGroup* FindGroup(GroupCategory name);
	ObjectBase* FindObject(GroupCategory name, std::string ObjectName);
	CharacterBase* FindChara(GroupCategory name, std::string CharaName);

private:
	std::unordered_map<GroupCategory, _CharaGroup*>Charas;
	World *world;
	Render *renderer;
};
