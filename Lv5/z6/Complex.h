#pragma once
#include <iostream>
using namespace std;

class Complex
{
	double real;
	double imag;
public:
	Complex();
	Complex(double);
	Complex(double real, double imag);
	//Complex(const Complex&); //dovoljan je default copy konstruktor
	~Complex();
	Complex operator+(const Complex& x);
	Complex operator*(const Complex& x);
	Complex& operator=(const Complex& x);
	Complex& operator=(int i);
	friend istream& operator>>(istream& ulaz, Complex& a);
	friend ostream& operator<<(ostream& izlaz, const Complex& a);

};

