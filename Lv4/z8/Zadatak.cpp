#include "Zadatak.h"



Zadatak::Zadatak() //nevalidan zadatak
{
	kod = 0;
	stepenTezine = -1;
}


Zadatak::~Zadatak()
{
}

void Zadatak::postaviKodAndStepenTezine(int kod, int stepen) {
	setKod(kod);
	setStepenTezine(stepen);
}