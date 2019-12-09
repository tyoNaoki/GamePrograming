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
typedef union _STextParam
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
}STextParamInfo;

// パラメータ一つの情報
typedef struct _STextParamInfoUnit
{
	// パラメータの名前
	char               Name[TEXTPARAM_NAME_MAXLENGTH];

	// パラメータタイプ
	_ETextParamType     Type;

	// パラメータ本体
	_STextParam         Param;
}STextParamInfo;

// １ファイルのテキストパラメータ情報
typedef struct _STextParamInfo
{
	// パラメータの数
	int                ParamNum;

	// パラメータ配列
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

