#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
typedef unsigned int uint;
#define DEBUG

class Animal
{
private:
public:
	virtual void sound()const = 0; //Чисто виртуальный метод (Pure-virtual function)
};

class Cat:public Animal
{
	//Это тоже асбтрактный класс, так как не реальзует чисто виртуальный метод.
};

class Tiger:public Cat
{
	void sound()const
	{
		cout << "Рррррр" << endl;
	}
};

class HomeCat: public Cat
{
	void sound()const
	{
		cout << "Мяу" << endl;
	}
};

class Dog:public Animal
{
private:
public:
	void sound()const
	{
		cout << "Гав" << endl;
	}
};

void main() 
{
	setlocale(LC_ALL, "RU");
	//Animal a;
	//Cat tom;
	//Dog rex;

	Animal* zoo[] =
	{
		new HomeCat,
		new Dog,
		new Tiger,
		new Dog,
		new HomeCat
	};

	for (int i = 0; i < sizeof(zoo)/sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
}