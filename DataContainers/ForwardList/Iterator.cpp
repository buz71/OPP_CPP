#include "Header.h"
Iterator::Iterator(Element* Temp) :Temp(Temp)
{
#ifdef DEBUG
	cout << "ICtor:\t" << this << endl;
#endif // DEBUG

}
Iterator::~Iterator()
{
#ifdef DEBUG
	cout << "IDeCtor:\t" << this << endl;
#endif // DEBUG

}
Iterator& Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
Iterator& Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
bool Iterator::operator==(const Iterator& other)const
{
	return this->Temp == other.Temp;
}
bool Iterator::operator!=(const Iterator& other)const
{
	return this->Temp != other.Temp;
}
const int& Iterator::operator*()const
{
	return Temp->Data;
}
const Element* Iterator::operator->()const
{
	return Temp;
}
Element* Iterator::operator->()
{
	return Temp;
}