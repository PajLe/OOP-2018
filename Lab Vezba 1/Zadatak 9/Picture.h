#pragma once
#include <stdio.h>

class Picture {
private:
	unsigned short** slika;
	unsigned short visina;
	unsigned short sirina;
public:
	Picture();
	Picture(unsigned short visina,unsigned short sirina);
	Picture(const Picture& slicka);
	~Picture();
	inline void dimenzije(unsigned short& visina, unsigned short& sirina) {
		visina = this->visina;
		sirina = this->sirina;
	}
	void Brightness(int s);
	void ucitajSliku(FILE* izFajla);
	void prikaziSliku();
	Picture* resize(int nWidth, int nHeight);
};