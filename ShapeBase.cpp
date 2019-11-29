#include"ShapeBase.h"

#include<cassert>
#include<DxLib.h>

ShapeBase::ShapeBase() {
	RegistFunc();
}

bool ShapeBase::Intersect(const ShapeBase& shape, HitInfo& hitInfo) {
	//—LŒø‚ÈŒ`ó‚©H
	if (shape.GetShapeType() == ShapeType::Max_Num) return false;
	return func[static_cast<int>(shape.GetShapeType())](shape, hitInfo);
}

bool ShapeBase::Collide_BoundingSphere(const ShapeBase& shape, HitInfo& hitInfo) {
	//³í‚ÉŒp³‚³‚ê‚Ä‚¢‚È‚¢B
	assert(!"It does not override this function.");
	return false;
}
bool ShapeBase::Collide_Capsule(const ShapeBase& shape, HitInfo& hitInfo) {
	//³í‚ÉŒp³‚³‚ê‚Ä‚¢‚È‚¢B
	assert(!"It does not override this function.");
	return false;
}
bool ShapeBase::Collide_Line(const ShapeBase& shape, HitInfo& hitInfo) {
	//³í‚ÉŒp³‚³‚ê‚Ä‚¢‚È‚¢B
	assert(!"It does not override this function.");
	return false;
}

void ShapeBase::Draw() const {
	//Œp³æ‚Å•`‰æ
}

void ShapeBase::RegistFunc() {
	//‚±‚±C³
	//‚s‚n‚c‚nF‚ ‚½‚è”»’è‚ğ‚ÂƒAƒNƒ^[‚Ì”•ª‚±‚Ì”z—ñ‚Í—­‚Ü‚Á‚Ä‚¢‚­‰Â”\«‘å
	//‚È‚Ì‚ÅAstatic‚É‚µ‚Äˆê‚Â‚Ì‚İ‚ğ‚Â‚©‚¤‚æ‚¤‚É‚·‚é
	func[0] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_BoundingSphere(shape, hitInfo); };
	func[1] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_Capsule(shape, hitInfo); };
	func[2] = [&](const ShapeBase& shape, HitInfo& hitInfo) { return Collide_Line(shape, hitInfo); };
}
