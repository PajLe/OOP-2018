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
	char* pomocni = new char[strlen(ime)+1];
	strcpy(pomocni, ime);
	strcat(pomocni, ".");
	strcat(pomocni, ekstenzija);
	return pomocni;
}

void File::printList() {
	//roditeljski->printList();
	std::cout << punoIme() << std::endl;
}