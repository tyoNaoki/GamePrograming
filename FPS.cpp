#include "FPS.h"
#include "DxLib.h"

#define MAX_FPS 60

FPS::FPS()
	: AverageCount(60)
	, Delattime(0.0f)
	, counter(0)
	, StartTime(0)
{
}

FPS::~FPS()
{
}

void FPS::Update()
{
	if (counter == 0) {
		StartTime = GetNowCount();
	}
	if (counter == AverageCount) {
		int t = GetNowCount();
		Delattime = 1000.0f / ((t - StartTime) / static_cast<float>(AverageCount));
		counter = 0; 
		StartTime = t;
	}
	++counter;
}

void FPS::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "SetFPS = %.1f : NowFPS = %.1f : frameTime = %.3f", MAX_FPS, Delattime, Delattime / MAX_FPS);
}

float FPS::GetDeltaTime()
{
	return Delattime / MAX_FPS;
}

float FPS::GetDeltaSecond() {
	return 0;
}

void FPS::Wait()
{
	int tookTime = GetNowCount() - StartTime;	//‚©‚©‚Á‚½ŽžŠÔ
	int waitTime = counter * 1000 / MAX_FPS - tookTime;	//‘Ò‚Â‚×‚«ŽžŠÔ
	if (waitTime > 0) {
		Sleep(waitTime);	//‘Ò‹@
	}
}