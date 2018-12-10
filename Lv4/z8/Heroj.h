#pragma once
#include "Zadatak.h"
#define BROJ_ZADATAKA 17

class Heroj
{
protected:
	char* ime;
	int vekRodjenja;
	Zadatak** zadaci;
	unsigned int brojDodeljenihZadataka;
public:
	Heroj(const char*, int);
	~Heroj();
	Heroj& operator=(const Heroj& hero);
	Zadatak& operator[](int index);
	inline char* getIme() { return this->ime; }
	inline int getBrojDodeljenihZadataka() { return brojDodeljenihZadataka; }
	virtual void dodajZadatak(Zadatak&) = 0;
	virtual void prikaz() = 0;
};

