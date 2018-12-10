#include "MitskiHeroj.h"
#include <iostream>


MitskiHeroj::MitskiHeroj(const char* ime, int vekRodjenja, int brojMitova, int minTezinaZadatka) : Heroj(ime, vekRodjenja)
{
	this->brojMitova = brojMitova;
	this->minTezinaZadatka = minTezinaZadatka;
}


MitskiHeroj::~MitskiHeroj()
{
}

void MitskiHeroj::dodajZadatak(Zadatak& quest) {
	if (quest.getStepenTezine() >= this->minTezinaZadatka)
		if (brojDodeljenihZadataka < BROJ_ZADATAKA)
			zadaci[brojDodeljenihZadataka++] = &quest;
}

void MitskiHeroj::prikaz() {
	std::cout << ime << " " << vekRodjenja << " " << brojDodeljenihZadataka <<
		" mit:" << brojMitova<< " minTezina: "<< minTezinaZadatka << std::endl;
}