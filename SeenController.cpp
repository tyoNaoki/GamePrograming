#include "SeenController.h"
#include <DxLib.h>
#include "ISeen.h"
#include <memory>


SeenController::SeenController() :alpha(1.0f)
{
}

SeenController::~SeenController()
{
	for (auto itr = scenes.begin(); itr != scenes.end(); itr++) {
		delete itr->second;
	}
}

void SeenController::AddScene(Scene name,ISeen *scene) {
	scenes[name] = scene;
}



void SeenController::MainUpdate(float Deltatime) {

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

	if (alpha <= 0.0f){ //フェードイン終了後の処理

		currentSeen->Update(Deltatime);
	}
}

void SeenController::Change(Scene name) {
	Finalize();
	alpha = 1.0f;
	currentSeen = scenes[name];
	currentSeen->LoadAsset();
}

void SeenController::MainRender(float Deltatime) {
	if (!currentSeen->IsEnd()) {
		currentSeen->Draw();
	}
}

void SeenController::Initialize() {
	Finalize();
	scenes.clear();
	render = new Render();
	Tytle = new Seen_Tytle(render);
	AddScene(Scene::Title, Tytle);
	Change(Scene::Title);
}

void SeenController::Finalize() {
}


