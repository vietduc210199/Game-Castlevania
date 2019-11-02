#pragma once
#include "GameObject.h"


#define SIMON_WALKING_SPEED		0.1f 
//0.1f
#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_GRAVITY			0.002f

#define SIMON_STATE_IDLE			0
#define SIMON_STATE_WALKING_RIGHT	100
#define SIMON_STATE_WALKING_LEFT	200
#define SIMON_STATE_JUMP			300
#define SIMON_STATE_DIE				400

#define SIMON_ANI_IDLE_RIGHT		0
#define SIMON_ANI_IDLE_LEFT			1

#define SIMON_ANI_WALKING_RIGHT			2
#define SIMON_ANI_WALKING_LEFT			3

#define SIMON_ANI_JUMP_RIGHT        4
#define SIMON_ANI_JUMP_LEFT         5


#define SIMON_BBOX_WIDTH  32
#define SIMON_BBOX_HEIGHT 62

#define SIMON_JUMP_WIDTH   32
#define SIMON_JUMP_HEIGHT  48


#define SIMON_UNTOUCHABLE_TIME 5000


class CSimon : public CGameObject
{
	bool jumping;
	bool grounded;
	int untouchable;
	DWORD untouchable_start;
public: 
	CSimon() : CGameObject()
	{
		grounded = false;
		jumping = false;
		untouchable = 1;
	}
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void StartUntouchable() { untouchable = 1; untouchable_start = GetTickCount(); }

	bool isjumping()
	{
		return jumping;
	}

	bool isgrounded()
	{
		return grounded;
	}

	void makejump()
	{
		vy = -SIMON_JUMP_SPEED_Y;
		jumping = true;
	}

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};