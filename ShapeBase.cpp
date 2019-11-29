#include"ShapeBase.h"

#include<cassert>
#include<DxLib.h>

ShapeBase::ShapeBase() {
	RegistFunc();
}

bool ShapeBase::Intersect(const ShapeBase& shape, HitInfo& hitInfo) {
	//有効な形状か？
	if (shape.GetShapeType() == ShapeType::Max_Num) return false;
	return func[static_cast<int>(shape.GetShapeType())](shape, hitInfo);
}

bool ShapeBase::Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo) {
	//正常に継承されていない。
	assert(!"It does not override this function.");
	return false;
}
bool ShapeBase::Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo) {
	//正常に継承されていない。
	assert(!"It does not override this function.");
	return false;
}
bool ShapeBase::Collide_Line(const ShapeBase& shape, HitInfo& hitInfo) {
	//正常に継承されていない。
	assert(!"It does not override this function.");
	return false;
}

void ShapeBase::Draw() const {
	//継承先で描画
}

void ShapeBase::RegistFunc() {
	//ここ修正
	//ＴＯＤＯ：あたり判定を持つアクターの数分この配列は溜まっていく可能性大
	//なので、staticにして一つのみをつかうようにする
	func[0] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_BoundingSphere(shape, hitInfo); };
	func[1] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_Capsule(shape, hitInfo); };
	func[2] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_Line(shape, hitInfo); };
}
