#include "Mocvara.h"



Mocvara::Mocvara(const char* ime, double P, float Z) : Put(P, ime)
{
	this->Z = Z;
	identifikator = 'c';
}


Mocvara::~Mocvara()
{
}

ostream& Mocvara::operator<<(ostream& izlaz) {
	izlaz << "Ime:" << this->ime << " povrsina:" << this->povrsina << " Z:" << this->Z;
	return izlaz;
}