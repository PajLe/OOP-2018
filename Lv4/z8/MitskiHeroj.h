#pragma once
#include "Heroj.h"
class MitskiHeroj :
	public Heroj
{
private:
	int brojMitova;
	int minTezinaZadatka;
public:
	MitskiHeroj(const char* ime, int vekRodjenja, int brojMitova, int minTezinaZadatka);
	~MitskiHeroj();
	void dodajZadatak(Zadatak&);
	void prikaz();
};

