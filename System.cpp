#include "System.h"
#include "DxLib.h"
#include "Mathematics.h"
#include "SeenController.h"
#include <Windows.h>
#include "Seen_Tytle.h"


// フェードアウト、フェードインの速度
#define FADE_SPEED			(1.0f)

// １フレームの最大時間
#define MAX_DELTA_TIME		(1.0f / 120.0f)

// 一度に処理する最大フレーム数
#define MAX_FRAME_NUM		(8)

// 編集できる整数パラメータの最大数
#define DEBUG_INT_MAXNUM	(20)

static SystemInfo g_SystemInfo;

static bool System_MainLoop();

static bool System_Initialize();

static void System_Terminate();

static void System_Render(float Step){
};

SeenController *seenController;

static void System_FadeStep(
	// 推移させる時間( 単位 : 秒 )
	float StepTime
)
{
	// フェード処理を行っているかどうかのフラグが倒れている場合は何もせず終了
	if (!g_SystemInfo.Fade)
	{
		return;
	}

	// フェードアウト率の変更
	if (ParamChangeFloat( &g_SystemInfo.FadeOutRate,
		g_SystemInfo.FadeOut ? 1.0f : 0.0f, StepTime, FADE_SPEED))
	{
		// 値の変更が完了したらフェードアウトを行っているかどうかのフラグを倒す
		g_SystemInfo.Fade = false;
	}
}

bool System_Main() {

	seenController = new SeenController;

	if (!System_Initialize()) {
		System_Terminate();
		delete seenController;

		return false;
	}
	
	if (!System_MainLoop()) {
		System_Terminate();
		delete seenController;

		return false;
	}

	System_Terminate();

	delete seenController;


	return true;
}

static bool System_Initialize()
{
	int i;
//	char FilePath[MAX_PATH];

	if (MessageBox(NULL, "ウインドウモードで起動しますか？", "画面モード確認", MB_YESNO) == IDYES) {
		ChangeWindowMode(TRUE);
	}

	if (MessageBox(NULL, "低処理負荷モードで起動しますか？", "処理負荷モード確認", MB_YESNO) == IDYES) {
		g_SystemInfo.LowSpecMode = true;
	}

	SetGraphMode(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT, 32);

	SetMainWindowText("Sword Bout");

	SetEnableXAudioFlag(g_SystemInfo.LowSpecMode ? false : true);

	Set3DSoundOneMetre(100.0f);

	if (DxLib_Init() == -1) {
		return false;
	}

	g_SystemInfo.FontHandle[EFontHandle_Small] = CreateFontToHandle(NULL, FONTHANDLE_SMALL_SIZE, 8, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 2);
	g_SystemInfo.FontHandle[EFontHandle_Midium] = CreateFontToHandle(NULL, FONTHANDLE_MIDIUM_SIZE, 8, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 2);
	g_SystemInfo.FontHandle[EFontHandle_Big] = CreateFontToHandle(NULL, FONTHANDLE_BIG_SIZE, 8, DX_FONTTYPE_ANTIALIASING_EDGE_8X8, -1, 2);

	for (i = 0; i < EFontHandle_Num; i++) {
		if (g_SystemInfo.FontHandle[i] == -1) {
			return false;
		}
	}

	g_SystemInfo.FadeOut = true;
	g_SystemInfo.Fade = false;
	g_SystemInfo.FadeOutRate = 1.0f;

	g_SystemInfo.FrameCounter = 0;
	g_SystemInfo.DispFrameCount = 0;

	Render *render = new Render;
	ISeen *tytle = new Seen_Tytle(render);
	bool Debug = seenController->AddTask(Scene::Title,tytle);
	seenController->Change(Scene::Title);

	return true;
}

static bool System_MainLoop() {
	int i;
	LONGLONG NowTime;
	SetDrawScreen(DX_SCREEN_BACK);

	g_SystemInfo.StepTime = MAX_DELTA_TIME;
	g_SystemInfo.PrevTime = GetNowHiPerformanceCount();
	g_SystemInfo.StepTime = 1;

	while (ProcessMessage() == 0) {
		if(seenController)
		//状態推移処理を行う回数分ループする
		for (i = 0; i < g_SystemInfo.StepNum; i++) {
			if (CheckHitKey(KEY_INPUT_ESCAPE) == 1 || g_SystemInfo.ExitGame) {
				g_SystemInfo.ExitGame = true;
				break;
			}
#ifdef _DEBUG

#endif // DEBUG
			if (!System_Step(g_SystemInfo.StepTime)) {
				return false;
			}
		}
		//ソフト終了
		if (g_SystemInfo.ExitGame) {
			break;
		}

		System_Render(g_SystemInfo.StepTime);

		//裏画面の内容を表画面に反映させる
		ScreenFlip();
		//現在時間を所得する
		NowTime = GetNowHiPerformanceCount();
		//前回所得した時間からの経過時間を算出
		g_SystemInfo.StepTime = (NowTime - g_SystemInfo.PrevTime) / 1000000.0f;

		//状態推移処理を行う回数を算出する
		g_SystemInfo.StepNum = (int)(g_SystemInfo.StepTime / MAX_DELTA_TIME);

		//状態推移処理を行う回数が0回の場合は1回にする
		if (g_SystemInfo.StepNum == 0) {
			g_SystemInfo.StepNum = 1;
		}
		else {
			//0回ではない場合は状態推移で進める時間を状態推移を行う回数で割る
			g_SystemInfo.StepTime /= g_SystemInfo.StepNum;

			//もし状態推移を行う回数が最大値を超えていたら最大値にする
			if (g_SystemInfo.StepNum > MAX_FRAME_NUM) {
				g_SystemInfo.StepNum = MAX_FRAME_NUM;
			}
		}

		//今回の時間を保存する
		g_SystemInfo.PrevTime = NowTime;

		//フレームレート計測用のカウントを1足す
		g_SystemInfo.FrameCounter++;

		//前回フレームカウントを更新してから1秒経過したら表示用フレームカウントを更新する
		if (NowTime - g_SystemInfo.BackDispFrameTime > 1000000) {
			//表示用フレームカウントを更新
			g_SystemInfo.DispFrameCount = g_SystemInfo.FrameCounter;
			//計測用フレームカウントを初期化
			g_SystemInfo.FrameCounter = 0;
			//表示用フレームカウントを更新した時間を更新
			g_SystemInfo.BackDispFrameTime = NowTime;
		}
		ClearDrawScreen();
	}
	//正常終了
	return true;
}

static void System_Terminate() {
	DxLib_End();
}

static bool System_Step(float Step) {
	seenController->MainUpdate(Step);
	return true;
}

void System_ExitGame() {

}




