#pragma once
#include <iostream>
using namespace std;

class Put
{
protected:
	double povrsina;
	char* ime;
	char identifikator;
public:
	
	Put(double povrsina, const char* ime);
	~Put();
	virtual inline double koefTezine() = 0;
	virtual inline double koefLepote() = 0;
	virtual inline char getIdentifikator() { return identifikator; }
	virtual ostream& operator<<(ostream&) = 0;
};

