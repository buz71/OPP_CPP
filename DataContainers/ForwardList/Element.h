#pragma once
#include <iostream>
#include <stdarg.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
typedef unsigned int uint;
#define tab "\t"
#define DELIMITER "---------------------------------------------------"
//#define HARDCORE
//#define EXCEPTION
//class defenition Element
template<typename T>
class Iterator;

template <typename T>
class ForwardList;

template <typename T>class Element
{
private:
	T Data; //«начение элемента
	Element* pNext; //”казатель на следующий элемент
	static int count;
public:
	const Element* get_pNext()const;
	const T get_Data()const;
	void set_pNext(Element* pNext);
	Element(T Data, Element* pNext = nullptr);
	~Element();
	friend class ForwardList<T>;
	friend class Iterator<T>;
	friend ForwardList<T> operator+(const ForwardList<T>& left, const ForwardList<T>& right);
};

