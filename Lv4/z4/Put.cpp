#include "Put.h"
#include <string.h>



Put::Put(double povrsina, const char* ime)
{
	this->povrsina = povrsina;
	this->ime = _strdup(ime);
}


Put::~Put()
{
	if(ime)
		delete[] ime;
}
