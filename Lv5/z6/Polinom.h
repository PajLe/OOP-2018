#pragma once
//#include <math.h>
#include <iostream>
using namespace std;

/*
Type treba imati definisano:
- copy konstruktor
- konstruktor sa jednim parametrom (int)
- operator>>
- operator=
- operator+
- operator*
- operator= sa parametrom (int)
*/

template <class Type, int stepen> 
class Polinom {
private:
	Type* koeficijenti; //koristiti nedinamicke nizove da ne bismo pokusali da resizujemo 
	//int brojKoeficijenata;
public:

	Polinom();
	~Polinom();
	void ucitajKoeficijente();
	Type izracunajVrednost(const Type& x);
};

template <class Type, int stepen>
Polinom<Type, stepen>::Polinom() {
	koeficijenti = new Type[stepen+1]; //idu od 0 do, i ukljucujuci, stepen
	//brojKoeficijenata = stepen;
	for (unsigned int i = 0; i <= stepen; i++) {
		koeficijenti[i] = 0;
	}
}

template <class Type, int stepen>
Polinom<Type, stepen>::~Polinom() {
	if (koeficijenti) {
		delete[] koeficijenti;
	}
}

template <class Type, int stepen>
void Polinom<Type, stepen>::ucitajKoeficijente(){
	for (unsigned int i = 0; i <= stepen; i++) {
		cin >> koeficijenti[i];
	}
}

template <class Tip>
Tip pozitivanStepenBroja(const Tip&, unsigned int);

template <class Type, int stepen>
Type Polinom<Type, stepen>::izracunajVrednost(const Type& x) { //potreban copy konstr. za Type
								
	Type a = 0;
	for (unsigned int i = 0; i <= stepen; i++) {	//podrazumevano da su koeficijenti smesteni od najmanjeg stepena do najveceg
							//odnosno prvi element u nizu stoji uz a^0, drugi uz a^1, treci uz a^2 itd
		a = a + koeficijenti[i] * pozitivanStepenBroja(x, i); //koriscena (neoptimalna verovantno, ali ne znam bolje) sablonska funkcija umesto pow iz math.h zbog ogranicenja tipova
	}
	return a;
}

template <class Tip>
Tip pozitivanStepenBroja(const Tip& broj, unsigned int st) {
	Tip a = broj;
	if (st == 0) {
		a = 1;
		return a;
	}
	for (unsigned int i = 2; i <= st; i++) {
		a = a * broj;
	}
	return a;
}
