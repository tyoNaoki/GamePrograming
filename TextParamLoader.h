#pragma once
#ifndef TEXTPARAM_H
#define TEXTPARAM_H

#include "DxLib.h"
#include "Vector3.h"

// テキストパラメータの名前に使える最大文字数
#define TEXTPARAM_NAME_MAXLENGTH		(64)

// ファイル一つに含められるテキストパラメータの最大数
#define TEXTPARAM_MAXNUM				(1024)

// 文字列タイプのパラメータの最大文字数
#define TEXTPARAM_STRING_MAXLENGTH		(64)

// パラメータタイプ
typedef enum _ETextParamType
{
	ETextParamType_Int,				// 整数値
	ETextParamType_Bool,			// bool値
	ETextParamType_Float,			// 浮動小数点数値
	ETextParamType_Vector,			// VECTOR値
	ETextParamType_String,			// 文字列
	ETextParamType_Color,			// カラー値

	ETextParamType_Num,				// パラメータタイプの数
}ETextParamType;

// パラメータ本体の共用体
union _STextParam
{
	// intタイプのパラメータ用変数
	int                Int;

	// boolタイプのパラメータ用変数
	bool               Bool;

	// floatタイプのパラメータ用変数
	float              Float;

	// vectorタイプのパラメータ用変数
	VECTOR             Vector;

	// stringタイプのパラメータ用変数
	char               String[TEXTPARAM_STRING_MAXLENGTH];

	// colorタイプのパラメータ用変数
	COLOR_U8           Color;
};

// パラメータ一つの情報
struct _STextParamInfoUnit
{
	// パラメータの名前
	char               Name[TEXTPARAM_NAME_MAXLENGTH];

	// パラメータタイプ
	_ETextParamType     Type;

	// パラメータ本体
	_STextParam         Param;
};

// １ファイルのテキストパラメータ情報
struct _STextParamInfo
{
	// パラメータの数
	int                ParamNum;

	// パラメータ配列
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

