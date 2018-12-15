#include "FileSystemElement.h"
#include <string.h>


FileSystemElement::FileSystemElement()
{
	ime = new char;
	ekstenzija = new char;
	roditeljski = nullptr;
	std::cout << "default constr";
}

FileSystemElement::FileSystemElement(char* ime) {
	this->ime = _strdup(ime);
	roditeljski = nullptr;
}

FileSystemElement::FileSystemElement(char* ime, char* ekstenzija) {
	this->ime = _strdup(ime);
	this->ekstenzija = _strdup(ekstenzija);
	roditeljski = nullptr;
}

FileSystemElement::~FileSystemElement()
{
	if (ime != 0) {
		delete[] ime;
		ime = 0;
	}

	if (ekstenzija != 0) {
		delete[] ekstenzija;
		ekstenzija = 0;
	}
}


