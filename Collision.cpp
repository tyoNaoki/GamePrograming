#include"Collision.h"

#include"Ray.h"
#include"Line.h"
#include"Capsule.h"
#include"BoundingSphere.h"
#include"HitInfo.h"
#include"Math.h"
#include"Convert.h"

#include<cassert>

bool Collision::BoundingShpere_BoundingSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2, HitInfo& hitInfo) {
	float radius = sphere1.radius + sphere2.radius;
	Vector3 distance = sphere2.center - sphere1.center;

	if (distance.SquareLength() >= radius * radius)
		return false;

	//中央を結んだベクトルの正規化
	Vector3 n = distance.GetNormal();

	hitInfo.intersect = sphere2.center - radius * n;
	return true;
}

bool Collision::BoundingSphere_Line(const BoundingSphere& sphere, const Line& line, HitInfo& hitInfo) {
	Vector3 vec = line.vector;

	Vector3 v1 = sphere.center - line.p1;
	float t = vec.Dot(v1) / vec.Dot(vec);
	if (t < 0 && v1.SquareLength() <= sphere.radius * sphere.radius) {
		hitInfo.intersect = line.p1;
		return true;
	}

	Vector3 v2 = sphere.center - line.p2;
	if (t > 0 && v2.SquareLength() <= sphere.radius * sphere.radius) {
		hitInfo.intersect = line.p2;
		return true;
	}

	Vector3 vn = v1 - t * vec;
	if ((0 < t && t < 1) && (vn.SquareLength() < sphere.radius * sphere.radius)) {
		hitInfo.intersect = line.p1 + t * vec;
		return true;
	}

	return false;
}

bool Collision::BoundingSphere_Capsule(const BoundingSphere& sphere, const Capsule& capsule, HitInfo& hitInfo) {
	BoundingSphere s = { sphere.center, sphere.radius + capsule.radius };
	Line l = { capsule.p1, capsule.p2 };
	return BoundingSphere_Line(s, l, hitInfo);
}

bool Collision::Capsule_Capsule(const Capsule& capsule1, const Capsule& capsule2, HitInfo& hitInfo) {
	Vector3 a = capsule1.vector;
	Vector3 b = capsule2.vector;
	Vector3 c = capsule2.p1 - capsule1.p1;

	float distance = capsule1.radius + capsule2.radius;

	Vector3 n = a.Cross(b).GetNormal();
	float L = c.Dot(n);

	Vector3 n1 = a.Cross(n).GetNormal();
	Vector3 n2 = b.Cross(n).GetNormal();

	Vector3 p3Dash = capsule2.p1 - n * L;
	Vector3 p4Dash = capsule2.p2 - n * L;

	Vector3 v1 = capsule1.p1 - p3Dash;
	Vector3 v2 = capsule1.p2 - p3Dash;
	Vector3 v3 = p3Dash - capsule1.p1;
	Vector3 v4 = p4Dash - capsule1.p1;

	float L1 = v1.Dot(n2);
	float L2 = v2.Dot(n2);
	float L3 = v3.Dot(n1);
	float L4 = v4.Dot(n1);

	float t1 = L3 / (L3 - L4);
	float t2 = L1 / (L1 - L2);

	if ((Math::Abs(L) < distance) && (0 < t1 && t1 < 1) && (0 < t2 && t2 < 1)) {
		return true;
	}

	BoundingSphere s = BoundingSphere(capsule1.p1, capsule1.radius);
	if ((t1 < 0) && BoundingSphere_Capsule(s, capsule2, hitInfo)) {
		return true;
	}

	s = BoundingSphere(capsule2.p1, capsule2.radius);
	if ((t1 > 1) && BoundingSphere_Capsule(s, capsule1, hitInfo)) {
		return true;
	}

	s = BoundingSphere(capsule2.p1, capsule2.radius);
	if ((t2 < 0) && BoundingSphere_Capsule(s, capsule1, hitInfo)) {
		return true;
	}

	s = BoundingSphere(capsule2.p2, capsule2.radius);
	if ((t2 > 1) && BoundingSphere_Capsule(s, capsule1, hitInfo)) {
		return true;
	}

	return false;
}

bool Collision::Capsule_Line(const Capsule& capsule, const Line& line, HitInfo& hitInfo) {
	assert(!"ごめん、実装してない。");
	return false;
}

bool Collision::Octree_Line(int modelID, const Line& line, HitInfo& hitInfo) {
	MV1_COLL_RESULT_POLY mv1HitInfo;
	mv1HitInfo = MV1CollCheck_Line(modelID, -1, Convert::ToVECTOR(line.p1), Convert::ToVECTOR(line.p2));

	if (mv1HitInfo.HitFlag != 1) {
		return false;
	}
	VECTOR pos = mv1HitInfo.HitPosition;
	hitInfo.intersect = Vector3(pos.x, pos.y, pos.z);
	VECTOR normal = mv1HitInfo.Normal;
	hitInfo.normal = Vector3(normal.x, normal.y, normal.z);

	return true;
}

bool Collision::Octree_BoundingSphere(int modelID, const BoundingSphere& sphere, HitInfo& hitInfo) {
	MV1_COLL_RESULT_POLY_DIM mv1HitInfo;
	mv1HitInfo = MV1CollCheck_Sphere(modelID, -1, Convert::ToVECTOR(sphere.center), sphere.radius);

	if (mv1HitInfo.HitNum < 1) {
		return false;
	}

	int hitNum = mv1HitInfo.HitNum;

	Vector3 pos;
	Vector3 normal;
	for (int i = 0; i < hitNum; ++i) {
		VECTOR p = mv1HitInfo.Dim[i].HitPosition;
		pos += Vector3(p.x, p.y, p.z);
		VECTOR n = mv1HitInfo.Dim[i].Normal;
		normal += Vector3(n.x, n.y, n.z);
	}
	pos /= hitNum;
	normal /= hitNum;
	hitInfo.intersect = pos;
	hitInfo.normal = normal.GetNormal();

	MV1CollResultPolyDimTerminate(mv1HitInfo);

	return true;

}

bool Collision::Octree_Capsule(int modelID, const Capsule& capsule, HitInfo& hitInfo) {
	MV1_COLL_RESULT_POLY_DIM mv1HitInfo;
	mv1HitInfo = MV1CollCheck_Capsule(modelID, -1, Convert::ToVECTOR(capsule.p1), Convert::ToVECTOR(capsule.p2), capsule.radius);

	if (mv1HitInfo.HitNum < 1) {
		return false;
	}

	int hitNum = mv1HitInfo.HitNum;

	Vector3 pos;
	Vector3 normal;
	for (int i = 0; i < hitNum; ++i) {
		VECTOR p = mv1HitInfo.Dim[i].HitPosition;
		pos += Vector3(p.x, p.y, p.z);
		VECTOR n = mv1HitInfo.Dim[i].Normal;
		normal += Vector3(n.x, n.y, n.z);
	}
	pos /= hitNum;
	normal /= hitNum;
	hitInfo.intersect = pos;
	hitInfo.normal = normal.GetNormal();

	MV1CollResultPolyDimTerminate(mv1HitInfo);

	return true;
}
