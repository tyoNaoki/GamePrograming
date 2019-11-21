#include "Render.h"

#include<DxLib.h>
#include<cassert>
#include<sstream>
#include<iomanip>
#include"Math.h"
#include"Convert.h"

const float Render::LerpTime = 15.0f;

Render::Render()
	: models()
	, textures()
	, fonts()
{
}

Render::~Render() {
	Clear();
}


void Render::LoadTexture(const std::string & name, const std::string & fileName)
{
	int id = LoadGraph((fileName).c_str());
	if (id == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	textures.emplace(name, id);
}

void Render::LoadFont(const std::string & name, int size, int thick, const std::string & fileName)
{
	int id = CreateFontToHandle((fileName).c_str(), size, thick, DX_FONTTYPE_NORMAL);
	if (id == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	fonts.emplace(name, id);
}

void Render::Load3DModel(const std::string & name, const std::string & fileName)
{
	int id = MV1LoadModel((fileName).c_str());
	if (id == -1) {
		assert(!"Failure to read the file.");
		return;
	}
	ModelInfo info;
	info.modelID = id;
	MV1SetUseZBuffer(id, TRUE);
	MV1SetWriteZBuffer(id, TRUE);
	models.emplace(name, info);
}

int Render::GetDuplicateModelID(const std::string & name)
{
	return MV1DuplicateModel(models[name].modelID);
}

void Render::LoadAnimation(const std::string & modelName, const std::string & fileName)
{
	static const int DefaultAnimationIndex = 0;
	int sourceAnimeModelID = MV1LoadModel((fileName).c_str());
	if (sourceAnimeModelID == -1) {
		assert(!"Failure to read the file.");
		return;
	}

	ModelInfo info = models[modelName];
	info.sourceAnimeModelID = sourceAnimeModelID;
	info.animeID = MV1AttachAnim(info.modelID, DefaultAnimationIndex, sourceAnimeModelID, FALSE);
	info.nowPlayAnimeIndex = DefaultAnimationIndex;
	models[modelName] = info;
}


void Render::DrawTexture(const std::string & name, const Vector2 & position, const Vector2 & center, const Vector2 & scale, float angle, float alpha)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(alpha * 255.0f));
	DrawRotaGraph3(
		position.x, position.y,
		center.x, center.y,
		scale.x, scale.y,
		angle * Math::toRadian,
		textures[name],
		TRUE, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Render::DrawRectangle(const std::string & name, const Vector2 & position, const Rect & rect, float alpha)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(alpha * 255.0f));
	DrawRectGraph(
		position.x, position.y,
		rect.left, rect.top,
		rect.right, rect.bottom,
		textures[name],
		TRUE,
		FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Render::DrawFont(const std::string & text, const Vector2 & position, const Color & color, const std::string & name)
{
	DrawStringToHandle(
		position.x, position.y,
		text.c_str(),
		color.ToCOLOR(),
		fonts[name]);
}

void Render::DrawNumber(const std::string & name, const Vector2 & position, int number, int width, int height, int digit, char fill)
{
	std::stringstream ss;
	ss << std::setw(digit) << std::setfill(fill) << number;

	std::string numStr = ss.str();

	for (unsigned int i = 0; i < numStr.size(); ++i) {
		if (numStr[i] == ' ')
			continue;

		int n = numStr[i] - '0';
		Vector2 pos(position.x + i * width, position.y);
		Rect rect(n * width, 0.0f, width, height);
		DrawRectangle(name, pos, rect);
	}
}

void Render::DrawBillboard(const std::string & name, const Vector3 & position, const Vector2 & center, float scale, float angle, float alpha, const Color& color)
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(alpha * 255.0f));

	SetDrawBright(color.r * 255.0f, color.g * 255.0f, color.b * 255.0f);

	DrawBillboard3D(
		Convert::ToVECTOR(position),
		center.x,
		center.y,
		scale,
		angle * Math::toRadian,
		textures[name],
		TRUE
	);

	SetDrawBright(255, 255, 255);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Render::DrawNumberBillboard(const std::string & name, const Vector3 & position, int number, int width, int height, float alpha)
{
	std::string numStr = std::to_string(number);

	for (unsigned int i = 0; i < numStr.size(); ++i) {
		if (numStr[i] == ' ')
			continue;

		int n = numStr[i] - '0';
		Vector2 topLeft(0 + i * 3, 3);
		Vector2 topRight(3 + i * 3, 3);
		Vector2 bottomRight(3 + i * 3, 0);
		Vector2 bottomLeft(0 + i * 3, 0);
		Rect rect(n * width, 0.0f, width, height);
		int numberRect = DerivationGraph( //新しいグラフィックハンドルを作る
			rect.left, rect.top,
			rect.right, rect.bottom,
			textures[name]);


		SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(alpha * 255.0f));
		DrawModiBillboard3D(
			VGet(position.x, position.y, position.z),
			topLeft.x, topLeft.y,
			topRight.x, topRight.y,
			bottomRight.x, bottomRight.y,
			bottomLeft.x, bottomLeft.y,
			numberRect,
			TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

		DeleteGraph(numberRect);
	}
}


void Render::Draw3DModel(const std::string & name, const Matrix4 & matrix)
{
	int id = models[name].modelID;
	MV1SetMatrix(id, Convert::ToMATRIX(matrix));
	MV1DrawModel(id);
}

void Render::DrawDuplicateModel(int modelID, const Matrix4 & matrix)
{
	MV1SetMatrix(modelID, Convert::ToMATRIX(matrix));
	MV1DrawModel(modelID);
}

void Render::BindAnimation(int modelID, int animeID, float animeTime)
{

	MV1SetAttachAnimTime(modelID, animeID, animeTime);

}

void Render::BindAnimation(const std::string & modelName, int animeIndex, float animeTime)
{
	ModelInfo info = models[modelName];

	if (info.nowPlayAnimeIndex == animeIndex) {
		MV1SetAttachAnimTime(info.modelID, info.animeID, animeTime);
		return;
	}

	info.nowPlayAnimeIndex = animeIndex;
	MV1DetachAnim(info.modelID, info.animeID);
	info.animeID = MV1AttachAnim(info.modelID, animeIndex, info.sourceAnimeModelID, FALSE);
	MV1SetAttachAnimTime(info.modelID, info.animeID, animeTime);
	models[modelName] = info;
}

void Render::BindAnimationBlend(const std::string & modelName, int animeIndex, float animeTime)
{
	ModelInfo info = models[modelName];

	if (info.nowPlayAnimeIndex != animeIndex) {
		MV1DetachAnim(info.modelID, info.previousAnimeID);
		info.previousAnimeID = info.animeID;
		info.animeID = MV1AttachAnim(info.modelID, animeIndex, info.sourceAnimeModelID, FALSE);

		info.previousPlayAnimeIndex = info.nowPlayAnimeIndex;

		info.nowPlayAnimeIndex = animeIndex;
		info.lerpTime = 0.0f;
	}

	info.lerpTime = Math::Min<float>(info.lerpTime + 1.0f, LerpTime);

	float rate = info.lerpTime / LerpTime;


	MV1SetAttachAnimBlendRate(info.modelID, info.previousAnimeID, 1.0f - rate);
	MV1SetAttachAnimBlendRate(info.modelID, info.animeID, rate);

	MV1SetAttachAnimTime(info.modelID, info.animeID, animeTime);

	models[modelName] = info;
}

void Render::BindAnimationBlendToBone(const std::string & modelName, int animeIndex, float animeTime00, float animeTime01, int boneIndex)
{
	ModelInfo info = models[modelName];

	if (info.nowPlayAnimeIndex != animeIndex) {
		MV1DetachAnim(info.modelID, info.previousAnimeID);
		info.previousAnimeID = info.animeID;
		info.animeID = MV1AttachAnim(info.modelID, animeIndex, info.sourceAnimeModelID, FALSE);

		info.previousPlayAnimeIndex = info.nowPlayAnimeIndex;

		info.nowPlayAnimeIndex = animeIndex;

		info.lerpTime = 0.0f;
	}

	info.lerpTime = Math::Min<float>(info.lerpTime + 1.0f, LerpTime);

	float rate = info.lerpTime / LerpTime;


	MV1SetAttachAnimBlendRateToFrame(info.modelID, info.previousAnimeID, boneIndex, 1.0f - rate, TRUE);
	MV1SetAttachAnimBlendRateToFrame(info.modelID, info.animeID, boneIndex, rate, TRUE);

	MV1SetAttachAnimTime(info.modelID, info.animeID, animeTime00);
	MV1SetAttachAnimTime(info.modelID, info.previousAnimeID, animeTime01);

	models[modelName] = info;

}



float Render::GetAnimationTime(const std::string & modelName, int animeIndex)
{
	return MV1GetAnimTotalTime(models[modelName].sourceAnimeModelID, animeIndex);
}

int Render::GetModelID(const std::string & modelName)
{
	return models[modelName].modelID;
}

Vector3 Render::GetBonePosition(const std::string & modelName, int boneIndex)
{
	return Convert::ToVector3(MV1GetFramePosition(models[modelName].modelID, boneIndex));
}

Matrix4 Render::GetBoneLocalMatrix(const std::string & modelName, int boneIndex)
{
	return Convert::ToMatrix4(MV1GetFrameLocalMatrix(models[modelName].modelID, boneIndex));
}

Matrix4 Render::GetBoneLocalWorldMatrix(const std::string & modelName, int boneIndex)
{
	return Convert::ToMatrix4(MV1GetFrameLocalWorldMatrix(models[modelName].modelID, boneIndex));
}

int Render::GetModelTextureIndex(const std::string & modelName, int index)
{
	return MV1GetMaterialDifMapTexture(models[modelName].modelID, index);
}

void Render::ChangeModelTexture(const std::string & modelName, const std::string & textureName, int textureIndex)
{
	MV1SetTextureGraphHandle(models[modelName].modelID, textureIndex, textures[textureName], FALSE);
}

void Render::ChangePreviousAnimeID(const std::string & modelName, int animeIndex)
{
	ModelInfo info = models[modelName];

	if (info.previousPlayAnimeIndex != animeIndex) {
		MV1DetachAnim(info.modelID, info.previousAnimeID);
		info.previousAnimeID = MV1AttachAnim(info.modelID, animeIndex, info.sourceAnimeModelID, FALSE);

		info.previousPlayAnimeIndex = animeIndex;

	}
}

void Render::SetUVTransform(const std::string & modelName, const Vector2 & translate, const Vector2 & scale, const Vector2 & rotateCenter, float angle)
{
	MV1SetFrameTextureAddressTransform(models[modelName].modelID, 0, translate.x, translate.y, scale.x, scale.y, rotateCenter.x, rotateCenter.y, angle * Math::toRadian);
}

void Render::ReSetUVTransform(const std::string & modelName)
{
	MV1ResetFrameTextureAddressTransform(models[modelName].modelID, 0);
}

void Render::SetOpacity(const std::string & modelName, float alpha)
{
	MV1SetOpacityRate(models[modelName].modelID, alpha);
}


void Render::Clear()
{
	for (auto& id : models) {
		MV1DeleteModel(id.second.modelID);
		MV1DeleteModel(id.second.sourceAnimeModelID);
	}

	for (auto& id : textures) {
		DeleteGraph(id.second);
	}

	for (auto& id : fonts) {
		DeleteFontToHandle(id.second);
	}

	models.clear();
	textures.clear();
	fonts.clear();
}

void Render::DeleteDuplicateModel(int modelID)
{
	MV1DeleteModel(modelID);
}
