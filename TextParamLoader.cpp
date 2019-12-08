#include "TextParamLoader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// パラメータを取得する関数の先頭で必ず行う定型処理
// 可変個引数からパラメータ名を生成して、配列中のパラメータのインデックスを取得する
#define GETTEXTPARAM_COMMON		\
	int Index;\
	va_list VaList;\
	char ParamNameS[ MAX_PATH ];\
	\
	va_start( VaList, ParamName );\
	vsprintf( ParamNameS, ParamName, VaList );\
	va_end( VaList );\
	\
	Index = SearchTextParam( TxtParam, ParamNameS );

// パラメータタイプ名
static const char *g_TextParamTypeName[ETextParamType_Num] =
{
	"int",
	"bool",
	"float",
	"vector",
	"string",
	"color"
};

bool TextParamLoader::LoadTextParam(_STextParamInfo *TxtParam, const char *FilePath,...){
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

	// 可変個引数からファイルパスを生成する
	va_start(VaList, FilePath);
	vsprintf(FilePathS, FilePath, VaList);
	va_end(VaList);

	// テキストタイプの読み込み指定でファイルを開く
	fp = fopen(FilePathS, "rt");

	// ファイルを開くことに失敗したら失敗終了
	if (fp == NULL)
	{
		return false;
	}

	// テキストパラメータ構造体を０で初期化する
	memset(TxtParam, 0, sizeof(STextParamInfo));

	// テキストファイルの終端に到達するまでループ
	Num = 0;
	while (fscanf(fp, "%s %s = %s", Type, Name, Param1) != EOF)
	{
		// パラメータの名前を保存
		strcpy(TxtParam->Param[Num].Name, Name);

		// パラメータのタイプを調べる
		for (i = 0; i < ETextParamType_Num; i++)
		{
			if (strcmp(g_TextParamTypeName[i], Type) == 0)
			{
				break;
			}
		}

		// タイプ名が見つかった場合のみ処理
		if (i == ETextParamType_Num)
		{
			// 改行の位置まで読み進める
			fscanf(fp, "\n");
			continue;
		}

		// タイプを保存
		TxtParam->Param[Num].Type = (_ETextParamType)i;

		// タイプによって処理を分岐
		switch (TxtParam->Param[Num].Type)
		{
		case ETextParamType_Int:			// 整数値
			// タイプ名が『int』だった場合はパラメータ文字列を整数値に変換する
			TxtParam->Param[Num].Param.Int = atoi(Param1);
			break;

		case ETextParamType_Bool:			// bool値
			// タイプ名が『bool』だった場合はパラメータ文字列をbool値に変換する
			TxtParam->Param[Num].Param.Bool = strcmp(Param1, "true") == 0;
			break;

		case ETextParamType_Float:			// 浮動小数点数値
			// タイプ名が『float』だった場合はパラメータ文字列を浮動小数点数値に変換する
			TxtParam->Param[Num].Param.Float = (float)atof(Param1);
			break;

		case ETextParamType_Vector:			// VECTOR値
			// タイプ名が『vector』だった場合は追加で二つパラメータ文字列を取得する
			fscanf(fp, "%s %s", Param2, Param3);

			// ３つのパラメータ文字列を浮動小数点数値に変換する
			TxtParam->Param[Num].Param.Vector.x = (float)atof(Param1);
			TxtParam->Param[Num].Param.Vector.y = (float)atof(Param2);
			TxtParam->Param[Num].Param.Vector.z = (float)atof(Param3);
			break;

		case ETextParamType_String:			// 文字列
			// タイプ名が『string』だった場合はパラメータ文字列をそのまま保存する
			strcpy(TxtParam->Param[Num].Param.String, Param1);
			break;

		case ETextParamType_Color:			// カラー値
			// タイプ名が『color』だった場合は追加で三つパラメータ文字列を取得する
			fscanf(fp, "%s %s %s", Param2, Param3, Param4);

			// ４つのパラメータ文字列を整数値に変換する
			TxtParam->Param[Num].Param.Color.r = atoi(Param1);
			TxtParam->Param[Num].Param.Color.g = atoi(Param2);
			TxtParam->Param[Num].Param.Color.b = atoi(Param3);
			TxtParam->Param[Num].Param.Color.a = atoi(Param4);
			break;
		}

		// パラメータの数を増やす
		Num++;

		// 改行の位置まで読み進める
		fscanf(fp, "\n");
	}

	// パラメータの数を保存
	TxtParam->ParamNum = Num;

	// ファイルを閉じる
	fclose(fp);

	// 成功終了
	return true;
}

int TextParamLoader::SearchTextParam(_STextParamInfo *TxtParam, const char *ParamName,...){
	int     i;
	va_list VaList;
	char    ParamNameS[MAX_PATH];

	// 可変個引数からパラメータ名を生成する
	va_start(VaList, ParamName);
	vsprintf(ParamNameS, ParamName, VaList);
	va_end(VaList);

	// パラメータの数だけ繰り返し
	for (i = 0; i < TxtParam->ParamNum; i++)
	{
		// 指定のパラメータ名と一致するパラメータがあった場合は配列のインデックスを返す
		if (strcmp(TxtParam->Param[i].Name, ParamNameS) == 0)
		{
			return i;
		}
	}

	// 見つからなかった場合は -1 を返す
	return -1;
}

int TextParamLoader::GetTextParamInt(_STextParamInfo *TxtParam, const char *ParamName,...){
	// 可変個引数からパラメータ名を生成し、パラメータの配列中の
	// インデックスを取得する定型処理を実行する
	GETTEXTPARAM_COMMON

		// パラメータが見つからなかった場合は 0 を返す
		if (Index < 0)
		{
			return 0;
		}

	// パラメータが見つかった場合は、パラメータの整数値を返す
	return TxtParam->Param[Index].Param.Int;
}

bool TextParamLoader::GetTextParamBool(_STextParamInfo *TxtParam, const char *ParamName,...){
	// 可変個引数からパラメータ名を生成し、パラメータの配列中の
	// インデックスを取得する定型処理を実行する
	GETTEXTPARAM_COMMON

		// パラメータが見つからなかった場合は false を返す
		if (Index < 0)
		{
			return false;
		}

	// パラメータが見つかった場合は、パラメータのbool値を返す
	return TxtParam->Param[Index].Param.Bool;
}

float TextParamLoader::GetTextParamFloat(_STextParamInfo *TxtParam, const char *ParamName,...){
	// 可変個引数からパラメータ名を生成し、パラメータの配列中の
	// インデックスを取得する定型処理を実行する
	GETTEXTPARAM_COMMON

		// パラメータが見つからなかった場合は 0.0f を返す
		if (Index < 0)
		{
			return 0.0f;
		}

	// パラメータが見つかった場合は、パラメータの浮動小数点数値を返す
	return TxtParam->Param[Index].Param.Float;
}

Vector3 TextParamLoader::GetTextParamVector(_STextParamInfo *TxtParam, const char *ParamName,...){
	// 可変個引数からパラメータ名を生成し、パラメータの配列中の
	// インデックスを取得する定型処理を実行する
	GETTEXTPARAM_COMMON

		// パラメータが見つからなかった場合は x=0.0f, y=0.0f, z=0.0f を返す
		if (Index < 0)
		{
			return Vector3(0.0f, 0.0f, 0.0f);
		}

	// パラメータが見つかった場合は、パラメータのVECTOR値を返す
	 VECTOR Vec = TxtParam->Param[Index].Param.Vector;
	 return Vector3(Vec.x, Vec.y, Vec.z);
}

const char * TextParamLoader::GetTextParamString(_STextParamInfo *TxtParam, const char *ParamName,...){
	// 可変個引数からパラメータ名を生成し、パラメータの配列中の
	// インデックスを取得する定型処理を実行する
	GETTEXTPARAM_COMMON

		// パラメータが見つからなかった場合は NULL を返す
		if (Index < 0)
		{
			return NULL;
		}

	// パラメータが見つかった場合は、パラメータの文字列のアドレスを返す
	return TxtParam->Param[Index].Param.String;
}

DxLib::COLOR_U8 TextParamLoader::GetTextParamColor(_STextParamInfo *TxtParam, const char *ParamName,...){
	// 可変個引数からパラメータ名を生成し、パラメータの配列中の
	// インデックスを取得する定型処理を実行する
	GETTEXTPARAM_COMMON

		// パラメータが見つからなかった場合は r=0 g=0 b=0 a=0 を返す
		if (Index < 0)
		{
			return GetColorU8(0, 0, 0, 0);
		}

	// パラメータが見つかった場合は、パラメータのCOLOR_U8の値を返す
	return TxtParam->Param[Index].Param.Color;
}

TextParamLoader::TextParamLoader()
{
}

TextParamLoader::~TextParamLoader()
{
}


