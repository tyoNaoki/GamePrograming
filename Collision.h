#pragma once

class Ray;
class Line;
class Capsule;
class BoundingSphere;
class HitInfo;

/// <summary> 概要 : あたり判定クラス　</summary>
class Collision {
public:
	//球のあたり判定
	static bool BoundingShpere_BoundingSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2);
	static bool BoundingShpere_BoundingSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2, HitInfo& hitInfo);
	static bool BoundingSphere_Line(const BoundingSphere& sphere, const Line& line, HitInfo& hitInfo);
	static bool BoundingSphere_Capsule(const BoundingSphere& sphere, const Capsule& capsule, HitInfo& hitInfo);

	//カプセルのあたり判定
	static bool Capsule_Capsule(const Capsule& capsule1, const Capsule& capsule2, HitInfo& hitInfo);
	static bool Capsule_Line(const Capsule& capsule, const Line& line, HitInfo& hitInfo);



	//地形データ(オクツリー)のあたり判定
	static bool Octree_Line(int modelID, const Line& line, HitInfo& hitInfo);
	static bool Octree_BoundingSphere(int modelID, const BoundingSphere& sphere, HitInfo& hitInfo);
	static bool Octree_Capsule(int modelID, const Capsule& capsule, HitInfo& hitInfo);
};
