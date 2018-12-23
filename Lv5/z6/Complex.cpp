#include "Complex.h"



Complex::Complex()
{
	real = imag = 0;
}

Complex::Complex(double br) {
	real = br;
	imag = 0;
}

Complex::Complex(double real, double imag) {
	this->real = real;
	this->imag = imag;
}

Complex::~Complex()
{
}

Complex Complex::operator+(const Complex& x) {
	return Complex(real + x.real, imag + x.imag);
}

Complex Complex::operator*(const Complex& x) {
	return Complex((real*x.real) - (imag*x.imag), (imag*x.real) + (real*x.imag));
}

Complex& Complex::operator=(const Complex& x) {
	if (this == &x) {
		return *this;
	}
	this->real = x.real;
	this->imag = x.imag;
	return *this;
}

Complex& Complex::operator=(int x) {
	this->real = (double)x;
	this->imag = 0;
	return *this;
}

istream& operator>>(istream& ulaz, Complex& a) {
	ulaz >> a.real >> a.imag;
	return ulaz;
}

ostream& operator<<(ostream& izlaz, const Complex& a) {
	izlaz << a.real << " + j" << a.imag;
	return izlaz;
}