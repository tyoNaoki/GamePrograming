#pragma once

#include "DxLib.h"

// �Q�[����ʂ̕�
#define GAME_SCREEN_WIDTH			(1280)

// �Q�[����ʂ̍���
#define GAME_SCREEN_HEIGHT			(720)

// ���t�H���g�̃T�C�Y
#define FONTHANDLE_SMALL_SIZE		(24)

// ���t�H���g�̃T�C�Y
#define FONTHANDLE_MIDIUM_SIZE		(32)

// ��t�H���g�̃T�C�Y
#define FONTHANDLE_BIG_SIZE			(80)

// �t�H���g�n���h��
typedef enum _EFontHandle
{
	EFontHandle_Small,		// ���t�H���g�n���h��
	EFontHandle_Midium,		// ���t�H���g�n���h��
	EFontHandle_Big,		// ��t�H���g�n���h��
	EFontHandle_Num			// �t�H���g�n���h���̐�
} EFontHandle;

typedef struct _SystemInfo
{
	//��O�̃t���[���̎���
	LONGLONG PrevTime;

	//��Ԑ��ڏ����Ő��ڂ����鎞��
	float StepTime;

	//1�t���[���ŏ�Ԑ��ڏ������s����
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

	// �t���[�����[�g�\���p�̃t���[���J�E���^
	int             FrameCounter;

	// �t���[�����[�g�\���ŕ\������t���[�����[�g
	int             DispFrameCount;



}SystemInfo;



extern bool System_Main();

extern void System_ExitGame();

extern bool System_StartTitle();
