#include "Fraction.h"
int Fraction::GetInteger()const
{
	return integer;
};
int Fraction::GetNumerator()const
{
	return numerator;
};
int Fraction::GetDenominator()const
{
	return denominator;
};
void Fraction::SetInteger(int integer)
{
	this->integer = integer;

};
void Fraction::SetNumerator(int numerator)
{
	this->numerator = numerator;
};
void Fraction::SetDenominator(int denominator)

{
	if (denominator == 0)
	{
		denominator = 1;
	}
	this->denominator = denominator;
};
	// Constructors & Destructor
	Fraction::Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->SetDenominator(denominator);
	};
	Fraction::Fraction() //Default constructor
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 0;
	}
	Fraction::Fraction(int integer) //Sinagle argument constructor
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction::Fraction(double decimal)
	{
		decimal += 1e-15;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9; //1000000000
		numerator = decimal * denominator;
		reduce();
	}
	Fraction::Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->SetDenominator(denominator);
	}
	Fraction::Fraction(const Fraction& other) //Конструктор копирования
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction::~Fraction()
	{
	};
	// Methods
	void Fraction::print()
	{
		cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
	}
	Fraction& Fraction::reduce()
	{
		if (numerator == 0)
		{
			return *this;
		}
		int more, less, rest;
		// 1)определяем кто больше числитель или знаменатель;
		if (numerator > denominator)
		{
			more = numerator, less = denominator;
		}
		else
		{
			less = numerator, more = denominator;
		}
		//2) Вычисляем НОД (GCD)
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD, denominator /= GCD;
		return	*this;
	}
	Fraction Fraction::to_proper() //в правильную дробь
	{
		/*Fraction copy = *this;
		copy.integer += copy.numerator / copy.denominator;
		copy.numerator %= copy.denominator;
		return copy;*/
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction Fraction::to_improper() //в неправильную дробь
	{
		numerator += (integer * denominator);
		integer = 0;
		return *this;

	}
	Fraction Fraction::inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); //swap меняет местами 2 переменные
		return inverted;
	};
	//operators overload
	Fraction& Fraction::operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
#ifdef DEBUG
		cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG

	}
	Fraction& Fraction::operator*=(const Fraction& other)
	{
		return *this = *this * other;

	}
	Fraction& Fraction::operator/=(const Fraction& other)
	{
		return *this = *this / other;

	}
	Fraction& Fraction::operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& Fraction::operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& Fraction::operator++()
	{
		integer++;
		return *this;
	}
	Fraction Fraction::operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& Fraction::operator--()
	{
		this->integer--;
		return *this;

	}
	Fraction& Fraction::operator--(int value)
	{
		Fraction newThis = *this;
		this->integer--;
		return newThis;
	}
	//Type cast operators;
	Fraction::operator int()const
	{
		return integer;
	}
	Fraction::operator double()const
	{
		return integer + (double)numerator / denominator;
	}
	//Operators oveldoad outside class
	ostream& operator<<(ostream& os, const Fraction& obj)
	{
		if (obj.GetInteger())
		{
			os << obj.GetInteger();
		}
		if (obj.GetNumerator())
		{
			if (obj.GetInteger())
			{
				os << "(";
			}

			os << obj.GetNumerator() << "/" << obj.GetDenominator();

			if (obj.GetInteger())
			{
				cout << ")";
			}
		}
		else if (obj.GetInteger() == 0)
		{
			os << 0;
		}
		return os;

	}
	Fraction operator+(Fraction left, Fraction right)
	{
		left.to_proper();
		right.to_proper();
		Fraction result;
		result.SetInteger(left.GetInteger() + right.GetInteger());
		result.SetNumerator(left.GetNumerator() * right.GetDenominator() + right.GetNumerator() * left.GetDenominator());
		result.SetDenominator(left.GetDenominator() * right.GetDenominator());
		result.to_proper().reduce();
		return result;


	}
	Fraction operator*(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return Fraction
		(
			left.GetNumerator() * right.GetNumerator(),
			left.GetDenominator() * right.GetDenominator()

		).to_proper().reduce();

	}
	Fraction operator-(Fraction left, Fraction right)
	{
		left.to_proper();
		right.to_proper();
		Fraction result
		(
			left.GetInteger() - right.GetInteger(),
			left.GetNumerator() * right.GetDenominator() - right.GetNumerator() * left.GetDenominator(),
			left.GetDenominator() * right.GetDenominator()
		);
		result.to_proper();
		result.reduce();
		return result;

	}
	Fraction operator/(Fraction left, Fraction right)
	{
		return left * right.inverted();

	}
	//Comparison operators
	bool operator ==(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return left.GetNumerator() * right.GetDenominator() == right.GetNumerator() * left.GetDenominator();
	}
	bool operator !=(const Fraction& left, const Fraction& right)
	{
		return !(left == right);

	}