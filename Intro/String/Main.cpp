#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define DELIMITER "\n--------------------------------------------\n"

class String
{
private:
	char* str; //Указатель на строку в динамической памяти
	int size; //Размер строки в байтах
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	//Constructors
	String(int size = 80) 
	{
		this->size = size;
		this->str = new char[size] {};
		cout <<(size==80?"Default":"Size")<< "Ctor:\t"<<this<<endl;
	};
	String(const char* str) 
	{
		this->size = strlen(str) + 1;
		this->str = new char [size] {};
		strcpy(this->str, str);
		cout << "Ctor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyCtor:\t" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//Operators
	String& operator=(const String& other)
	{
		//0) Проверить не является ли другой объект нашим объектом
		if (this==&other)return *this;
		//1)Сначала удаляем старое значение объекта
		delete[]this->str;
		//2) Только потом присваиваем ему новое значение
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	//Methods
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t"<< str << endl;
	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right )
{
	String result = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size(); i++)
	{
		result.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		result.get_str()[i+left.get_size()-1] = right.get_str()[i];
	}
	return result;
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "RU");
#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();
	String str2 = "Hello";
	str2.print();
	cout << str2 <<endl;
	cout << "Str2:\t" << str2 << endl;
	String str3 = str2;
	cout << "Str3:\t" << str3 << endl;
	String str4;
	str4 = str3;
	cout << "Str4:\t" << str4 << endl;
#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK

	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;
#endif //  ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << DELIMITER << endl;
	String str3 = str1 +str2; //Оператор + будет выполнять конкатенацию (слияние) строк
	cout << DELIMITER << endl;
	cout << str3 << endl;



}