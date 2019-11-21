#include "Convert.h"

#include"Vector2.h"
#include"Vector3.h"
#include"Matrix4.h"

VECTOR Convert::ToVECTOR(const Vector2 & vector)
{
	VECTOR v;
	v.x = vector.x;
	v.y = vector.y;
	v.z = 0.0f;
	return v;
}

VECTOR Convert::ToVECTOR(const Vector3 & vector)
{
	VECTOR v;
	v.x = vector.x;
	v.y = vector.y;
	v.z = vector.z;
	return v;
}

MATRIX Convert::ToMATRIX(const Matrix4 & matrix)
{
	MATRIX m;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m.m[i][j] = matrix.m[i][j];
		}
	}
	return m;
}

Vector2 Convert::ToVector2(const VECTOR & vector)
{
	return Vector2(vector.x, vector.y);
}

Vector3 Convert::ToVector3(const VECTOR & vector)
{
	return Vector3(vector.x, vector.y, vector.z);
}

Matrix4 Convert::ToMatrix4(const MATRIX & matrix)
{
	Matrix4 m;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			m.m[i][j] = matrix.m[i][j];
		}
	}
	return m;
}
