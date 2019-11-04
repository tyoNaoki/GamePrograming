#pragma once

#include "DxLib.h"

// ゲーム画面の幅
#define GAME_SCREEN_WIDTH			(1280)

// ゲーム画面の高さ
#define GAME_SCREEN_HEIGHT			(720)

// 小フォントのサイズ
#define FONTHANDLE_SMALL_SIZE		(24)

// 中フォントのサイズ
#define FONTHANDLE_MIDIUM_SIZE		(32)

// 大フォントのサイズ
#define FONTHANDLE_BIG_SIZE			(80)

// フォントハンドル
typedef enum _EFontHandle
{
	EFontHandle_Small,		// 小フォントハンドル
	EFontHandle_Midium,		// 中フォントハンドル
	EFontHandle_Big,		// 大フォントハンドル
	EFontHandle_Num			// フォントハンドルの数
} EFontHandle;

typedef struct _SystemInfo
{
	//一つ前のフレームの時間
	LONGLONG PrevTime;

	//状態推移処理で推移させる時間
	float StepTime;

	//1フレームで状態推移処理を行う回数
	int StepNum;

	bool ExitGame;

	int StartStage;

	int DebugparamIntNum;

	int FontHandle[EFontHandle_Num];

	bool Fade;

	bool FadeOut;

	float FadeOutRate;

	bool LowSpecMode;

	LONGLONG BackDispFrameTime;

	// フレームレート表示用のフレームカウンタ
	int             FrameCounter;

	// フレームレート表示で表示するフレームレート
	int             DispFrameCount;



}SystemInfo;



extern bool System_Main();

extern void System_ExitGame();

extern bool System_StartTitle();
