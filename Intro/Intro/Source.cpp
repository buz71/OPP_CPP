#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
//#define INTRO

class Point
{
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

	

	Point() 
	{
		x = y = 0;
		cout<< "Constructor:\t" << this << endl;
	};

	Point(double x, double y) 
	{
		this -> x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Methods

	void print()const
	{
		cout << "X= " << x << tab << "Y= " << y << endl;
	}

	double Distance()
	{
		
		return sqrt((double)(pow(this->x, 2) + pow(this->y, 2)));
	
	}
};

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

	Point A;
	A.set_x(2);
	A.set_y(2);

	A.print();

	/*Point B(2,3);

	B.print();*/

	cout << A.Distance() << endl;

}