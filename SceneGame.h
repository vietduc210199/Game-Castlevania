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

	CMario* mario;
	CGoomba* goomba;

	vector<LPGAMEOBJECT> objects;

public:
	SceneGame(CGame* game, CMario* mario);
	~SceneGame() {};
	void Loadresources();
	void Update(DWORD dt);
	void Render();

	static SceneGame* GetInstance(CGame* game, CMario* mario);
};

