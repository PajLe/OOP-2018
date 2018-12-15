#include "Folder.h"
#include <string.h>
#include <iostream>


Folder::Folder(char* ime) : FileSystemElement(ime)
{
	ekstenzija = _strdup("");
	fsElementi = new FileSystemElement*[MAX_VELICINA];
	indexPrvogSlobodnogMesta = 0;

	//popunimo niz nullama
	for (unsigned short i = 0; i < MAX_VELICINA; i++) {	
		fsElementi[i] = 0;
	}
}


Folder::~Folder()
{
	//brise "niz pointera", a sami "pointeri" se brisu u main-u
	if (fsElementi != 0) {
		delete[] fsElementi;
		fsElementi = 0;
	}
}

char* Folder::punoIme() {
	unsigned short duzina = 0;
	char* roditeljskiPunoIme = 0;  //da ne bismo vise puta pozivali funkciju punoIme()

	//ako postoji roditeljski
	if (roditeljski) {
		roditeljskiPunoIme = roditeljski->punoIme();
		duzina += strlen(roditeljskiPunoIme);
		duzina += 2;
	}
	duzina += strlen(ime) + 2 + 1; //2 za "\\", 1 za '\0'
	char* pomocni = new char[duzina];

	strcpy(pomocni, "");
	if (roditeljski) {				//trebalo bi da moze i bez ove provere (sa strcat ce se nadovezati '\0')
		strcat(pomocni, roditeljskiPunoIme);
		strcat(pomocni, "\\");
	}
	strcat(pomocni, ime); 
	strcat(pomocni, "\\");
	pomocni[strlen(pomocni)] = '\0';
	return pomocni;
}

void Folder::dodajUfolder(FileSystemElement* fselement) { 
	fsElementi[indexPrvogSlobodnogMesta] = fselement;

	//trazimo prvi clan niza koji je jednak nulli (prazan, nema elemenata)
	//i postavljamo indexPrvogSlobodnogMesta na njega
	while (fsElementi[++indexPrvogSlobodnogMesta]);		

	fselement->postaviRoditeljskiElement(this);
}

void Folder::izbrisiIzFoldera(unsigned short index) {
	if (fsElementi[index]) {	//ako je niz prazan ili ne postoji taj element ne radimo nista
										//???provera ne radi ako je negde drugde(van klase) element postavljen na 0
		fsElementi[index]->postaviRoditeljskiElement(0);
		//delete fsElementi[index];    brise se u main
		fsElementi[index] = 0;
		indexPrvogSlobodnogMesta = index;
	}
}

void Folder::printList() {
	std::cout << "Hijerarhija foldera "<< this->ime << "\n"<< std::endl;
	for (unsigned short i = 0; i < indexPrvogSlobodnogMesta; i++) {
		if (fsElementi[i] != 0) {
			if (fsElementi[i]->isFile()) {
				std::cout << fsElementi[i]->punoIme() << std::endl;
			} else {
				fsElementi[i]->printList();
			}
		}
	}
}

void Folder::printFileList(){
	for (unsigned short i = 0; i < indexPrvogSlobodnogMesta; i++) {
		if (fsElementi[i] != 0) {
			if (fsElementi[i]->isFile()) {
				std::cout << fsElementi[i]->punoIme() << std::endl;
			}
		}
	}
}