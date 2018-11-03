#include "String.h"

String::String() {
	this->duzinaStringa = 0;
	this->bafer = new char;
}

String::String(unsigned int duzinaStringa) {
	this->duzinaStringa = duzinaStringa;
	this->bafer = new char[duzinaStringa];
}

String::String(const String& stringZaKopiranje) : String::String(stringZaKopiranje.duzinaStringa) {
	for (unsigned int i = 0; i < stringZaKopiranje.duzinaStringa; i++) {
		this->bafer[i] = stringZaKopiranje.bafer[i];
	}
	this->bafer[this->duzinaStringa] = 0; //ako stringZaKopiranje nema '\0' na kraju
}

String::~String() {
	if (bafer != 0) { //!= 0
		delete[] this->bafer;
	}
}

int String::pozicijaPodstringa(const String& podstring) {
	unsigned int pronadjenoKaraktera = 0;
	for (unsigned int i = 0; i < this->duzinaStringa; i++) {
		if (this->bafer[i] == podstring.bafer[pronadjenoKaraktera]) {
			pronadjenoKaraktera++;
		} else {
			pronadjenoKaraktera = 0;
		}

		if (pronadjenoKaraktera == podstring.duzinaStringa-1) {
			return i - (pronadjenoKaraktera - 1);
		}
	}
	return -1; //podstring nije pronadjen, invalidna pozicija 
}

void String::ucitajStringIzFajla(FILE* fajl) {	//pretpostavljamo da fajl ima bar isto karaktera kolika je i duzinaStringa
	for (unsigned int i = 0; i < this->duzinaStringa; i++) {
		char karakter;
		fscanf(fajl, "%c", &karakter);
		this->bafer[i] = karakter;
	}
	this->bafer[this->duzinaStringa-1] = '\0'; //ako u fajlu za poslednju vrednost u nizu karaktera ne postavimo null karakter
}

void String::prikaziString() {
	for (unsigned int i = 0; i < this->duzinaStringa; i++) {
		printf("%c", this->bafer[i]);
	}
}

void String::setBafer(const char* string) {
	for (unsigned int i = 0; i < this->duzinaStringa; i++) {
		this->bafer[i] = string[i];
	}
	this->bafer[this->duzinaStringa-1] = '\0';
}