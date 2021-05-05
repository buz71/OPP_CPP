#pragma once
#include <iostream>
#include <math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define DELIMITER "\n---------------------------------------\n"
#define tab "\t"
//#define DEBUG
//#define arithmetical_operator
//#define CONSTRUCTORS_CHECK
//#define COMPAUND_ASSIGNMENTS
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS
#define TYPE_CONVERSION

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);

class Fraction
{
private:
	int integer; //целая часть
	int numerator; //числитель
	int denominator; //знаменатель
	int common_denominator(Fraction A);

public:
	int GetInteger()const;
	int GetNumerator()const;
	int GetDenominator()const;
	void SetInteger(int integer);
	void SetNumerator(int numerator);
	void SetDenominator(int denominator);
	// Constructors & Destructor
	Fraction(int integer, int numerator, int denominator);
	Fraction(); //Default constructor
	explicit Fraction(int integer); //Sinagle argument constructor
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	// Methods
	void print();
	Fraction& reduce();
	Fraction to_proper();
	Fraction to_improper();
	Fraction inverted()const;
	//operators overload
	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction& operator--(int value);
	//Type cast operators;
	operator int()const;
	explicit operator double()const;
};


