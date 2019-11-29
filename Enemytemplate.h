#pragma once
#include "EnemyBase.h"
class Enemytemplate :
	public EnemyBase
{
public:
	Enemytemplate(World &world,  Vector3 &position);
	~Enemytemplate();
};

