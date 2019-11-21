#include "SeenController.h"
#include <DxLib.h>
#include "ISeen.h"
#include "Seen_Game.h"
#include <memory>


SeenController::SeenController()
{
}

SeenController::~SeenController()
{
	for (auto itr = scenes.begin(); itr != scenes.end(); itr++) {
		delete itr->second;
	}
}

bool SeenController::AddTask(Scene name,ISeen *scene) {
	scenes[name] = scene;
	return true;
}



void SeenController::MainUpdate(float Deltatime) {
	if (!currentSeen->IsEnd()) {

		currentSeen->Update(Deltatime);
	}
}

void SeenController::Change(Scene name) {
	currentSeen = scenes[name];
}

void SeenController::Initialize() {

}


