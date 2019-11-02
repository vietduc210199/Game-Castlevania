#include <algorithm>
#include "debug.h"

#include "Simon.h"
#include "Game.h"

#include "Goomba.h"

void CSimon::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down
	vy += SIMON_GRAVITY*dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	// turn off collision when die 
	if (state!=SIMON_STATE_DIE)
		CalcPotentialCollisions(coObjects, coEvents);

	// reset untouchable timer if untouchable time has passed
	if ( GetTickCount() - untouchable_start > SIMON_UNTOUCHABLE_TIME) 
	{
		untouchable_start = 0;
		untouchable = 0;
	}

	// No collision occured, proceed normally
	if (coEvents.size()==0)
	{
		
		x += dx;
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += min_tx*dx + nx*0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty*dy + ny*0.4f;
		
		if (nx!=0) vx = 0;
		if (ny != 0)
		{
			jumping = false;
			vy = 0;
			if(vx == 0)
				if (isjumping())
				{
					this->SetPosition(x , y + 14);
					SetState(SIMON_STATE_IDLE);
					
				}
		}
			
		// Collision logic with Goombas
		//for (UINT i = 0; i < coEventsResult.size(); i++)
		//{
		//	LPCOLLISIONEVENT e = coEventsResult[i];

		//	if (dynamic_cast<CGoomba *>(e->obj)) // if e->obj is Goomba 
		//	{
		//		CGoomba *goomba = dynamic_cast<CGoomba *>(e->obj);

		//		// jump on top >> kill Goomba and deflect a bit 
		//		if (e->ny < 0)
		//		{
		//			if (goomba->GetState()!= GOOMBA_STATE_DIE)
		//			{
		//				goomba->SetState(GOOMBA_STATE_DIE);
		//				vy = -MARIO_JUMP_DEFLECT_SPEED;
		//			}
		//		}
		//		else if (e->nx != 0)
		//		{
		//			if (untouchable==0)
		//			{
		//				if (goomba->GetState()!=GOOMBA_STATE_DIE)
		//				{
		//					if (level > MARIO_LEVEL_SMALL)
		//					{
		//						level = MARIO_LEVEL_SMALL;
		//						StartUntouchable();
		//					}
		//					else 
		//						SetState(SIMON_STATE_DIE);
		//				}
		//			}
		//		}
		//	}
		//}
	}

	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void CSimon::Render()
{
	int ani;
	if (state == SIMON_STATE_DIE)
	{

	}
	else
	{
		if (isjumping())
			if (nx > 0) ani = SIMON_ANI_JUMP_RIGHT;
			else ani = SIMON_ANI_JUMP_LEFT;
		else
		if (state == SIMON_STATE_IDLE)
		{
			if (nx > 0) ani = SIMON_ANI_IDLE_RIGHT;
			else ani = SIMON_ANI_IDLE_LEFT;
		}
		else switch (state)
		{
		case SIMON_STATE_WALKING_LEFT:
			ani = SIMON_ANI_WALKING_LEFT;
			break;
		case SIMON_STATE_WALKING_RIGHT:
			ani = SIMON_ANI_WALKING_RIGHT;
			break;
		}	
	}

	int alpha = 255;
	if (untouchable) alpha = 128;
	animations[ani]->Render(x, y, alpha);

	RenderBoundingBox();
}

void CSimon::SetState(int state)
{
	

	switch (state)
	{
	case SIMON_STATE_WALKING_RIGHT:
		jumping = false;
		nx = 1;
		break;
	case SIMON_STATE_WALKING_LEFT:
		jumping = false;
		nx = -1;
		break;
	case SIMON_STATE_JUMP:
		vy = -SIMON_JUMP_SPEED_Y;
		jumping = true;
		break;
	case SIMON_STATE_IDLE:
		//if (this->GetState() == SIMON_STATE_JUMP) y += 14;
		vx = 0;
		break;
	case SIMON_STATE_DIE:
		break;
	}

	CGameObject::SetState(state);
}

void CSimon::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y; 

	if (isjumping())
	{
		right = x + SIMON_JUMP_WIDTH;
		bottom = y + SIMON_JUMP_HEIGHT;
	}
	else
	{
		right = x + SIMON_BBOX_WIDTH;
		bottom = y + SIMON_BBOX_HEIGHT;
	}

	
}

