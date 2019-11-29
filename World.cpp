#include "World.h"
#include "_CharaGroup.h"


World::World()
{
}


World::~World()
{
}

void World::Initialize()
{

}

void World::AddGroup(GroupCategory name, _CharaGroup *Group) {
	objectManager->RegisterGroup(name);
}

template<typename T>
void World::AddTarget(GroupCategory name, std::string TargetName,T *target) {
	objectManager->Add(name,TargetName,target);
}

void World::Update(float Deltatime)
{
	stageBase->Update(Deltatime);
	objectManager->Update(Deltatime);
}

void World::Draw(float Delattime, Render &renderer)
{
	stageBase->Draw(Delattime);
	objectManager->Draw(Delattime, renderer);
}

Vector3 World::GetStartPosition()
{
	return Vector3();
}
