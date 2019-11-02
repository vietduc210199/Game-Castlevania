#pragma once
#include "define.h"

class camera
{
private:
	float cx;
	float cy;
	CSimon* simon;
public:
	camera(CSimon* simon) { this->simon = simon; cx = 0; cy = 0; };
	~camera() {};
	void setCameraPos();
	float getCameraPosX();
	float getCameraPosY();
};

