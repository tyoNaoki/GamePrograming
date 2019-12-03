#include "EnemyBase.h"


EnemyBase::EnemyBase(World &world, Vector3 &position, std::string &name)
	: CharacterBase(world, position), EnemyName(name)
{
}


EnemyBase::~EnemyBase()
{
}
