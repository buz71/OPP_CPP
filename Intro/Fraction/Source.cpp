#include <iostream>
#include <math.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
//#define CONSTRUCTORS_CHECK

class Fraction
{
private:
	int integer; //целая часть
	int numerator; //числитель
	int denominator; //знаменатель
	int common_denominator(Fraction A) //Вспомогательная функция для вычисления общего знаменателя
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
	int GetInteger()const
	{
		return integer;
	}
	int GetNumerator()const
	{
		return numerator;
	}
	int GetDenominator()const
	{
		return denominator;
	}
	void SetInteger(int integer)
	{
		this->integer = integer;
	
	}
	void SetNumerator(int numerator)
	{
		this->numerator = numerator;
	}
	void SetDenominator(int denominator)

	{
		if (denominator==0)
		{
			denominator = 1;
		}
		this->denominator = denominator;
	}
	
	// Constructors & Destructor
	Fraction(int integer, int numerator, int denominator )
	{
		this->integer = integer;
		this->numerator = numerator;
		this->SetDenominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction() //Default constructor
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 0;
		cout << "Default constructor: " << this << endl;
	}
	Fraction(int integer) //Sinagle argument constructor
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleIntegerConstructor: " << this << endl;
	}
	Fraction(int numerator,int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->SetDenominator(denominator);
		cout << "Constructor: " << this << endl;
	
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction() 
	{
		cout << "Destructor:\t" << this << endl;
	};

	// Methods
	
	void print()
	{
		cout <<integer<<"("<<numerator << "/" << denominator <<")"<< endl;
	}
	Fraction to_proper() //в правильную дробь
	{
		/*Fraction copy = *this;
		copy.integer += copy.numerator / copy.denominator;
		copy.numerator %= copy.denominator;
		return copy;*/
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction to_improper() //в неправильную дробь
	{
		/*Fraction copy = *this;
		copy.numerator += (copy.integer * copy.denominator);
		copy.integer = 0;
		return copy;*/
		numerator += (integer * denominator);
		integer = 0;
		return *this;

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

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.GetInteger())
	{
		os << obj.GetInteger();
	}
	if (obj.GetInteger())
	{
		if (obj.GetInteger())
		{
			os << "(";
			os << obj.GetNumerator() << "/" << obj.GetDenominator();
		}
		
		if (obj.GetInteger())
		{
			cout << ")";
		}
	}
	else if (obj.GetInteger()==0)
	{
		os << 0;
	}
	return os;

}

void main()
{
	setlocale(LC_ALL, "ru");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	cout << A << endl;
	double b = 5;
	Fraction B = 5;
	B.print();
	cout << B << endl;
	Fraction C(1, 2);
	C.print();
	cout << C << endl;
	Fraction D(3, 4, 5);
	D.print();
	cout << D << endl;
#endif // CONSTRUCTORS_CHECK

	Fraction A(11, 4);
	cout << A.to_improper() <<" = "<<A.to_proper()<<endl;
	cout << A.to_proper() << " = " << A.to_improper() << endl;

}