#include"ShapeBase.h"

#include<cassert>
#include<DxLib.h>

ShapeBase::ShapeBase() {
	RegistFunc();
}

bool ShapeBase::Intersect(const ShapeBase& shape, HitInfo& hitInfo) {
	//�L���Ȍ`�󂩁H
	if (shape.GetShapeType() == ShapeType::Max_Num) return false;
	return func[static_cast<int>(shape.GetShapeType())](shape, hitInfo);
}

bool ShapeBase::Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo) {
	//����Ɍp������Ă��Ȃ��B
	assert(!"It does not override this function.");
	return false;
}
bool ShapeBase::Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo) {
	//����Ɍp������Ă��Ȃ��B
	assert(!"It does not override this function.");
	return false;
}
bool ShapeBase::Collide_Line(const ShapeBase& shape, HitInfo& hitInfo) {
	//����Ɍp������Ă��Ȃ��B
	assert(!"It does not override this function.");
	return false;
}

void ShapeBase::Draw() const {
	//�p����ŕ`��
}

void ShapeBase::RegistFunc() {
	//�����C��
	//�s�n�c�n�F�����蔻������A�N�^�[�̐������̔z��͗��܂��Ă����\����
	//�Ȃ̂ŁAstatic�ɂ��Ĉ�݂̂������悤�ɂ���
	func[0] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_BoundingSphere(shape, hitInfo); };
	func[1] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_Capsule(shape, hitInfo); };
	func[2] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_Line(shape, hitInfo); };
}
