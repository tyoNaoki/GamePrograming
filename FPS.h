#pragma once

//�t���[���Ǘ��N���X
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
	//�ő�t���[��
	const float fps;
	//���ϒl
	const int AverageCount;

	float Delattime;

	float DeltaSecond;

	int counter;

	int StartTime;
};

