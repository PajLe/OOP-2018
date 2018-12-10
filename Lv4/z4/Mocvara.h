#pragma once
#include "Put.h"
#include <iostream>
using namespace std;

class Mocvara :
	public Put
{
	float Z; //stepen zitkosti mulja
public:
	Mocvara(const char* ime, double P, float Z);
	~Mocvara();
	inline double koefTezine() { return (1 - Z)*(1 - 1 / (Z*povrsina)); }
	inline double koefLepote() { return 1 - koefTezine(); }

	ostream& operator<<(ostream& izlaz);
};

