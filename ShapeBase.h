#pragma once

#include<array>
#include<functional>

class Vector3;
class Matrix4;
class HitInfo;

#include "Shapetype.h"

/// <summary> �T�v : �����蔻��̊�b�N���X�@</summary>
class ShapeBase {
public:
	ShapeBase();
	virtual ~ShapeBase() {}
	/// <summary> �T�v : �����蔻��@</summary>
	/// <param name="shape">�����蔻�肷��`��</param>
	/// <param name="hitInfo">�Փˏ��</param>
	bool Intersect(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary> �T�v : �ړ��@</summary>
	virtual ShapeBase* Translate(const Vector3& position) const = 0;
	/// <summary> �T�v : ���W�ϊ��@</summary>
	virtual ShapeBase* Transform(const Matrix4& matrix) const = 0;

	/// <summary> �T�v : �`��擾�@</summary>
	virtual ShapeType GetShapeType() const { return ShapeType::Max_Num; }
	/// <summary> �T�v : ���̂Ƃ����蔻��@</summary>
	virtual bool Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary> �T�v : �J�v�Z���Ƃ����蔻��@</summary>
	virtual bool Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary> �T�v : �����Ƃ����蔻��@</summary>
	virtual bool Collide_Line(const ShapeBase& shape, HitInfo& hitInfo);
	/// <summary> �T�v : �`��@</summary>
	virtual void Draw() const;

private:
	/// <summary> �T�v : �֐��o�^�@</summary>
	void RegistFunc();
private:
	//�����蔻�肷��֐�������z��
	using CollisionFunc = std::array < std::function<bool(const ShapeBase&, HitInfo& hitInfo)>, static_cast<int>(ShapeType::Max_Num)>;
	CollisionFunc func;
};
