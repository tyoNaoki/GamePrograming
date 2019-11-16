#include "Seen_Tytle.h"
#include "Input.h"


Seen_Tytle::Seen_Tytle()
{
}


Seen_Tytle::~Seen_Tytle()
{
}

void Seen_Tytle::Update(float Deltatime) {

	if (Input::GetInstance().GetCommand(Command::Dicide)) {
		isEnd = true;
	}

	if (Input::GetInstance().GetCommand(Command::Down)) {
		Next = Next + 100;
	}
	if (Input::GetInstance().GetCommand(Command::Up)) {
		Next = Next + 100;
	}

	if (Next < 0) 
		Next = 100;
	if (Next > 100)
		Next = 0;
}

bool Seen_Tytle::Input() {
	return true;
}

void Seen_Tytle::Draw() {
	//Flame
	//renderer.DrawTexture("frame", framePosition, Vector2(0, 0), Vector2(barSize, 0.6f), 0.0f, 0.4f);

	renderer.DrawTexture("title", Vector2(256, 100));

	//renderer.DrawTexture("Start", Vector2(512 - 100, 500), Vector2::Zero);
	//renderer.DrawTexture("Exit", Vector2(512 - 80, 500 + 100), Vector2::Zero);

	//renderer.DrawTexture("bar", Vector2(0, Screen::Height - 30));
}
