#include "Skup.h"
using namespace std;

Skup::Skup() {
	this->niz = new int;
	this->brojClanova = 0;
}

Skup::Skup(unsigned int brojClanova) {
	this->brojClanova = brojClanova;
	this->niz = new int[brojClanova];
}

Skup::Skup(const Skup& drugiSkup) {
	this->brojClanova = drugiSkup.brojClanova;
	this->niz = new int[this->brojClanova];

	for (unsigned int i = 0; i < this->brojClanova; i++) {
		this->niz[i] = drugiSkup.niz[i];
	}
}

Skup::~Skup() {
	if (this->niz != nullptr) {
		delete[] this->niz;
	}
}

void Skup::pomeriNizLevoOdPozicije(unsigned int pozicija, unsigned int indexPoslednjegElementa) {
	for (unsigned int i = pozicija; i < indexPoslednjegElementa; i++) {
		this->niz[i] = this->niz[i + 1];
	}
	this->brojClanova--;
}

void Skup::izbaciDuplikate() {
	for (unsigned int i = 0; i < this->brojClanova - 1; i++) {
		for (unsigned int j = i + 1; j < this->brojClanova; j++) {
			if (this->niz[j] == this->niz[i]) {
				pomeriNizLevoOdPozicije(j, this->brojClanova - 1);
				j--;
			}
		}
	}
}

bool Skup::elementPripadaSkupu(unsigned int element) {
	//ako izbaciDuplikate implementiramo tako da vraca novi niz, a ne da menja postojeci,
	//mozemo taj novi niz koristiti ovde kako bismo potencijalno smanjili broj prolaska kroz for petlju
	for (unsigned int i = 0; i < this->brojClanova; i++) {
		if (this->niz[i] == element) {
			return true;
		}
	}
	return false;
}

void Skup::postaviElement(unsigned int element, unsigned int index) {
	if (index < this->brojClanova) {
		this->niz[index] = element;
	}
}

void Skup::sortirajNerastuci() { //koriscen bubble sort; lepo bi bilo neki drugi sort koristiti
	bool promena = true;
	while (promena) {
		promena = false;
		for (unsigned int i = 0; i < this->brojClanova - 1; i++) {
			if (this->niz[i] < this->niz[i + 1]) {
				unsigned int p = this->niz[i+1];
				this->niz[i + 1] = this->niz[i];
				this->niz[i] = p;
				promena = true;
			}
		}
	}
}

void Skup::prikaziSkup() {
	for (unsigned int i = 0; i < this->brojClanova; i++) {
		cout << this->niz[i] << " ";
	}
	cout << endl;
}