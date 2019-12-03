#pragma once
#include "DxLib.h"
#include "CharacterBase.h"
#include<unordered_map>
#include<forward_list>
#include "Render.h"
#include "string.h"

#define MAX_COUNT_ARRANGEMENT 20

class CharacterBase;
class ObjectBase;

class ObjectGroup
{
public:
	ObjectGroup();
	~ObjectGroup();
	virtual void Regist(const std::string name, ObjectBase* object);
	virtual int GetAliveNumber();
	virtual void Initialize();
	virtual void Finalize();
	virtual void UpdateObject(const float Deltatime);
	virtual void DrawObject(const float Deltatime, Render &renderer);
	virtual void Remove(const std::string name);
	virtual ObjectBase* Get(const std::string name);
	virtual bool contain(const std::string &name);
private:
	std::vector<ObjectBase*>Group;
};


