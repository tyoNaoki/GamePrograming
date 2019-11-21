#include "Seen_Tytle.h"
#include "Input.h"

 
Seen_Tytle::Seen_Tytle(Render *renderer)
	: isEnd(false),renderer(renderer),Nextpos(0),framePosition(Vector2(270,520 + Nextpos))
{
}


Seen_Tytle::~Seen_Tytle()
{
	delete renderer;
}

void Seen_Tytle::LoadAsset() {
	renderer->LoadTexture("title", "Data\\2D\\Swordbout_logo.png");
}

bool Seen_Tytle::IsEnd()const {
	return isEnd;
}

void Seen_Tytle::Update(float Deltatime) {

	if (Input::GetInstance().GetCommand(Command::Dicide)) {
		isEnd = true;
	}

	if (Input::GetInstance().GetCommand(Command::Down)) {
		Nextpos = Nextpos + 100;
	}

	if (Input::GetInstance().GetCommand(Command::Up)) {
		Nextpos = Nextpos + 100;
	}

	if (Nextpos < 0) 
		Nextpos = 100;
	if (Nextpos > 100)
		Nextpos = 0;
}

bool Seen_Tytle::Input() {
	return true;
}

Scene Seen_Tytle::Next() {
	return NextScene;
}

void Seen_Tytle::Draw() {
	//Flame
	//renderer.DrawTexture("frame", framePosition, Vector2(0, 0), Vector2(barSize, 0.6f), 0.0f, 0.4f);

	renderer->DrawTexture("title", Vector2(256, 100));

	//renderer.DrawTexture("Start", Vector2(512 - 100, 500), Vector2::Zero);
	//renderer.DrawTexture("Exit", Vector2(512 - 80, 500 + 100), Vector2::Zero);

	//renderer.DrawTexture("bar", Vector2(0, Screen::Height - 30));
}
