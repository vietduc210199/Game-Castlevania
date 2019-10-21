#pragma once
#include "define.h"
#include "SpritesManager.h"

class AnimationManager
{
private:
	CAnimations* animations = CAnimations::GetInstance();
	CSprites* sprites = CSprites::GetInstance();
	static AnimationManager* __instance;

public:
	static AnimationManager* GetInstance();

	AnimationManager();
	~AnimationManager() {};
	CAnimations* getAnimations();

};

