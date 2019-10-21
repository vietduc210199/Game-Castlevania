#include "camera.h"

void camera::setCameraPos()
{
	float cx, cy;
	mario->GetPosition(cx, cy);

	cx -= SCREEN_WIDTH / 2;
	cy -= SCREEN_HEIGHT / 2;

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
