#pragma once

//矩形クラス

class Rect {
public:
	Rect() {
		left = 0.0f;
		top = 0.0f;
		right = 1.0f;
		bottom = 1.0f;
	}

	/// <param name="left">左上のx座標</param>
	/// <param name="top">左上のy座標</param>
	/// <param name="right">右下のx座標</param>
	/// <param name="bottom">右下のy座標</param>
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