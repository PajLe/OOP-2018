#include "Skup.h"
using namespace std;

int main() {
	static unsigned int BROJ_ELEMENATA = 10;
	Skup* skup = new Skup(BROJ_ELEMENATA);
	for (unsigned int i = 0; i < BROJ_ELEMENATA; i++) {
		unsigned int element;
		cin >> element;
		skup->postaviElement(element, i);
	}
	
	if (skup->elementPripadaSkupu(59)) {
		cout << "Element " << "59" /*neka druga varijabla*/ << " pripada skupu" << endl;
	} else {
		cout << "Element " << "59" /*neka druga varijabla*/ << " ne pripada skupu" << endl;
	}

	Skup* drugiSkup = new Skup(*skup);

	drugiSkup->prikaziSkup();

	/* testiranje ostalih funkcija
	cout << "skup:" << endl;
	skup->prikaziSkup();

	cout << "izbaceni duplikati:" << endl;
	skup->izbaciDuplikate();
	skup->prikaziSkup();

	cout << "sortiran skup nerastuci poredak: " << endl;
	skup->sortirajNerastuci();
	skup->prikaziSkup();
	*/
	
	delete skup;
	skup = nullptr;
	delete drugiSkup;
	drugiSkup = nullptr;

	return 0;
}