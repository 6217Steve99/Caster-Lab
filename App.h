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
	~App();
private:
	void DoFrame();
private:
	Window wnd;
	CasterTimer timer;
	std::vector<std::unique_ptr<class Box>> boxes;
};