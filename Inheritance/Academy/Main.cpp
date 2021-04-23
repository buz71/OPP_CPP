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
		Human::info();
		cout << "Курс: " << semester << ", Специальность: " << specialty << ", Успеваемость: " << ratting << endl;
	}
	

};
class Teacher:public Human
{
private:
	string specialty;
	uint expirience;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	uint get_expirience()const
	{
		return expirience;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_expirience(uint expirience)
	{
		this->expirience = expirience;
	}
//Constructors
	Teacher(const string& last_name, const string& first_name, uint age,
		const string& specialty, uint expirience)
		:Human(last_name,first_name,age)
	{
		set_specialty(specialty);
		set_expirience(expirience);
		cout << "TeacherCtor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TeacherDestructor:\t" << this << endl;
	}
//Methods
	void info() const
	{
		Human::info();
		cout <<"Специальность: " << specialty << ", Стаж: " << expirience <<", лет"<< endl;


	}
		
};
class Graduate:public Student
{
private:
	string topicOfProject;
	uint graduationYear;
public:
	string get_topicOfProject() const
	{
		return topicOfProject;
	}
	uint get_graduaitionYear()const
	{
		return graduationYear;
	}
	void set_topicOfProject(const string& topicOfProject)
	{
		this->topicOfProject = topicOfProject;
	}
	void set_graduationYear(uint graduationYear)
	{
		if (graduationYear>=1990)
		{
			this->graduationYear = graduationYear;
		}
		else
		{
			this->graduationYear = 1990;
		}
	}
//Constructor
	Graduate(const string& last_name, const string& first_name, uint age,
		const string& specialty, double ratting, uint semester,
		const string& topicOfProject, uint graduationYear) :
		Student(last_name, first_name, age, specialty, ratting, semester)
	{
		set_topicOfProject(topicOfProject);
		set_graduationYear(graduationYear);
		cout << "GraduateCtor:\t" << this << endl;

	};
	~Graduate()
	{
		cout << "GraduateDestructor:\t" << this << endl;
	}
//Method
	void info()const
	{
		Student::info();
		cout << "Тема дипломного проекта: " << topicOfProject << ", Год выпуска: " << graduationYear << endl;
	}

};
#define DELIMITER "----------------------------------------------"
#define homework_check
void main()
{
	setlocale(LC_ALL, "RU");
	/*Student vasily("Тупенко", "Василий", 18, "Программирование", 4.2, 1);
	vasily.info();*/
#ifdef homework_check
	Teacher ivanovna("Мария", "Ивановна", 36, "Физика", 10);
	ivanovna.info();
	cout << DELIMITER << endl;
	Graduate andrei("Петров", "Андрей", 18, "Промышленная теплоэнергетика", 5.0, 5, "Проектирование котельной", 2025);
	andrei.info();
	cout << DELIMITER << endl;

#endif // teacher_check


}