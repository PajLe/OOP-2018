#include "Gora.h"



Gora::Gora(const char* ime, double P, double D, double V, float B) : Put(P, ime)
{
	duzinaPuta = D;
	this->V = V;
	this->B = B;
	identifikator = 'g';
}


Gora::~Gora()
{
}

ostream& Gora::operator<<(ostream& izlaz) {
	izlaz << "Ime:" << this->ime << " povrsina:" << this->povrsina
		<<" duzina_puta:" << this->duzinaPuta
		<< " V:" << this->V << " B:" << this->B;
	return izlaz;
}
