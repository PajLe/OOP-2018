#include "String.h"
#include <iostream>

using namespace std;

int main() {
	FILE* fajl = fopen("fajl.txt", "r");
	if (fajl == nullptr){
		return 1;
	}

	String* string = new String(11);
	string->ucitajStringIzFajla(fajl);

	String* ana = new String(4);//ako menjamo ovaj string treba promeniti i velicinu objekta
	ana->setBafer("ana");

	int n = string->pozicijaPodstringa(*ana);
	if (n == -1) {
		cout << "podstring nije pronadjen" << endl;
	} else {
		cout << "pozicija datog podstringa je : " << n << endl;
	}

	delete ana;
	ana = nullptr;
	delete string;
	string = nullptr;
	fclose(fajl);
	cin.get();
	return 0;
}