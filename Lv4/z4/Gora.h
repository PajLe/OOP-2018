#pragma once
#include "Put.h"
#include <iostream>
using namespace std;

class Gora :
	public Put
{
	double duzinaPuta;
	double V; // relativna razlika nadmorske visine izmedju najnize i najvise tacke 
	float B; // stepen inverzne posumljenosti 
public:
	Gora(const char* ime, double P, double D, double V, float B);
	~Gora();
	inline double koefTezine() { return B * duzinaPuta / (duzinaPuta + povrsina + V + duzinaPuta / povrsina); }
	inline double koefLepote() { return (1 - B)*V; }

	ostream& operator<<(ostream& izlaz);
};

