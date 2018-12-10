#pragma once
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
	void postaviRoditeljskiElement(FileSystemElement* element);
	virtual char* punoIme() = 0;
	virtual void printList() = 0;
};

