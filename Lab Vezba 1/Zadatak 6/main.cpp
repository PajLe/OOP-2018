#include "Minesweeper.h"
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	//Minesweeper* a = new Minesweeper(3,3);
	Minesweeper* a = new Minesweeper();
	FILE* fajl = fopen("mine.txt", "r"); // poslednje dve cifre u fajlu predstavljaju koordinate
										 // za polje koje posmatramo

	a->ucitajMinskoPolje(fajl);			 //ucitava minsko polje dimenzija x,y / 10,10
	
	short pozicijaX, pozicijaY;
	fscanf(fajl, "%hd", &pozicijaX);
	fscanf(fajl, "%hd", &pozicijaY);

	/*
	a->prikaziMinskoPolje();
	a->formatiraj();
	a->prikaziMinskoPolje();
	*/
	
	short izabranoPolje = a->brojMinaKojeOkruzujuDatoPolje(pozicijaX, pozicijaY);
	if (izabranoPolje == -1) {
		a->prikaziMinskoPolje();
	}
	else {
		cout << izabranoPolje;
	}

	fclose(fajl);
	delete a;

	cin.get();
	return 0;
}