#pragma once
#include <iostream>
#include <stdarg.h>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
typedef unsigned int uint;
class ForwardList;
#define tab "\t"
#define DELIMITER "---------------------------------------------------"
//#define DEBUG
//#define adding_elements_check
//#define HOMEWORK
#define HARDCORE
//#define EXCEPTION
//#define COPYMETHODS_CHECK
//#define OPERATOR_PLUS_CHECK

class Element
{
private:
	int Data; //«начение элемента
	Element* pNext; //”казатель на следующий элемент
	static int count;
public:
	const Element* get_pNext() const;
	const int get_Data()const;
	void set_pNext(Element* pNext);
	//Constructors
	explicit Element(int Data, Element* pNext = nullptr);
	~Element();
	friend class ForwardList;
	friend class Iterator;
	friend ForwardList operator+(const ForwardList left, const ForwardList right);
};

class Iterator
{
private:
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr);
	~Iterator();
	//operators overload
	Iterator& operator++();
	Iterator& operator++(int);
	bool operator==(const Iterator& other)const;
	bool operator!=(const Iterator& other)const;
	const int& operator*()const;
	const Element* operator->()const;
	Element* operator->();
};

class ForwardList
{
private:
	uint size;
	Element* Head; //”казатель на начальный элемент списка
public:
	uint get_size()const;
	const Element* get_head() const;
	//Methods
	Iterator begin();
	Iterator end();
	//Constructors
	ForwardList();
	ForwardList(const std::initializer_list<int>& il);
	ForwardList(const ForwardList& other);
	ForwardList(ForwardList&& other)noexcept;
	~ForwardList();
	//Adding elements:
	void push_front(int Data);
	void push_back(int Data);
	void insert(int Index, int Data);
	//Removing elements
	void pop_front();
	void pop_back();
	void erase(int index);
	//Operators overload
	ForwardList& operator=(const ForwardList& other);
	ForwardList& operator=(ForwardList&& other)noexcept;
	int& operator[](int index);
	//Methods
	void print()const;
};

