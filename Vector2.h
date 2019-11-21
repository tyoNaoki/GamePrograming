#pragma once
/************************************************************
* File Name	: Vector2.h
* Description	: �񎟌��x�N�g���N���X
*																Date		:	2015-10-22.
*															  Author	:	���]
*************************************************************/
#pragma once

class Vector2 {
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& vector);
	~Vector2();

	/// <summary> �T�v : �x�N�g���̒������擾�@</summary>
	/// <returns>�x�N�g���̒���</returns>
	float Length() const;

	/// <summary> �T�v : �x�N�g����2��̒������擾�@</summary>
	/// <returns>�x�N�g����2��̒���</returns>
	float SquareLength() const;

	/// <summary> �T�v : �x�N�g���𐳋K��(�����P��)����@</summary>
	void Normalize();

	/// <summary> �T�v : ���K��(�����P��)�����x�N�g�����擾�@</summary>
	/// <returns>���K�����ꂽ�x�N�g��</returns>
	Vector2 GetNormal() const;

	/// <summary> �T�v : X��Y�̗v�f���R���\�[����ʂɕ\���@</summary>
	void Print() const;

public:
	/// <summary> �T�v : ���ρ@</summary>
	float Dot(const Vector2& vector);

	/// <summary> �T�v : �O�ρ@</summary>
	float Cross(const Vector2& vector);

	/// <summary> �T�v : �Q�_�Ԃ̋��������߂�@</summary>
	float Distance(const Vector2& vector);

	/// <summary> �T�v : �x�N�g����͈͓��Ɏ��߂�@</summary>
	void Clamp(const Vector2& min, const Vector2& max);

	/// <summary> �T�v : 2�̃x�N�g���̊p�x�����߂�@</summary>
	float Angle(const Vector2& vector);

	/// <summary> �T�v : 2�̃x�N�g���̐��`��ԁ@</summary>
	Vector2 Lerp(const Vector2& vector, float lerpTime);

	/// <summary> �T�v : ���_�𒆐S�ɉ�]����x�N�g�������߂�@</summary>
	Vector2 Rotate(float angle);

public:
	//X�v�f
	float x;
	//Y�v�f
	float y;

	/// <summary> �T�v : �I�[�o�[���C�h��` </summary>
public:
	Vector2 operator + ();
	Vector2 operator - ();
	Vector2 operator + (const Vector2& vector) const;
	Vector2 operator - (const Vector2& vector) const;
	Vector2 operator * (float scalar) const;
	Vector2 operator / (float scalar) const;
	Vector2& operator += (const Vector2& vector);
	Vector2& operator -= (const Vector2& vector);
	Vector2& operator *= (float scalar);
	Vector2& operator /= (float scalar);

public:
	static const Vector2 Up;			// Vector2( 0,  1)
	static const Vector2 Down;			// Vector2( 0, -1)
	static const Vector2 Left;			// Vector2(-1,  0)
	static const Vector2 Right;			// Vector2( 1,  0)
	static const Vector2 UnitX;			// Vector2( 1,  0)
	static const Vector2 UnitY;			// Vector2( 0,  1)
	static const Vector2 One;			// Vector2( 1,  1)
	static const Vector2 Zero;			// Vector2( 0,  0)
};


