#pragma once
#include "DxLib.h"
#include "CharacterBase.h"
#include<unordered_map>
#include <vector>
#include "Render.h"
#include "string.h"

class CharacterBase;
class ObjectBase;

class _CharaGroup
{
public:
	_CharaGroup();
	~_CharaGroup();
	virtual void Regist(const std::string name, CharacterBase* character);
	virtual int GetAliveNumber();
	virtual void Initialize(Render &renderer);
	virtual void Finalize();
	virtual void Update(const float Deltatime);
	virtual void Draw(const float &Deltatime,Render &renderer);
	virtual bool Remove(const std::string name);
	virtual CharacterBase* Get(const std::string name);
	virtual bool contain(const std::string &name);
private:
	std::vector<CharacterBase*>Character;
};

