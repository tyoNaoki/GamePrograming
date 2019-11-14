#pragma once
#include "CharacterBase.h"
#include "PlayerController.h"

typedef struct _SPlayerData : _SObjectBaseData {

};

class _Player :
	public CharacterBase
{
private:
	PlayerController *PController;
	void Movement(char *Key);
	_SPlayerData *SPlayerData;
public:
	void Update(float Deltatime)override;
	_Player(_SPlayerData*playerdata);
	~_Player();
};

