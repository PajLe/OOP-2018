#pragma once
#include "FileSystemElement.h"
#define MAX_VELICINA 2018

class Folder :
	public FileSystemElement
{
private:
	FileSystemElement** fsElementi;
	unsigned short indexPrvogSlobodnogMesta;
	unsigned short indexPoslednjegSlobodnogMesta; //index nakon najdaljeg elementa u nizu
public:
	
	Folder(char* ime);
	~Folder();
	char* punoIme();
	void dodajUfolder(FileSystemElement* fselement);
	void izbrisiIzFoldera(unsigned short index);
	void printList();
	
};

