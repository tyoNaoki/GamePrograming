#include "World.h"
#include "_CharaGroup.h"
#include "FirstStage.h"


World::World(Render *renderer):renderer(renderer){
	objectManager = new ObjectManager();
}


World::~World()
{
	//delete stageBase;
	delete objectManager;
}

void World::Initialize()
{
	objectManager->AddGroup(GroupCategory::PlayerGroup, new _CharaGroup());
	objectManager->Initialize();
	curretnStage = new FirstStage(this,renderer,objectManager);
	curretnStage->StageInitialize();
}


void World::RegisterGroup(GroupCategory name, _CharaGroup *Group) {
	objectManager->RegisterGroup(name);
}

void World::AddChildren(GroupCategory name, std::string TargetName, CharacterBase *Target) {
	objectManager->
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
