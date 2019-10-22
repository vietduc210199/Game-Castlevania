#pragma once
#include "GameObject.h"


#define SIMON_WALKING_SPEED		0.1f 
//0.1f
#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_JUMP_DEFLECT_SPEED 0.2f
#define SIMON_GRAVITY			0.002f
#define SIMON_DIE_DEFLECT_SPEED	 0.5f

#define SIMON_STATE_IDLE			0
#define SIMON_STATE_WALKING_RIGHT	100
#define SIMON_STATE_WALKING_LEFT	200
#define SIMON_STATE_JUMP			300
#define SIMON_STATE_DIE				400

#define SIMON_ANI_IDLE_RIGHT		0
#define SIMON_ANI_IDLE_LEFT			1

#define SIMON_ANI_WALKING_RIGHT		2
#define SIMON_ANI_WALKING_LEFT		3

#define SIMON_ANI_DIE				8

#define SIMON_BBOX_WIDTH  32
#define SIMON_BBOX_HEIGHT 62

#define SIMON_UNTOUCHABLE_TIME 5000

class Simon : public CGameObject
{
	int state;
	int untouchable;
	DWORD untouchable_start;
public:
	Simon() : CGameObject()
	{
		state = SIMON_ANI_IDLE_RIGHT;
		untouchable = 0;
	}
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};

