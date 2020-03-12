#pragma once
#include "Window.h"
#include "CasterTimer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	CasterTimer timer;
};