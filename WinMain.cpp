#include <DxLib.h>

#define SCREEN_MAX_X_SIZE 1200
#define SCREEN_MAX_Y_SIZE 800
#define PI 3.141492654

enum Direction
{
	DOWN = 0,
	LEFT,
	UP,
	RIGHT,
};

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR IpCmdLine,int nCmdShow){
	SetGraphMode(1200, 800, 32); ChangeWindowMode(TRUE),SetDrawScreen(DX_SCREEN_BACK); // �E�B���h�E���[�h�ɐݒ�
	int model1, anim_nutral,anim_run,attachidx,rootflm;
	float anim_totaltime, playtime = 0.0f;
	bool running = FALSE;
	VECTOR pos = VGet(600.0f, 300.0f, -400.0f);
	VECTOR cpos = VGet(600.0f, 600.0f, -400.0f), ctgt = VGet(600.0f, 300.0f, -400.0f);
	int key;
	Direction direction = DOWN;
	MATRIX mat1, mat2;

	if (DxLib_Init() == -1)return -1;

	//�����������

	//���f���ǂݍ���
	model1 = MV1LoadModel("Data\\Character\\Player\\PC.mv1");
	if (model1 == -1)return -1;
	anim_nutral = MV1LoadModel("Data\\Character\\Player\\Anim_Neutral.mv1");
	if (anim_nutral == -1)return -1;
	anim_run = MV1LoadModel("Data\\Character\\Player\\Anim_Run.mv1");
	if (anim_run == -1)return -1;
	attachidx = MV1AttachAnim(model1, 0, anim_nutral);
	anim_totaltime = MV1GetAttachAnimTotalTime(model1, attachidx);
	rootflm = MV1SearchFrame(model1,"root");
	MV1SetFrameUserLocalMatrix(model1, rootflm, MGetIdent());
	
	//Camera�ݒ�
	SetCameraPositionAndTargetAndUpVec(cpos, ctgt, VGet(0.0f, 0.0f, 1.0f));

	//while(����ʂ�\��ʂɔ��f,���b�Z�[�W����, ��ʃN���A)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && CheckHitKey(KEY_INPUT_ESCAPE)==0) {
		//�A�j���[�V�����i�s
		playtime += 0.5f;
		if (playtime > anim_totaltime)playtime = 0.0f;
		MV1SetAttachAnimTime(model1, attachidx,playtime);

		key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		switch (key)
		{
		case PAD_INPUT_DOWN:
			pos.z -= 4.0f;
			direction = DOWN;
			break;
		case PAD_INPUT_UP:
			pos.z += 4.0f;
			direction = UP;
			break;
		case PAD_INPUT_LEFT:
			pos.x -= 4.0f;
			direction = LEFT;
			break;
		case  PAD_INPUT_RIGHT:
			pos.x += 4.0f;
			direction = RIGHT;
			break;
		default:
			break;
		}

		if (key == 0) {
			if (running == true) {
				running = false;
				MV1DetachAnim(model1, attachidx);
				attachidx = MV1AttachAnim(model1, 0, anim_nutral);
				anim_totaltime = MV1GetAttachAnimTotalTime(model1, attachidx);
			}
		}
		else
		{
			if (running == false) {
				running = true;
				MV1DetachAnim(model1, attachidx);
				attachidx = MV1AttachAnim(model1, 0, anim_run);
				anim_totaltime = MV1GetAttachAnimTotalTime(model1, attachidx);
			}
		}

	ClearDrawScreen();
	DrawBox(0, 0, 1200, 800, GetColor(255, 255, 255),TRUE) ;

	MV1SetRotationXYZ(model1, VGet(0.0f, 1.57f * direction, 0.0f));
	MV1SetPosition(model1, pos);
	MV1DrawModel(model1);
	
	ScreenFlip();
	}

    DxLib_End();    // DX���C�u�����I������

	return 0;
}