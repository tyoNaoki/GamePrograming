#pragma once

//フレーム管理クラス
class FPS
{
public:

	FPS();
	~FPS();

	void Update();
	void Draw();

	float GetDeltaTime();

	float GetDeltaSecond();

	void Wait();

private:
	//平均値
	const int AverageCount;

	float Delattime;

	float DeltaSecond;

	int counter;

	int StartTime;
};

