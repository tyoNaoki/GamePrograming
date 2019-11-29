#pragma once

#include"Vector3.h"
#include"Matrix4.h"
#include"ShapeBase.h"

/// <summary> 概要 : カプセル　</summary>
class Capsule : public ShapeBase {
public:
	/// <param name="p1">始点</param>
	/// <param name="p2">終点</param>
	/// <param name="radius">半径</param>
	Capsule(const Vector3& p1, const Vector3& p2, float radius);
	~Capsule();
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
	//始点
	Vector3 p1;
	//終点
	Vector3 p2;
	//始点と終点を結ぶ方向ベクトル
	Vector3 vector;
	//半径
	float radius;
};