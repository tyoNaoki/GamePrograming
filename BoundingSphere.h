#pragma once

#include"Vector3.h"
class Matrix4;
class HitInfo;

#include"ShapeBase.h"

//境界円
class BoundingSphere : public ShapeBase {
public:
	/// <param name="center">中心座標</param>
	/// <param name="radius">半径</param>
	BoundingSphere(const Vector3& center, float radius);
	BoundingSphere(float radius = 0.0f);


	/// <summary> 概要 : 移動　</summary>
	virtual ShapeBase* Translate(const Vector3& position) const override;
	/// <summary> 概要 : 座標変換　</summary>
	virtual ShapeBase* Transform(const Matrix4& matrix) const override;
	/// <summary> 概要 : 形状取得　</summary>
	virtual ShapeType GetShapeType() const override;
	/// <summary> 概要 : 球体とあたり判定　</summary>
	virtual bool Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo) override;
	/// <summary> 概要 : カプセルとあたり判定　</summary>
	virtual bool Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo)override;
	/// <summary> 概要 : 線分とあたり判定　</summary>
	virtual bool Collide_Line(const ShapeBase& shape, HitInfo& hitInfo)override;
	/// <summary> 概要 : 描画　</summary>
	virtual void Draw() const override;
public:
	//中心座標
	Vector3 center;
	//半径
	float radius;
};

