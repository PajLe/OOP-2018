#include "Heroj.h"
#include <string.h>


Heroj::Heroj(const char* ime, int vekRodjenja)
{
	this->ime = _strdup(ime);
	this->vekRodjenja = vekRodjenja;
	zadaci = new Zadatak*[BROJ_ZADATAKA];
	brojDodeljenihZadataka = 0;
}


Heroj::~Heroj()
{
	if(this->ime != 0)
		delete[] this->ime;

	delete[] zadaci;

	//Konkretne zadatke brisemo tamo gde smo ih napravili(u main-u)
	//Ovde je potrebno samo obrisati niz pokazivaca, pa nam ovo ispod nije potrebno:
	/*for (unsigned int i = 0; i < brojDodeljenihZadataka; i++) {
		if(zadaci[i] != 0)
			delete zadaci[i];
	}*/
}

Heroj& Heroj::operator=(const Heroj& hero) {
	if (this == &hero)
		return *this;

	if (ime) delete[] ime;
	for (unsigned int i = 0; i < brojDodeljenihZadataka; i++) {
		if (zadaci[i] != 0)
			delete zadaci[i];
	}
	delete[] zadaci;

	this->ime = _strdup(hero.ime);
	this->vekRodjenja = hero.vekRodjenja;
	this->zadaci = new Zadatak*[BROJ_ZADATAKA];
	for (unsigned int i = 0; i < brojDodeljenihZadataka; i++) {
		this->zadaci[i] = hero.zadaci[i];
	}

	return *this;
}

Zadatak& Heroj::operator[](int index) {
	if(index >= 0 && index <BROJ_ZADATAKA)
		return *this->zadaci[index];
	return *(new Zadatak());
}