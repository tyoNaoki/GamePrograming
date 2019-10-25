#pragma once
#include <string>

using namespace std;

typedef struct {
	int R = 255;
	int G = 255;
	int B = 255;
}Color_t;


typedef struct {

	int x = 0;
	int y = 0;

	string str;

	Color_t Color;
}Layer;

class UI
{
public:
	UI();
	virtual ~UI();
};

