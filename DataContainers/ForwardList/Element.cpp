#include "Element.h"
//class implementation Element
template<typename T>int Element<T>::count = 0;
template<typename T>const Element<T>* Element<T>::get_pNext()const
{
	return pNext;
};
template<typename T>const T Element<T>::get_Data()const
{
	return Data;
};
template<typename T>void Element<T>::set_pNext(Element* pNext)
{
	this->pNext = pNext;
};
template<typename T>Element<T>::Element(T Data, Element* pNext) :Data(Data), pNext(pNext)
{
	count++;
};
template<typename T>Element<T>::~Element()
{
	count--;
};
