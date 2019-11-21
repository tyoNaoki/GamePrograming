#pragma once
#include "CharacterBase.h"

typedef struct _SPlayerData {

};

class _Player :
	public CharacterBase
{
private:
	void Movement(char *Key);
	_SObjectBaseData SObjectBaseData;
	_SPlayerData *SPlayerData;
public:
	void Update(float Deltatime)override;
	_Player(_SPlayerData*playerdata);
	_Player();
	~_Player();
};

