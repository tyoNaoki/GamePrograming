#pragma once

//�t���[���Ǘ��N���X
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
	//���ϒl
	const int AverageCount;

	float Delattime;

	float DeltaSecond;

	int counter;

	int StartTime;
};

