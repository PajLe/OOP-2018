#include "DocumentWindow.h"
#include <iostream>
using namespace std;


DocumentWindow::DocumentWindow(char* ime, unsigned int duzinaImena) : Window(ime, duzinaImena)
{
}


DocumentWindow::~DocumentWindow()
{
}

void DocumentWindow::draw() {
	cout << "DocumentWindow nacrtan" << endl;
}

