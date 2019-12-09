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
typedef union _STextParam
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
}STextParamInfo;

// �p�����[�^��̏��
typedef struct _STextParamInfoUnit
{
	// �p�����[�^�̖��O
	char               Name[TEXTPARAM_NAME_MAXLENGTH];

	// �p�����[�^�^�C�v
	_ETextParamType     Type;

	// �p�����[�^�{��
	_STextParam         Param;
}STextParamInfo;

// �P�t�@�C���̃e�L�X�g�p�����[�^���
typedef struct _STextParamInfo
{
	// �p�����[�^�̐�
	int                ParamNum;

	// �p�����[�^�z��
	_STextParamInfoUnit Param[TEXTPARAM_MAXNUM];
}STextParamInfo;

class TextParamLoader
{
public:
	static bool  LoadTextParam(STextParamInfo *TxtParam,const char *FilePath,...);
	static int   SearchTextParam(STextParamInfo *TxtParam,const char *ParamName,...);
	static int   GetTextParamInt(STextParamInfo *TxtParam,const char *ParamName,...);
	static bool  GetTextParamBool(STextParamInfo *TxtParam,const char *ParamName,...);
	static float GetTextParamFloat(STextParamInfo *TxtParam,const char *ParamName,...);
	static Vector3 GetTextParamVector(STextParamInfo *TxtParam,const char *ParamName,...);
	static const char *GetTextParamString(STextParamInfo *TxtParam,const char *ParamName,...);
	static COLOR_U8 GetTextParamColor(STextParamInfo *TxtParam,const char *ParamName,...);
	TextParamLoader();
	~TextParamLoader();
};

#endif

