#pragma once

#include<array>
#include"Vector3.h"
#include"Vector2.h"
class Quaternion;

class Matrix4 {
public:
	Matrix4();
	Matrix4(float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44);
	Matrix4(const Quaternion& q);
	~Matrix4();

	static Matrix4 Scale(float x, float y, float z);
	static Matrix4 Scale(const Vector3& scale);
	Matrix4& SetScale(float x, float y, float z);
	Matrix4& SetScale(const Vector3& scale);
	Vector3 GetScale() const;

	static Matrix4 Translate(float x, float y, float z);
	static Matrix4 Translate(const Vector3& translate);
	Matrix4& SetPosition(float x, float y, float z);
	Matrix4& SetPosition(const Vector3& position);
	Vector3 GetPosition() const;

	static Matrix4 RotateX(float angle);
	static Matrix4 RotateY(float angle);
	static Matrix4 RotateZ(float angle);
	Matrix4& SetRotateX(float angle);
	Matrix4& SetRotateY(float angle);
	Matrix4& SetRotateZ(float angle);

	Quaternion GetRotation() const;
	Matrix4 GetRotationMatrix() const;

	static Matrix4 CreateWorld(const Vector3& scale, const Quaternion& rotate, const Vector3& translate);
	static Matrix4 CreateWorld(const Vector3& scale, const Matrix4& rotate, const Vector3& translate);
	/// <summary> 概要 : 設定された前方向を向く行列を作成</summary>
	/// <param name="position">座標</param>
	/// <param name="forward">前方向</param>
	/// <param name="up">上上方向</param>
	static Matrix4 CreateLookAt(const Vector3& position, const Vector3& forward, const Vector3& up);

	static Matrix4 CreatePerspective(float fov, float aspect, float near_, float far_);
	static Matrix4 CreateView(const Vector3& position, const Vector3& target, const Vector3& up);

	static Matrix4 CreateFromAxisAngle(const Vector3& axis, float angle);
	static Matrix4 CreateFromQuaternion(const Quaternion& rotate);
	static Matrix4 CreateFromYawPitchRoll(float yaw, float pitch, float roll);

	static Vector3 CreateProjection(const Vector3& position, const Matrix4& screen, const Matrix4& perspective, const Matrix4& view, const Matrix4& world = IdentityMatrix);
	static Vector3 CreateUnProjection(const Vector3& position, const Matrix4& screen, const Matrix4& perspective, const Matrix4& view, const Matrix4& world = IdentityMatrix);


	static Matrix4 CreateScreenDirectX(const Vector2& position, float width, float height);
	static Matrix4 CreateScreenOpenGL(const Vector2& position, float width, float height);

	Matrix4 Transpose();
	Matrix4 Lerp(const Matrix4& matrix, float amount);

	//取得
	void Decompose(Vector3& scale, Quaternion& rotation, Vector3& translation) const;

	Matrix4& SetLeft(const Vector3& left);
	Matrix4& SetUp(const Vector3& up);
	Matrix4& SetFront(const Vector3& front);
	Vector3 GetLeft() const;
	Vector3 GetUp() const;
	Vector3 GetFront() const;

	/// <summary> 概要 : 座標変換　</summary>
	/// <param name="vector">座標変換する座標</param>
	/// <returns>この行列によって座標変換された座標</returns>
	Vector3 Transform(const Vector3& vector) const;

	Matrix4& Identity();
	Matrix4 Inverse() const;
	//回転と平行移動のみ
	Matrix4 InverseFast() const;


	Matrix4 GetNormalizeRotationMatrix() const;
	Matrix4& NormalizeRotationMatrix();


public:
	static const Matrix4 IdentityMatrix;

public:
	Matrix4 operator * (const Matrix4& matrix);
	Vector3 operator * (const Vector3& vector);
	Matrix4& operator *= (const Matrix4& matrix);

public:
	Matrix4 Multiply(const Matrix4& a, const Matrix4& b);
	Vector3 Multiply(const Vector3& vector, const Matrix4& matrix);

public:
	using Matrix = std::array<std::array<float, 4>, 4>;
	Matrix m;
};

inline 	Vector3 operator * (const Vector3& vector, const Matrix4& matrix) {
	return Matrix4(matrix).Transform(vector);
}

inline Matrix4 operator * (const Matrix4& m1, const Matrix4& m2) {
	return Matrix4().Multiply(m1, m2);
}
