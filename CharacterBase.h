#pragma once
#include "ObjectBase.h"

typedef struct _SCharacterInfo {
	bool UseFlag;
	int ModelHandle;
	
};

class CharacterBase : ObjectBase
{
public:
	virtual void Update(float Deltatime) {};
	CharacterBase();
	~CharacterBase();
};

