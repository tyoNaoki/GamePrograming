#include "Math.h"



float Math::SquareRoot(float value) {
	return static_cast<float>(std::sqrt(value));
}

float Math::Sin(float angle)
{
	return std::sinf(angle * toRadian);
}

float Math::Cos(float angle)
{
	return std::cosf(angle * toRadian);
}

float Math::Tan(float angle)
{
	return std::tanf(angle * toRadian);
}

float Math::ArcSin(float sin)
{
	return std::asinf(sin) * toDegree;
}

float Math::ArcCos(float cos)
{
	return std::acosf(cos) * toDegree;
}

float Math::ArcTan(float y, float x)
{
	return std::atan2f(y, x) * toDegree;
}
