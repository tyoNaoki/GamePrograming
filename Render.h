#pragma once

#include<string>
#include"Matrix4.h"
#include<unordered_map>
#include"Vector2.h"
#include"Rect.h"
#include"Color.h"


struct ModelInfo {
	//�`�悷�郂�f����ID
	int modelID;
	//�A�j���[�V����ID
	int animeID;
	//�O��̃A�j���[�V����ID
	int previousAnimeID;

	//���Đ����Ă���A�j���[�V�����ԍ�
	int nowPlayAnimeIndex;
	//�O��Đ����Ă����A�j���[�V�����ԍ�
	int previousPlayAnimeIndex;
	//��ԃA�j���[�V��������
	float lerpTime;
	//�A�j���[�V�����̎Q�ƌ��̃��f��ID
	int sourceAnimeModelID;



	ModelInfo() {
		Initialize();
	}

	void Initialize() {
		modelID = -1;
		animeID = -1;
		previousAnimeID = -1;
		nowPlayAnimeIndex = -1;
		previousPlayAnimeIndex = -1;
		lerpTime = 0.0f;
		sourceAnimeModelID = -1;
	}
};

class Render
{
public:
	Render();
	~Render();

	void LoadTexture(const std::string& name, const std::string& fileName);
	void LoadFont(const std::string& name = "Default", int size = 16, int thick = 2, const std::string& fileName = "Default");


	void Load3DModel(const std::string& name, const std::string& fileName);
	//�������f���f�[�^���g�p���郂�f���n���h�����擾
	int GetDuplicateModelID(const std::string& name);

	void LoadAnimation(const std::string& modelName, const std::string& fileName);

	void DrawTexture(const std::string& name, const Vector2& position = Vector2(0, 0), const Vector2& center = Vector2(0, 0), const Vector2& scale = Vector2(1, 1), float angle = 0.0f, float alpha = 1.0f);
	void DrawRectangle(const std::string& name, const Vector2& position = Vector2(0, 0), const Rect& rect = Rect(0, 0, 1, 1), float alpha = 1.0f);
	void DrawFont(const std::string& text, const Vector2& position, const Color& color = Color::White, const std::string& name = "Default");
	void DrawNumber(const std::string& name, const Vector2& position, int number, int width, int height, int digit = 0, char fill = '0');

	void DrawBillboard(const std::string& name, const Vector3& position, const Vector2& center = Vector2::Zero, float scale = 1.0f, float angle = 0.0f, float alpha = 1.0f, const Color& color = Color::White);
	void DrawNumberBillboard(const std::string& name, const Vector3& position, int number, int width, int height, float alpha = 1.0f);

	/// <summary> �T�v : 3D���f���̕`��@</summary>
		/// <param name="name">�o�^�������O</param>
		/// <param name="matrix">�p���s��</param>
	void Draw3DModel(const std::string& name, const Matrix4& matrix);

	void DrawDuplicateModel(int modelID, const Matrix4& matrix);

	void BindAnimation(int modelID, int animeID, float animeTime);
	void BindAnimation(const std::string& modelName, int animeIndex, float animeTime);
	void BindAnimationBlend(const std::string& modelName, int animeIndex, float animeTime);
	void BindAnimationBlendToBone(const std::string& modelName, int animeIndex, float animeTime00, float animeTime01, int boneIndex);

	float GetAnimationTime(const std::string& modelName, int animeIndex);

	int GetModelID(const std::string& modelName);
	//���[���h�̃{�[���̍��W���擾
	Vector3 GetBonePosition(const std::string& modelName, int boneIndex);
	Matrix4 GetBoneLocalMatrix(const std::string& modelName, int boneIndex);
	Matrix4 GetBoneLocalWorldMatrix(const std::string& modelName, int boneIndex);

	int GetModelTextureIndex(const std::string& modelName, int index);
	void ChangeModelTexture(const std::string& modelName, const std::string& textureName, int textureIndex);
	void ChangePreviousAnimeID(const std::string& modelName, int animeIndex);

	void SetUVTransform(const std::string& modelName, const Vector2& translate = Vector2(0, 0), const Vector2& scale = Vector2(1, 1), const Vector2& rotateCenter = Vector2(0, 0), float angle = 0.0f);
	void ReSetUVTransform(const std::string& modelName);

	void SetOpacity(const std::string& modelName, float alpha);

	/// <summary> �T�v : �ǂݍ��񂾃��\�[�X�̍폜�@</summary>
	void Clear();

	void DeleteDuplicateModel(int modelID);

private:
	std::unordered_map<std::string, ModelInfo> models;
	std::unordered_map<std::string, int> textures;
	std::unordered_map<std::string, int> fonts;

private:
	static const float LerpTime;
};

