#pragma once
#include "define.h"
#include "TexturesManager.h"

class SpritesManager
{
private:

	CSprites* sprites = CSprites::GetInstance();
	CTextures* textures = CTextures::GetInstance();
	static SpritesManager* __instance;

public:
	static SpritesManager* GetInstance();

	SpritesManager();
	~SpritesManager() {};
	CSprites* getSprites();

};

