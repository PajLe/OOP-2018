#pragma once
#include "Heroj.h"
class BitskiHeroj :
	public Heroj
{
public:
	BitskiHeroj(const char* ime, int vekRodjenja);
	~BitskiHeroj();
	void dodajZadatak(Zadatak&);
	void prikaz();
};

