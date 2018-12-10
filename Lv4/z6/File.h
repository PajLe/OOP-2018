#pragma once
#include "FileSystemElement.h"
class File :
	public FileSystemElement
{
public:
	File(char* ime, char* ekstenzija);
	~File();
	char* punoIme();
	void printList();
};

