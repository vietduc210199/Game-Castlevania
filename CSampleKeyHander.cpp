#include "CSampleKeyHander.h"

void CSampleKeyHander::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
	{
		if(!simon->isjumping())
			simon->SetState(SIMON_STATE_JUMP);
		break;
	}		
	case DIK_A: // reset
		simon->SetState(SIMON_STATE_IDLE);
		simon->SetPosition(50.0f, 0.0f);
		simon->SetSpeed(0, 0);
		break;
	}
}

void CSampleKeyHander::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
}

void CSampleKeyHander::KeyState(BYTE* states)
{
	// disable control key when Mario die 
	if (simon->GetState() == SIMON_STATE_DIE) return;

	if (game->IsKeyDown(DIK_RIGHT))
	{
		simon->SetSpeed(SIMON_WALKING_SPEED, simon->vy);
		if (!simon->isjumping())
			simon->SetState(SIMON_STATE_WALKING_RIGHT);
	}			
	else if (game->IsKeyDown(DIK_LEFT))
	{
		simon->SetSpeed(-SIMON_WALKING_SPEED, simon->vy);
		if (!simon->isjumping())
			simon->SetState(SIMON_STATE_WALKING_LEFT);
	}			
	else
		simon->SetState(SIMON_STATE_IDLE);		
}