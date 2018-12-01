#include "Window.h"
#include "DialogWindow.h"
#include "DocumentWindow.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;


#define VELICINA 2018

void sortirajPoImenu(Window** prozori) {
	bool promena = true;
	while (promena) {
		promena = false;
		for (unsigned int i = 0; i < VELICINA-1; i++) {
			if (strcmp(prozori[i]->getTitle(), prozori[i + 1]->getTitle()) < 0) {
				Window* prozor = prozori[i];
				prozori[i] = prozori[i + 1];
				prozori[i + 1] = prozor;
				promena = true;
			}
		}
	}
}

int main() {
	Window** prozori = new Window*[VELICINA];

	//Unos Dialog
	for (unsigned int i = 0; i < VELICINA / 2; i++) {
		char* ime = new char[13];
		strcpy(ime, "DialogWindow");
		prozori[i] = new DialogWindow(ime, strlen(ime));
	}

	//Unos Document
	for (unsigned int i = VELICINA / 2; i < VELICINA; i++) {
		char* ime = new char[15];
		strcpy(ime, "DocumentWindow");
		prozori[i] = new DocumentWindow(ime, strlen(ime));
	}

	//Test Document
	char* ime = new char[10];
	strcpy(ime, "abcdefghi");
	DocumentWindow* a = new DocumentWindow(ime, strlen(ime));
	a->open();
	a->close();
	a->draw();
	
	//Test Dialog
	DialogWindow* b = new DialogWindow(ime, strlen(ime));
	b->draw();
	b->open();
	b->close();
	cout << b->cancel() << endl;
	cout << b->confirm() << endl;

	//Test Window
	Window* c = new Window(ime, strlen(ime));
	c->draw();
	c->open();
	c->draw();
	c->close();
	c->draw();

	// fact: DocumentWindow > DialogWindow
	sortirajPoImenu(prozori);
	ofstream out("niz.txt");
	if (out.good()) {
		for (unsigned int i = 0; i < VELICINA; i++) {
			out << *prozori[i] << endl;
		}
	}
	
	
	delete a;
	delete b;
	for (unsigned int i = 0; i < VELICINA; i++) {
		delete prozori[i];
	}
	delete[] prozori;
	return 0;
}