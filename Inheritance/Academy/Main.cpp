#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
typedef unsigned int uint;
#define DEBUG
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
		/*if (age >= 15 && age <= 100)
		{
			this->age = age;
		}
		else
		{
			this->age = 0;
		}*/
		this->age = age;
	}
	//constructors
	Human(const string& last_name, const string& first_name, uint age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
#ifdef DEBUG
		cout << "HumanCtor: \t" << this << endl;
#endif // DEBUG

	}
	virtual ~Human()
	{
#ifdef DEBUG
		cout << "Destructor: \t" << this << endl;
#endif // DEBUG

	}
	//Methods
	virtual void info()const
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
#ifdef DEBUG
		cout << "StudentCtor: \t" << this << endl;
#endif // DEBUG

	}
	~Student()
	{
#ifdef DEBUG
		cout << "StudentDestr: \t" << this << endl;
#endif // DEBUG

	}
	void info()const
	{
		Human::info();
		cout << "Курс: " << semester << ", Специальность: " << specialty << ", Успеваемость: " << ratting << endl;
	}
};
class Teacher:public Human
{
private:
	string specialty;
	uint experience;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	uint get_experience()const
	{
		return experience;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(uint expirience)
	{
		this->experience = expirience;
	}
//Constructors
	Teacher(const string& last_name, const string& first_name, uint age,
		const string& specialty, uint expirience)
		:Human(last_name,first_name,age)
	{
		set_specialty(specialty);
		set_experience(expirience);
#ifdef DEBUG
		cout << "TeacherCtor:\t" << this << endl;
#endif // DEBUG

	}
	~Teacher()
	{
#ifdef DEBUG
			cout << "TeacherDestructor:\t" << this << endl;
#endif // DEBUG

	}
//Methods
	void info() const
	{
		Human::info();
		cout <<"Специальность: " << specialty << ", Стаж: " << experience <<", лет"<< endl;
	}
};
class Graduate:public Student
{
private:
	string topic;
public:
	string get_topic() const
	{
		return topic;
	}

	void set_topic(const string& topic)
	{
		this->topic = topic;
	}
	
//Constructor
	Graduate(const string& last_name, const string& first_name, uint age,
		const string& specialty, double ratting, uint semester,
		const string& topic) :
		Student(last_name, first_name, age, 
				specialty, ratting, semester)
	{
		set_topic(topic);
#ifdef DEBUG
		cout << "GraduateCtor:\t" << this << endl;
#endif // DEBUG

	};
	~Graduate()
	{
#ifdef DEBUG
			cout << "GraduateDestructor:\t" << this << endl;
#endif // DEBUG

	}
//Method
	void info()const
	{
		Student::info();
		cout << "Тема дипломного проекта: " << topic << endl;
	}

};
#define DELIMITER "----------------------------------------------"

//#define inheritance_basics
void main()
{
	setlocale(LC_ALL, "RU");
#ifdef inheritance_basics
	Student vasily("Тупенко", "Василий", 18, "Программирование", 4.2, 1);
	vasily.info();
	Teacher teacher("Einstein", "Albert", 142, "Astronomy", 120);
	teacher.info();
	cout << DELIMITER << endl;
	Graduate grad("Pinkman", "Jessy", 25, "Chemistry", 5, 5, "Drug Dealer");
	grad.info();
	cout << DELIMITER << endl;
	Human* p_vasily = &vasily;
	Human* p_teacher = &teacher;
	Human* p_grad = &grad;
	Human* group[] =
	{
		&vasily,
		&teacher,
		&grad
	}; 
#endif // inheritance_basics


	Human* group[] =
	{
		new Student("Тупенко", "Василий", 18, "Программирование", 4.2, 1),
		new Student("Пилипенко", "Евгений", 25, "Программирование", 4.5, 2),
		new Teacher("Einstein", "Albert", 142, "Astronomy", 120),
		new Student("Montana", "Antonio", 30, "Cocaine dealer", 4.8, 4),
		new Graduate("Pinkman", "Jessy", 25, "Chemistry", 5, 5, "Drug Dealer")
	};

	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		group[i]->info();
		cout << DELIMITER << endl;
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}


}