#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

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

};



void main()
{
	setlocale(LC_ALL, "RU");

	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << tab << A.get_y() << endl;

	Point* pA = &A;

	cout << pA->get_x() << tab << pA->get_y() << endl;
	//cout << *(pA).x << tab << *(pA).y << endl;


	cout << sizeof(A) << endl;
	cout << sizeof(pA);

}