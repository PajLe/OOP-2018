#include "Window.h"
#include <string.h>
#include <iostream>
using namespace std;


Window::Window(char* ime, unsigned int duzinaImena)
{
	title = new char[duzinaImena+1];
	title = _strdup(ime);
	state = false;
}


Window::~Window()
{
	delete title;
}

void Window::draw() {
	puts(title);
	cout << "stanje " << state << endl;
}

ostream& operator<<(ostream& izlaz, const Window& prozor) {
	izlaz << prozor.title;
	return izlaz;
}