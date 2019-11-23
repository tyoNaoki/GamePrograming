#include "FPS.h"
#include "DxLib.h"

FPS::FPS(float fps)
	: fps(60)
	, AverageCount(60)
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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "SetFPS = %.1f : NowFPS = %.1f : frameTime = %.3f", fps, Delattime, Delattime / fps);
}

float FPS::GetDeltaTime()
{
	return Delattime / fps;
}

float FPS::GetDeltaSecond() {
	return 0;
}

void FPS::Wait()
{
	int tookTime = GetNowCount() - StartTime;	//‚©‚©‚Á‚½ŽžŠÔ
	int waitTime = counter * 1000 / fps - tookTime;	//‘Ò‚Â‚×‚«ŽžŠÔ
	if (waitTime > 0) {
		Sleep(waitTime);	//‘Ò‹@
	}
}