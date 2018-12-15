#include "File.h"
#include "FileSystemElement.h"
#include "Folder.h"
#include <string.h>
#include <iostream>

int main() {
	char* Dime = _strdup("D");
	Folder* D = new Folder(Dime);

	char* FilmoviIme = _strdup("Filmovi");
	Folder* Filmovi = new Folder(FilmoviIme);

	char* SerijeIme = _strdup("Serije");
	Folder* Serije = new Folder(SerijeIme);

	char* DesperadoIme = _strdup("Desperado");
	char* DesperadoEkstenzija = _strdup("mp4");
	File* Desperado = new File(DesperadoIme, DesperadoEkstenzija);

	char* WotlkIme = _strdup("Wotlk");
	Folder* Wotlk = new Folder(WotlkIme);

	char* wowIme = _strdup("wow");
	char* wowEkstenzija = _strdup("exe"); 
	File* wow = new File(wowIme, wowEkstenzija);

	char* wowErrorIme = _strdup("wowError");
	char* wowErrorEkstenzija = _strdup("exe");
	File* wowError = new File(wowErrorIme, wowErrorEkstenzija);
	
	Filmovi->dodajUfolder(Desperado);			//fajl Desperado se dodaje u folder Filmovi

	Wotlk->dodajUfolder(wow);					//fajlovi wow i wowError se dodaju u folder Wotlk
	Wotlk->dodajUfolder(wowError);

	D->dodajUfolder(Filmovi);					//folderi Filmovi, Serije i Wotlk se dodaju u folder D
	D->dodajUfolder(Serije);
	D->dodajUfolder(Wotlk);

	std::cout << Filmovi->punoIme() << std::endl; //puno ime foldera
	std::cout << Desperado->punoIme() << std::endl;	//puno ime fajla
	wowError->printList();						//printlist fajla (postoji jos jedan sa istim roditeljskim)
	D->printList();								//printlist foldera
	Desperado->printList();						//printlist fajla (ne postoji ni jedan sa istim roditeljskim)

	Wotlk->printList();							//stanje foldera pre brisanja fajla iz njega
	Wotlk->izbrisiIzFoldera(1);					//brisanje fajla wowError iz foldera Wotlk
	Wotlk->printList();							//stanje foldera nakon brisanja

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