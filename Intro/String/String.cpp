#include "String.h"
////////////////////////// Class defenition -Определение класса  ///////////////
////////////////////////////////////////////////////////////////////////////////
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size()const
{
	return size;
}
//Constructors
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << (size == 80 ? "Default" : "Size") << "Ctor:\t" << this << endl;
};
String::String(const char* str) :size(strlen(str) + 1), str(new char[size] {})
{
	/*this->size = strlen(str) + 1;
	this->str = new char [size] {};*/
	strcpy(this->str, str);
	cout << "Ctor:\t\t" << this << endl;
}
String::String(const String& other) :size(other.size), str(new char[size] {})
{
	/*this->size = other.size;
	this->str = new char[size] {};*/
	strcpy(this->str, other.str);
	cout << "CopyCtor:\t" << this << endl;
}
String::String(String&& other) :size(size), str(new char[size] {})
{
	/*this->size = other.size;
	this->str = other.str;*/
	other.str = nullptr;
	cout << "MoveCtor:\t" << this << endl;
}
String::~String()
{
	delete this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//Operators
String& String::operator+=(const String& other)
{
	return *this = *this + other;

}
String& String::operator=(const String& other)
{
	//0) Проверить не является ли другой объект нашим объектом
	if (this == &other)return *this;
	//1)Сначала удаляем старое значение объекта
	delete[]this->str;
	//2) Только потом присваиваем ему новое значение
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[]this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
const char& String::operator[](int index)const
{
	return this->str[index];
}
char& String::operator[](int index)
{
	return this->str[index];
}
//Methods
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		result.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return result;
}
////////////////////////// Class defenition - Определение класса  ///////////////
////////////////////////////////////////////////////////////////////////////////