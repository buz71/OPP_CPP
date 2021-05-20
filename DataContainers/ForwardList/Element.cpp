#include "Header.h"
int Element::count = 0;
const Element* Element::get_pNext() const
{
	return pNext;
}
const int Element::get_Data()const
{
	return Data;
}
void Element::set_pNext(Element* pNext)
{
	this->pNext = pNext;
}
Element::Element(int Data, Element* pNext) :Data(Data), pNext(pNext)
{
	count++;
#ifdef DEBUG
	//cout << "ECtor:\t" << this << endl;
#endif // DEBUG

}
Element::~Element()
{
	count--;
#ifdef DEBUG
	//cout << "EDeCtor:\t" << this << endl;
#endif // DEBUG

}