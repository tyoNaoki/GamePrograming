#pragma once

class Vector3;
class Matrix4;

class Quaternion {
public:

	Quaternion(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 1.0f);
	Quaternion(const Vector3& axis, float angle);
	Quaternion(const Matrix4& m);
	~Quaternion();

	Quaternion& Normalize();
	Quaternion GetNormal();
	float Dot(const Quaternion& q);
	float Length();
	Quaternion Slerp(const Quaternion& q, float amount);

	Matrix4 ToRotateMatrix();
	Quaternion CreateFromRotationMatrix(const Matrix4& m);

public:
	Quaternion operator - ();

	Quaternion& operator += (const Quaternion& q);
	Quaternion& operator -= (const Quaternion& q);
	Quaternion& operator *= (float scalar);
	Quaternion& operator *= (const Quaternion& q);
	Quaternion& operator /= (float scalar);

	Quaternion operator + (const Quaternion& q);
	Quaternion operator - (const Quaternion& q);
	Quaternion operator * (const Quaternion& q);
	Quaternion operator * (float scalar);
	Quaternion operator / (float scalar);

private:
	Quaternion Mul(const Quaternion& q1, const Quaternion& q2);

public:
	float x;
	float y;
	float z;
	float w;
};

inline Quaternion operator * (float scalar, const Quaternion& q) {
	return Quaternion(q.x * scalar, q.y * scalar, q.z * scalar, q.w * scalar);
}

