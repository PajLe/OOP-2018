#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

class Minesweeper
{
private:
	bool** minskoPolje;
	short visina;
	short sirina;
	static const short DEFAULT_DIMENZIJA = 10;

	void obrisiRed(short kojiRed);			//brise red
	void pomeriKolonuNaLevo(short odKojeKolone);	//"brise" kolonu
public:
	Minesweeper();
	Minesweeper(short visina, short sirina);
	~Minesweeper();

	inline short getVisina() { return this->visina; }
	inline short getSirina() { return this->sirina; }
	short brojMinaKojeOkruzujuDatoPolje(short x, short y); // gornja leva tacka x = 0, y = 0;
														   // x - horizontalna osa, y - vertikalna osa
	void ucitajMinskoPolje(FILE* rasporedMina);
	void prikaziMinskoPolje();
	void formatiraj();									   //brise sve kolone i redove koji ne sadrze ni jednu minu
	
	//LV2
	void pomeriMineDesno();								   //jedno mesto na desno
	void pomeriMineDole();								   //jedno mesto na dole
	void pomeriMineLevo();								   //jedno mesto na levo
	void pomeriMineGore();								   //jedno mesto na gore
	void svakoNtoPoljeZameniMinom(unsigned short N);	   //svako N-to polje zameni minom
	friend ostream& operator<<(ostream& izlaz, const Minesweeper& a);	
	friend istream& operator>>(istream& ulaz, const Minesweeper& a);

	
};

