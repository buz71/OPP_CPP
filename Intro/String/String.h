#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define DELIMITER "\n--------------------------------------------\n"
////////////////////////// Class declaration - Объявление класса  ///////////////
////////////////////////////////////////////////////////////////////////////////
class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);
class String
{
private:
	char* str; //Указатель на строку в динамической памяти
	int size; //Размер строки в байтах
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;
	//Constructors
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//Operators
	String& operator+=(const String& other);
	String& operator=(const String& other);
	String& operator=(String&& other);
	const char& operator[](int index)const;
	char& operator[](int index);
	//Methods
	void print()const;
};
////////////////////////// Class declaration end ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////


