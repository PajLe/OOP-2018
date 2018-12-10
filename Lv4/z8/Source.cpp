#include "Heroj.h"
#include "Zadatak.h"
#include "MitskiHeroj.h"
#include "BitskiHeroj.h"
#include <string.h>
#include <iostream>

int main() {
	Heroj** heroji20 = new Heroj*[20];
	short n = 2;
	for (unsigned int i = 0; i < 20; i++) {
		if (i % 2 == 0) {
			heroji20[i] = new MitskiHeroj("micki", i - 3, i, n+=2); //proizvoljno izabrane zavisnosti od 'i' i 'n'
		} else {													//eventualno bi bilo bolje ucitavanje iz fajla
			heroji20[i] = new BitskiHeroj("bicki", i + 3);			//proizvoljno izabrane zavisnosti od 'i'
		}
		heroji20[i]->prikaz();
	}
	std::cout << "----------------------" << std::endl;

	Zadatak** zadaci30 = new Zadatak*[30];
	for (unsigned int i = 0; i < 30; i++) {
		zadaci30[i] = new Zadatak();
		zadaci30[i]->postaviKodAndStepenTezine(i, (i + 2) / 3);		//proizvoljno izabrane zavisnosti od 'i'
	}
	
	for (unsigned int j = 0; j < 20; j++) {
		for (unsigned int i = 0; i < 30; i++) {
			heroji20[j]->dodajZadatak(*zadaci30[i]);
		}
	}

	for (unsigned int i = 0; i < 20; i++) {
		if (heroji20[i]->getBrojDodeljenihZadataka() > 3)
			heroji20[i]->prikaz();
	}
	
	for (unsigned int i = 0; i < 30; i++) {
		delete zadaci30[i];
	}
	delete[] zadaci30;
	for (unsigned int i = 0; i < 20; i++) {
		delete heroji20[i];
	}
	delete[] heroji20;
	return 0;
}