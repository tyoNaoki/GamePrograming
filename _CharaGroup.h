#pragma once
#include "DxLib.h"
#include "CharacterBase.h"
#include<unordered_map>

class _CharaGroup
{
public:
	_CharaGroup();
	~_CharaGroup();
	virtual void RegistChara(const std::string&,CharacterBase*);
	virtual int GetAliveNumber();
	virtual void Initialize();
	virtual void Finalize();
	virtual void UpdateChara(const float &Deltatime);
	virtual void RemoveChara(const std::string&);
	virtual CharacterBase* FindChara(const std::string &name);
	virtual bool contain(const std::string &name);
private:
	std::unordered_map<std::string, CharacterBase*>Chara;
};

