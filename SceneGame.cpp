#include "SceneGame.h"

SceneGame* SceneGame::__instance = NULL;

SceneGame::SceneGame(CGame* game, CSimon* simon)
{
	this->game = game;
	this->simon = simon;
}

SceneGame* SceneGame::GetInstance(CGame* game, CSimon* simon)
{
	if (__instance == NULL) __instance = new SceneGame(game, simon);
	return __instance;
}


void SceneGame::Loadresources()
{
	CAnimations* animations = CAnimations::GetInstance();

	AnimationManager* aniManager = AnimationManager::GetInstance();
	animations = aniManager->getAnimations();

	simon->AddAnimation(400);		// idle right
	simon->AddAnimation(401);		// idle left

	simon->AddAnimation(500);		// walk right
	simon->AddAnimation(501);		// walk left

	simon->AddAnimation(2000);		// jump right
	simon->AddAnimation(2010);		// jump left


	simon->SetPosition(50.0f, 0);
	objects.push_back(simon);


	for (int i = 0; i < 48; i++)
	{
		CBrick* brick = new CBrick();
		brick->AddAnimation(601);
		brick->SetPosition(-220.0f + i * 32.0f, 270);
		objects.push_back(brick);
	}
	
	cam = new camera(simon);

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
		
		game->Draw(-220.0f, -50.0f, TexturesManager::GetInstance()->Gettextures()->Get(ID_TEX_MAP1), 0, 0, 1535, 383);
		for (int i = 0; i < objects.size(); i++)
			objects[i]->Render();

		spriteHandler->End();
		d3ddv->EndScene();
	}


	d3ddv->Present(NULL, NULL, NULL, NULL);
}


