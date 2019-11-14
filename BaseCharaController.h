#pragma once
#include "Dxlib.h"
#include "CharacterBase.h"

class BaseCharaController
{
protected:
	CharacterBase *ControllCharacter;
public:
	CharacterBase GetControllCharacter() {
		if (ControllCharacter) {
			return *ControllCharacter;
		}
		ControllCharacter = nullptr;
		return *ControllCharacter;
	}
	virtual void Update(float Deltatime) {};
	BaseCharaController() {};
	~BaseCharaController() { delete ControllCharacter; }
};

