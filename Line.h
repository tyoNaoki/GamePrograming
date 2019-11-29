#pragma once

#include"Vector3.h"
#include"Color.h"
class Matrix4;
class BoundingSphere;
class HitInfo;
#include"ShapeBase.h"

/// <summary> 概要 : 線分　</summary>
class Line {
public:
	/// <param name="p1">始点</param>
	/// <param name="p2">終点</param>
	Line(const Vector3& p1, const Vector3& p2);
	~Line();

	Line Translate(const Vector3& position);
	Line Transform(const Matrix4& matrix);
	bool Intersects(const BoundingSphere& other, HitInfo& hitInfo);
	void Draw(const _Color& color = _Color::White);
public:
	//始点
	Vector3 p1;
	//終点
	Vector3 p2;
	//始点と終点を結ぶ方向ベクトル
	Vector3 vector;
};
