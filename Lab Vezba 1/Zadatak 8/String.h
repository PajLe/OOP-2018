#pragma once
#include <stdio.h>

class String {
private:
	unsigned int duzinaStringa;
	char* bafer;
public:
	String();
	String(unsigned int duzinaStringa);
	String(const String& stringZaKopiranje);
	~String();
	inline unsigned int getDuzinaStringa() {
		return duzinaStringa;
	}
	int pozicijaPodstringa(const String& podstring); //pronalazi pocetnu poziciju prvog podstringa(ako ih ima vise)
	void ucitajStringIzFajla(FILE* fajl);
	void prikaziString();
	void setBafer(const char* string);

};
