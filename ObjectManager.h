#pragma once
#include "ObjectBase.h"
#include "_CharaGroup.h"
#include <unordered_map>

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
private:
	std::unordered_map<std::string,_CharaGroup*> Objects;
};

