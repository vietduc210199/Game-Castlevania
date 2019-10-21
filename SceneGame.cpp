#include "SceneGame.h"

SceneGame* SceneGame::__instance = NULL;

SceneGame::SceneGame(CGame* game, CMario* mario)
{
	this->game = game;
	this->mario = mario;
}

SceneGame* SceneGame::GetInstance(CGame* game, CMario* mario)
{
	if (__instance == NULL) __instance = new SceneGame(game, mario);
	return __instance;
}


void SceneGame::Loadresources()
{
	CAnimations* animations = CAnimations::GetInstance();

	AnimationManager* aniManager = AnimationManager::GetInstance();
	animations = aniManager->getAnimations();

	mario->AddAnimation(400);		// idle right big
	mario->AddAnimation(401);		// idle left big
	mario->AddAnimation(402);		// idle right small
	mario->AddAnimation(403);		// idle left small

	mario->AddAnimation(500);		// walk right big
	mario->AddAnimation(501);		// walk left big
	mario->AddAnimation(502);		// walk right small
	mario->AddAnimation(503);		// walk left big

	mario->AddAnimation(599);		// die

	mario->SetPosition(50.0f, 0);
	objects.push_back(mario);

	for (int i = 0; i < 5; i++)
	{
		CBrick* brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(100.0f + i * 60.0f, 74.0f);
		objects.push_back(brick);

		brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(100.0f + i * 60.0f, 90.0f);
		objects.push_back(brick);

		brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(84.0f + i * 60.0f, 90.0f);
		objects.push_back(brick);
	}


	for (int i = 0; i < 30; i++)
	{
		CBrick* brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(0 + i * 16.0f, 150);
		objects.push_back(brick);
	}

	// and Goombas 
	for (int i = 0; i < 4; i++)
	{
		goomba = new CGoomba();
		goomba->AddAnimation(701);
		goomba->AddAnimation(702);
		//goomba->SetPosition(200 + i*60, 135);
		goomba->SetPosition(220.0f + i * 60, 60.0f);
		goomba->SetState(GOOMBA_STATE_WALKING);
		objects.push_back(goomba);
	}
	
	cam = new camera(mario);

}

void SceneGame::Update(DWORD dt)
{
	vector<LPGAMEOBJECT> coObjects;
	for (int i = 1; i < objects.size(); i++)
	{
		coObjects.push_back(objects[i]);
	}

	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}

	// Update camera to follow mario
	cam->setCameraPos();

}

void SceneGame::Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		for (int i = 0; i < objects.size(); i++)
			objects[i]->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}


	d3ddv->Present(NULL, NULL, NULL, NULL);
}


