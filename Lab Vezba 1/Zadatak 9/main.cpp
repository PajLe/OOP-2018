#include "Picture.h"
#include <iostream>

int main() {
	Picture* slika = new Picture(10,10);
	FILE* fajl = fopen("fajl.txt", "r");
	if(fajl != nullptr)
		slika->ucitajSliku(fajl);
	else return 1;

	Picture* slika2 = new Picture(*slika);
	slika2->prikaziSliku();

	//slika = (slika->resize(15, 15));
	//slika->prikaziSliku();

	fclose(fajl);
	delete slika2;
	slika2 = nullptr;
	delete slika;
	slika = nullptr;

	std::cin.get();
	return 0;
}