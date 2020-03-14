#pragma once
#include "Window.h"
#include "CasterTimer.h"
#include "CasterException.h"

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