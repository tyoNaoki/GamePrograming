#include "World.h"
#include "_CharaGroup.h"


World::World():objectManager(new ObjectManager()){
}


World::~World()
{
	//delete stageBase;
	delete objectManager;
}

void World::Initialize()
{
	objectManager->Initialize();
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

GameTurn World::GetTurn() {
	return stageBase->GetTurn();
}

void World::Draw(float Delattime, Render &renderer)
{
	stageBase->Draw(Delattime);
	objectManager->Draw(Delattime, renderer);
}

Vector3 World::GetStartPosition()
{
	return stageBase->GetStartPotion();
}