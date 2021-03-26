#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
//#define INTRO
#define DELIMITER "--------------------------------------\n"
//#define HOMEWORK
//#define CONSTRUCTORS_CHECK

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

	//	Operators:

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" <<this << endl;
		return *this;
	}

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

	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point();



}