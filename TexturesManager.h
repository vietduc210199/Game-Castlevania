#pragma once
#include "define.h"
#include "TexturesManager.h"

class TexturesManager
{
private:
	static TexturesManager * __instance;
	CTextures* textures = CTextures::GetInstance();

public:
	static TexturesManager* GetInstance();
	
	TexturesManager();
	~TexturesManager() {};
	CTextures* Gettextures();
};

