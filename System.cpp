#include "System.h"
#include "DxLib.h"
#include "Mathematics.h"
#include "SeenController.h"
#include <Windows.h>

// �t�F�[�h�A�E�g�A�t�F�[�h�C���̑��x
#define FADE_SPEED			(1.0f)

// �P�t���[���̍ő厞��
#define MAX_DELTA_TIME		(1.0f / 120.0f)

// ��x�ɏ�������ő�t���[����
#define MAX_FRAME_NUM		(8)

// �ҏW�ł��鐮���p�����[�^�̍ő吔
#define DEBUG_INT_MAXNUM	(20)

static SystemInfo g_SystemInfo;

static bool System_MainLoop();

static bool System_Initialize();

static void System_Terminate();

static void System_FadeRender();

SeenController *seenController;

static void System_FadeStep(
	// ���ڂ����鎞��( �P�� : �b )
	float StepTime
)
{
	// �t�F�[�h�������s���Ă��邩�ǂ����̃t���O���|��Ă���ꍇ�͉��������I��
	if (!g_SystemInfo.Fade)
	{
		return;
	}

	// �t�F�[�h�A�E�g���̕ύX
	if (ParamChangeFloat( &g_SystemInfo.FadeOutRate,
		g_SystemInfo.FadeOut ? 1.0f : 0.0f, StepTime, FADE_SPEED))
	{
		// �l�̕ύX������������t�F�[�h�A�E�g���s���Ă��邩�ǂ����̃t���O��|��
		g_SystemInfo.Fade = false;
	}
}

bool System_Main() {

	seenController = new SeenController;

	if (!System_Initialize()) {
		delete seenController;

		return false;
	}

	if (!System_MainLoop()) {
		SetDrawScreen(DX_SCREEN_BACK);
	}

	System_Terminate();

	delete seenController;

	return true;
}

static bool System_Initialize()
{
	int i;
//	char FilePath[MAX_PATH];

	if (MessageBox(NULL, "�E�C���h�E���[�h�ŋN�����܂����H", "��ʃ��[�h�m�F", MB_YESNO) == IDYES) {
		ChangeWindowMode(TRUE);
	}

	if (MessageBox(NULL, "�Ꮘ�����׃��[�h�ŋN�����܂����H", "�������׃��[�h�m�F", MB_YESNO) == IDYES) {
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

	if (!System_StartTitle()) {
		return false;
	}

	g_SystemInfo.FrameCounter = 0;
	g_SystemInfo.DispFrameCount = 0;

	bool Debug = seenController->AddTask(CTask_Game);

	return true;
}

static bool System_MainLoop() {
	return false;
}

static void System_Terminate() {
	DxLib_End();
}

bool System_StartTitle() {
	return true;
}

void System_ExitGame() {

}







