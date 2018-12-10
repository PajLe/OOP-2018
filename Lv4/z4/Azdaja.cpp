#include "Azdaja.h"
#include "Gora.h"
#include "Mocvara.h"
#include "More.h"



Azdaja::Azdaja()
{
	putevi = new Put*[Azdaja::UKUPNO_SEGMENATA];
}


Azdaja::~Azdaja()
{
	for (unsigned int i = 0; i < Azdaja::UKUPNO_SEGMENATA; i++) {
		if (putevi[i]) {
			delete putevi[i];	//brisemo svaki od puteva posebno
			putevi[i] = 0;
		}
			
	}
	if (putevi) {
		delete[] putevi;		//brisemo niz pokazivaca na puteve
		putevi = 0;
	}
}

istream& operator>>(istream& ulaz, Azdaja& azhdahaShmog) {
	for (unsigned int i = 0, n = Azdaja::UKUPNO_SEGMENATA / 3; i < n; i++) {	//ucitavanje Gora
		char* ime = new char[20]; //max duzina imena 19 + 1 za '\0' ; ime je jedna rec
		ulaz >> ime;				
		double povrs;
		ulaz >> povrs;
		double D;
		ulaz >> D;
		double V;
		ulaz >> V;
		float B; 
		ulaz >> B;
		

		azhdahaShmog.putevi[i] = new Gora(ime, povrs, D, V, B);
	}
	for (unsigned int i = Azdaja::UKUPNO_SEGMENATA / 3, n = (Azdaja::UKUPNO_SEGMENATA / 3) * 2; i < n; i++) { //ucitavanje Mora
		char* ime = new char[20]; //max duzina imena 19 + 1 za '\0' ; ime je jedna rec
		ulaz >> ime;
		double povrs;
		ulaz >> povrs;
		double S;
		ulaz >> S;
		unsigned short MSV;
		ulaz >> MSV;

		azhdahaShmog.putevi[i] = new More(ime, povrs, S, MSV);
	}
	for(unsigned int i = (Azdaja::UKUPNO_SEGMENATA / 3) * 2; i < Azdaja::UKUPNO_SEGMENATA; i++){
		char* ime = new char[20]; //max duzina imena 19 + 1 za '\0' ; ime je jedna rec
		ulaz >> ime;
		double povrs;
		ulaz >> povrs;
		float Z;
		ulaz >> Z;

		azhdahaShmog.putevi[i] = new Mocvara(ime, povrs, Z);
	}

	return ulaz;
}

ostream& operator<<(ostream& izlaz, const Azdaja& azhdahaShmog) {
	for (unsigned int i = 0; i < Azdaja::UKUPNO_SEGMENATA; i++) {
		
		azhdahaShmog.putevi[i]->operator<<(izlaz);
			izlaz << " koef_lepote:"<< azhdahaShmog.putevi[i]->koefLepote()
			<< " koef_tezine:" << azhdahaShmog.putevi[i]->koefTezine() << endl;
	}
	return izlaz;
}