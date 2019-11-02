#include "SpritesManager.h"

SpritesManager* SpritesManager::__instance = NULL;


SpritesManager* SpritesManager::GetInstance()
{
	if (__instance == NULL) __instance = new SpritesManager();
	return __instance;
}

SpritesManager::SpritesManager()
{
	TexturesManager* TexManager = TexturesManager::GetInstance();

	textures = TexManager->Gettextures();


	LPDIRECT3DTEXTURE9 texBrick = textures->Get(ID_TEX_BRICK);
	sprites->Add(20001, 0, 0, 32, 32, texBrick);

	LPDIRECT3DTEXTURE9 texEnemy = textures->Get(ID_TEX_ENEMY);
	sprites->Add(30001, 5, 14, 21, 29, texEnemy);
	sprites->Add(30002, 25, 14, 41, 29, texEnemy);

	sprites->Add(30003, 45, 21, 61, 29, texEnemy); // die sprite

	//Simon---------------------------

	LPDIRECT3DTEXTURE9 texSimonRight = textures->Get(ID_TEX_SIMON_RIGHT); //right
	sprites->Add(10001, 435, 2, 470, 65, texSimonRight);		// idle right

	sprites->Add(10002, 375, 2, 403, 65, texSimonRight);		// walk right
	sprites->Add(10003, 312, 2, 345, 65, texSimonRight);

		// jump right
	sprites->Add(100040, 195, 0, 228, 48, texSimonRight);
	sprites->Add(100041, 195, 0, 228, 48, texSimonRight);
	sprites->Add(100042, 195, 0, 228, 48, texSimonRight);
	sprites->Add(100043, 195, 0, 228, 48, texSimonRight);
	
	LPDIRECT3DTEXTURE9 texSimonLeft = textures->Get(ID_TEX_SIMON_LEFT); //left
	sprites->Add(10011, 11, 2, 45, 65, texSimonLeft); //idle left

	sprites->Add(10012, 76, 2, 103, 65, texSimonLeft); //walk left
	sprites->Add(10013, 133, 2, 168, 65, texSimonLeft);

		// jump left
	sprites->Add(100140, 250, 0, 285, 48, texSimonLeft);
	sprites->Add(100141, 250, 0, 285, 48, texSimonLeft);
	sprites->Add(100142, 250, 0, 285, 48, texSimonLeft);
	sprites->Add(100143, 250, 0, 285, 48, texSimonLeft);


}

CSprites* SpritesManager::getSprites()
{
	return sprites;
}
