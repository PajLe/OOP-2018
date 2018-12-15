#pragma once
#include <iostream>

class FileSystemElement
{
protected:
	char* ime;
	char* ekstenzija;
	FileSystemElement* roditeljski;
public:
	FileSystemElement();
	FileSystemElement(char* ime);
	FileSystemElement(char* ime, char* ekstenzija);
	~FileSystemElement();
	inline void postaviRoditeljskiElement(FileSystemElement* element) { roditeljski = element; }
	virtual char* punoIme() = 0;
	virtual void printList() = 0;
	virtual bool isFile() = 0;
	virtual void printFileList() = 0;
};

