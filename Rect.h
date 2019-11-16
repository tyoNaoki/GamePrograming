#pragma once

//��`�N���X

class Rect {
public:
	Rect() {
		left = 0.0f;
		top = 0.0f;
		right = 1.0f;
		bottom = 1.0f;
	}

	/// <param name="left">�����x���W</param>
	/// <param name="top">�����y���W</param>
	/// <param name="right">�E����x���W</param>
	/// <param name="bottom">�E����y���W</param>
	Rect(float left, float top, float right, float bottom)
		: left(left)
		, top(top)
		, right(right)
		, bottom(bottom) {
	}

public:
	float left;
	float top;
	float right;
	float bottom;
};