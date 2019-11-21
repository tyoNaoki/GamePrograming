#include "System.h"
#include "DxLib.h"
#include "Mathematics.h"
#include "SeenController.h"
#include <Windows.h>
#include "Seen_Tytle.h"


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

static void System_Render(float Step){
};

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
		//��Ԑ��ڏ������s���񐔕����[�v����
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
		//�\�t�g�I��
		if (g_SystemInfo.ExitGame) {
			break;
		}

		System_Render(g_SystemInfo.StepTime);

		//����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
		//���ݎ��Ԃ���������
		NowTime = GetNowHiPerformanceCount();
		//�O�񏊓��������Ԃ���̌o�ߎ��Ԃ��Z�o
		g_SystemInfo.StepTime = (NowTime - g_SystemInfo.PrevTime) / 1000000.0f;

		//��Ԑ��ڏ������s���񐔂��Z�o����
		g_SystemInfo.StepNum = (int)(g_SystemInfo.StepTime / MAX_DELTA_TIME);

		//��Ԑ��ڏ������s���񐔂�0��̏ꍇ��1��ɂ���
		if (g_SystemInfo.StepNum == 0) {
			g_SystemInfo.StepNum = 1;
		}
		else {
			//0��ł͂Ȃ��ꍇ�͏�Ԑ��ڂŐi�߂鎞�Ԃ���Ԑ��ڂ��s���񐔂Ŋ���
			g_SystemInfo.StepTime /= g_SystemInfo.StepNum;

			//������Ԑ��ڂ��s���񐔂��ő�l�𒴂��Ă�����ő�l�ɂ���
			if (g_SystemInfo.StepNum > MAX_FRAME_NUM) {
				g_SystemInfo.StepNum = MAX_FRAME_NUM;
			}
		}

		//����̎��Ԃ�ۑ�����
		g_SystemInfo.PrevTime = NowTime;

		//�t���[�����[�g�v���p�̃J�E���g��1����
		g_SystemInfo.FrameCounter++;

		//�O��t���[���J�E���g���X�V���Ă���1�b�o�߂�����\���p�t���[���J�E���g���X�V����
		if (NowTime - g_SystemInfo.BackDispFrameTime > 1000000) {
			//�\���p�t���[���J�E���g���X�V
			g_SystemInfo.DispFrameCount = g_SystemInfo.FrameCounter;
			//�v���p�t���[���J�E���g��������
			g_SystemInfo.FrameCounter = 0;
			//�\���p�t���[���J�E���g���X�V�������Ԃ��X�V
			g_SystemInfo.BackDispFrameTime = NowTime;
		}
		ClearDrawScreen();
	}
	//����I��
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




