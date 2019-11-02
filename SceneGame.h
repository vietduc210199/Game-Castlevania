#pragma once
#include "define.h"
#include "AnimationManager.h"
#include "camera.h"

class SceneGame
{
private: 
	static SceneGame* __instance;

	camera* cam;
	CGame* game;
	CSampleKeyHander* keyHandler;

	CSimon* simon;
	CGoomba* goomba;

	vector<LPGAMEOBJECT> objects;

public:
	SceneGame(CGame* game, CSimon* simon);
	~SceneGame() {};
	void Loadresources();
	void Update(DWORD dt);
	void Render();

	static SceneGame* GetInstance(CGame* game, CSimon* simon);
};

