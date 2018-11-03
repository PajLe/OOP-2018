#include "Picture.h"
#include <math.h>

Picture::Picture() : Picture::Picture(0,0){
	
}

Picture::Picture(const Picture& slicka) {
	this->visina = slicka.visina;
	this->sirina = slicka.sirina;

	this->slika = new unsigned short*[this->visina];
	for (short i = 0; i < this->visina; i++) {
		this->slika[i] = new unsigned short[this->sirina];
	}

	for (short i = 0; i < this->visina; i++) {
		for (short j = 0; j < this->sirina; j++) {
			this->slika[i][j] = slicka.slika[i][j];
		}
	}
	
}

Picture::Picture(unsigned short visina, unsigned short sirina) {
	this->visina = visina;
	this->sirina = sirina;

	this->slika = new unsigned short*[visina];
	for (short i = 0; i < visina; i++) {
		this->slika[i] = new unsigned short[sirina];
	}
}

Picture::~Picture() {
	if (this->slika != nullptr) {
		for (short i = 0; i < this->visina; i++) {
			delete[] this->slika[i];
		}

		delete[] this->slika;
	}
	
}

void Picture::Brightness(int s) {
	for (short i = 0; i < this->visina; i++) {
		for (short j = 0; j < this->sirina; j++) {
			int sabrano = s + this->slika[i][j];
			if (sabrano <= 512 && sabrano >= 0) {
				this->slika += s;
			}
		}
	}
}

void Picture::ucitajSliku(FILE* fajl) {
	for (short i = 0; i < this->visina; i++) {
		for (short j = 0; j < this->sirina; j++) {
			if (feof(fajl)) {
				this->slika[i][j] = 0;
				continue;
			}
			int element;
			fscanf(fajl, "%d", &element);
			if (element >= 0 && element <= 512)
				this->slika[i][j] = element;
			else
				this->slika[i][j] = 0;
		}
	}
}

void Picture::prikaziSliku() {
	for (short i = 0; i < this->visina; i++) {
		for (short j = 0; j < this->sirina; j++) {
			printf("%hd ", this->slika[i][j]);
		}
		printf("\n");
	}
}

Picture* Picture::resize(int nWidth, int nHeight) {
	double nXFactor = (double)this->sirina / (double)nWidth;
	double nYFactor = (double)this->visina/ (double)nHeight;

	Picture* novaSlika = new Picture(nHeight, nWidth);

	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < nWidth; j++) {
			novaSlika->slika[i][j] = this->slika[((int)(floor(i * nYFactor)))][((int)(floor(j * nXFactor)))];
		}
	}
	return novaSlika;
}