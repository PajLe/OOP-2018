#include "File.h"
#include "Folder.h"
#include <string.h>
#include <iostream>


File::File(char* ime, char* ekstenzija) : FileSystemElement(ime, ekstenzija)
{
}


File::~File()
{
}

char* File::punoIme() {
	char* roditeljskiPunoIme = roditeljski->punoIme(); //da ne bismo pozivali funkciju dva puta 
	char* pomocni = new char[strlen(roditeljskiPunoIme) + strlen(ime) + 1 + strlen(ekstenzija) + 1]; //1 za '\0' i 1 za '.' (tacku)
	strcpy(pomocni, "");
	strcat(pomocni, roditeljskiPunoIme);
	strcat(pomocni, ime);
	strcat(pomocni, ".");
	strcat(pomocni, ekstenzija);
	pomocni[strlen(pomocni)] = '\0';
	return pomocni;
}

void File::printList() {
	roditeljski->printFileList();
	std::cout << std::endl;
}