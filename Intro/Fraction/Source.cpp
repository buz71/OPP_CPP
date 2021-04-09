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
#ifdef DEBUG
		cout << "Constructor:\t" << this << endl;
#endif // DEBUG

	}
	Fraction() //Default constructor
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 0;
#ifdef DEBUG
		cout << "Default constructor: " << this << endl;
#endif // DEBUG

	}
	explicit Fraction(int integer) //Sinagle argument constructor
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "SingleArgumentConstructor: " << this << endl;
#endif // DEBUG

	}
	Fraction(double decimal)
	{
		decimal += 1e-15;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9; //1000000000
		numerator = decimal * denominator;
		reduce();
	}
	Fraction(int numerator,int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->SetDenominator(denominator);
#ifdef DEBUG
		cout << "Constructor: " << this << endl;
#endif // DEBUG

	
	}
	Fraction(const Fraction& other) //Конструктор копирования
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "CopyConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Fraction() 
	{
#ifdef DEBUG
		cout << "Destructor:\t" << this << endl;
#endif // DEBUG

	};

	// Methods
	void print()
	{
		cout <<integer<<"("<<numerator << "/" << denominator <<")"<< endl;
	}
//	Fraction& reduce() //Мой метод REDUCE
//	{
//		//this->to_proper();
//		for (int i = this->denominator; i > 0; i--)
//		{
//			if ((this->numerator) % i == 0 && (this->denominator) % i == 0)
//			{
//				this->numerator /= i;
//				this->denominator /= i;
//				break;
//			}
//
//		}
//		return *this;
//	} 
	Fraction& reduce()
	{
		if (numerator == 0)
		{
			return *this;
		}
		int more, less, rest;
		// 1)определяем кто больше числитель или знаменатель;
		if (numerator>denominator)
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
	Fraction inverted()const 
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator); //swap меняет местами 2 переменные
		return inverted;
	};

	//operators overload
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
#ifdef DEBUG
		cout << "CopyAssignment:\t" << this << endl;
#endif // DEBUG

	}
	Fraction& operator*=(const Fraction& other) 
	{
		return *this = *this * other;
	
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this= *this / other;
	
	}
	Fraction& operator+=(const Fraction& other) 
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		this->integer--;
		return *this;

	}
	Fraction& operator--(int value)
	{
		Fraction newThis = *this;
		this->integer--;
		return newThis;
	}
	/*bool operator ==(const Fraction& other)
	{
		Fraction copyThis=*this;
		Fraction copyOther = other;
		copyThis.to_improper();
		copyOther.to_improper();
		if ((copyThis.GetNumerator()*copyOther.GetDenominator())==(copyOther.GetNumerator()*copyThis.GetDenominator()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator <(const Fraction& other)
	{
		Fraction copyThis = *this;
		Fraction copyOther = other;
		copyThis.to_improper();
		copyOther.to_improper();
		if ((copyThis.GetNumerator() * copyOther.GetDenominator()) < (copyOther.GetNumerator() * copyThis.GetDenominator()))
		{
			return true;
		}
		else
		{
			return false;
		}
	
	}
	bool operator !=(const Fraction& other)
	{
		Fraction copyThis = *this;
		Fraction copyOther = other;
		copyThis.to_improper();
		copyOther.to_improper();
		if ((copyThis.GetNumerator() * copyOther.GetDenominator()) != (copyOther.GetNumerator() * copyThis.GetDenominator()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator <=(const Fraction& other) 
	{
		Fraction copyThis = *this;
		Fraction copyOther = other;
		copyThis.to_improper();
		copyOther.to_improper();
		if ((copyThis.GetNumerator() * copyOther.GetDenominator()) <= (copyOther.GetNumerator() * copyThis.GetDenominator()))
		{
			return true;
		}
		else
		{
			return false;
		}
	
	}
	bool operator >(const Fraction& other) 
	{
		Fraction copyThis = *this;
		Fraction copyOther = other;
		copyThis.to_improper();
		copyOther.to_improper();
		if ((copyThis.GetNumerator() * copyOther.GetDenominator()) > (copyOther.GetNumerator() * copyThis.GetDenominator()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator >=(const Fraction& other)
	{
		Fraction copyThis = *this;
		Fraction copyOther = other;
		copyThis.to_improper();
		copyOther.to_improper();
		if ((copyThis.GetNumerator() * copyOther.GetDenominator()) >= (copyOther.GetNumerator() * copyThis.GetDenominator()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/

	//Type cast operators;
	operator int()const 
	{
		return integer;
	}
	explicit operator double()const 
	{
		return integer+(double)numerator/denominator;
	}

};

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
	else if (obj.GetInteger()==0)
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
	result.SetNumerator(left.GetNumerator()*right.GetDenominator() + right.GetNumerator()*left.GetDenominator());
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
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.GetNumerator() * right.GetDenominator(),
		left.GetDenominator() * right.GetNumerator()
	);*/

}
//Comparison operators
bool operator ==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.GetNumerator()*right.GetDenominator()==right.GetNumerator()*left.GetDenominator())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return left.GetNumerator() * right.GetDenominator() == right.GetNumerator() * left.GetDenominator();
}
bool operator !=(const Fraction& left, const Fraction& right)
{
	return !(left==right);

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
#ifdef arithmetical_operators
	Fraction A(11, 4);
	<<<<<< < HEAD
		Fraction B(5, 6, 7);
	cout << DELIMITER << endl;
	Fraction C = A * B;
	cout << C << endl;
	cout << DELIMITER << endl;
	C = A - B;
	cout << C << endl;
	cout << DELIMITER << endl;
	cout << A / B << endl;
#endif // arithmetical_operators
#ifdef COMPAUND_ASSIGNMENTS
	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	cout << A << endl;
	cout << B << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;
	cout << A - A << endl;
}
#endif // COMPAUND_ASSIGNMENTS
#ifdef INCREMENT_CHECK
for (double i = .3; i < 10; i++)
{
	cout << i << tab;

}
cout << endl;
for (Fraction i(3, 4); i < 10; i++)
{
	cout << i << tab;

}
cout << endl;
#endif // INCREMENT_CHECK
#ifdef COMPARISON_OPERATORS
Fraction A(1, 2);
Fraction B(5, 10);
cout << A << endl;
cout << B << endl;
/*cout << (A == B) << endl;
if (A==B)
{
	cout << "Дроби равны" << endl;
}
else
{
	cout<< "Дроби разные" << endl;
}*/
cout << (A == B) << endl;
cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;
cout << DELIMITER << endl;
cout << A << endl;
cout << B << endl;
#endif // COMPARISON_OPERATORS
#ifdef TYPE_CONVERSION
	//int a = 43;
	////явное преобразование типов - explicit conversion
	//cout << (char)a << endl; //C-like style
	//cout << char(a) << endl; //Function style
	////неявное преобразование - implicit conversion
	//double b = 3.5;
	//cout<<typeid(a + b).name(); 
	Fraction A (5); //explicit constructor можно вызвать только так и невозможно вызвать оператором "="
	cout << A << endl;
	A = (Fraction)8;
	cout << A << endl;
	Fraction B (3, 4, 5);
	double b = B;
	cout <<b<< endl;
	Fraction C = 2.55;
	cout << C << endl;
#endif // TYPE_CONVERSION

	


}

