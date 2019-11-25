#include "SceneController.h"
#include <DxLib.h>
#include "IScene.h"
#include <memory>


SceneController::SceneController() :alpha(1.0f),IsFinishedInitialize(false)
{
}

SceneController::~SceneController()
{
	for (auto itr = scenes.begin(); itr != scenes.end(); itr++) {
		delete itr->second;
	}
}

void SceneController::AddScene(Scene name,IScene *scene) {
	scenes[name] = scene;
}



void SceneController::MainUpdate(float Deltatime) {

	if (!currentSeen->IsEnd()) {
		if (alpha > 0.0f){
			alpha -= Deltatime / 60.0f;
		}else {
			alpha = 0.0f;
		}
	}
	else {
		alpha += Deltatime / 60.0f;
		if (alpha >= 1.0f) {
			Change(currentSeen->Next());
		}
	}

	if (alpha <= 0.0f){ //�t�F�[�h�C���I����̏���

		currentSeen->Update(Deltatime);
	}
}

void SceneController::Change(Scene name) {
	Finalize();
	alpha = 1.0f;
	currentSeen = scenes[name];
	currentSeen->LoadAsset();
}

void SceneController::MainRender(float Deltatime) {
	if (!currentSeen->IsEnd()) {
		currentSeen->Draw();
	}
}

void SceneController::Initialize() {
	Finalize();
	scenes.clear();

	Tytle = new Scene_Tytle(new Render());
	Game = new Scene_Game(new Render());

	AddScene(Scene::Title, Tytle);
	AddScene(Scene::Battle, Game);
	Change(Scene::Title);
	IsFinishedInitialize = true;
}

void SceneController::Finalize() {
}

