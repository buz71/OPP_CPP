#include <iostream>
#include <math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Fraction
{


private:
	int numerator;
	int denominator;
	int common_denominator(Fraction A)
	{
		if ((this->denominator) < (A.denominator))
		{
			for (int i = A.denominator; ; i += A.denominator)
			{
				if (i % (this->denominator) == 0)
				{
					return i;
				}
			}
		}
		if ((this->denominator) > (A.denominator))
		{

			for (int i = this->denominator; ; i += this->denominator)
			{
				if (i % (A.denominator) == 0)
				{
					return i;
				}
			}
		}





	}

public:
	int GetNumerator()const
	{
		return numerator;
	}
	int GetDenominator()const
	{
		return denominator;
	}
	void SetNumerator(int numerator)
	{
		this->numerator = numerator;
	}
	void SetDenominator(int denominator)
	{
		this->denominator = denominator;
	}
	// Constructors & Destructor

	Fraction(int numerator = 0, int denominator = 0)
	{
		this->numerator = numerator;
		this->denominator = denominator;
	}
	~Fraction() {};

	// Methods

	void print()
	{
		cout << this->numerator << "/" << this->denominator << endl;
	}
	void to_propper()
	{
		if (this->numerator > this->denominator)
		{
			short buffer = this->numerator;
			this->numerator = this->denominator;
			this->denominator = buffer;
		}
	}
	void to_improper()
	{
		if (this->numerator < this->denominator)
		{
			short buffer = this->numerator;
			this->numerator = this->denominator;
			this->denominator = buffer;
		}

	}
	void reduce()
	{
		for (int i = this->denominator; i > 0; i--)
		{
			if ((this->numerator) % i == 0 && (this->denominator) % i == 0)
			{
				this->numerator /= i;
				this->denominator /= i;
				break;
			}
		}
	}


	// Operators

	Fraction& operator+(Fraction A)
	{
		//Fraction B=*this;
		if (this->denominator == A.denominator)
		{
			this->numerator += A.numerator;
		}

		if (this->denominator != A.denominator)
		{
			int com_denum = common_denominator(A);
			this->numerator *= (com_denum / this->denominator);
			A.numerator *= (com_denum / A.denominator);
			this->numerator += A.numerator;
			this->denominator = com_denum;
		}

		return *this;
	}
	Fraction& operator-(Fraction A)
	{
		if (this->denominator == A.denominator)
		{
			this->numerator += A.numerator;
		}

		if (this->denominator != A.denominator)
		{
			int com_denum = common_denominator(A);
			this->numerator *= (com_denum / this->denominator);
			A.numerator *= (com_denum / A.denominator);
			this->numerator -= A.numerator;
			this->denominator = com_denum;
		}

		return *this;

	}
	Fraction& operator*(Fraction A)
	{
		this->numerator *= A.numerator;
		this->denominator *= A.denominator;
		return *this;
	}
	Fraction& operator/(Fraction A)
	{
		this->numerator *= A.denominator;
		this->denominator *= A.numerator;
		return *this;
	}
	Fraction& operator+=(Fraction A)
	{
		if (this->denominator == A.denominator)
		{
			this->numerator += A.numerator;
		}

		if (this->denominator != A.denominator)
		{
			int com_denum = common_denominator(A);
			this->numerator *= (com_denum / this->denominator);
			A.numerator *= (com_denum / A.denominator);
			this->numerator += A.numerator;
			this->denominator = com_denum;
		}

		return *this;

	}
	Fraction& operator-=(Fraction A)
	{
		if (this->denominator == A.denominator)
		{
			this->numerator += A.numerator;
		}

		if (this->denominator != A.denominator)
		{
			int com_denum = common_denominator(A);
			this->numerator *= (com_denum / this->denominator);
			A.numerator *= (com_denum / A.denominator);
			this->numerator -= A.numerator;
			this->denominator = com_denum;
		}

		return *this;

	}
	Fraction& operator*=(Fraction A)
	{
		this->numerator *= A.numerator;
		this->denominator *= A.denominator;
		return *this;
	}
	Fraction& operator/=(Fraction A)
	{
		this->numerator *= A.denominator;
		this->denominator *= A.numerator;
		return *this;
	}






};

void main()
{
	setlocale(LC_ALL, "ru");



}