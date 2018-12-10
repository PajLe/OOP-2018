#include "FileSystemElement.h"
#include <string.h>


FileSystemElement::FileSystemElement()
{
	ime = new char;
	ekstenzija = new char;
}

FileSystemElement::FileSystemElement(char* ime) {
	this->ime = new char[strlen(ime)+1];
	strcpy(this->ime, ime);
	this->ekstenzija = new char;
}

FileSystemElement::FileSystemElement(char* ime, char* ekstenzija) {
	this->ime = new char[strlen(ime)+1];
	strcpy(this->ime, ime);
	this->ekstenzija = new char[strlen(ekstenzija)+1];
	strcpy(this->ekstenzija, ekstenzija);
}

FileSystemElement::~FileSystemElement()
{
	if (ime != nullptr) {
		delete[] ime;
		ime = 0;
	}

	if (ekstenzija != nullptr) {
		delete[] ekstenzija;
		ekstenzija = 0;
	}
}

void FileSystemElement::postaviRoditeljskiElement(FileSystemElement* element) {
	roditeljski = element;
}

