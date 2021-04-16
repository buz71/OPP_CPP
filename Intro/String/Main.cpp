#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define DELIMITER "\n--------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

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
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout <<(size==80?"Default":"Size")<< "Ctor:\t"<<this<<endl;
	};
	String(const char* str) :size(strlen(str)+1), str(new char[size] {})
	{
		/*this->size = strlen(str) + 1;
		this->str = new char [size] {};*/
		strcpy(this->str, str);
		cout << "Ctor:\t\t" << this << endl;
	}
	String(const String& other) :size(other.size), str(new char[size] {})
	{
		/*this->size = other.size;
		this->str = new char[size] {};*/
		strcpy(this->str, other.str);
		cout << "CopyCtor:\t" << this << endl;
	}
	String(String&& other) :size(size), str(new char[size] {})
	{
		/*this->size = other.size;
		this->str = other.str;*/
		other.str = nullptr;
		cout << "MoveCtor:\t" << this << endl;
	}
	~String()
	{
		delete this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//Operators
	String& operator+=(const String& other) 
	{
		return *this = *this + other;
	
	}
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
	String& operator=(String&& other)
	{
		delete[]this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}
	const char& operator[](int index)const
	{
		return this->str[index];
	}
	char& operator[](int index)
	{
		return this->str[index];
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
	String result(left.get_size() + right.get_size() - 1);
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
//#define OPERATOR_PLUS_CHECK
	
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
#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << DELIMITER << endl;
	String str3 = str1 + str2; //Оператор + будет выполнять конкатенацию (слияние) строк
	cout << DELIMITER << endl;
	cout << str3 << endl;
#endif // OPERATOR_PLUS_CHECK
	
	String str1; //Default constructor
	String str2(); //Объявляется функция str2, которая ничего не принимает
					//и возвращает значение типа String
	String str3{}; //Default constructor
	String str4(5); //Size constructor
	String str5{ 8 };
	String str6("Hello");
	String str7{ "Hello" };
	//String str8 = 16; //неаявное преобразование int в String

			

}