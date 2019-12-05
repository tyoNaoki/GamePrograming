#include "World.h"
#include "_CharaGroup.h"
#include "FirstStage.h"


World::World(Render *renderer):renderer(renderer){
	objectManager = new ObjectManager(this,renderer);
}


World::~World()
{
	delete curretStage;
	delete objectManager;
}

void World::Initialize()
{
	Stages = new FirstStage(this, renderer, objectManager);
	curretStage = Stages;
	curretStage->StageInitialize();
	objectManager->AddGroup(CharaCategory::Player);
	objectManager->AddChildren(CharaCategory::Player, "Player");
	objectManager->Initialize();
}

template <class T>
void World::AddGroup(T category) {
	objectManager->AddGroup(category);
}

template <class T>
void World::AddChildren(T category,std::string name) {
	objectManager->AddChildren(category, name);
}

void World::Update(float Deltatime){
	curretStage->Update(Deltatime);
	objectManager->Update(Deltatime);
}

GameTurn World::GetTurn() {
	return curretStage->GetTurn();
}

void World::Draw(float Delattime, Render &renderer)
{
	curretStage->Draw(Delattime);
	objectManager->Draw(Delattime, renderer);
}

Vector3 World::GetStartPosition()
{
	return curretStage->GetStartPotion();
}
