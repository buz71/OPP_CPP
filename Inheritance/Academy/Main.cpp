#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
typedef unsigned int uint;
//Classes
class Human
{
private:
	string last_name;
	string first_name;
	uint age;
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	uint get_age()const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(uint age) //так же можно передать по константной ссылке
	{
		if (age >= 15 && age <= 100)
		{
			this->age = age;
		}
		else
		{
			this->age = 0;
		}
	}
	//constructors
	Human(const string& last_name, const string& first_name, uint age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HumanCtor: \t" << this << endl;
	}
	~Human()
	{
		cout << "Destructor: \t" << this << endl;
	}
	//Methods
	void info()const
	{
		cout << last_name << " " << first_name << ", " << age << " лет" << endl;
	}



};
class Student:public Human
{
private:
	string specialty;
	double ratting;
	uint semester;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	double get_ratting()const
	{
		return ratting;
	}
	uint get_semester()const
	{
		return semester;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_ratting(double ratting)
	{
		if (ratting<=5)
		{
			this->ratting = ratting;
		}
		else
		{
			this->ratting = 0;
		}
	}
	void set_semester(uint semester)
	{
		if (semester<=5)
		{
			this->semester = semester;
		}
		else
		{
			this->semester = 0;
		}
	
	}
//Constructors
	Student
	(
		const string& last_name, const string& first_name, uint age,  
		const string& specialty, double ratting,uint semester
	):Human(last_name,first_name,age)
	{
		set_specialty(specialty);
		set_ratting(ratting);
		set_semester(semester);
		cout << "StudentCtor: \t" << this << endl;
	}
	~Student()
	{
		cout << "StudentDestr: \t" << this << endl;
	}
	void info()const
	{
		cout << "Курс: " << semester << ", Специальность: " << specialty << ", Успеваемость: " << ratting << endl;
	}
	

};

void main()
{
	setlocale(LC_ALL, "RU");
	//Human vasily("Тупенко", "Василий", 18);
	//vasily.info();
	Student vasily("Тупенко", "Василий", 18, "Программирование", 4.2, 1);
	vasily.info();

}