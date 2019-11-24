#include "Scene_Tytle.h"
#include "Input.h"
#include "Math.h"

static const float speed = 6.0f;
static const float scale = 0.6f;

Scene_Tytle::Scene_Tytle(Render *renderer)
	: isEnd(false),renderer(renderer),Nextpos(0),framePosition(Vector2(270,520 + Nextpos)),barSize(0.0f)
{
}


Scene_Tytle::~Scene_Tytle()
{
	delete renderer;
}

void Scene_Tytle::LoadAsset() {
	renderer->LoadTexture("title", "Data\\2D\\Swordbout_logo.png");
	renderer->LoadTexture("frame", "Data\\2D\\SlidBar.png");
	renderer->LoadTexture("Start", "Data\\2D\\Start.png");
	renderer->LoadTexture("Exit", "Data\\2D\\Exit.png");
}

bool Scene_Tytle::IsEnd()const {
	return isEnd;
}

void Scene_Tytle::Update(float Deltatime) {

	BarSlide();

	if (Input::GetInstance().GetCommand(Command::Dicide)) {
		isEnd = true;
	}

	if (Input::GetInstance().GetCommand(Command::Down)) {
		Nextpos -= 100;
		barSize = 0.0f;
	}

	if (Input::GetInstance().GetCommand(Command::Up)) {
		Nextpos += 100;
		barSize = 0.0f;
	}

	if (Nextpos < 0) 
		Nextpos = 100;
	if (Nextpos > 100)
		Nextpos = 0;

	if (Input::GetInstance().GetCommand(Command::Dicide)&&Nextpos == 100) {
		System_ExitGame();
	}

	framePosition = Vector2(350, 520 + Nextpos);
}


Scene Scene_Tytle::Next() {
	return Scene::Battle;
}

void Scene_Tytle::Draw() {
	//Flame
	renderer->DrawTexture("frame", framePosition, Vector2(0, 0), Vector2(barSize, 0.6f), 0.0f, 0.4f);

	renderer->DrawTexture("title", Vector2(0, 70));

	renderer->DrawTexture("Start", Vector2(512 - 100, 500), Vector2::Zero);
	renderer->DrawTexture("Exit", Vector2(512 - 80, 500 + 100), Vector2::Zero);
}

void Scene_Tytle::Initialize() {
	isEnd = false;
	Nextpos = 0;
	renderer->LoadTexture("fade", "Data\\2D\\fade.png");
}

void Scene_Tytle::BarSlide() {
	barSize += scale / speed;
	barSize = Math::Clamp<float>(barSize, 0.0f, scale);
}

void Scene_Tytle::Finalize() {
}
