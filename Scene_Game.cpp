#include "Scene_Game.h"
#include "IScene.h"
#include <DxLib.h>

#define Charafolder "Data//Character"
#define Playerfolder "//Player//"

Scene_Game::Scene_Game(Render *render,StageBase *firstStage,World *world)
	: isEnd(false),render(render),CurrentStage(firstStage),worlds(world)
{
}

Scene_Game::~Scene_Game()
{
	delete render;
	delete worlds;
	delete CurrentStage;
}

void Scene_Game::LoadAsset() {
	render->Load3DModel("Player", Charafolder Playerfolder"PC.mv1" );
	render->LoadAnimation("Player", Charafolder Playerfolder"Anim_Attack1.mv1");
}

void Scene_Game::Update(float Deltatime) {
	worlds->Update(Deltatime);
}

void Scene_Game::Draw(float Deltatime) {
	worlds->Draw(Deltatime,*render);
}

void Scene_Game::Initialize() {
	worlds->Initialize();
}

void Scene_Game::Finalize() {
}

Scene Scene_Game::Next() {
	return Scene::None;
}

bool Scene_Game::IsEnd()const {
	return isEnd;
}


