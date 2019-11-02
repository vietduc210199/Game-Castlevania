#include "AnimationManager.h"

AnimationManager* AnimationManager::__instance = NULL;

AnimationManager* AnimationManager::GetInstance()
{
	if (__instance == NULL) __instance = new AnimationManager();
	return __instance;
}

AnimationManager::AnimationManager()
{
	SpritesManager* spritesManager = SpritesManager::GetInstance();

	sprites = spritesManager->getSprites();

	LPANIMATION ani;
	//-----------SIMON---------------
	ani = new CAnimation(100);	// idle right
	ani->Add(10001);
	animations->Add(400, ani);

	ani = new CAnimation(100);	// idle left
	ani->Add(10011);
	animations->Add(401, ani);

	ani = new CAnimation(100);	// walk right
	ani->Add(10001);
	ani->Add(10002);
	ani->Add(10003);
	animations->Add(500, ani);

	ani = new CAnimation(100);	// walk left
	ani->Add(10011);
	ani->Add(10012);
	ani->Add(10013);
	animations->Add(501, ani);

	ani = new CAnimation(300);	// jump right
	ani->Add(100040);
	ani->Add(100041);
	ani->Add(100042);
	ani->Add(100043);
	ani->Add(100043);
	ani->Add(100043);
	ani->Add(100043);
	ani->Add(100043);
	ani->Add(100043);
	animations->Add(2000, ani);

	ani = new CAnimation(300);	// jump left
	ani->Add(100140);
	ani->Add(100141);
	ani->Add(100142);
	ani->Add(100143);
	animations->Add(2010, ani);



	//-------------------------------
	ani = new CAnimation(100);		// brick
	ani->Add(20001);
	animations->Add(601, ani);

	ani = new CAnimation(300);		// Goomba walk
	ani->Add(30001);
	ani->Add(30002);
	animations->Add(701, ani);

	ani = new CAnimation(1000);		// Goomba dead
	ani->Add(30003);
	animations->Add(702, ani);
}

CAnimations* AnimationManager::getAnimations()
{
	return animations;
}
