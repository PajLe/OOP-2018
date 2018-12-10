#pragma once
#include "Put.h"
#include <iostream>
using namespace std;

class Azdaja
{
	static const unsigned int UKUPNO_SEGMENATA = 1 * 3;
	Put** putevi;
public:
	Azdaja();
	~Azdaja();
	friend istream& operator>>(istream& ulaz, Azdaja& azhdahaShmog);
	friend ostream& operator<<(ostream& izlaz, const Azdaja& azhdahaShmog);
	void sortirajPoLepoti();
	void sortirajPoTezini();
};

