#include "TexturesManager.h"

TexturesManager* TexturesManager::__instance = NULL;

TexturesManager* TexturesManager::GetInstance()
{
	if (__instance == NULL) __instance = new TexturesManager();
	return __instance;
}

TexturesManager::TexturesManager()
{
	CTextures* textures = CTextures::GetInstance();

	textures->Add(ID_TEX_MARIO, L"textures\\mario.png", D3DCOLOR_XRGB(255, 255, 255));
	//textures->Add(ID_TEX_MISC, L"textures\\misc.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_ENEMY, L"textures\\enemies.png", D3DCOLOR_XRGB(3, 26, 110));

	textures->Add(ID_TEX_BBOX, L"textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));

	textures->Add(ID_TEX_MAP1, L"Resources\\map\\map1.png", D3DCOLOR_XRGB(0, 0, 0));
	textures->Add(ID_TEX_BRICK, L"Resources\\ground\\2.png", D3DCOLOR_XRGB(0, 0, 0));
}

CTextures* TexturesManager::Gettextures()
{
	return textures;
}
