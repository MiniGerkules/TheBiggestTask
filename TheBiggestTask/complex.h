#pragma once
#include <iostream>

class Complex
{
private:
	double Re;
	double Im;

public:
	explicit Complex(double Re = 0, double Im = 0)
		: Re(Re), Im(Im)
	{}

	Complex operator+ (const Complex& other)
	{
		Complex temp;

		temp.Re = Re + other.Re;
		temp.Im = Im + other.Im;

		return temp;
	}

	Complex operator- (const Complex& other)
	{
		Complex temp;

		temp.Re = Re - other.Re;
		temp.Im = Im - other.Im;

		return temp;
	}

	Complex operator* (const Complex& other)
	{
		Complex temp;

		temp.Re = Re * other.Re - Im * other.Im;
		temp.Im = Re * other.Im + Im * other.Re;

		return temp;
	}

	Complex operator+ (const double other)
	{
		Complex temp;

		temp.Re = Re + other;
		temp.Im = Im;

		return temp;
	}

	friend Complex operator+ (const double number, const Complex& complexNumber)
	{
		Complex temp;

		temp.Re = number + complexNumber.Re;
		temp.Im = complexNumber.Im;

		return temp;
	}

	Complex operator- (const double other)
	{
		Complex temp;

		temp.Re = Re - other;
		temp.Im = Im;

		return temp;
	}

	friend Complex operator- (const double number, const Complex& complexNumber)
	{
		Complex temp;

		temp.Re = number - complexNumber.Re;
		temp.Im = complexNumber.Im;

		return temp;
	}

	Complex operator* (const double other)
	{
		Complex temp;

		temp.Re = Re * other;
		temp.Im = Im * other;

		return temp;
	}

	friend Complex operator* (const double number, const Complex& complexNumber)
	{
		Complex temp;

		temp.Re = number * complexNumber.Re;
		temp.Im = number * complexNumber.Im;

		return temp;
	}

	explicit operator double() const 
	{
		return Re;
	}

	friend std::ostream& operator<< (std::ostream& out, const Complex& complexNumber)
	{
		out << complexNumber.Re << " + " << complexNumber.Im << "i";

		return out;
	}
};
