#pragma once
#include "define.h"

class CSampleKeyHander: public CKeyEventHandler
{
private:
	CSimon* simon;
	CGame* game;
public:
	CSampleKeyHander(CSimon* simon, CGame* game) { this->simon = simon; this->game = game; };
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	~CSampleKeyHander() {};
};
