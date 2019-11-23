#pragma once

//フレーム管理クラス
class FPS
{
public:

	FPS(float fps = 60);
	~FPS();

	void Update();
	void Draw();

	float GetDeltaTime();

	float GetDeltaSecond();

	void Wait();

private:
	//最大フレーム
	const float fps;
	//平均値
	const int AverageCount;

	float Delattime;

	float DeltaSecond;

	int counter;

	int StartTime;
};

