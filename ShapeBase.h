#pragma once

//�����蔻��̌`��
enum class ShapeType {
	BoundingSphere,
	Capsule,
	Line,

	Max_Num
};

class ShapeBase
{
public:
	ShapeBase();
	~ShapeBase();
};

