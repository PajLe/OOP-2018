#include "More.h"



More::More(const char* ime, double P, double S, unsigned short MSV) : Put(P, ime)
{
	stepenPlavetnila = S;
	maxSnagaVetra = MSV;
	identifikator = 'm';
}


More::~More()
{
}

ostream& More::operator<<(ostream& izlaz) {
	
	izlaz << "Ime:" << this->ime << " povrsina:" << this->povrsina << " stepen_plavetnila:"
		<< this->stepenPlavetnila << " max_snaga_vetra:" << this->maxSnagaVetra;
	return izlaz;
}

