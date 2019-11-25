#pragma once
#include "ObjectBase.h"

typedef struct _SCharacterInfo {
	bool UseFlag;
	int ModelHandle;
	
};

class CharacterBase : public ObjectBase
{
public:
	virtual void Update(float Deltatime) =0;
	virtual ~CharacterBase() {};
};

