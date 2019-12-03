#pragma once

#include "CharacterBase.h"
#include "Vector3.h"
#include "Render.h"
#include "World.h"

enum class EnemyType {
	Goblin,
	BossGoblin
};

class EnemyBase :
	public CharacterBase
{
public:
	EnemyBase(World &world,Vector3 &position,std::string &name);
	~EnemyBase();
protected:
	std::string EnemyName = "None";
};

