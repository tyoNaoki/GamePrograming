#pragma once
#include<cmath>

class Math {
public:
	/// <summary> �T�v : ��捪�i���[�g�j�����߂�@</summary>
	/// <param name="value">�l</param>
	static float SquareRoot(float value);

	/// <summary> �T�v : �������l�����߂�@</summary>
	/// <param name="value1">�l</param>
	/// <param name="value2">�l</param>
	/// <returns>�ŏ��̒l</returns>
	template<typename T>
	static T Min(T value1, T value2) {
		return (T)std::fminf(value1, value2);
	}

	/// <summary> �T�v : �傫���l�����߂�@</summary>
	/// <param name="value1">�l</param>
	/// <param name="value2">�l</param>
	/// <returns>�ő�̒l</returns>
	template<typename T>
	static T Max(T value1, T value2) {
		return (T)std::fmaxf(value1, value2);
	}

	/// <summary> �T�v : �l��͈͓��Ɏ��߂�@</summary>
	/// <param name="value">�l</param>
	/// <param name="min">�ŏ��l</param>
	/// <param name="max">�ő�l</param>
	/// <returns>�͈͓��̒l</returns>
	template<typename T>
	static T Clamp(T value, T min, T max) {
		return (T)std::fmaxf(min, std::fminf(value, max));
	}

	/// <summary> �T�v : �T�C���@</summary>
	/// <param name="angle">�p�x(�x)</param>
	/// <returns>�T�C���l(-1.0f�`1.0f)</returns>
	static float Sin(float angle);

	/// <summary> �T�v : �R�T�C���@</summary>
	/// <param name="angle">�p�x(�x)</param>
	/// <returns>�R�T�C���l(-1.0f�`1.0f)</returns>
	static float Cos(float angle);

	/// <summary> �T�v : �^���W�F���g�@</summary>
	/// <param name="angle">�p�x(�x)</param>
	/// <returns>�^���W�F���g�l(-1.0f�`1.0f)</returns>
	static float Tan(float angle);

	/// <summary> �T�v : �A�[�N�T�C���@</summary>
	/// <param name="sin">�T�C���l(-1.0f�`1.0f)</param>
	/// <returns>�p�x(�x)</returns>
	static float ArcSin(float sin);

	/// <summary> �T�v : �A�[�N�R�T�C���@</summary>
	/// <param name="cos">�R�T�C���l(-1.0f�`1.0f)</param>
	/// <returns>�p�x(�x)</returns>
	static float ArcCos(float cos);

	/// <summary> �T�v : �A�[�N�^���W�F���g�@</summary>
	/// <param name="tan">�^���W�F���g�l(-1.0f�`1.0f)</param>
	/// <returns>�p�x(�x)</returns>
	static float ArcTan(float y, float x);

	template<typename T = float>
	static T Abs(T value) {
		return (T)abs(value);
	}

	template<typename T = float>
	static T Lerp(T value1, T value2, float amount) {
		return (value1 * (1.0f - amount)) + (value2 * amount);
	}

	template<typename T = float>
	static int Sign(T value) {
		return static_cast<int>((value / Math::Abs<float>(value)));
	}

public:
	/// <summary> �T�v : �~����(��)�@</summary>
	static constexpr float PI = 3.141592f;
	/// <summary> �T�v : �x���@�ɕϊ��@</summary>
	static constexpr float toDegree = 180.0f / PI;
	/// <summary> �T�v : ���W�A���p�ɕϊ��@</summary>
	static constexpr float toRadian = PI / 180.0f;
};


