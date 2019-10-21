#pragma once
#include "define.h"

class camera
{
private:
	float cx;
	float cy;
	CMario* mario;
public:
	camera(CMario* mario) { this->mario = mario; cx = 0; cy = 0; };
	~camera() {};
	void setCameraPos();
	float getCameraPosX();
	float getCameraPosY();
};

