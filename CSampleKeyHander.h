#pragma once
#include "define.h"

class CSampleKeyHander: public CKeyEventHandler
{
private:
	CMario* mario;
	CGame* game;
public:
	CSampleKeyHander(CMario* mario, CGame* game) { this->mario = mario; this->game = game; };
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	~CSampleKeyHander() {};
};
