#pragma once
#include "Element.h"
// class implementation ForwardList
template<typename T>class ForwardList
{
private:
	uint size;
	Element<T>* Head; //”казатель на начальный элемент списка
public:
	uint get_size()const;
	const Element<T>* get_head() const;
	//Methods
	Iterator<T> begin();
	Iterator<T> end();
	//Constructors
	ForwardList();
	ForwardList(const std::initializer_list<T>& il);
	ForwardList<T>(const ForwardList<T>& other);
	ForwardList(ForwardList&& other)noexcept;
	~ForwardList();
	//Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(int Index, T Data);
	//Removing elements
	void pop_front();
	void pop_back();
	void erase(int index);
	//Operators overload
	ForwardList& operator=(const ForwardList& other);
	ForwardList<T>& operator=(ForwardList<T>&& other)noexcept;
	T& operator[](int index);
	//Methods
	void print()const;
};
