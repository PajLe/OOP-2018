#include "Minesweeper.h"
using namespace std;

int main() {
	//Minesweeper* a = new Minesweeper(5,5);
	Minesweeper* a = new Minesweeper();
	FILE* fajl = fopen("mine.txt", "r"); // poslednje dve cifre u fajlu predstavljaju koordinate
										 // za polje koje posmatramo

	a->ucitajMinskoPolje(fajl);			 //ucitava minsko polje dimenzija x,y / 10,10

	cout << "polje:\n"<<*a;
	a->pomeriMineDesno();
	cout << "\npomerene mine na desno\n"<<*a;
	a->pomeriMineDole();
	cout << "\npomerene mine na dole\n" << *a;
	a->pomeriMineLevo();
	cout << "\npomerene mine na levo\n" << *a;
	a->pomeriMineGore();
	cout << "\npomerene mine na gore\n" << *a;


	//cin >> *a;

	//Testiranje funkcije formatiraj()
	/* 
	a->prikaziMinskoPolje();
	cout<<endl;
	a->formatiraj();
	a->prikaziMinskoPolje();
	*/
	// Testiranje funkcije pomeriMineDesno()
	/*a->prikaziMinskoPolje();
	cout << endl;
	a->pomeriMineDesno();
	a->prikaziMinskoPolje();
	*/
	//Testiranje funkcije pomeriMineDole()
	/*a->prikaziMinskoPolje();
	cout << endl;
	a->pomeriMineDole();
	a->prikaziMinskoPolje();
	*/
	//Testiranje funkcije pomeriMineLevo()
	/*a->prikaziMinskoPolje();
	cout << endl;
	a->pomeriMineLevo();
	a->prikaziMinskoPolje();*/
	//Testiranje funkcije pomeriMineGore()
	/*a->prikaziMinskoPolje();
	cout << endl;
	a->pomeriMineGore();
	a->prikaziMinskoPolje();*/
	//Testiranje funkcije svakoNtoPoljeZameniMinom(N)
	/*cout << *a;
	a->svakoNtoPoljeZameniMinom(100);
	cout <<"\n"<< *a;*/
	
	//LV1
	/*short pozicijaX, pozicijaY;
	fscanf(fajl, "%hd", &pozicijaX);
	fscanf(fajl, "%hd", &pozicijaY);
	short izabranoPolje = a->brojMinaKojeOkruzujuDatoPolje(pozicijaX, pozicijaY);
	if (izabranoPolje == -1) {
		cout << "Na polju ("<< pozicijaX << "," << pozicijaY <<") je mina!" << endl;
		a->prikaziMinskoPolje();
	}
	else {
		cout << "Oko polja (" << pozicijaX << "," << pozicijaY << ") nalazi se: " << izabranoPolje << " mine/a" << endl;;
	}*/

	fclose(fajl);
	delete a;

	cin.get();
	return 0;
}