#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Window
{
private:
	char* title;
	bool state;
public:
	Window(char* ime, unsigned int duzinaImena);
	~Window();

	virtual void draw();
	
	inline void open() { state = true; }
	inline void close() { state = false; }
	inline char* getTitle() {
		return title;
	}
	friend ostream& operator<<(ostream& izlaz, const Window& prozor);
};

