#pragma once

#include"Math.h"
#include<DxLib.h>

class _Color {
public:
	_Color() {
		r = 0.0f;
		g = 0.0f;
		b = 0.0f;
		a = 1.0f;
	}

	/// <param name="r">ê‘(0.0f ~ 1.0f)</param>
	/// <param name="g">óŒ(0.0f ~ 1.0f)</param>
	/// <param name="b">ê¬(0.0f ~ 1.0f)</param>
	/// <param name="a">ìßñæìx(0.0f ~ 1.0f)</param>
	_Color(float r, float g, float b, float a)
		: r(Math::Clamp(r, 0.0f, 1.0f))
		, g(Math::Clamp(g, 0.0f, 1.0f))
		, b(Math::Clamp(b, 0.0f, 1.0f))
		, a(Math::Clamp(a, 0.0f, 1.0f)) {
	}

	unsigned int ToCOLOR() const {
		return GetColor((int)(r * 255.0f), (int)(g * 255.0f), (int)(b * 255.0f));
	}

	static const _Color Red;
	static const _Color Green;
	static const _Color Blue;
	static const _Color Yellow;
	static const _Color Black;
	static const _Color White;

public:
	float r, g, b, a;
};
