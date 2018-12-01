#pragma once
#include "Window.h"
class DialogWindow : public Window
{
public:
	DialogWindow(char* ime, unsigned int duzinaImena);
	~DialogWindow();
	void draw();
	short confirm();
	short cancel();
	
};


