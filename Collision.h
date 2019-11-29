#pragma once

class Ray;
class Line;
class Capsule;
class BoundingSphere;
class HitInfo;

/// <summary> �T�v : �����蔻��N���X�@</summary>
class Collision {
public:
	//���̂����蔻��
	static bool BoundingShpere_BoundingSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2);
	static bool BoundingShpere_BoundingSphere(const BoundingSphere& sphere1, const BoundingSphere& sphere2, HitInfo& hitInfo);
	static bool BoundingSphere_Line(const BoundingSphere& sphere, const Line& line, HitInfo& hitInfo);
	static bool BoundingSphere_Capsule(const BoundingSphere& sphere, const Capsule& capsule, HitInfo& hitInfo);

	//�J�v�Z���̂����蔻��
	static bool Capsule_Capsule(const Capsule& capsule1, const Capsule& capsule2, HitInfo& hitInfo);
	static bool Capsule_Line(const Capsule& capsule, const Line& line, HitInfo& hitInfo);



	//�n�`�f�[�^(�I�N�c���[)�̂����蔻��
	static bool Octree_Line(int modelID, const Line& line, HitInfo& hitInfo);
	static bool Octree_BoundingSphere(int modelID, const BoundingSphere& sphere, HitInfo& hitInfo);
	static bool Octree_Capsule(int modelID, const Capsule& capsule, HitInfo& hitInfo);
};
