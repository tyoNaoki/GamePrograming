#pragma once

#include"Vector3.h"
class Matrix4;
class HitInfo;

#include"ShapeBase.h"

//���E�~
class BoundingSphere : public ShapeBase {
public:
	/// <param name="center">���S���W</param>
	/// <param name="radius">���a</param>
	BoundingSphere(const Vector3& center, float radius);
	BoundingSphere(float radius = 0.0f);


	/// <summary> �T�v : �ړ��@</summary>
	virtual ShapeBase* Translate(const Vector3& position) const override;
	/// <summary> �T�v : ���W�ϊ��@</summary>
	virtual ShapeBase* Transform(const Matrix4& matrix) const override;
	/// <summary> �T�v : �`��擾�@</summary>
	virtual ShapeType GetShapeType() const override;
	/// <summary> �T�v : ���̂Ƃ����蔻��@</summary>
	virtual bool Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo) override;
	/// <summary> �T�v : �J�v�Z���Ƃ����蔻��@</summary>
	virtual bool Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo)override;
	/// <summary> �T�v : �����Ƃ����蔻��@</summary>
	virtual bool Collide_Line(const ShapeBase& shape, HitInfo& hitInfo)override;
	/// <summary> �T�v : �`��@</summary>
	virtual void Draw() const override;
public:
	//���S���W
	Vector3 center;
	//���a
	float radius;
};

