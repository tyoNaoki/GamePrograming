#pragma once
#include "DxLib.h"
#include "CharacterBase.h"
#include<unordered_map>
#include "Render.h"
#include "string.h"

class CharacterBase;
class ObjectBase;

class _CharaGroup
{
public:
	_CharaGroup();
	~_CharaGroup();
	virtual void RegistObject(const std::string name, ObjectBase* object);
	virtual void RegistChara(const std::string name, CharacterBase* character);
	virtual int GetAliveNumber();
	virtual void Initialize();
	virtual void Finalize();
	virtual void UpdateChara(const float Deltatime);
	virtual void UpdateObject(const float Deltatime);
	virtual void DrawChara(const float &Deltatime,Render &renderer);
	virtual void DrawObject(const float Deltatime, Render &renderer);
	virtual void RemoveChara(const std::string name);
	virtual CharacterBase* GetChara(const std::string name);
	virtual ObjectBase* GetObject(const std::string name);
	virtual bool contain(const std::string &name);
private:
	std::unordered_map<std::string, ObjectBase*>Objects;
	std::unordered_map<std::string, CharacterBase*>Characters;
};

