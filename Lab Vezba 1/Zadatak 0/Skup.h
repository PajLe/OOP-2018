#pragma once
#include <iostream>

class Skup{
private:
	unsigned int brojClanova;
	int* niz;
	void pomeriNizLevoOdPozicije(unsigned int pozicija, unsigned int indexPoslednjegElementa);

public:
	Skup();
	Skup(unsigned int brojClanova);
	Skup(const Skup& drugiSkup);
	~Skup();

	inline unsigned int getBrojClanova() { return brojClanova; }

	bool elementPripadaSkupu(unsigned int element);
	void izbaciDuplikate();
	void postaviElement(unsigned int element, unsigned int index);
	void sortirajNerastuci();
	void prikaziSkup();
};