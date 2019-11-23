#include "Seen_Tytle.h"
#include "Input.h"
#include "Math.h"

static const float speed = 6.0f;
static const float scale = 0.6f;

Seen_Tytle::Seen_Tytle(Render *renderer)
	: isEnd(false),renderer(renderer),Nextpos(0),framePosition(Vector2(270,520 + Nextpos)),barSize(0.0f)
{
}


Seen_Tytle::~Seen_Tytle()
{
	delete renderer;
}

void Seen_Tytle::LoadAsset() {
	renderer->LoadTexture("title", "Data\\2D\\Swordbout_logo.png");
	renderer->LoadTexture("frame", "Data\\2D\\SlidBar.png");
	renderer->LoadTexture("Start", "Data\\2D\\Start.png");
	renderer->LoadTexture("Exit", "Data\\2D\\Exit.png");
}

bool Seen_Tytle::IsEnd()const {
	return isEnd;
}

void Seen_Tytle::Update(float Deltatime) {

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

bool Seen_Tytle::Input() {
	return true;
}

Scene Seen_Tytle::Next() {
	return NextScene;
}

void Seen_Tytle::Draw() {
	//Flame
	renderer->DrawTexture("frame", framePosition, Vector2(0, 0), Vector2(barSize, 0.6f), 0.0f, 0.4f);

	renderer->DrawTexture("title", Vector2(0, 70));

	renderer->DrawTexture("Start", Vector2(512 - 100, 500), Vector2::Zero);
	renderer->DrawTexture("Exit", Vector2(512 - 80, 500 + 100), Vector2::Zero);

	//renderer.DrawTexture("bar", Vector2(0, Screen::Height - 30));
}

void Seen_Tytle::Initialize() {
	isEnd = false;
	Nextpos = 0;
}

void Seen_Tytle::BarSlide() {
	barSize += scale / speed;
	barSize = Math::Clamp<float>(barSize, 0.0f, scale);
}

void Seen_Tytle::Finalize() {
	renderer->Clear();
}
