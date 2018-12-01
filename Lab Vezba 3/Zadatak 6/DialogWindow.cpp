#include "DialogWindow.h"
#include <iostream>
using namespace std;


DialogWindow::DialogWindow(char* ime, unsigned int duzinaImena) : Window(ime, duzinaImena)
{
}


DialogWindow::~DialogWindow()
{
}

void DialogWindow::draw() {
	cout << "DialogWindow nacrtan" << endl;
}

short DialogWindow::confirm() {
	this->close();
	return 1;
}

short DialogWindow::cancel() {
	this->close();
	return 0;
}

