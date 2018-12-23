#include "Polinom.h"
#include "Complex.h"
#include <iostream>
using namespace std;

int main() {
	Polinom<double, 5>* realni= new Polinom<double, 5>();
	realni->ucitajKoeficijente();
	cout << realni->izracunajVrednost(2) << endl;

	Polinom<Complex, 5>* kompleksni = new Polinom<Complex, 5>();
	kompleksni->ucitajKoeficijente();
	cout << kompleksni->izracunajVrednost(2) << endl;
	
	delete kompleksni;
	delete realni;
	return 0;
}