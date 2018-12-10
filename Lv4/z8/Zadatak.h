#pragma once
class Zadatak
{
private:
	int kod;
	int stepenTezine;
public:
	Zadatak();
	~Zadatak();
	inline void setKod(int kod) { this->kod = kod; }
	inline void setStepenTezine(int stepenTezine) { this->stepenTezine = stepenTezine; }
	void postaviKodAndStepenTezine(int kod, int stepenTezine);
	inline int getKod() { return kod; }
	inline int getStepenTezine() { return stepenTezine; }


};

