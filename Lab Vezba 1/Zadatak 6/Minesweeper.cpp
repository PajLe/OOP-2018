#include "Minesweeper.h"
#include <iostream>
using namespace std;


Minesweeper::Minesweeper(short visina, short sirina)
{
	this->visina = visina;
	this->sirina = sirina;
	if (visina <= 0 || sirina <= 0) { // invalidni unosi - resiti u main programu
		
	}

	this->minskoPolje = new bool*[visina];
	for (short i = 0; i < visina; i++) {
		minskoPolje[i] = new bool[sirina];
	}

}

Minesweeper::Minesweeper() : Minesweeper(Minesweeper::DEFAULT_DIMENZIJA, Minesweeper::DEFAULT_DIMENZIJA) {}



Minesweeper::~Minesweeper()
{
	for (short i = 0; i < this->visina; i++) {
		delete[] this->minskoPolje[i];
	}
	delete[] minskoPolje;

}

short Minesweeper::brojMinaKojeOkruzujuDatoPolje(short x, short y) {
	short brojMina = 0;
	if (this->minskoPolje[y][x] == true) {
		return -1;
	}
	for (short i = y - 1; i <= y + 1; i++) {
		for (short j = x - 1; j <= x + 1; j++) {
			if (i < 0 || i > this->visina - 1 || j < 0 || j > this->sirina - 1 || (i == y && j == x)) {
				continue;
			}
			if (minskoPolje[i][j] == true) {
				brojMina++;
			}
		}
	}
	return brojMina;
}

void Minesweeper::ucitajMinskoPolje(FILE* rasporedMina) { //FILE* fajl = fopen("imefajla","r");
	for (short i = 0; i < this->visina; i++) {
		for (short j = 0; j < this->sirina; j++) {
			int polje;

			if (feof(rasporedMina)) {
				return;
			}

			fscanf_s(rasporedMina, "%d", &polje);

			if (polje == 1) {
				this->minskoPolje[i][j] = true;
			}
			else if (polje == 0) {
				this->minskoPolje[i][j] = false;
			}
		}
	}
	
}

void Minesweeper::prikaziMinskoPolje() {
	for (short i = 0; i < this->visina; i++) {
		for (short j = 0; j < this->sirina; j++) {
			cout << ((this->minskoPolje[i][j]) ? ("*") : ("-")) << " ";
		}
		cout << endl;
	}
}

void Minesweeper::obrisiRed(short kojiRed) {
	for (short i = kojiRed; i < this->visina - 1; i++) {
		for (short j = 0; j < this->sirina; j++) {
			this->minskoPolje[i][j] = this->minskoPolje[i + 1][j];
		}
	}
	delete[] this->minskoPolje[visina - 1];
	this->visina--;
}

void Minesweeper::pomeriNaLevo(short odKojeKolone) {
	for (short j = odKojeKolone; j < this->sirina - 1; j++) {
		for (short i = 0; i < this->visina; i++) {
			this->minskoPolje[i][j] = this->minskoPolje[i][j + 1];
		}
	}
	this->sirina--;
}

void Minesweeper::formatiraj() {
	bool nemaMina;

	for (short i = 0; i < this->visina; i++) {
		nemaMina = true;
		for (short j = 0; j < this->sirina; j++) {
			if (this->minskoPolje[i][j] == true) { //ako pronadjemo minu u redu nemaMina postavljamo na false
				nemaMina = false;
			}
		}
		if (nemaMina == true) {					  //ako nema mina u celom redu, taj red treba obrisati
			this->obrisiRed(i);
			i--;								  //jer je sada novi red sa indexom i
		}
	}
	

	//isto to treba uraditi za kolone

	for (short j = 0; j < this->sirina; j++) {
		nemaMina = true;
		for (short i = 0; i < this->visina; i++) {
			if (this->minskoPolje[i][j] == true) {
				nemaMina = false;
			}
		}
		if (nemaMina) {
			this->pomeriNaLevo(j);
			j--;
		}
	}
	
}