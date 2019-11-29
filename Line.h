#pragma once

#include"Vector3.h"
#include"Color.h"
class Matrix4;
class BoundingSphere;
class HitInfo;
#include"ShapeBase.h"

/// <summary> �T�v : �����@</summary>
class Line {
public:
	/// <param name="p1">�n�_</param>
	/// <param name="p2">�I�_</param>
	Line(const Vector3& p1, const Vector3& p2);
	~Line();

	Line Translate(const Vector3& position);
	Line Transform(const Matrix4& matrix);
	bool Intersects(const BoundingSphere& other, HitInfo& hitInfo);
	void Draw(const _Color& color = _Color::White);
public:
	//�n�_
	Vector3 p1;
	//�I�_
	Vector3 p2;
	//�n�_�ƏI�_�����ԕ����x�N�g��
	Vector3 vector;
};
