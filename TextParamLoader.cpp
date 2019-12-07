#include "TextParamLoader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// �p�����[�^���擾����֐��̐擪�ŕK���s����^����
// �ό�������p�����[�^���𐶐����āA�z�񒆂̃p�����[�^�̃C���f�b�N�X���擾����
#define GETTEXTPARAM_COMMON		\
	int Index;\
	va_list VaList;\
	char ParamNameS[ MAX_PATH ];\
	\
	va_start( VaList, ParamName );\
	sprintf( ParamNameS, ParamName, VaList );\
	va_end( VaList );\
	\
	Index = SearchTextParam( TxtParam, ParamNameS );

// �p�����[�^�^�C�v��
static const char *g_TextParamTypeName[ETextParamType_Num] =
{
	"int",
	"bool",
	"float",
	"vector",
	"string",
	"color"
};

bool TextParamLoader::LoadTextParam(_STextParamInfo *TxtParam, const char *FilePath){
	FILE   *fp;
	char    Type[64];
	char    Name[TEXTPARAM_NAME_MAXLENGTH];
	char    Param1[64];
	char    Param2[64];
	char    Param3[64];
	char    Param4[64];
	va_list VaList;
	char    FilePathS[MAX_PATH];
	int     i;
	int     Num;

	// �ό�������t�@�C���p�X�𐶐�����
	va_start(VaList, FilePath);
	sprintf(FilePathS, FilePath, VaList);
	va_end(VaList);

	// �e�L�X�g�^�C�v�̓ǂݍ��ݎw��Ńt�@�C�����J��
	fp = fopen(FilePathS, "rt");

	// �t�@�C�����J�����ƂɎ��s�����玸�s�I��
	if (fp == NULL)
	{
		return false;
	}

	// �e�L�X�g�p�����[�^�\���̂��O�ŏ���������
	memset(TxtParam, 0, sizeof(STextParamInfo));

	// �e�L�X�g�t�@�C���̏I�[�ɓ��B����܂Ń��[�v
	Num = 0;
	while (fscanf(fp, "%s %s = %s", Type, Name, Param1) != EOF)
	{
		// �p�����[�^�̖��O��ۑ�
		strcpy(TxtParam->Param[Num].Name, Name);

		// �p�����[�^�̃^�C�v�𒲂ׂ�
		for (i = 0; i < ETextParamType_Num; i++)
		{
			if (strcmp(g_TextParamTypeName[i], Type) == 0)
			{
				break;
			}
		}

		// �^�C�v�������������ꍇ�̂ݏ���
		if (i == ETextParamType_Num)
		{
			// ���s�̈ʒu�܂œǂݐi�߂�
			fscanf(fp, "\n");
			continue;
		}

		// �^�C�v��ۑ�
		TxtParam->Param[Num].Type = (_ETextParamType)i;

		// �^�C�v�ɂ���ď����𕪊�
		switch (TxtParam->Param[Num].Type)
		{
		case ETextParamType_Int:			// �����l
			// �^�C�v�����wint�x�������ꍇ�̓p�����[�^������𐮐��l�ɕϊ�����
			TxtParam->Param[Num].Param.Int = atoi(Param1);
			break;

		case ETextParamType_Bool:			// bool�l
			// �^�C�v�����wbool�x�������ꍇ�̓p�����[�^�������bool�l�ɕϊ�����
			TxtParam->Param[Num].Param.Bool = strcmp(Param1, "true") == 0;
			break;

		case ETextParamType_Float:			// ���������_���l
			// �^�C�v�����wfloat�x�������ꍇ�̓p�����[�^������𕂓������_���l�ɕϊ�����
			TxtParam->Param[Num].Param.Float = (float)atof(Param1);
			break;

		case ETextParamType_Vector:			// VECTOR�l
			// �^�C�v�����wvector�x�������ꍇ�͒ǉ��œ�p�����[�^��������擾����
			fscanf(fp, "%s %s", Param2, Param3);

			// �R�̃p�����[�^������𕂓������_���l�ɕϊ�����
			TxtParam->Param[Num].Param.Vector.x = (float)atof(Param1);
			TxtParam->Param[Num].Param.Vector.y = (float)atof(Param2);
			TxtParam->Param[Num].Param.Vector.z = (float)atof(Param3);
			break;

		case ETextParamType_String:			// ������
			// �^�C�v�����wstring�x�������ꍇ�̓p�����[�^����������̂܂ܕۑ�����
			strcpy(TxtParam->Param[Num].Param.String, Param1);
			break;

		case ETextParamType_Color:			// �J���[�l
			// �^�C�v�����wcolor�x�������ꍇ�͒ǉ��ŎO�p�����[�^��������擾����
			fscanf(fp, "%s %s %s", Param2, Param3, Param4);

			// �S�̃p�����[�^������𐮐��l�ɕϊ�����
			TxtParam->Param[Num].Param.Color.r = atoi(Param1);
			TxtParam->Param[Num].Param.Color.g = atoi(Param2);
			TxtParam->Param[Num].Param.Color.b = atoi(Param3);
			TxtParam->Param[Num].Param.Color.a = atoi(Param4);
			break;
		}

		// �p�����[�^�̐��𑝂₷
		Num++;

		// ���s�̈ʒu�܂œǂݐi�߂�
		fscanf(fp, "\n");
	}

	// �p�����[�^�̐���ۑ�
	TxtParam->ParamNum = Num;

	// �t�@�C�������
	fclose(fp);

	// �����I��
	return true;
}

int TextParamLoader::SearchTextParam(_STextParamInfo *TxtParam, const char *ParamName){
	int     i;
	va_list VaList;
	char    ParamNameS[MAX_PATH];

	// �ό�������p�����[�^���𐶐�����
	va_start(VaList, ParamName);
	sprintf(ParamNameS, ParamName, VaList);
	va_end(VaList);

	// �p�����[�^�̐������J��Ԃ�
	for (i = 0; i < TxtParam->ParamNum; i++)
	{
		// �w��̃p�����[�^���ƈ�v����p�����[�^���������ꍇ�͔z��̃C���f�b�N�X��Ԃ�
		if (strcmp(TxtParam->Param[i].Name, ParamNameS) == 0)
		{
			return i;
		}
	}

	// ������Ȃ������ꍇ�� -1 ��Ԃ�
	return -1;
}

int TextParamLoader::GetTextParamInt(_STextParamInfo *TxtParam, const char *ParamName){
	// �ό�������p�����[�^���𐶐����A�p�����[�^�̔z�񒆂�
	// �C���f�b�N�X���擾�����^���������s����
	GETTEXTPARAM_COMMON

		// �p�����[�^��������Ȃ������ꍇ�� 0 ��Ԃ�
		if (Index < 0)
		{
			return 0;
		}

	// �p�����[�^�����������ꍇ�́A�p�����[�^�̐����l��Ԃ�
	return TxtParam->Param[Index].Param.Int;
}

bool TextParamLoader::GetTextParamBool(_STextParamInfo *TxtParam, const char *ParamName){
	// �ό�������p�����[�^���𐶐����A�p�����[�^�̔z�񒆂�
	// �C���f�b�N�X���擾�����^���������s����
	GETTEXTPARAM_COMMON

		// �p�����[�^��������Ȃ������ꍇ�� false ��Ԃ�
		if (Index < 0)
		{
			return false;
		}

	// �p�����[�^�����������ꍇ�́A�p�����[�^��bool�l��Ԃ�
	return TxtParam->Param[Index].Param.Bool;
}

float TextParamLoader::GetTextParamFloat(_STextParamInfo *TxtParam, const char *ParamName){
	// �ό�������p�����[�^���𐶐����A�p�����[�^�̔z�񒆂�
	// �C���f�b�N�X���擾�����^���������s����
	GETTEXTPARAM_COMMON

		// �p�����[�^��������Ȃ������ꍇ�� 0.0f ��Ԃ�
		if (Index < 0)
		{
			return 0.0f;
		}

	// �p�����[�^�����������ꍇ�́A�p�����[�^�̕��������_���l��Ԃ�
	return TxtParam->Param[Index].Param.Float;
}

Vector3 TextParamLoader::GetTextParamVector(_STextParamInfo *TxtParam, const char *ParamName){
	// �ό�������p�����[�^���𐶐����A�p�����[�^�̔z�񒆂�
	// �C���f�b�N�X���擾�����^���������s����
	GETTEXTPARAM_COMMON

		// �p�����[�^��������Ȃ������ꍇ�� x=0.0f, y=0.0f, z=0.0f ��Ԃ�
		if (Index < 0)
		{
			return Vector3(0.0f, 0.0f, 0.0f);
		}

	// �p�����[�^�����������ꍇ�́A�p�����[�^��VECTOR�l��Ԃ�
	 VECTOR Vec = TxtParam->Param[Index].Param.Vector;
	 return Vector3(Vec.x, Vec.y, Vec.z);
}

const char * TextParamLoader::GetTextParamString(_STextParamInfo *TxtParam, const char *ParamName){
	// �ό�������p�����[�^���𐶐����A�p�����[�^�̔z�񒆂�
	// �C���f�b�N�X���擾�����^���������s����
	GETTEXTPARAM_COMMON

		// �p�����[�^��������Ȃ������ꍇ�� NULL ��Ԃ�
		if (Index < 0)
		{
			return NULL;
		}

	// �p�����[�^�����������ꍇ�́A�p�����[�^�̕�����̃A�h���X��Ԃ�
	return TxtParam->Param[Index].Param.String;
}

DxLib::COLOR_U8 TextParamLoader::GetTextParamColor(_STextParamInfo *TxtParam, const char *ParamName){
	// �ό�������p�����[�^���𐶐����A�p�����[�^�̔z�񒆂�
	// �C���f�b�N�X���擾�����^���������s����
	GETTEXTPARAM_COMMON

		// �p�����[�^��������Ȃ������ꍇ�� r=0 g=0 b=0 a=0 ��Ԃ�
		if (Index < 0)
		{
			return GetColorU8(0, 0, 0, 0);
		}

	// �p�����[�^�����������ꍇ�́A�p�����[�^��COLOR_U8�̒l��Ԃ�
	return TxtParam->Param[Index].Param.Color;
}

TextParamLoader::TextParamLoader()
{
}

TextParamLoader::~TextParamLoader()
{
}

