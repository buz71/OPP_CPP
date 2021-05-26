#include "Iterator.h"
//class realisation Iterator
template<typename T>Iterator<T>::Iterator(Element<T>* Temp) :Temp(Temp)
{

}
template<typename T>Iterator<T>::~Iterator()
{
}
template<typename T>Iterator<T>& Iterator<T>::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
template<typename T>Iterator<T>& Iterator<T>::operator++(int)
{
	Iterator<T> old = *this;
	Temp = Temp->pNext;
	return old;
}
template<typename T>bool Iterator<T>::operator==(const Iterator<T>& other)const
{
	return this->Temp == other.Temp;
}
template<typename T>bool Iterator<T>::operator!=(const Iterator<T>& other)const
{
	return this->Temp != other.Temp;
}
template<typename T>const T& Iterator<T>::operator*()const
{
	return Temp->Data;
}
template<typename T>const Element<T>* Iterator<T>::operator->()const
{
	return Temp;
}
template<typename T> Element<T>* Iterator<T>::operator->()
{
	return Temp;
}
