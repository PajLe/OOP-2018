#pragma once
#include "Put.h"
#include <iostream>
using namespace std;

class More :
	public Put
{
	double stepenPlavetnila;
	unsigned short maxSnagaVetra;

public:
	More(const char* ime, double P, double S, unsigned short MSV);
	~More();
	inline double koefLepote() { return maxSnagaVetra * stepenPlavetnila / povrsina; }
	inline double koefTezine() { return maxSnagaVetra * povrsina / (koefLepote() - 1); }
	
	ostream& operator<<(ostream& izlaz);
	//friend istream& operator>>(istream& ulaz, More& more);
};

