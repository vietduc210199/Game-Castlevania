#include "camera.h"

void camera::setCameraPos()
{
	float cx, cy;
	simon->GetPosition(cx, cy);

	cx -= SCREEN_WIDTH / 8;
	cy -= SCREEN_HEIGHT / 2;

	if (cx < -220.0f) cx = -220.0f;
	else if (cx > 790.0f) cx = 790.0f;
	CGame::GetInstance()->SetCamPos(cx, 0.0f /*cy*/);
}

float camera::getCameraPosX()
{
	return cx;
}

float camera::getCameraPosY()
{
	return cy;
}
