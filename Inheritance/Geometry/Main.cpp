#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
typedef unsigned int uint;
#define DEBUG
class Shape
{
private:
	string color;
public:
	Shape(const string color) 
	{
		this->color = color;
	};
	virtual double area()const = 0;
	virtual double perimeter()const = 0;
	virtual void draw()const = 0;
};
class Square:public Shape
{
private:
	double side;
public:
	double get_side()const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side>0)
		{
			this->side = side;
		}
		else
		{
			this->side = 1;
		}
	}
	explicit Square(double side,const string& color="white"):Shape(color)
	{
		set_side(side);
	}
	~Square()
	{

	}
	double area()const
	{
		return side * side;
	}
	double perimeter()const
	{
		return side * 4;
	}
	void draw()const
	{
		for (int i = 0; i <side-1; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
};
class Rectangle:public Shape
{
private:
	double sideA;
	double sideB;

public:
	double get_sideA()const
	{
		return sideA;
	}
	double get_sideB()const
	{
		return sideB;
	}
	void set_sideA(double sideA)
	{
		if (sideA>0)
		{
			this->sideA = sideA;
		}
	}
	void set_sideB(double sideB)
	{
		if (sideB > 0)
		{
			this->sideB = sideB;
		}
	}
	Rectangle(double sideA, double sideB, const string& color = "white") :Shape(color) 
	{
		this->set_sideA(sideA);
		this->set_sideB(sideB);
	};
	~Rectangle()
	{

	}
	double area()const
	{
		return sideA * sideB;
	}
	double perimeter()const
	{
		return (sideA+sideB)*2;
	}
	void draw()const
	{
		for (int i = 0; i < sideA; i++)
		{
			for (int j = 0; j < sideB-1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}



};

void main()
{
	setlocale(LC_ALL, "RU");
	/*Square square(5);
	cout << "Площадь: " << square.area() << endl;
	cout << "Периметр: " << square.perimeter() << endl;
	square.draw();*/
	Rectangle rectangle(3,6);
	cout << "Площадь: " << rectangle.area() << endl;
	cout << "Периметр: " << rectangle.perimeter() << endl;
	rectangle.draw();
}