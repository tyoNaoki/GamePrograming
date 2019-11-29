#pragma once

#include<array>
#include<functional>

class Vector3;
class Matrix4;
class HitInfo;

#include "Shapetype.h"

/// <summary> 概要 : あたり判定の基礎クラス　</summary>
class ShapeBase {
public:
	ShapeBase();
	virtual ~ShapeBase() {}
	/// <summary> 概要 : あたり判定　</summary>
	/// <param name="shape">あたり判定する形状</param>
	/// <param name="hitInfo">衝突情報</param>
	bool Intersect(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary> 概要 : 移動　</summary>
	virtual ShapeBase* Translate(const Vector3& position) const = 0;
	/// <summary> 概要 : 座標変換　</summary>
	virtual ShapeBase* Transform(const Matrix4& matrix) const = 0;

	/// <summary> 概要 : 形状取得　</summary>
	virtual ShapeType GetShapeType() const { return ShapeType::Max_Num; }
	/// <summary> 概要 : 球体とあたり判定　</summary>
	virtual bool Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary> 概要 : カプセルとあたり判定　</summary>
	virtual bool Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary> 概要 : 線分とあたり判定　</summary>
	virtual bool Collide_Line(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary> 概要 : 描画　</summary>
	virtual void Draw() const;

private:
	/// <summary> 概要 : 関数登録　</summary>
	void RegistFunc();
private:
	//あたり判定する関数を入れる配列
	using CollisionFunc = std::array < std::function<bool(const ShapeBase&, HitInfo& hitInfo)>, static_cast<int>(ShapeType::Max_Num)>;
	CollisionFunc func;
};
