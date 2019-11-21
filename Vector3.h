#pragma once

class Matrix4;

class Vector3 {
public:
	Vector3(float x, float y, float z);
	Vector3(const Vector3& vector);
	Vector3();
	~Vector3();

	/// <summary> 概要 : 正規化　</summary>
	void Normalize();
	/// <summary> 概要 : 法線ベクトルを取得　</summary>
	Vector3 GetNormal() const;
	/// <summary> 概要 :  長さを取得　</summary>
	float Length()const;
	/// <summary> 概要 : 長さの2倍の値を取得　</summary>
	float SquareLength();
	/// <summary> 概要 : コンソール画面に出力　</summary>
	void Print();


	/// <summary> 概要 : ベクトルを範囲内に収める　</summary>
	/// <param name="min">収める範囲の最小のベクトル</param>
	/// <param name="max">収める範囲の最大のベクトル</param>
	void Clamp(const Vector3& min, const Vector3& max);

	/// <summary> 概要 : ２点間の距離を求める　</summary>
	/// <param name="vec">ベクトル</param>
	/// <returns>２点間の距離</returns>
	float Distance(const Vector3& vec);

	float DistanceSquare(const Vector3& vec);

	/// <summary> 概要 : 2つのベクトルの角度を求める　</summary>
	/// <param name="vector1">ベクトル</param>
	/// <returns>2つのベクトルの角度(度)</returns>
	float Angle(const Vector3& vec);

	/// <summary> 概要 : 内積　</summary>
	/// <param name="vector1">ベクトル</param>
	/// <returns>スカラー</returns>
	float Dot(const Vector3& vec);
	/// <summary> 概要 : 外積　</summary>
	/// <param name="vector1">ベクトル</param>
	/// <param name="vector2">ベクトル</param>
	/// <returns>スカラー</returns>
	Vector3 Cross(const Vector3& vec);

	/// <summary> 概要 : 2つのベクトルの線形補間　</summary>
	/// <param name="lerpTime">値(0.0f～1.0f)</param>
	/// <returns>補間されたベクトル</returns>
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

