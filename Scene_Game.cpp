#include "Scene_Game.h"
#include "IScene.h"
#include <DxLib.h>


Scene_Game::Scene_Game(Render *render):isEnd(false),render(render)
{
}

Scene_Game::~Scene_Game()
{
	delete render;
}

void Scene_Game::LoadAsset() {
	render->Load3DModel("Player", "Data//Character//Player//PC.mv1");
}

void Scene_Game::Update(float Deltatime) {
}

void Scene_Game::Draw() {
	render->Draw3DModel("Player", PlayerPos);
}

void Scene_Game::Initialize() {

}

void Scene_Game::Finalize() {

}

Scene Scene_Game::Next() {
	return Scene::None;
}

bool Scene_Game::IsEnd()const {
	return isEnd;
}


