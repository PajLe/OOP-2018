#pragma once
#include "Window.h"
class DocumentWindow : public Window
{
public:
	DocumentWindow(char* ime, unsigned int duzinaImena);
	~DocumentWindow();
	void draw();
	
};

