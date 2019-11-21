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
}

bool SeenController::AddTask(Scene name,const ISeen *scene) {
	scenes[name] = scene;
}

void SeenController::MainUpdate(float Deltatime) {
	if (!currentSeen->IsEnd()) {
		currentSeen->Update(Deltatime);
	}
}