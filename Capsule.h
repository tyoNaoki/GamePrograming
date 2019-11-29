#pragma once

#include"Vector3.h"
#include"Matrix4.h"
#include"ShapeBase.h"

/// <summary> �T�v : �J�v�Z���@</summary>
class Capsule : public ShapeBase {
public:
	/// <param name="p1">�n�_</param>
	/// <param name="p2">�I�_</param>
	/// <param name="radius">���a</param>
	Capsule(const Vector3& p1, const Vector3& p2, float radius);
	~Capsule();
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
	//�n�_
	Vector3 p1;
	//�I�_
	Vector3 p2;
	//�n�_�ƏI�_�����ԕ����x�N�g��
	Vector3 vector;
	//���a
	float radius;
};