#include <DxLib.h>
#include "System.h"

#define SCREEN_MAX_X_SIZE 1200
#define SCREEN_MAX_Y_SIZE 800
#define PI 3.141492654

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR IpCmdLine,int nCmdShow){
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	System_Main();

	return 0;
}