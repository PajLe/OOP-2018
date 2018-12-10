#include "BitskiHeroj.h"
#include <iostream>


BitskiHeroj::BitskiHeroj(const char* ime, int vekRodjenja) : Heroj(ime, vekRodjenja)
{
}


BitskiHeroj::~BitskiHeroj()
{
}

void BitskiHeroj::dodajZadatak(Zadatak& quest) {
	if (quest.getStepenTezine() == 0 || quest.getStepenTezine() == 1)
		if (brojDodeljenihZadataka < BROJ_ZADATAKA)
			zadaci[brojDodeljenihZadataka++] = &quest;
}

void BitskiHeroj::prikaz() {
	std::cout << ime << " " << vekRodjenja << " " << brojDodeljenihZadataka << std::endl;
}