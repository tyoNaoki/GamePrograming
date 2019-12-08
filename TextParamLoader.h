#pragma once
#ifndef TEXTPARAM_H
#define TEXTPARAM_H

#include "DxLib.h"
#include "Vector3.h"

// �e�L�X�g�p�����[�^�̖��O�Ɏg����ő啶����
#define TEXTPARAM_NAME_MAXLENGTH		(64)

// �t�@�C����Ɋ܂߂���e�L�X�g�p�����[�^�̍ő吔
#define TEXTPARAM_MAXNUM				(1024)

// ������^�C�v�̃p�����[�^�̍ő啶����
#define TEXTPARAM_STRING_MAXLENGTH		(64)

// �p�����[�^�^�C�v
typedef enum _ETextParamType
{
	ETextParamType_Int,				// �����l
	ETextParamType_Bool,			// bool�l
	ETextParamType_Float,			// ���������_���l
	ETextParamType_Vector,			// VECTOR�l
	ETextParamType_String,			// ������
	ETextParamType_Color,			// �J���[�l

	ETextParamType_Num,				// �p�����[�^�^�C�v�̐�
}ETextParamType;

// �p�����[�^�{�̂̋��p��
union _STextParam
{
	// int�^�C�v�̃p�����[�^�p�ϐ�
	int                Int;

	// bool�^�C�v�̃p�����[�^�p�ϐ�
	bool               Bool;

	// float�^�C�v�̃p�����[�^�p�ϐ�
	float              Float;

	// vector�^�C�v�̃p�����[�^�p�ϐ�
	VECTOR             Vector;

	// string�^�C�v�̃p�����[�^�p�ϐ�
	char               String[TEXTPARAM_STRING_MAXLENGTH];

	// color�^�C�v�̃p�����[�^�p�ϐ�
	COLOR_U8           Color;
};

// �p�����[�^��̏��
struct _STextParamInfoUnit
{
	// �p�����[�^�̖��O
	char               Name[TEXTPARAM_NAME_MAXLENGTH];

	// �p�����[�^�^�C�v
	_ETextParamType     Type;

	// �p�����[�^�{��
	_STextParam         Param;
};

// �P�t�@�C���̃e�L�X�g�p�����[�^���
struct _STextParamInfo
{
	// �p�����[�^�̐�
	int                ParamNum;

	// �p�����[�^�z��
	_STextParamInfoUnit Param[TEXTPARAM_MAXNUM];
};

class TextParamLoader
{
public:
	bool  LoadTextParam(_STextParamInfo *TxtParam,const char *FilePath,...);
	int   SearchTextParam(_STextParamInfo *TxtParam,const char *ParamName,...);
	int   GetTextParamInt(_STextParamInfo *TxtParam,const char *ParamName,...);
	bool  GetTextParamBool(_STextParamInfo *TxtParam,const char *ParamName,...);
	float GetTextParamFloat(_STextParamInfo *TxtParam,const char *ParamName,...);
	Vector3 GetTextParamVector(_STextParamInfo *TxtParam,const char *ParamName,...);
	const char *GetTextParamString(_STextParamInfo *TxtParam,const char *ParamName,...);
	COLOR_U8 GetTextParamColor(_STextParamInfo *TxtParam,const char *ParamName,...);
	TextParamLoader();
	~TextParamLoader();
private:
	_STextParam STextParam;
	_STextParamInfo STextParamInfo;
	_STextParamInfoUnit STextParamInfoUnit;
};

#endif

