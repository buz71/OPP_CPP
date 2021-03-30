#include <iostream>
#include <math.h>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

typedef unsigned int uint;

#define tab "\t"
//#define INTRO
#define DELIMITER "--------------------------------------\n"
//#define HOMEWORK
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS
#define HOMEWORK_FRACTION

//double Distance(Point A, Point B)
//{
//	int x = (A.x - B.x);
//	int y = (A.y - B.y);
//	return sqrt((double)(pow(x, 2) + pow(y, 2)));
//
//}

class Point
{

private:
	double x;
	double y;

public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	// Constructors

	//Point() 
	//{
	//	x = y = 0;
	//	cout<< "Constructor:\t" << this << endl;
	//};
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = 0;
	//	cout << "SingleArgumentConstructor: " << this << endl;
	//	//Конструктор с одним параметром отвечает за преобразование типов.
	//}

	Point(double x=0, double y=0) 
	{
		this -> x = x;
		this-> y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//	Operators overload:

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" <<this << endl;
		return *this;
	}

	Point & operator+=(const Point other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator += " << this << endl;
		return *this;
	}

	Point& operator-=(const Point other)
	{
		this->x -= other.x;
		this->y -= other.y;
		cout << "Operator -= " << this << endl;
		return *this;
	}
	
	// Increment/Decrement

	Point& operator++()
	{
		this->x++;
		this->y++;
		return *this;
	}

	Point& operator++(int)
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}

	/*Point operator+(const Point& other)const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "Operator + " << this << endl;
		return result;
	}*/


	//	Methods:

	void Print()const
	{
		cout << "X= " << x << tab << "Y= " << y << endl;
	}
	double Distance()
	{
		
		return sqrt((double)(pow(this->x, 2) + pow(this->y, 2)));

	}
	double DistBetween(Point A, Point B)
	{
		int x = (A.x-B.x);
		int y = (A.y - B.y);
		return sqrt((double)(pow(x,2) + pow(y,2)));
	
	}

};

class Fraction
{
	

private:
	uint numerator;
	uint denominator;
	uint common_denominator(Fraction A)
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
	uint GetNumerator()const
	{
		return numerator;
	}
	uint GetDenominator()const
	{
		return denominator;
	}
	void SetNumerator(uint numerator)
	{
		this->numerator = numerator;
	}
	void SetDenominator(uint denominator) 
	{
		this->denominator = denominator;
	}
	// Constructors & Destructor

	Fraction(uint numerator = 0, uint denominator =0)
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
		if (this->numerator>this->denominator)
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
		for (int i = this->denominator; i >0 ; i--)
		{
			if ((this->numerator)%i==0&&(this->denominator)%i==0)
			{
				this->numerator /= i;
				this->denominator /= i;
				break;
			}
		}
	}
	

	// Operators

	Fraction operator+(Fraction A)
	{
		if (this->denominator==A.denominator)
		{
			this->numerator += A.numerator;
		}

		if (this->denominator!=A.denominator)
		{
			int com_denum = common_denominator(A);
			this->numerator *= ( com_denum/this->denominator );
			A.numerator *= ( com_denum/A.denominator);
			this->numerator += A.numerator;
			this->denominator = com_denum;
		}

		return *this;
	}




};

 // OPERATORS
Point operator+(const Point& left, const Point& right) 
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	cout << "Global - " << endl;
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	cout << "Global * " << endl;
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()

	);

}

Point operator/(const Point& left, const Point& right)
{
	cout << "Global / " << endl;
	return Point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()

	);

}

ostream& operator<<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
	
}

void main()
{
	setlocale(LC_ALL, "RU");

#ifdef INTRO
	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << tab << A.get_y() << endl;

	Point* pA = &A;

	cout << pA->get_x() << tab << pA->get_y() << endl;
	//cout << *(pA).x << tab << *(pA).y << endl;

	cout << sizeof(A) << endl;
	cout << sizeof(pA);
#endif // INTRO

#ifdef HOMEWORK

	int x, y;
	cout << "Введите координаты точки А" << endl;
	cout << "X: ";cin >> x;
	cout << "Y: "; cin >> y;

	Point A(x, y);

	cout << "Введите координаты точки B" << endl;
	cout << "X: "; cin >> x;
	cout << "Y: "; cin >> y;

	Point B(x, y);

	cout << DELIMITER;

	cout <<"Расстояние до точки А: " <<A.Distance()<<endl;

	cout << DELIMITER;

	cout << "Расстояние от точки А до В: " << A.DistBetween(A,B) << endl;

	cout << DELIMITER;

#endif // HOMEWORK

#ifdef CONSTRUCTORS_CHECK
	int a;
	Point A;
	A.Print();
	Point B(2, 3);
	B.Print();

	Point C = 5; // Single argument constructor
	C.Print();
	Point D(8);// Single argument constructor
	D.Print();
	int b(3); // Якобы вызыватся конструктор с одним параметром
	int();	//Якобы вызывается конструктор по умолчанию для типа int
			//и возвращает значение по умолчанию для типа int
			//так можно получить значение по умолчанию для любого типа.

	Point E{ 13 }; //Single argument constructor
	E.Print();
	Point F = B;
	F.Print();
	Point G;
	G = F; // CopyAssigment  
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	A = B = C = Point();
#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS
	Point A(2, 3);
	Point B(3, 4);
	A.Print();
	B.Print();
	Point C = A / B;
	C.Print();
	(A / B).Print();
	A.Print();
	B.Print();

#endif // ARITHMETICAL_OPERATORS

#ifdef HOMEWORK_FRACTION
	Fraction A(5, 8);
	Fraction B(1, 3);
	A.print();
	B.print();
	A + B;
	A.print();
	B.print();

	
	


#endif // HOMEWORK_FRACTION


}