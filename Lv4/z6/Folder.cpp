#include "Folder.h"
#include <string.h>
#include <iostream>

Folder::Folder(char* ime) : FileSystemElement(ime)
{
	strcpy(ekstenzija, "");
	fsElementi = new FileSystemElement*[MAX_VELICINA];
	indexPrvogSlobodnogMesta = indexPoslednjegSlobodnogMesta = 0;
	roditeljski = nullptr;
}


Folder::~Folder()
{
	for (unsigned short i = 0; i < indexPoslednjegSlobodnogMesta; i++) {
		this->izbrisiIzFoldera(i);
	}
	if (fsElementi != nullptr) {
		delete[] fsElementi;
		fsElementi = nullptr;
	}
}

char* Folder::punoIme() {
	char* pomocni = new char[1];
	strcpy(pomocni, "");
	
	if (roditeljski != nullptr) {
		strcat(pomocni, roditeljski->punoIme());
		strcat(pomocni, "\\");
	}
	strcat(pomocni, ime); 
	strcat(pomocni, "\\");
	return pomocni;
}


//ako se obrise vise od jednog elementa pre dodavanja novog, ne radi kako treba
void Folder::dodajUfolder(FileSystemElement* fselement) { 
	fsElementi[indexPrvogSlobodnogMesta] = fselement;
	indexPrvogSlobodnogMesta = ++indexPoslednjegSlobodnogMesta;
	fselement->postaviRoditeljskiElement(this);
}

void Folder::izbrisiIzFoldera(unsigned short index) {
	if (fsElementi[index] != nullptr) {	//ako je niz prazan ili ne postoji taj element ne radimo nista
										//provera ne radi ako je negde drugde(van klase) element postavljen na 0
		fsElementi[index]->postaviRoditeljskiElement(nullptr);
		//delete fsElementi[index];    brise se u main
		fsElementi[index] = nullptr;

		indexPrvogSlobodnogMesta = index;
		indexPoslednjegSlobodnogMesta--;
	}
}

void Folder::printList() {
	std::cout << this->ime;
	
	for (unsigned short i = 0; i < indexPoslednjegSlobodnogMesta; i++) {
		if (fsElementi[i] != nullptr) {
			std::cout << "\n";
			fsElementi[i]->printList();
		}
	}
}