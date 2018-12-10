#include "Azdaja.h"
#include "Gora.h"
#include "Mocvara.h"
#include "More.h"
#include "Put.h"
#include <fstream>

int main() {
	Azdaja* smaug = new Azdaja();
	ifstream input("input.txt");
	if (input.good()) {
		input >> *smaug;
	}

	input.close();
	ofstream output("output.txt");
	if (output.good()) {
		output << *smaug;
	}

	delete smaug;
	return 0;
}