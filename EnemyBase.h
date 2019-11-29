#pragma once

#include "CharacterBase.h"
#include "Vector3.h"
#include "Render.h"
#include "World.h"

class EnemyBase :
	public CharacterBase
{
public:
	EnemyBase(World &world,Vector3 &position);
	~EnemyBase();
};

