#pragma once
#include "Element.h"
#include "Iterator.h"
//class implementation Iterator
template<typename T>class Iterator
{
private:
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr);
	~Iterator();
	//operators overload
	Iterator<T>& operator++();
	Iterator<T>& operator++(int);
	bool operator==(const Iterator<T>& other)const;
	bool operator!=(const Iterator<T>& other)const;
	const T& operator*()const;
	const Element<T>* operator->()const;
	Element<T>* operator->();
};
