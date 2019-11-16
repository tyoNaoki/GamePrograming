#pragma once

class Matrix4;

class Vector3 {
public:
	Vector3(float x, float y, float z);
	Vector3(const Vector3& vector);
	Vector3();
	~Vector3();

	/// <summary> �T�v : ���K���@</summary>
	void Normalize();
	/// <summary> �T�v : �@���x�N�g�����擾�@</summary>
	Vector3 GetNormal() const;
	/// <summary> �T�v :  �������擾�@</summary>
	float Length()const;
	/// <summary> �T�v : ������2�{�̒l���擾�@</summary>
	float SquareLength();
	/// <summary> �T�v : �R���\�[����ʂɏo�́@</summary>
	void Print();


	/// <summary> �T�v : �x�N�g����͈͓��Ɏ��߂�@</summary>
	/// <param name="min">���߂�͈͂̍ŏ��̃x�N�g��</param>
	/// <param name="max">���߂�͈͂̍ő�̃x�N�g��</param>
	void Clamp(const Vector3& min, const Vector3& max);

	/// <summary> �T�v : �Q�_�Ԃ̋��������߂�@</summary>
	/// <param name="vec">�x�N�g��</param>
	/// <returns>�Q�_�Ԃ̋���</returns>
	float Distance(const Vector3& vec);

	float DistanceSquare(const Vector3& vec);

	/// <summary> �T�v : 2�̃x�N�g���̊p�x�����߂�@</summary>
	/// <param name="vector1">�x�N�g��</param>
	/// <returns>2�̃x�N�g���̊p�x(�x)</returns>
	float Angle(const Vector3& vec);

	/// <summary> �T�v : ���ρ@</summary>
	/// <param name="vector1">�x�N�g��</param>
	/// <returns>�X�J���[</returns>
	float Dot(const Vector3& vec);
	/// <summary> �T�v : �O�ρ@</summary>
	/// <param name="vector1">�x�N�g��</param>
	/// <param name="vector2">�x�N�g��</param>
	/// <returns>�X�J���[</returns>
	Vector3 Cross(const Vector3& vec);

	/// <summary> �T�v : 2�̃x�N�g���̐��`��ԁ@</summary>
	/// <param name="lerpTime">�l(0.0f�`1.0f)</param>
	/// <returns>��Ԃ��ꂽ�x�N�g��</returns>
	Vector3 Lerp(const Vector3& vec, float lerpTime) const;



	Vector3 Transform(const Matrix4& matrix);
	Vector3 TransformNormal(const Matrix4& matrix);
	Vector3 CreateFromYawPitch(float yaw, float pitch);

	float Pitch();
	float Yaw();

public:
	float x;
	float y;
	float z;

public:
	Vector3 operator + ();
	Vector3 operator - ();
	Vector3 operator + (const Vector3& vector) const;
	Vector3 operator - (const Vector3& vector) const;
	Vector3 operator * (float scalar) const;
	Vector3 operator / (float scalar) const;
	Vector3& operator += (const Vector3& vector);
	Vector3& operator -= (const Vector3& vector);
	Vector3& operator *= (float scalar);
	Vector3& operator /= (float scalar);

public:
	static const Vector3 Up;			// Vector3( 0,  1,  0)
	static const Vector3 Down;			// Vector3( 0, -1,  0)
	static const Vector3 Left;			// Vector3(-1,  0,  0)
	static const Vector3 Right;			// Vector3( 1,  0,  0)
	static const Vector3 Backward;		// Vector3( 0,  0, -1)
	static const Vector3 Forward;		// Vector3( 0,  0,  1)
	static const Vector3 UnitX;			// Vector3( 1,  0,  0)
	static const Vector3 UnitY;			// Vector3( 0,  1,  0)
	static const Vector3 UnitZ;			// Vector3( 0,  1,  1)
	static const Vector3 One;			// Vector3( 1,  1,  1)
	static const Vector3 Zero;			// Vector3( 0,  0,  0)
};

inline Vector3 operator*(float scalar, const Vector3 & vector)
{
	return Vector3(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

