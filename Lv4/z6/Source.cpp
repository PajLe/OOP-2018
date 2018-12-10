#include "File.h"
#include "FileSystemElement.h"
#include "Folder.h"
#include <string.h>
#include <iostream>

int main() {
	char* Dime = new char[strlen("D")+1];
	strcpy(Dime, "D");
	Folder* D = new Folder(Dime);

	char* FilmoviIme = new char[strlen("Filmovi")+1];
	strcpy(FilmoviIme, "Filmovi");
	Folder* Filmovi = new Folder(FilmoviIme);

	char* SerijeIme = new char[strlen("Serije") + 1];
	strcpy(SerijeIme, "Serije");
	Folder* Serije = new Folder(SerijeIme);

	char* DesperadoIme = new char[strlen("Desperado")+1];
	strcpy(DesperadoIme, "Desperado");
	char* DesperadoEkstenzija = new char[strlen("mp4")+1];
	strcpy(DesperadoEkstenzija, "mp4");
	File* Desperado = new File(DesperadoIme, DesperadoEkstenzija);

	char* WotlkIme = new char[strlen("Wotlk") + 1];
	strcpy(WotlkIme, "Wotlk");
	Folder* Wotlk = new Folder(WotlkIme);

	char* wowIme = new char[strlen("wow") + 1];
	strcpy(wowIme, "wow");
	char* wowEkstenzija = new char[strlen("exe") + 1];
	strcpy(wowEkstenzija, "exe");
	File* wow = new File(wowIme, wowEkstenzija);

	char* wowErrorIme = new char[strlen("wowError") + 1];
	strcpy(wowErrorIme, "wowError");
	char* wowErrorEkstenzija = new char[strlen("exe") + 1];
	strcpy(wowErrorEkstenzija, "exe");
	File* wowError = new File(wowErrorIme, wowErrorEkstenzija);

	Filmovi->dodajUfolder(Desperado);

	Wotlk->dodajUfolder(wow);
	Wotlk->dodajUfolder(wowError);

	D->dodajUfolder(Filmovi);
	D->dodajUfolder(Serije);
	D->dodajUfolder(Wotlk);

	std::cout << Filmovi->punoIme() << std::endl;
	std::cout << Wotlk->punoIme() << std::endl;
	wowError->printList();
	D->printList();

	delete wowError;
	delete[] wowErrorEkstenzija;
	delete[] wowErrorIme;
	delete wow;
	delete[] wowEkstenzija;
	delete[] wowIme;
	delete Wotlk;
	delete[] WotlkIme;

	delete Desperado;	
	delete[] DesperadoEkstenzija;
	delete[] DesperadoIme;
	delete Serije;
	delete[] SerijeIme;
	delete Filmovi;
	delete[] FilmoviIme;
	
	delete D;
	delete[] Dime;

	return 0;

}