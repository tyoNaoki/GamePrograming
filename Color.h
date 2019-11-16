#include"Math.h"
#include<DxLib.h>

class Color {
public:
	Color() {
		r = 0.0f;
		g = 0.0f;
		b = 0.0f;
		a = 1.0f;
	}

	/// <param name="r">��(0.0f ~ 1.0f)</param>
	/// <param name="g">��(0.0f ~ 1.0f)</param>
	/// <param name="b">��(0.0f ~ 1.0f)</param>
	/// <param name="a">�����x(0.0f ~ 1.0f)</param>
	Color(float r, float g, float b, float a)
		: r(Math::Clamp(r, 0.0f, 1.0f))
		, g(Math::Clamp(g, 0.0f, 1.0f))
		, b(Math::Clamp(b, 0.0f, 1.0f))
		, a(Math::Clamp(a, 0.0f, 1.0f)) {
	}

	unsigned int ToCOLOR() const {
		return GetColor((int)(r * 255.0f), (int)(g * 255.0f), (int)(b * 255.0f));
	}

	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Black;
	static const Color White;

public:
	float r, g, b, a;
};
